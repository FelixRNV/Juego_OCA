#ifndef TIPODEJUEGO_H
#define TIPODEJUEGO_H

#include <QDialog>

namespace Ui {
class TipoDeJuego;
}

class TipoDeJuego : public QDialog
{
    Q_OBJECT

public:
    explicit TipoDeJuego(QWidget *parent = nullptr);
    ~TipoDeJuego();

private:
    Ui::TipoDeJuego *ui;
};

#endif // TIPODEJUEGO_H
