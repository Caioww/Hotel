#ifndef MENUPAINEL_H
#define MENUPAINEL_H

#include <QDialog>

namespace Ui {
class menupainel;
}

class menupainel : public QDialog
{
    Q_OBJECT

public:
    explicit menupainel(QWidget *parent = nullptr);
    ~menupainel();

private slots:
    void on_btnSair_clicked();

    void on_btnCadastroCliente_clicked();

    void on_btnConfirmar_clicked();

    void on_btnConfirmar_2_clicked();

    void on_btnCancelar_clicked();

    void on_btnMenu_clicked();

private:
    Ui::menupainel *ui;
};

#endif // MENUPAINEL_H
