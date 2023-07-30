#include "agregar.h"
#include "ui_agregar.h"
#include "QTranslator"
Agregar::Agregar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Agregar)
{
    ui->setupUi(this);
    setWindowTitle(tr("Agregar Pregunta"));

    // Agrega las opciones "V" y "F" al ComboBox
    ui->comboBoxRespuesta->addItem(tr("V"));
    ui->comboBoxRespuesta->addItem(tr("F"));

}

Agregar::~Agregar()
{
    delete ui;
}

void Agregar::setPregunta(const QString& pregunta)
{
    ui->inPregunta->setText(pregunta);
}

void Agregar::setRespuesta(const QString& respuesta)
{
    int index = ui->comboBoxRespuesta->findText(respuesta);
    if (index != -1) {
        ui->comboBoxRespuesta->setCurrentIndex(index);
    }
}

QString Agregar::getPregunta() const
{
    return ui->inPregunta->text();
}

QString Agregar::getRespuesta() const
{
    return ui->comboBoxRespuesta->currentText();
}


Preguntas *Agregar::preguntas() const
{
    return m_pregunta;
}

void Agregar::on_buttonBox_2_accepted()
{
    // Obtener el texto del campo de pregunta
    QString pregunta = ui->inPregunta->text().trimmed(); // Eliminar espacios en blanco al inicio y al final

    // Verificar si el campo de pregunta está vacío
    if (pregunta.isEmpty()) {
        QMessageBox::warning(this, tr("Ingresar pregunta"), tr("Debe ingresar una pregunta antes de continuar"));

        return;
    }

    QString respuesta = ui->comboBoxRespuesta->currentText();

    // Crear el objeto de Preguntas
    this->m_pregunta = new Preguntas(pregunta, respuesta);
    accept();
}


void Agregar::on_buttonBox_2_rejected()
{
    close();
}
