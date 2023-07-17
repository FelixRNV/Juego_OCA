#ifndef JUEGO_OCA_H
#define JUEGO_OCA_H

#include <QMainWindow>
#include <newjuego.h>
#include <newtematica.h>
#include <acercade.h>
#include <jugadores.h>
#include <QRandomGenerator>


QT_BEGIN_NAMESPACE
namespace Ui { class Juego_OCA; }
QT_END_NAMESPACE

class Juego_OCA : public QMainWindow
{
    Q_OBJECT

public:
    Juego_OCA(QWidget *parent = nullptr);
    ~Juego_OCA();

private slots:
    void on_action_Nuevo_triggered();

    void on_action_Tem_ticas_triggered();

    void on_btnDado_released();

private:
    Ui::Juego_OCA *ui;
    QString m_tema;
    int m_level;
    Jugadores *p1;
    Jugadores *p2;
    Jugadores *p3;
    Jugadores *p4;
};
#endif // JUEGO_OCA_H
