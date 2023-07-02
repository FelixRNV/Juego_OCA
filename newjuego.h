#ifndef NEWJUEGO_H
#define NEWJUEGO_H

#include <QDialog>

namespace Ui {
class NewJuego;
}

class NewJuego : public QDialog
{
    Q_OBJECT

public:
    explicit NewJuego(QWidget *parent = nullptr);
    ~NewJuego();

private:
    Ui::NewJuego *ui;
};

#endif // NEWJUEGO_H
