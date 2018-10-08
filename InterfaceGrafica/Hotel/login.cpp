#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include "menu.h"
#include <fstream>
#include "cadastrar.h"

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


bool Login::validacaoLogin(){
    QString usuario = ui->txtNome->text();
    QString senha = ui->txtSenha->text();

    using namespace std;
    ofstream fout("C:\\Users\\Caio\\Documents\\login.txt", ios::app);

    fout <<usuario.toStdString()<<endl;
    fout <<senha.toStdString()<<endl;

    if(usuario == "Caio Sousa" && senha =="12345"){
        return true;

    }else{
        return false;
    }
}

void Login::validacaoFuncionarios(){
    using namespace std;
    ifstream fin("C:\\Users\\Caio\\Documents\\login.txt");
    char temp;
    QString buffer;
    while (fin.get(temp)) {
        buffer.push_back(QChar(temp));

    }
}


void Login::on_btnEntrar_clicked()

{

     validacaoFuncionarios();

    if(validacaoLogin()==true){

        Menu menu;
        menu.exec();


    }else{
        QMessageBox::warning(this,"Login","Usuario ou senha incorretos");
    }




}

void Login::on_btnCadastrar_clicked()
{
    cadastrar cadastra;
    cadastra.exec();
}
