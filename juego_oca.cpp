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

