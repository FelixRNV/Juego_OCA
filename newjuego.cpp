#include "newjuego.h"
#include "ui_newjuego.h"
#include "selecjugadores.h"
#include "QComboBox"
#include "QWidget"
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
    // Conectar la señal currentIndexChanged del ComboBox con la ranura correspondiente
    connect(ui->cbx_jugadores, SIGNAL(currentIndexChanged(int)), this, SLOT(on_cbx_jugadores_currentIndexChanged(int)));
}
NewJuego::~NewJuego()
{
    delete ui;
}

void NewJuego::on_btn_Reglas_clicked()
{
   close();
   SelecJugadores *ventana=new SelecJugadores();
   ventana->show();
}

void NewJuego::on_btn_Salir_clicked()
{
    close();
}
void NewJuego::on_cbx_jugadores_currentIndexChanged(int index) {
    if (index == 1) {
        // Deshabilitar LineEdit 3 y 4
        SelecJugadores ventana;
        QLineEdit* lineEdit3 = ventana.getLineEdit3();
        QLineEdit* lineEdit4 = ventana.getLineEdit4();
        QComboBox* comboBox3 = ventana.getComboBox3();
        QComboBox* comboBox4 = ventana.getComboBox4();

        lineEdit3->setEnabled(false);
        lineEdit4->setEnabled(false);
        comboBox3->setEnabled(false);
        comboBox4->setEnabled(false);
    } else if (index == 2) {
        // Deshabilitar LineEdit 4
        SelecJugadores ventana;
        QLineEdit* lineEdit4 = ventana.getLineEdit4();
        QComboBox* comboBox4 = ventana.getComboBox4();
        lineEdit4->setEnabled(false);
        comboBox4->setEnabled(false);
    } else {
        // Habilitar todos los LineEdit
        SelecJugadores ventana;
        QLineEdit* lineEdit3 = ventana.getLineEdit3();
        QLineEdit* lineEdit4 = ventana.getLineEdit4();
        QComboBox* comboBox3 = ventana.getComboBox3();
        QComboBox* comboBox4 = ventana.getComboBox4();
        lineEdit3->setEnabled(true);
        lineEdit4->setEnabled(true);
        comboBox3->setEnabled(true);
        comboBox4->setEnabled(true);
    }
}

const Jugadores &NewJuego::p1() const
{
    return m_p1;
}

const Jugadores &NewJuego::p2() const
{
    return m_p2;
}

const Jugadores &NewJuego::p3() const
{
    return m_p3;
}

const Jugadores &NewJuego::p4() const
{
    return m_p4;
}



