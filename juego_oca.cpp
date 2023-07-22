#include "juego_oca.h"
#include "ui_juego_oca.h"

Juego_OCA::Juego_OCA(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Juego_OCA)
{
    ui->setupUi(this);


}

Juego_OCA::~Juego_OCA()
{
    delete ui;
}


void Juego_OCA::on_action_Nuevo_triggered()
{
    NewJuego ne(this);
    if(ne.exec()==QDialog::Accepted){
        p1=ne.p1();
        p2=ne.p2();
        p3=ne.p3();
        p4=ne.p4();
        m_level=ne.level();
        m_tema=ne.Tema();
        ui->ltxJugador->setText(p1->name());
        qDebug() << p1->name();
    }


}


void Juego_OCA::on_action_Tem_ticas_triggered()
{
    NewTematica te(this);
    int res = te.exec();
    if (res== QDialog::Rejected)
        return;
}



void Juego_OCA::on_btnDado_released()
{
    int dado;

    dado = QRandomGenerator::system()->bounded(1,6);
    QMessageBox::information(this, "Dado", "Avanza : "+ QString::number(dado) +" Casilleros");
}


void Juego_OCA::on_action_Reglas_triggered()
{
    // Cargar el archivo PDF desde el recurso de Qt
    QFile pdfFile(ARCHIVO);

    // Verificar si el archivo PDF se puede abrir correctamente
    if (!pdfFile.open(QIODevice::ReadOnly))
    {
        qDebug() << "Error al abrir el archivo PDF.";
        return;
    }

    // Obtener la ruta temporal para guardar el archivo
    QString tempFilePath = QStandardPaths::writableLocation(QStandardPaths::TempLocation) + "/reglamento_temp.pdf";

    // Crear un archivo temporal para guardar el contenido del PDF
    QFile tempFile(tempFilePath);
    if (!tempFile.open(QIODevice::WriteOnly))
    {
        qDebug() << "Error al guardar el archivo PDF temporalmente.";
        pdfFile.close();
        return;
    }

    // Leer el contenido del PDF desde el recurso y escribirlo en el archivo temporal
    tempFile.write(pdfFile.readAll());

    // Cerrar ambos archivos
    pdfFile.close();
    tempFile.close();

    // Abrir el archivo PDF usando el visor de PDF predeterminado del sistema
    QDesktopServices::openUrl(QUrl::fromLocalFile(tempFilePath));
}


void Juego_OCA::on_actionA_cerca_de_triggered()
{
    Acercade ventanaAcercaDe;
    ventanaAcercaDe.exec();
}


void Juego_OCA::on_action_Salir_triggered()
{
    close();
}

