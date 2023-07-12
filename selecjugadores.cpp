#include "selecjugadores.h"
#include "ui_selecjugadores.h"
#include "juego_oca.h"
#include "QMessageBox"

SelecJugadores::SelecJugadores(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelecJugadores)
{
    ui->setupUi(this);
    setWindowTitle("Configurar Partida");

    // Agregar opciones al QComboBox del jugador 1
    ui->cbx_jugador1->addItem(QIcon(":/avatar/avantar1/iconos.png"), "Avatar 1");
    ui->cbx_jugador1->addItem(QIcon(":/avatar/avantar1/iconos.png"), "Avatar 2");
    ui->cbx_jugador1->addItem(QIcon(":/avatar/avantar1/iconos.png"),  "Avatar 3");
    ui->cbx_jugador1->addItem(QIcon(":/avatar/avantar1/iconos.png"), "Avatar 4");
    ui->cbx_jugador1->addItem(QIcon(":/avatar/avantar1/iconos.png"), "Avatar 5");
    ui->cbx_jugador1->addItem(QIcon(":/avatar/avantar1/iconos.png"),  "Avatar 6");

    // Agregar opciones al QComboBox del jugador 2
    ui->cbx_jugador2->addItem(QIcon(":/avatar/avantar1/iconos.png"), "Avatar 1");
    ui->cbx_jugador2->addItem(QIcon(":/avatar/avantar1/iconos.png"), "Avatar 2");
    ui->cbx_jugador2->addItem(QIcon(":/avatar/avantar1/iconos.png"),  "Avatar 3");
    ui->cbx_jugador2->addItem(QIcon(":/avatar/avantar1/iconos.png"), "Avatar 4");
    ui->cbx_jugador2->addItem(QIcon(":/avatar/avantar1/iconos.png"), "Avatar 5");
    ui->cbx_jugador2->addItem(QIcon(":/avatar/avantar1/iconos.png"),  "Avatar 6");

    // Agregar opciones al QComboBox del jugador 3
    ui->cbx_jugador3->addItem(QIcon(":/avatar/avantar1/iconos.png"), "Avatar 1");
    ui->cbx_jugador3->addItem(QIcon(":/avatar/avantar1/iconos.png"), "Avatar 2");
    ui->cbx_jugador3->addItem(QIcon(":/avatar/avantar1/iconos.png"),  "Avatar 3");
    ui->cbx_jugador3->addItem(QIcon(":/avatar/avantar1/iconos.png"), "Avatar 4");
    ui->cbx_jugador3->addItem(QIcon(":/avatar/avantar1/iconos.png"), "Avatar 5");
    ui->cbx_jugador3->addItem(QIcon(":/avatar/avantar1/iconos.png"),  "Avatar 6");

    // Agregar opciones al QComboBox del jugador 4
    ui->cbx_jugador4->addItem(QIcon(":/avatar/avantar1/iconos.png"), "Avatar 1");
    ui->cbx_jugador4->addItem(QIcon(":/avatar/avantar1/iconos.png"), "Avatar 2");
    ui->cbx_jugador4->addItem(QIcon(":/avatar/avantar1/iconos.png"),  "Avatar 3");
    ui->cbx_jugador4->addItem(QIcon(":/avatar/avantar1/iconos.png"), "Avatar 4");
    ui->cbx_jugador4->addItem(QIcon(":/avatar/avantar1/iconos.png"), "Avatar 5");
    ui->cbx_jugador4->addItem(QIcon(":/avatar/avantar1/iconos.png"),  "Avatar 6");
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
QLineEdit* SelecJugadores::getLineEdit3() const {
    return ui->ltx_jugador3;
}

QLineEdit* SelecJugadores::getLineEdit4() const {
    return ui->ltx_jugador4;
}

QComboBox* SelecJugadores::getComboBox3() const {
    return ui->cbx_jugador3;
}

QComboBox* SelecJugadores::getComboBox4() const {
    return ui->cbx_jugador4;
}

