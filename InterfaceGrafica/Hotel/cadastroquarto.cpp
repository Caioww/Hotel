#include "cadastroquarto.h"
#include "ui_cadastroquarto.h"
#include <QMessageBox>

cadastroQuarto::cadastroQuarto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cadastroQuarto)
{
    ui->setupUi(this);
}

cadastroQuarto::~cadastroQuarto()
{
    delete ui;
}

void cadastroQuarto::on_btnConfirmar_clicked()
{
    QString numero = ui->txtNumero->text();
    QString descricao = ui->txtDescricao->toPlainText();
    QString caracteristicas = ui->txtCaracteristicas->toPlainText();
    QString andar = ui->comboAndar->currentText();
    QString diaria = ui->txtDiaria->text();
    QString pessoas = ui->comboPessoas->currentText();
    QString estado = ui->comboEstado->currentText();
    QString tipoQuarto = ui->comboQuarto->currentText();

    QMessageBox::information(this,"\nandar"+andar,"\ndiaria"+diaria,"\npessoas"+pessoas,"\nestado"+estado,"\ntipoQuarto"+tipoQuarto);
}

void cadastroQuarto::on_btnLimpar_clicked()
{
    ui->txtNumero->clear();
    ui->txtDescricao->clear();
    ui->txtCaracteristicas->clear();
    ui->comboAndar->clear();
    ui->txtDiaria->clear();
    ui->comboPessoas->clear();
    ui->comboEstado->clear();
    ui->comboQuarto->clear();

    ui->txtNumero->setFocus();
}
