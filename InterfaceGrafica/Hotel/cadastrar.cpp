#include "cadastrar.h"
#include "ui_cadastrar.h"
#include <QMessageBox>
#include <fstream>
#include "login.h"


cadastrar::cadastrar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cadastrar)
{
    ui->setupUi(this);
}

cadastrar::~cadastrar()
{
    delete ui;
}


void cadastrar::on_btnConfirmar_clicked()
{
    QString nome=ui->txtNome->text();
    QString senha=ui->txtSenha->text();
    QString confirmarSenha=ui->txtCsenha->text();
    QString cargo = ui->comboCargo->currentText();




    using namespace std;

    QFile file("cadastrar.txt");

        if(!file.open(QIODevice::Append|QIODevice::Text))
            return;

        QTextStream out(&file);
            out<<
                 QString::fromStdString(nome.toStdString())<<"-"<<
                 QString::fromStdString(senha.toStdString())<<"-"<<
                 QString::fromStdString(cargo.toStdString())<<"\n";
       file.close();

    if(senha == confirmarSenha){
      QMessageBox::information(this,"Cadastro","Cadastrado com sucesso");
      close();


    }else{
        QMessageBox::warning(this,"Senha","As senhas não conferem");
    }
}

void cadastrar::on_btnCancelar_clicked()
{
    close();
}
