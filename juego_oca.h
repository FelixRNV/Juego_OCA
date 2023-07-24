#ifndef JUEGO_OCA_H
#define JUEGO_OCA_H

#include <QMainWindow>
#include <newjuego.h>
#include <newtematica.h>
#include <acercade.h>
#include <jugadores.h>
#include <QRandomGenerator>
#include <QMainWindow>
#include <QFile>
#include <QDesktopServices>
#include <QUrl>
#include <QDir> // Agregamos esta línea para incluir QDir
#include <QStandardPaths> // Agregamos esta línea para incluir QStandardPaths
#include <QStack>
#include <QVector>
#include "QTimer"

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

    void on_action_Reglas_triggered();

    void on_actionA_cerca_de_triggered();

    void on_action_Salir_triggered();

private:
    Ui::Juego_OCA *ui;
    const QString ARCHIVO = ":/Resources/Reglamento_juego_OCA.pdf";
    QString m_tema;
    QStack<QString> preguntas;
    int m_level;
    int jug=1;
    int m_juegan;
    int turno;
    int jug_n;
    int gana;
    QString gnj;
    Jugadores *p1;
    Jugadores *p2;
    Jugadores *p3;
    Jugadores *p4;

    void activatedAv(int casil, int jug); //Activa la imagen de una ficha en una casilla
    void disactivatedAv(int casil, int jug); //Desactiva la imagen de una ficha en una casilla
    QString preguntar(); //Obtiene la pregunta
    void cargarPreguntas(); //Almacena las preguntas en un Stack
    bool casilleroSpe(int avan, int jug); //Analiza los casilleros especiales
    void setJugador(int jug); //Muestra el jugador que toca en pantalla
    void setCasilleros(int jug); //Muestra la posición del jugador
    void setTimer(int seg); //Crea una espera de "seg" segundos
};
#endif // JUEGO_OCA_H
