#include <QApplication>
#include <QMessageBox>
#include "inicio.h"
#include "QTranslator"
#include <QTranslator>
#include <QDir>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    Inicio inicio;
    inicio.show();

    return a.exec();
}
