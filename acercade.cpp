#include "acercade.h"
#include "ui_acercade.h"
#include "QTranslator"
Acercade::Acercade(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Acercade)
{
    ui->setupUi(this);
}

Acercade::~Acercade()
{
    delete ui;
}
