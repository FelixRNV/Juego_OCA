#ifndef JUEGO_OCA_H
#define JUEGO_OCA_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Juego_OCA; }
QT_END_NAMESPACE

class Juego_OCA : public QMainWindow
{
    Q_OBJECT

public:
    Juego_OCA(QWidget *parent = nullptr);
    ~Juego_OCA();

private:
    Ui::Juego_OCA *ui;
};
#endif // JUEGO_OCA_H