#ifndef NEWJUEGO_H
#define NEWJUEGO_H
#include "QLineEdit"
#include <QDialog>
#include "QComboBox"
#include "jugadores.h"
#include "selecjugadores.h"
#include "QDebug"

namespace Ui {
class NewJuego;
}

class NewJuego : public QDialog
{
    Q_OBJECT

public:
    explicit NewJuego(QWidget *parent = nullptr);
    ~NewJuego();

    Jugadores *p1() const;
    Jugadores *p2() const;
    Jugadores *p3() const;
    Jugadores *p4() const;

private slots:
    void on_btn_Reglas_clicked();
    void on_btn_Salir_clicked();
    void on_cbx_jugadores_currentIndexChanged(int index);

private:
    Ui::NewJuego *ui;
    SelecJugadores jug;
    Jugadores *m_p1=new Jugadores(jug.p1());
    Jugadores *m_p2=new Jugadores(jug.p2());
    Jugadores *m_p3=new Jugadores(jug.p3());
    Jugadores *m_p4=new Jugadores(jug.p4());

};

#endif // NEWJUEGO_H
