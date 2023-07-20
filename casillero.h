#ifndef CASILLERO_H
#define CASILLERO_H

#include <QWidget>

namespace Ui {
class Casillero;
}

class Casillero : public QWidget
{
    Q_OBJECT

public:
    explicit Casillero(QWidget *parent = nullptr);
    ~Casillero();

     void enableAV(int avatar);
     void deseableAV(int avatar);

private:
    Ui::Casillero *ui;


};

#endif // CASILLERO_H
