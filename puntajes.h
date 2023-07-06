#ifndef PUNTAJES_H
#define PUNTAJES_H

#include <QDialog>

namespace Ui {
class Puntajes;
}

class Puntajes : public QDialog
{
    Q_OBJECT

public:
    explicit Puntajes(QWidget *parent = nullptr);
    ~Puntajes();



private slots:



private:
    Ui::Puntajes *ui;

    enum Columna{
          NOMBRE, PUNTUACION, CORRECTAS, INCORRECTAS

    };
};
#endif // PUNTAJES_H
