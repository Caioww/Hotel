#ifndef MENUINICIAL_H
#define MENUINICIAL_H

#include <QDialog>

namespace Ui {
class menuinicial;
}

class menuinicial : public QDialog
{
    Q_OBJECT

public:
    explicit menuinicial(QWidget *parent = nullptr);
    ~menuinicial();

private slots:
    void on_btnCadastroCliente_clicked();

private:
    Ui::menuinicial *ui;
};

#endif // MENUINICIAL_H
