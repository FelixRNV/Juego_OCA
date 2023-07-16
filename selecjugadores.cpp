#include "selecjugadores.h"
#include "ui_selecjugadores.h"
#include "juego_oca.h"
#include "QMessageBox"

SelecJugadores::SelecJugadores(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelecJugadores)
{
    // Initialize the QLineEdits
    ui->setupUi(this);
    setWindowTitle("Configurar Partida");

    // Agregar opciones al QComboBox del jugador 1
    ui->cbx_jugador1->addItem(QIcon(":/avatar/avantar1/iconos.png"), "Avatar 1");
    ui->cbx_jugador1->addItem(QIcon(":/avatar/avantar1/iconos.png"), "Avatar 2");
    ui->cbx_jugador1->addItem(QIcon(":/avatar/avantar1/iconos.png"),  "Avatar 3");
    ui->cbx_jugador1->addItem(QIcon(":/avatar/avantar1/iconos.png"), "Avatar 4");

    // Agregar opciones al QComboBox del jugador 2
    ui->cbx_jugador2->addItem(QIcon(":/avatar/avantar1/iconos.png"), "Avatar 1");
    ui->cbx_jugador2->addItem(QIcon(":/avatar/avantar1/iconos.png"), "Avatar 2");
    ui->cbx_jugador2->addItem(QIcon(":/avatar/avantar1/iconos.png"),  "Avatar 3");
    ui->cbx_jugador2->addItem(QIcon(":/avatar/avantar1/iconos.png"), "Avatar 4");

    // Agregar opciones al QComboBox del jugador 3
    ui->cbx_jugador3->addItem(QIcon(":/avatar/avantar1/iconos.png"), "Avatar 1");
    ui->cbx_jugador3->addItem(QIcon(":/avatar/avantar1/iconos.png"), "Avatar 2");
    ui->cbx_jugador3->addItem(QIcon(":/avatar/avantar1/iconos.png"),  "Avatar 3");
    ui->cbx_jugador3->addItem(QIcon(":/avatar/avantar1/iconos.png"), "Avatar 4");

    // Agregar opciones al QComboBox del jugador 4
    ui->cbx_jugador4->addItem(QIcon(":/avatar/avantar1/iconos.png"), "Avatar 1");
    ui->cbx_jugador4->addItem(QIcon(":/avatar/avantar1/iconos.png"), "Avatar 2");
    ui->cbx_jugador4->addItem(QIcon(":/avatar/avantar1/iconos.png"),  "Avatar 3");
    ui->cbx_jugador4->addItem(QIcon(":/avatar/avantar1/iconos.png"), "Avatar 4");
}

SelecJugadores::~SelecJugadores()
{
    delete ui;
}

void SelecJugadores::on_btnBox_rejected()
{
    close();
}

void SelecJugadores::on_btnBox_accepted()
{
    close();
    Juego_OCA *ventana = new Juego_OCA();
    ventana->show();
}

void SelecJugadores::on_ltx_jugador1_textChanged(const QString &arg1)
{
    if (arg1.length() > 10) {
        QMessageBox::critical(this, "Error", "¡Has ingresado más de 10 caracteres!");
    }
}

void SelecJugadores::on_ltx_jugador2_textChanged(const QString &arg1)
{
    if (arg1.length() > 10) {
        QMessageBox::critical(this, "Error", "¡Has ingresado más de 10 caracteres!");
    }
}

void SelecJugadores::on_ltx_jugador3_textChanged(const QString &arg1)
{
    if (arg1.length() > 10) {
        QMessageBox::critical(this, "Error", "¡Has ingresado más de 10 caracteres!");
    }
}

void SelecJugadores::on_ltx_jugador4_textChanged(const QString &arg1)
{
    if (arg1.length() > 10) {
        QMessageBox::critical(this, "Error", "¡Has ingresado más de 10 caracteres!");
    }
}

int SelecJugadores::indi() const
{
    return m_indi;
}

const Jugadores &SelecJugadores::p1() const
{
    return m_p1;
}

const Jugadores &SelecJugadores::p2() const
{
    return m_p2;
}

const Jugadores &SelecJugadores::p3() const
{
    return m_p3;
}

const Jugadores &SelecJugadores::p4() const
{
    return m_p4;
}

void SelecJugadores::setIndi(int newIndi)
{
    m_indi = newIndi;

    //Se determinan los jugadores disponibles
    switch (m_indi){
    case 0:
        ui->cbx_jugador1->setEnabled(true);
        ui->cbx_jugador2->setEnabled(true);
        ui->ltx_jugador1->setEnabled(true);
        ui->ltx_jugador2->setEnabled(true);
        ui->cbx_jugador3->setEnabled(false);
        ui->cbx_jugador4->setEnabled(false);
        ui->ltx_jugador3->setEnabled(false);
        ui->ltx_jugador4->setEnabled(false);
        break;
    case 1:
        ui->cbx_jugador1->setEnabled(true);
        ui->cbx_jugador2->setEnabled(true);
        ui->ltx_jugador1->setEnabled(true);
        ui->ltx_jugador2->setEnabled(true);
        ui->cbx_jugador3->setEnabled(true);
        ui->cbx_jugador4->setEnabled(false);
        ui->ltx_jugador3->setEnabled(true);
        ui->ltx_jugador4->setEnabled(false);
        break;
    case 2:
        ui->cbx_jugador1->setEnabled(true);
        ui->cbx_jugador2->setEnabled(true);
        ui->ltx_jugador1->setEnabled(true);
        ui->ltx_jugador2->setEnabled(true);
        ui->cbx_jugador3->setEnabled(true);
        ui->cbx_jugador4->setEnabled(true);
        ui->ltx_jugador3->setEnabled(true);
        ui->ltx_jugador4->setEnabled(true);
        break;
    }
}


