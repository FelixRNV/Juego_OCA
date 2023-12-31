#include "newtematica.h"
#include "ui_newtematica.h"

NewTematica::NewTematica(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::NewTematica)
{
    ui->setupUi(this);
    setWindowTitle(tr("Formulario de Preguntas"));


    //Cargar ComboBox de temas
    QFile ind(BASE);
    if(!ind.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QTextStream indix(&ind);
    while (!indix.atEnd()) {
        QString line = indix.readLine();
        ui->cbx_Temas->addItem(line);
    }
    ind.close();
    ui->cbx_Temas->addItem(tr("Añadir Tema..."));
    // Configurar la tabla
    ui->tblLista->setColumnCount(2);
    QStringList titulo;
    titulo << tr("Pregunta") << tr("Respuesta");
    ui->tblLista->setHorizontalHeaderLabels(titulo);

    // Ajustar el ancho de la columna de preguntas

    ui->tblLista->setColumnWidth(PREGUNTAS, 746); // Ajusta el ancho en píxeles

    // Leer desde el archivo
    cargarPreguntas();
}

NewTematica::~NewTematica()
{
    delete ui;
}


void NewTematica::cargarPreguntas()
{
    // Verificar si el archivo existe
    QString filePath=QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)+"/OCASources/Temas" + path;

    // Verificar si el archivo existe
    QFile archivo(filePath);
    if (!archivo.exists())
        return;


    // Limpiar la tabla existente
    ui->tblLista->clearContents();
    ui->tblLista->setRowCount(0);

    // Cargar las preguntas del nuevo archivo
    if (archivo.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream entrada(&archivo);
        int fila = 0;
        while (!entrada.atEnd()) {
            QString linea = entrada.readLine();
            QStringList datos = linea.split(";");
            if (datos.size() == 2) {
                ui->tblLista->insertRow(fila);
                ui->tblLista->setItem(fila, PREGUNTAS, new QTableWidgetItem(datos[0]));
                ui->tblLista->setItem(fila, RESPUESTAS, new QTableWidgetItem(datos[1]));
                fila++;
            }
        }
        archivo.close();
    }
}

void NewTematica::cargarPreguntas(const QString& filePath)
{
    // Verificar si el archivo existe
    QFile archivo(filePath);
    if (!archivo.exists()) {
        QMessageBox::critical(this, tr("Cargar preguntas"), tr("El archivo no existe."));
        return;
    }

    // Limpiar la tabla existente
    ui->tblLista->clearContents();
    ui->tblLista->setRowCount(0);

    // Cargar las preguntas del nuevo archivo
    if (archivo.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream entrada(&archivo);
        int fila = 0;
        while (!entrada.atEnd()) {
            QString linea = entrada.readLine();
            QStringList datos = linea.split(";");
            if (datos.size() == 2) {
                ui->tblLista->insertRow(fila);
                ui->tblLista->setItem(fila, PREGUNTAS, new QTableWidgetItem(datos[0]));
                ui->tblLista->setItem(fila, RESPUESTAS, new QTableWidgetItem(datos[1]));
                fila++;
            }
        }
        archivo.close();
    } else {
        QMessageBox::critical(this, tr("Cargar preguntas"), tr("No se pudo abrir el archivo."));
    }
}



void NewTematica::on_btn_CargaPreguntas_clicked()
{
    // Mostrar el diálogo para seleccionar un archivo de texto o CSV
    QString filePath = QFileDialog::getOpenFileName(this, tr("Seleccionar archivo"), QString(), tr("Archivos de texto (*.txt *.csv )"));

    // Verificar si se seleccionó un archivo
    if (!filePath.isEmpty()) {
        cargarPreguntas(filePath);
        QMessageBox::information(this, tr("Cargar archivo"), tr("Archivo cargado exitosamente."));
    }
}




void NewTematica::on_btn_Guardar_clicked()
{
    // Verificar que existan datos para guardar
    int filas = ui->tblLista->rowCount();
    if (filas == 0) {
        QMessageBox::warning(this, tr("Guardar archivo"), tr("No hay datos para guardar"));
        return;
    }

    // Obtener el nombre del archivo ingresado por el usuario
    QString fileName;
    if (ui->cbx_Temas->currentText()=="Añadir Tema...")
        fileName = ui->ltxNombreTematica->text();
    else
        fileName=ui->cbx_Temas->currentText();


    // Verificar que se haya ingresado un nombre de archivo válido
    if (fileName.isEmpty()) {
        QMessageBox::warning(this, tr("Guardar archivo"), tr("Debe ingresar un nombre válido"));
        return;
    }

    // Agregar la extensión .bin al nombre del archivo
    QString binFilePath = fileName + ".oca";


    // Obtener la ruta de la carpeta de la aplicación
    QString folderPath =  QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)+"/OCASources/Temas";

    // Combinar la ruta de la carpeta y el nombre del archivo
    QString selectedFilePath = folderPath + "/" + binFilePath;

    // Abrir el archivo binario en modo escritura
    QDir dir;
    if (!dir.exists(folderPath)){
        dir.mkpath(folderPath);
    }

    QFile nue(selectedFilePath);
    if (!nue.open(QIODevice::WriteOnly)) {
        QMessageBox::critical(this, tr("Guardar archivo"), tr("No se puede almacenar la temática"));

        return;
    }

    QTextStream salida(&nue);

    for (int i = 0; i < filas; i++) {
        QTableWidgetItem *pregunta = ui->tblLista->item(i, PREGUNTAS);
        QTableWidgetItem *respuesta = ui->tblLista->item(i, RESPUESTAS);

        QString preguntaText = pregunta->text() + ";" + respuesta->text()+"\n";


        // Escribir los datos en el archivo binario
        salida << preguntaText;
    }

    nue.close();

    if (ui->cbx_Temas->currentText()=="Añadir Tema..."){
    QFile ind(BASE);
    if (!ind.open(QIODevice::WriteOnly | QIODevice::Append))
        return;

    QTextStream indix(&ind);
    indix << fileName + "\n";
    ind.close();
    //Cargar Nuevo tema

    ui->cbx_Temas->removeItem(ui->cbx_Temas->count()-1);
    ui->cbx_Temas->addItem(fileName);
    ui->cbx_Temas->addItem(tr("Añadir Tema..."));
    ui->ltxNombreTematica->clear();
    }

    QMessageBox::information(this, tr("Guardar archivo"), tr("Preguntas guardadas exitosamente"));


    return;



    close();
}


void NewTematica::on_btn_Ingresar_clicked()
{
    // Crear y mostrar el dialogo
    Agregar pd(this);
    pd.setWindowTitle(tr("Agregar Preguntas"));
    // Abrir la ventana y evaluar respuesta
    int res = pd.exec();
    if (res == QDialog::Rejected){
        return;
    }
    // Recuperar el objeto del cuadro de dialogo
    Preguntas *p = pd.preguntas();
    //Agregar a la tabla
    int fila = ui->tblLista->rowCount();
    ui->tblLista->insertRow(fila);

    ui->tblLista->setItem(fila, PREGUNTAS, new QTableWidgetItem(p->pregunta()));
    ui->tblLista->setItem(fila, RESPUESTAS, new QTableWidgetItem(p->respuesta()));
}


void NewTematica::on_btn_Editar_clicked()
{
    int filaSeleccionada = ui->tblLista->currentRow();

    if (filaSeleccionada < 0) {
        return;
    }

    // Obtener los datos de la fila seleccionada
    QTableWidgetItem *preguntaItem = ui->tblLista->item(filaSeleccionada, PREGUNTAS);
    QTableWidgetItem *respuestaItem = ui->tblLista->item(filaSeleccionada, RESPUESTAS);

    // Verificar si se seleccionó una fila válida
    if (preguntaItem && respuestaItem) {
        // Obtener los textos actuales de la pregunta y respuesta
        QString preguntaActual = preguntaItem->text();
        QString respuestaActual = respuestaItem->text();

        // Crear y mostrar el cuadro de diálogo para editar la pregunta y respuesta
        Agregar pd(this);
        pd.setWindowTitle(tr("Editar Pregunta"));
        pd.setPregunta(preguntaActual);
        pd.setRespuesta(respuestaActual);

        int res = pd.exec();
        if (res == QDialog::Rejected) {
            return;
        }

        // Obtener los nuevos valores de pregunta y respuesta desde el cuadro de diálogo
        QString nuevaPregunta = pd.getPregunta();
        QString nuevaRespuesta = pd.getRespuesta();

        // Actualizar los datos en la tabla
        preguntaItem->setText(nuevaPregunta);
        respuestaItem->setText(nuevaRespuesta);

        QMessageBox::information(this, tr("Editar Pregunta"), tr("Pregunta editada exitosamente."));
    }
}

void NewTematica::on_btn_Eliminar_clicked()
{
    int filaSeleccionada = ui->tblLista->currentRow();

    if (filaSeleccionada < 0) {
        return;
    }

    ui->tblLista->removeRow(filaSeleccionada);
}


void NewTematica::on_btn_Cerrar_clicked()
{
    close();
}



void NewTematica::on_cbx_Temas_currentTextChanged(const QString &arg1)
{
    ui->ltxNombreTematica->setEnabled(false);
    ui->btn_CargaPreguntas->setEnabled(false);
    if (arg1=="Añadir Tema..."){
        ui->ltxNombreTematica->setEnabled(true);
        ui->btn_CargaPreguntas->setEnabled(true);
        return;
    }
    if (arg1=="<Seleccionar>")
        return;
    path = "/"+arg1 + ".oca";

    cargarPreguntas();
}


void NewTematica::on_btn_NewTopic_released()
{
    ui->cbx_Temas->setCurrentIndex(ui->cbx_Temas->count()-1);


}

