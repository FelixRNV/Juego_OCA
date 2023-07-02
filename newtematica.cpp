#include "newtematica.h"
#include "ui_newtematica.h"

NewTematica::NewTematica(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewTematica)
{
    ui->setupUi(this);
}

NewTematica::~NewTematica()
{
    delete ui;
}
