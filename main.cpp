#include <QApplication>
#include <QMessageBox>
#include "inicio.h"
#include "QTranslator"
#include <QTranslator>
#include <QDir>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Creamos el objeto de traductor
    QTranslator translator;
    // Obtenemos la ruta del directorio donde se encuentra el ejecutable
    QString executablePath = QCoreApplication::applicationDirPath();
    // Construimos la ruta completa al archivo de traducción
    QString translationPath = executablePath + "/Juego_OCA_en_US.qm";
    // Mostramos el cuadro de diálogo para preguntar al usuario
    QMessageBox msgBox;
    msgBox.setText("¿Deseas cambiar la traduccion al ingles (Idioma Actual:ESPAÑOL) ?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::Yes);
    int reply = msgBox.exec();

    // Dependiendo de la respuesta del usuario, cargamos o no la traducción
    if (reply == QMessageBox::Yes)
    {
        // Intentamos cargar la traducción desde el archivo Juego_OCA_en_US.qm
        if (translator.load(translationPath))
        {
            // Si se carga correctamente, lo instalamos en la aplicación
            a.installTranslator(&translator);
        }
        else
        {
            qDebug() << "No se pudo cargar la traducción al inglés.";
        }
    }
    Inicio inicio;
    inicio.show();

    return a.exec();
}
