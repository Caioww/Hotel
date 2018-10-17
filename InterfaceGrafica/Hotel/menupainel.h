#ifndef MENUPAINEL_H
#define MENUPAINEL_H

#include <QDialog>
#include <QtCore>

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

    void on_btnConsulta_clicked();

    void on_btnReserva_clicked();

    void on_btnRenovar_clicked();

    void on_btnCheckout_clicked();

    void on_btnAdicionarItem_clicked();

    void updateClients(bool);

private:
    Ui::menupainel *ui;
    QFile *file;
    QTextStream stream;
};

#endif // MENUPAINEL_H
