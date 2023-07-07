#include "juego_oca.h"
#include "ui_juego_oca.h"

Juego_OCA::Juego_OCA(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Juego_OCA)
{
    ui->setupUi(this);
    ui->label->setStyleSheet("QLabel { background-color: red; color : blue; }");
    QPalette palette = ui->label->palette();
     palette.setColor(ui->label->backgroundRole(), Qt::yellow);
     palette.setColor(ui->label->foregroundRole(), Qt::yellow);
     ui->label->setPalette(palette);

}

Juego_OCA::~Juego_OCA()
{
    delete ui;
}

