#include "inicio.h"
#include "ui_inicio.h"
#include "juego_oca.h"
#include <QTimer>
Inicio::Inicio(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Inicio)
{
    ui->setupUi(this);
    show();
    //oculta la barra superior de la ventana para que parezca una verdadera ventana de carga
    setWindowFlags(Qt::CustomizeWindowHint);
    QTimer::singleShot(7000, this, SLOT(abrirJuegoOca())); // Establecer el temporizador para abrir Juego_OCA después de 7 segundos

}
Inicio::~Inicio()
{
    delete ui;
}

void Inicio::abrirJuegoOca()
{
    Juego_OCA *juego = new Juego_OCA();
    juego->show();
    close();
}
