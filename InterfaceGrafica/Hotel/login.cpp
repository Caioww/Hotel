#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include <fstream>
#include "cadastrar.h"
#include "menupainel.h"

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    connect(ui->btnEntrar,SIGNAL(clicked()),this,SLOT(validacaoLogin()));
}

Login::~Login()
{
    delete ui;
}




void Login::on_btnEntrar_clicked()

{
    QString usuario = ui->txtNome->text();
    QString senha = ui->txtSenha->text();


    QFile sr("cadastrar.txt");

        if(!sr.open(QIODevice::ReadOnly | QIODevice::Text))
                return;
     QTextStream in(&sr);
     while(!in.atEnd()){
         QString line = in.readLine();
         QStringList A = line.split("\n");
         QString pro=A[0];
         if(pro.contains(usuario)==true){
             close();
             menupainel menu;
             menu.exec();

         }
     }

     sr.close();
}


void Login::on_btnCadastrar_clicked()
{
    cadastrar cadastra;
    cadastra.exec();
}


