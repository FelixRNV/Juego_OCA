#include "selecjugadores.h"
#include "ui_selecjugadores.h"
#include "juego_oca.h"
#include "QMessageBox"
#include "QTranslator"
SelecJugadores::SelecJugadores(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelecJugadores)
{
    // Initialize the QLineEdits
    ui->setupUi(this);
    setWindowTitle(tr("Configurar Partida"));

    // Agregar opciones al QComboBox del jugador 1
    ui->cbx_jugador1->addItem(QIcon(":/fichas/Resources/fichas/ficha_1.png"), "Avatar 1");
    ui->cbx_jugador1->addItem(QIcon(":/fichas/Resources/fichas/ficha_2.png"), "Avatar 2");
    ui->cbx_jugador1->addItem(QIcon(":/fichas/Resources/fichas/ficha_3.png"),  "Avatar 3");
    ui->cbx_jugador1->addItem(QIcon(":/fichas/Resources/fichas/ficha_4.png"), "Avatar 4");

    // Agregar opciones al QComboBox del jugador 2
    ui->cbx_jugador2->addItem(QIcon(":/fichas/Resources/fichas/ficha_1.png"), "Avatar 1");
    ui->cbx_jugador2->addItem(QIcon(":/fichas/Resources/fichas/ficha_2.png"), "Avatar 2");
    ui->cbx_jugador2->addItem(QIcon(":/fichas/Resources/fichas/ficha_3.png"),  "Avatar 3");
    ui->cbx_jugador2->addItem(QIcon(":/fichas/Resources/fichas/ficha_4.png"), "Avatar 4");

    // Agregar opciones al QComboBox del jugador 3
    ui->cbx_jugador3->addItem(QIcon(":/fichas/Resources/fichas/ficha_1.png"), "Avatar 1");
    ui->cbx_jugador3->addItem(QIcon(":/fichas/Resources/fichas/ficha_2.png"), "Avatar 2");
    ui->cbx_jugador3->addItem(QIcon(":/fichas/Resources/fichas/ficha_3.png"),  "Avatar 3");
    ui->cbx_jugador3->addItem(QIcon(":/fichas/Resources/fichas/ficha_4.png"), "Avatar 4");

    // Agregar opciones al QComboBox del jugador 4
    ui->cbx_jugador4->addItem(QIcon(":/fichas/Resources/fichas/ficha_1.png"), "Avatar 1");
    ui->cbx_jugador4->addItem(QIcon(":/fichas/Resources/fichas/ficha_2.png"), "Avatar 2");
    ui->cbx_jugador4->addItem(QIcon(":/fichas/Resources/fichas/ficha_3.png"),  "Avatar 3");
    ui->cbx_jugador4->addItem(QIcon(":/fichas/Resources/fichas/ficha_4.png"), "Avatar 4");
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
    QString name;
    int av;
    switch (m_indi){
    case 0:
        name=ui->ltx_jugador1->text();
        av=ui->cbx_jugador1->currentIndex();
        m_p1.setJuga(name,0,av);

        name=ui->ltx_jugador2->text();
        av=ui->cbx_jugador2->currentIndex();
        m_p2.setJuga(name,0,av);
        break;
    case 1:
        name=ui->ltx_jugador1->text();
        av=ui->cbx_jugador1->currentIndex();
        m_p1.setJuga(name,0,av);

        name=ui->ltx_jugador2->text();
        av=ui->cbx_jugador2->currentIndex();
        m_p2.setJuga(name,0,av);

        name=ui->ltx_jugador3->text();
        av=ui->cbx_jugador3->currentIndex();
        m_p3.setJuga(name,0,av);

        break;
    case 2:
        name=ui->ltx_jugador1->text();
        av=ui->cbx_jugador1->currentIndex();
        m_p1.setJuga(name,0,av);

        name=ui->ltx_jugador2->text();
        av=ui->cbx_jugador2->currentIndex();
        m_p2.setJuga(name,0,av);

        name=ui->ltx_jugador3->text();
        av=ui->cbx_jugador3->currentIndex();
        m_p3.setJuga(name,0,av);

        name=ui->ltx_jugador4->text();
        av=ui->cbx_jugador4->currentIndex();
        m_p4.setJuga(name,0,av);

        break;
    }
    validAV_Na();
    if (condicion==true){
        return;
    }
    accept();


}

void SelecJugadores::on_ltx_jugador1_textChanged(const QString &arg1)
{
    if (arg1.length() > 10) {
        QMessageBox::critical(this, tr("Error"), tr("¡Has ingresado más de 10 caracteres!"));
    }
}

void SelecJugadores::on_ltx_jugador2_textChanged(const QString &arg1)
{
    if (arg1.length() > 10) {
        QMessageBox::critical(this, tr("Error"), tr("¡Has ingresado más de 10 caracteres!"));

    }
}

void SelecJugadores::on_ltx_jugador3_textChanged(const QString &arg1)
{
    if (arg1.length() > 10) {
        QMessageBox::critical(this, tr("Error"), tr("¡Has ingresado más de 10 caracteres!"));

    }
}

void SelecJugadores::on_ltx_jugador4_textChanged(const QString &arg1)
{
    if (arg1.length() > 10) {
        QMessageBox::critical(this, tr("Error"), tr("¡Has ingresado más de 10 caracteres!"));

    }
}

void SelecJugadores::validAV_Na()
{
    condicion=false;
    bool com = false, dop = false;
    int jav1=m_p1.avatar();
    int jav2=m_p2.avatar();
    int jav3=m_p3.avatar();
    int jav4=m_p4.avatar();


    if (m_indi==0){
        if(jav1==jav2){
            QMessageBox::warning(this, tr("Error"), tr("Los jugadores deben tener diferentes avatares"));

            com = true;
        }else{
            com = false;
        }
        if (m_p1.name().isEmpty()||m_p2.name().isEmpty()||m_p1.name()==m_p2.name()){
            QMessageBox::warning(this, tr("Error"), tr("Revisar el apodo de los jugadores"));
            dop = true;
        }else
            dop = false;
    }else if (m_indi==1){
        if(jav1==jav2||jav2==jav3||jav1==jav3){
            QMessageBox::warning(this, tr("Error"), tr("Los jugadores deben tener diferentes avatares"));
            com = true;
        }else{
            com = false;
        }
        if (m_p1.name().isEmpty()||m_p2.name().isEmpty()||m_p3.name().isEmpty()||m_p1.name()==m_p2.name()||m_p1.name()==m_p3.name()||m_p2.name()==m_p3.name()){
            QMessageBox::warning(this, tr("Error"), tr("Revisar el apodo de los jugadores"));
            dop = true;
        }else
            dop = false;
    }else if (m_indi==2){
        if(jav1==jav2||jav2==jav3||jav3==jav4||jav1==jav3||jav1==jav4||jav2==jav4){
            QMessageBox::warning(this, tr("Error"), tr("Los jugadores deben tener diferentes avatares"));
            com = true;
        }else{
            com = false;
        }
        if (m_p1.name().isEmpty()||m_p2.name().isEmpty()||m_p3.name().isEmpty()||m_p4.name().isEmpty()||m_p1.name()==m_p2.name()||m_p1.name()==m_p3.name()||m_p1.name()==m_p4.name()||m_p2.name()==m_p3.name()||m_p2.name()==m_p4.name()||m_p4.name()==m_p3.name()){
            QMessageBox::warning(this, tr("Error"), tr("Revisar el apodo de los jugadores"));
            dop = true;
        }else
            dop = false;
    }
    if (dop==true || com==true)
        condicion=true;
    return;
}

int SelecJugadores::indi() const
{
    return m_indi;
}

Jugadores &SelecJugadores::p1()
{
    return m_p1;
}

Jugadores &SelecJugadores::p2()
{
    return m_p2;
}

Jugadores &SelecJugadores::p3()
{
    return m_p3;
}

Jugadores &SelecJugadores::p4()
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



