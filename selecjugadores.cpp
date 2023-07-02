#include "selecjugadores.h"
#include "ui_selecjugadores.h"

SelecJugadores::SelecJugadores(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelecJugadores)
{
    ui->setupUi(this);
}

SelecJugadores::~SelecJugadores()
{
    delete ui;
}
