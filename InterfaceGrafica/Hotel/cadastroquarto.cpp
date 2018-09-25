#include "cadastroquarto.h"
#include "ui_cadastroquarto.h"
#include <QMessageBox>
#include <fstream>

cadastroQuarto::cadastroQuarto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cadastroQuarto)
{
    ui->setupUi(this);
    file=new QFile("teste.txt");


    connect(ui->btnConfirmar,SIGNAL(clicked()),this,SLOT(updateClients(bool)));
    connect(ui->btnLimpar,SIGNAL(clicked()),this,SLOT(on_btnLimpar_clicked()));

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

    if(ui->txtNumero->text().isEmpty()||ui->txtDescricao->toPlainText().isEmpty())
        return;

    using namespace std;
    ofstream fout("C:\\Users\\Caio\\Documents\\teste.txt", ios::app);

    fout <<numero.toStdString()<<endl;
    fout <<descricao.toStdString()<<endl;
    fout <<caracteristicas.toStdString()<<endl;
    fout <<andar.toStdString()<<endl;
    fout <<diaria.toStdString()<<endl;
    fout <<pessoas.toStdString()<<endl;
    fout <<estado.toStdString()<<endl;
    fout <<tipoQuarto.toStdString()<<endl;

    updateClients(true);

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

void cadastroQuarto::updateClients(bool){

    using namespace std;
    ifstream fin("C:\\Users\\Caio\\Documents\\teste.txt");
    char temp;
    QString buffer;
    while (fin.get(temp)) {
        buffer.push_back(QChar(temp));
    }

    }


