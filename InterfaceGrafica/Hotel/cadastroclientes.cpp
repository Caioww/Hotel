#include "cadastroclientes.h"
#include "ui_cadastroclientes.h"

cadastroclientes::cadastroclientes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cadastroclientes)
{
    ui->setupUi(this);
    connect(ui->btnConfirmar,SIGNAL(clicked()),this,SLOT(on_btnConfirmar_clicked()));
    connect(ui->btnLimpar,SIGNAL(clicked()),this,SLOT(on_btnLimpar_clicked()));
}

cadastroclientes::~cadastroclientes()
{
    delete ui;
}

void cadastroclientes::on_btnConfirmar_clicked()
{
    QString nome = ui->txtNome->text();
    QString idade = ui->txtIdade->text();
    QString sexo = ui->comboSexo->currentText();
    QString RG = ui->txtRG->text();
    QString Email = ui->txtEmail->text();
    QString fone = ui->txtTelefone->text();
}


void cadastroclientes::on_btnLimpar_clicked()
{
    ui->txtNome->clear();
    ui->txtIdade->clear();
    ui->comboSexo->clear();
    ui->txtRG->clear();
    ui->txtEmail->clear();
    ui->txtTelefone->clear();

}
