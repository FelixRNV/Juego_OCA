#include "puntajes.h"
#include "ui_puntajes.h"

Puntajes::Puntajes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Puntajes)
{
    ui->setupUi(this);
}

Puntajes::~Puntajes()
{
    delete ui;
}
