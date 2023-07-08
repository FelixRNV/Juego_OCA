#include "juego_oca.h"
#include "ui_juego_oca.h"

Juego_OCA::Juego_OCA(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Juego_OCA)
{
    ui->setupUi(this);
    ui->widCasIni->setStyleSheet("background-color: rgba(0,0,0,0)");

}

Juego_OCA::~Juego_OCA()
{
    delete ui;
}

