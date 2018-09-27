#include "cadastrar.h"
#include "ui_cadastrar.h"
#include <QMessageBox>
#include <fstream>


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

    using namespace std;
    ofstream fout("C:\\Users\\Caio\\Documents\\cadastrar.txt", ios::app);

    fout <<nome.toStdString()<<endl;

    if(senha == confirmarSenha){
      fout <<senha.toStdString()<<endl;
      QMessageBox::information(this,"Cadastro","Cadastrado com sucesso");

    }else{
        QMessageBox::warning(this,"Senha","As senhas não conferem");
    }
}
