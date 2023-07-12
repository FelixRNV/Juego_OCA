#ifndef NEWJUEGO_H
#define NEWJUEGO_H
#include "QLineEdit"
#include <QDialog>
#include "QComboBox"
namespace Ui {
class NewJuego;
}

class NewJuego : public QDialog
{
    Q_OBJECT

public:
    explicit NewJuego(QWidget *parent = nullptr);
    ~NewJuego();



private slots:
    void on_btn_Reglas_clicked();
    void on_btn_Salir_clicked();
    void on_cbx_jugadores_currentIndexChanged(int index);
private:
    Ui::NewJuego *ui;
};

#endif // NEWJUEGO_H
