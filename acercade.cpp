#include "acercade.h"
#include "ui_acercade.h"
#include "QTranslator"
Acercade::Acercade(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Acercade)
{
    ui->setupUi(this);
    setWindowTitle(tr("Acerca de"));
}

Acercade::~Acercade()
{
    delete ui;
}
