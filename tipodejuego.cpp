#include "tipodejuego.h"
#include "ui_tipodejuego.h"


TipoDeJuego::TipoDeJuego(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TipoDeJuego)
{
    ui->setupUi(this);

    setWindowTitle("Configurar Partida");

    // Agregar los campos al QComboBox utilizando un bucle for
    for (int i = 0; i < 3; ++i) {
        QString dificultad;
        switch (i) {
            case 0:
                dificultad = "Difícil";
                break;
            case 1:
                dificultad = "Medio";
                break;
            case 2:
                dificultad = "Fácil";
                break;
        }
        ui->cbxDificultad->addItem(dificultad);
    }
}


TipoDeJuego::~TipoDeJuego()
{
    delete ui;
}

