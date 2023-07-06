#include "selecjugadores.h"
#include "ui_selecjugadores.h"

SelecJugadores::SelecJugadores(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelecJugadores)
{
    ui->setupUi(this);
    setWindowTitle("Configurar Partida");

    // Agregar opciones al QComboBox del jugador 1
    ui->comboBox->addItem(QIcon(":/avatar/avantar1/iconos.png"), "Avatar 1");
    ui->comboBox->addItem(QIcon(":/avatar/avantar1/iconos.png"), "Avatar 2");
    ui->comboBox->addItem(QIcon(":/avatar/avantar1/iconos.png"),  "Avatar 3");
    ui->comboBox->addItem(QIcon(":/avatar/avantar1/iconos.png"), "Avatar 4");
    ui->comboBox->addItem(QIcon(":/avatar/avantar1/iconos.png"), "Avatar 5");
    ui->comboBox->addItem(QIcon(":/avatar/avantar1/iconos.png"),  "Avatar 6");

    // Agregar opciones al QComboBox del jugador 2
    ui->comboBox_2->addItem(QIcon(":/avatar/avantar1/iconos.png"), "Avatar 1");
    ui->comboBox_2->addItem(QIcon(":/avatar/avantar1/iconos.png"), "Avatar 2");
    ui->comboBox_2->addItem(QIcon(":/avatar/avantar1/iconos.png"),  "Avatar 3");
    ui->comboBox_2->addItem(QIcon(":/avatar/avantar1/iconos.png"), "Avatar 4");
    ui->comboBox_2->addItem(QIcon(":/avatar/avantar1/iconos.png"), "Avatar 5");
    ui->comboBox_2->addItem(QIcon(":/avatar/avantar1/iconos.png"),  "Avatar 6");

    // Agregar opciones al QComboBox del jugador 3
    ui->comboBox_3->addItem(QIcon(":/avatar/avantar1/iconos.png"), "Avatar 1");
    ui->comboBox_3->addItem(QIcon(":/avatar/avantar1/iconos.png"), "Avatar 2");
    ui->comboBox_3->addItem(QIcon(":/avatar/avantar1/iconos.png"),  "Avatar 3");
    ui->comboBox_3->addItem(QIcon(":/avatar/avantar1/iconos.png"), "Avatar 4");
    ui->comboBox_3->addItem(QIcon(":/avatar/avantar1/iconos.png"), "Avatar 5");
    ui->comboBox_3->addItem(QIcon(":/avatar/avantar1/iconos.png"),  "Avatar 6");

    // Agregar opciones al QComboBox del jugador 4
    ui->comboBox_4->addItem(QIcon(":/avatar/avantar1/iconos.png"), "Avatar 1");
    ui->comboBox_4->addItem(QIcon(":/avatar/avantar1/iconos.png"), "Avatar 2");
    ui->comboBox_4->addItem(QIcon(":/avatar/avantar1/iconos.png"),  "Avatar 3");
    ui->comboBox_4->addItem(QIcon(":/avatar/avantar1/iconos.png"), "Avatar 4");
    ui->comboBox_4->addItem(QIcon(":/avatar/avantar1/iconos.png"), "Avatar 5");
    ui->comboBox_4->addItem(QIcon(":/avatar/avantar1/iconos.png"),  "Avatar 6");
}

SelecJugadores::~SelecJugadores()
{
    delete ui;
}
