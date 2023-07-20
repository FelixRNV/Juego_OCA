#include "casillero.h"
#include "ui_casillero.h"

Casillero::Casillero(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Casillero)
{
    ui->setupUi(this);
}

Casillero::~Casillero()
{
    delete ui;
}

void Casillero::enableAV(int avatar)
{

    switch (avatar){
    case 1:
        ui->lblA_1->setStyleSheet("border-image: url:(Resources/fichas/ficha_1.png)");
        break;
    case 2:
        ui->lblA_2->setStyleSheet("border-image: url:(Resources/fichas/ficha_2.png)");
        break;
    case 3:
        ui->lblA_3->setStyleSheet("border-image: url:(Resources/fichas/ficha_3.png)");
        break;
    case 4:
        ui->lblA_4->setStyleSheet("border-image: url:(Resources/fichas/ficha_4.png)");
        break;
    }
}

void Casillero::deseableAV(int avatar)
{
    switch (avatar){
    case 1:
        ui->lblA_1->setStyleSheet("border-image: url:(Resources/Untitled.png)");
        break;
    case 2:
        ui->lblA_2->setStyleSheet("border-image: url:(Resources/Untitled.png)");
        break;
    case 3:
        ui->lblA_3->setStyleSheet("border-image: url:(Resources//Untitled.png)");
        break;
    case 4:
        ui->lblA_4->setStyleSheet("border-image: url:(Resources//Untitled.png)");
        break;
    }
}
