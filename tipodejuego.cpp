#include "tipodejuego.h"
#include "ui_tipodejuego.h"

TipoDeJuego::TipoDeJuego(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TipoDeJuego)
{
    ui->setupUi(this);
}

TipoDeJuego::~TipoDeJuego()
{
    delete ui;
}
