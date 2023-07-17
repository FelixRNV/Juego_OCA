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


void Juego_OCA::on_action_Nuevo_triggered()
{
    NewJuego ne(this);
    int res = ne.exec();
    if (res== QDialog::Rejected)
        return;
    p1=ne.p1();
    p2=ne.p2();
    p3=ne.p3();
    p4=ne.p4();

}


void Juego_OCA::on_action_Tem_ticas_triggered()
{
    NewTematica te(this);
    int res = te.exec();
    if (res== QDialog::Rejected)
        return;
}

