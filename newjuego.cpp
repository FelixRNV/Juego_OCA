#include "newjuego.h"
#include "ui_newjuego.h"

NewJuego::NewJuego(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewJuego)
{
    ui->setupUi(this);
}

NewJuego::~NewJuego()
{
    delete ui;
}
