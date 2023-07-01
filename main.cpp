#include "juego_oca.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Juego_OCA w;
    w.show();
    return a.exec();
}
