#ifndef NEWJUEGO_H
#define NEWJUEGO_H
#include "QLineEdit"
#include <QDialog>
#include "QComboBox"
#include "jugadores.h"
#include "selecjugadores.h"
#include "QDebug"
#include "QFile"
#include "QMessageBox"
#include "QStandardPaths"

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

    const QString &Tema() const;

    int level() const;

    int jueg() const;
    void setJueg(int newJueg);

private slots:

    void on_btn_Salir_clicked();
    void on_cbx_jugadores_currentIndexChanged(int index);

    void on_cbx_tematicas_currentIndexChanged(const QString &arg1);

    void on_cbx_dificultad_currentIndexChanged(int index);

    void on_btn_Seg_released();

private:
    Ui::NewJuego *ui;
    SelecJugadores jug;
    QString m_tema;
    int m_level;
    int m_jueg;
    bool valid;
    const QString BASE = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)+"/OCASources/BaseIndex.txt";
    Jugadores *m_p1=new Jugadores(jug.p1());
    Jugadores *m_p2=new Jugadores(jug.p2());
    Jugadores *m_p3=new Jugadores(jug.p3());
    Jugadores *m_p4=new Jugadores(jug.p4());

};

#endif // NEWJUEGO_H
