#ifndef SELECJUGADORES_H
#define SELECJUGADORES_H

#include <QDialog>

namespace Ui {
class SelecJugadores;
}

class SelecJugadores : public QDialog
{
    Q_OBJECT

public:
    explicit SelecJugadores(QWidget *parent = nullptr);
    ~SelecJugadores();

private:
    Ui::SelecJugadores *ui;
};

#endif // SELECJUGADORES_H
