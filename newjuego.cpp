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
    ui->cbx_dificultad->addItem("Baja");
    ui->cbx_dificultad->addItem("Media");
    ui->cbx_dificultad->addItem("Alta");

    //Cargar ComboBox de temas
    QFile ind(BASE);
    if(!ind.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QTextStream indix(&ind);
    while (!indix.atEnd()) {
        QString line = indix.readLine();
        ui->cbx_tematicas->addItem(line);
    }
    ind.close();
}

NewJuego::~NewJuego()
{
    delete ui;
}
void NewJuego::on_btn_Reglas_clicked()
{

    if(jug.exec()==QDialog::Accepted){
        m_p1=new Jugadores(jug.p1());
        m_p2=new Jugadores(jug.p2());
        m_p3=new Jugadores(jug.p3());
        m_p4=new Jugadores(jug.p4());
        accept();
    }



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


void NewJuego::on_cbx_tematicas_currentIndexChanged(const QString &arg1)
{
    if (arg1=="<Seleccionar>")
        return;
    m_tema=arg1;
}

int NewJuego::level() const
{
    return m_level;
}

const QString &NewJuego::Tema() const
{
    return m_tema;
}


void NewJuego::on_cbx_dificultad_currentIndexChanged(int index)
{
    m_level=index;
}

