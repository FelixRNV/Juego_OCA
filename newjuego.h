#ifndef NEWJUEGO_H
#define NEWJUEGO_H
#include "QLineEdit"
#include <QDialog>
#include "QComboBox"
#include "jugadores.h"
#include "selecjugadores.h"
namespace Ui {
class NewJuego;
}

class NewJuego : public QDialog
{
    Q_OBJECT

public:
    explicit NewJuego(QWidget *parent = nullptr);
    ~NewJuego();
    const Jugadores &p1() const;
    const Jugadores &p2() const;
    const Jugadores &p3() const;
    const Jugadores &p4() const;
private slots:
    void on_btn_Reglas_clicked();
    void on_btn_Salir_clicked();
private:
    Ui::NewJuego *ui;
    Jugadores m_p1;
    Jugadores m_p2;
    Jugadores m_p3;
    Jugadores m_p4;

};

#endif // NEWJUEGO_H
