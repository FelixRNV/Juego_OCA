#ifndef TEMATICAS_H
#define TEMATICAS_H

#include <QDialog>

namespace Ui {
class Tematicas;
}

class Tematicas : public QDialog
{
    Q_OBJECT

public:
    explicit Tematicas(QWidget *parent = nullptr);
    ~Tematicas();

private:
    Ui::Tematicas *ui;
};

#endif // TEMATICAS_H
