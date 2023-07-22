#ifndef SELECJUGADORES_H
#define SELECJUGADORES_H
#include "QLineEdit"
#include <QDialog>
#include "QComboBox"
#include "jugadores.h"
#include "QDebug"
#include "QCloseEvent"

namespace Ui {
class SelecJugadores;
}

class SelecJugadores : public QDialog
{
    Q_OBJECT

public:
    explicit SelecJugadores(QWidget *parent = nullptr);
    ~SelecJugadores();

    void setIndi(int newIndi);

    const Jugadores &p1() const;
    const Jugadores &p2() const;
    const Jugadores &p3() const;
    const Jugadores &p4() const;

    int indi() const;

private slots:
    void on_btnBox_rejected();

    void on_btnBox_accepted();

    void on_ltx_jugador1_textChanged(const QString &arg1);

    void on_ltx_jugador2_textChanged(const QString &arg1);

    void on_ltx_jugador3_textChanged(const QString &arg1);

    void on_ltx_jugador4_textChanged(const QString &arg1);


private:
    Ui::SelecJugadores *ui;
    int m_indi;
    Jugadores m_p1;
    Jugadores m_p2;
    Jugadores m_p3;
    Jugadores m_p4;
    bool condicion = false;
    void validAV_Na();

};

#endif // SELECJUGADORES_H
