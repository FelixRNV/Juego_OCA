#include "tematicas.h"
#include "ui_tematicas.h"

Tematicas::Tematicas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tematicas)
{
    ui->setupUi(this);
}

Tematicas::~Tematicas()
{
    delete ui;
}
