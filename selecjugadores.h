#ifndef SELECJUGADORES_H
#define SELECJUGADORES_H
#include "QLineEdit"
#include <QDialog>
#include "QComboBox"
namespace Ui {
class SelecJugadores;
}

class SelecJugadores : public QDialog
{
    Q_OBJECT

public:
    explicit SelecJugadores(QWidget *parent = nullptr);
    ~SelecJugadores();


private slots:
    void on_btnBox_rejected();

    void on_btnBox_accepted();

    void on_ltx_jugador1_textChanged(const QString &arg1);

    void on_ltx_jugador2_textChanged(const QString &arg1);

    void on_ltx_jugador3_textChanged(const QString &arg1);

    void on_ltx_jugador4_textChanged(const QString &arg1);


private:
    Ui::SelecJugadores *ui;

};

#endif // SELECJUGADORES_H
