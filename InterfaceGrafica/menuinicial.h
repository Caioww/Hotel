#ifndef MENUINICIAL_H
#define MENUINICIAL_H

#include <QDialog>

namespace Ui {
class MenuInicial;
}

class MenuInicial : public QDialog
{
    Q_OBJECT

public:
    explicit MenuInicial(QWidget *parent = nullptr);
    ~MenuInicial();

private:
    Ui::MenuInicial *ui;
};

#endif // MENUINICIAL_H
