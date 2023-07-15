#include <QApplication>
#include "inicio.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Inicio inicio;
   inicio.show();


    return a.exec();
}
