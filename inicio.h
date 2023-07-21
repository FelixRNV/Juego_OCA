#ifndef INICIO_H
#define INICIO_H
#include <QDialog>
#include "juego_oca.h"
#include "QProgressBar"
namespace Ui {
class Inicio;
}
class Inicio : public QDialog
{
    Q_OBJECT

public:
    explicit Inicio(QWidget *parent = nullptr);
    ~Inicio();

public slots:
    void abrirJuegoOca();
private:
    Ui::Inicio *ui;
    QProgressBar *barraCarga;
};

#endif // INICIO_H
