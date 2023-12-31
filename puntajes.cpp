#include "puntajes.h"
#include "ui_puntajes.h"
#include "QTranslator"
Puntajes::Puntajes(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Puntajes)
{
    ui->setupUi(this);
    //nombrar columnas
    QStringList titulos;
    int fila;
    fila = ui->tableClasificacion->rowCount()  -1;

    setWindowTitle(tr("Tabla de Clasificación"));
    ui->tableClasificacion->setColumnCount(4);//generar columnas
    titulos << tr("Nombre") << tr("Puntuación") << tr("Correctas") << tr("Incorrectas");
    ui->tableClasificacion->setHorizontalHeaderLabels(titulos);

    ui->tableClasificacion->insertRow(ui->tableClasificacion->rowCount());

    ui->tableClasificacion->setItem(fila, NOMBRE, new QTableWidgetItem(NOMBRE));
    ui->tableClasificacion->setItem(fila, PUNTUACION, new QTableWidgetItem(PUNTUACION));
    ui->tableClasificacion->setItem(fila, CORRECTAS, new QTableWidgetItem(CORRECTAS));
    ui->tableClasificacion->setItem(fila, INCORRECTAS, new QTableWidgetItem(INCORRECTAS));


}

Puntajes::~Puntajes()
{
    delete ui;
}





