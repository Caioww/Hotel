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

    void lis(QString linea,QString linha);

    void borrar();

    void on_btnAtualizar_clicked();

    void on_btnRemover_clicked();

    void listar(QString linea);

    void on_btnAdicionarItem2_clicked();

    void on_btnAttItem_clicked();


    void on_btnConfig_clicked();

    void on_btnEntrarV_clicked();

    void on_btnFAtualizar_clicked();

    void listarFuncionario(QString linea);

    void on_btnFBuscar_clicked();

    void on_btnFRemover_clicked();

    void on_btnCalcularValor_clicked();

    void borrarItem();

    void borrarFunc();

    void on_pushButton_4_clicked();

    void listCheck(QString linea,QString line);

    void borrarCheck();

    void on_btnCancel_clicked();


    void on_btnRemoveIt_clicked();

    void on_btnVoltarM_clicked();

    void on_btnItCancel_clicked();

    void on_btnVoltarV_clicked();

    void on_btnFuncVolt_clicked();




private:
    Ui::menupainel *ui;
    QFile *file;
    QTextStream stream;
};

#endif // MENUPAINEL_H
