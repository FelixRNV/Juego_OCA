#include "inicio.h"
#include "ui_inicio.h"

Inicio::Inicio(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Inicio)
{
    ui->setupUi(this);
}

Inicio::~Inicio()
{
    delete ui;
}
