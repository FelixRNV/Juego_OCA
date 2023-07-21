#include "inicio.h"
#include "ui_inicio.h"
#include "juego_oca.h"
#include <QTimer>
#include <QTranslator>

Inicio::Inicio(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Inicio)
{
    ui->setupUi(this);

    // Oculta la barra superior de la ventana para que parezca una verdadera ventana de carga
    setWindowFlags(Qt::CustomizeWindowHint);
    barraCarga = ui->barraCarga;
    // Crea el QTimer y conecta su señal de timeout
    QTimer* timer = new QTimer(this);
    int targetValue = 100;
    int durationInSeconds = 4; // Duración deseada en segundos
    connect(timer, &QTimer::timeout, [=]() {
        // Actualiza el valor de la barra de progreso en cada intervalo de tiempo
        int progressValue = barraCarga->value() + 1;
        barraCarga->setValue(progressValue);
        // Detiene el QTimer cuando se alcanza el valor objetivo
        if (progressValue >= targetValue) {
            timer->stop();
            abrirJuegoOca();
        }
    });
    int intervalInMilliseconds = (durationInSeconds * 1000) / targetValue;
    timer->setInterval(intervalInMilliseconds);
    timer->start();
    show();

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

