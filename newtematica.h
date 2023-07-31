#ifndef NEWTEMATICA_H
#define NEWTEMATICA_H

#include <QDialog>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include "preguntas.h"
#include "agregar.h"
#include <QTextStream>
#include <QDir>
#include <QFile>
#include "QDebug"
#include "QStandardPaths"

QT_BEGIN_NAMESPACE
namespace Ui { class NewTematica; }
QT_END_NAMESPACE

class NewTematica : public QDialog
{
    Q_OBJECT

public:
    NewTematica(QWidget *parent = nullptr);
    ~NewTematica();

private slots:




    void on_btn_CargaPreguntas_clicked();

    void on_btn_Guardar_clicked();

    void on_btn_Ingresar_clicked();

    void on_btn_Editar_clicked();

    void on_btn_Eliminar_clicked();

    void on_btn_Cerrar_clicked();

    void on_cbx_Temas_currentTextChanged(const QString &arg1);

    void on_btn_NewTopic_released();

private:
    Ui::NewTematica *ui;
    QString path;
    const QString BASE = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)+"/OCASources/BaseIndex.txt";
    const QString ARCHIVO = ":/TMatematicas.txt";
    enum Columna
    {
        PREGUNTAS, RESPUESTAS
    };

    void cargarPreguntas();
    void cargarPreguntas(const QString& filePath);
};

#endif // NEWTEMATICA_H
