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

    void on_btnBuscar_clicked();

    void on_btnConfirmar3_clicked();

    void on_btnConfirmar4_clicked();

    void on_btnAdicionarItem_2_clicked();

    void lis(QString linea,QString linha);

    void borrar();

    void on_btnAtualizar_clicked();

    void on_btnRemover_clicked();

    void listar(QString linea);

    void on_btnAdicionarItem2_clicked();

    void on_btnAttItem_clicked();


private:
    Ui::menupainel *ui;
    QFile *file;
    QTextStream stream;
};

#endif // MENUPAINEL_H
