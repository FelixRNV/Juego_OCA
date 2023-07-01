#ifndef INICIO_H
#define INICIO_H

#include <QDialog>

namespace Ui {
class Inicio;
}

class Inicio : public QDialog
{
    Q_OBJECT

public:
    explicit Inicio(QWidget *parent = nullptr);
    ~Inicio();

private:
    Ui::Inicio *ui;
};

#endif // INICIO_H
