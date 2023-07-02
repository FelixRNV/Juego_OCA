#ifndef NEWTEMATICA_H
#define NEWTEMATICA_H

#include <QDialog>

namespace Ui {
class NewTematica;
}

class NewTematica : public QDialog
{
    Q_OBJECT

public:
    explicit NewTematica(QWidget *parent = nullptr);
    ~NewTematica();

private:
    Ui::NewTematica *ui;
};

#endif // NEWTEMATICA_H
