#include "newjuego.h"
#include "ui_newjuego.h"
#include "selecjugadores.h"
#include "QComboBox"
#include "ui_selecjugadores.h"

NewJuego::NewJuego(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewJuego)
{
    ui->setupUi(this);
    ui->cbx_jugadores->addItem("2");
    ui->cbx_jugadores->addItem("3");
    ui->cbx_jugadores->addItem("4");
    ui->cbx_dificultad->addItem("baja");
    ui->cbx_dificultad->addItem("media");
    ui->cbx_dificultad->addItem("alta");
}

NewJuego::~NewJuego()
{
    delete ui;
}
void NewJuego::on_btn_Reglas_clicked()
{
    close();
    jug.exec();


}
void NewJuego::on_btn_Salir_clicked()
{
    close();
}


void NewJuego::on_cbx_jugadores_currentIndexChanged(int index)
{
    jug.setIndi(index);
}

Jugadores *NewJuego::p1() const
{
    return m_p1;
}

Jugadores *NewJuego::p2() const
{
    return m_p2;
}

Jugadores *NewJuego::p3() const
{
    return m_p3;
}

Jugadores *NewJuego::p4() const
{
    return m_p4;
}

