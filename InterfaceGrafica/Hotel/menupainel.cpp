#include "menupainel.h"
#include "ui_menupainel.h"
#include <QMessageBox>
<<<<<<< HEAD

=======
>>>>>>> 30266a4f8d7056ea41242133b293ef18a33a58eb
#include "Pessoa.hpp"
#include <QFile>
#include <QTextStream>
#include <memory>

<<<<<<< HEAD
=======

>>>>>>> 30266a4f8d7056ea41242133b293ef18a33a58eb

menupainel::menupainel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menupainel)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    ui->tableWidget->setColumnCount(4);
    QStringList titu;
    titu<<"Cliente"<<"Tipo Quarto"<<"Número"<<"Fim Reserva";
    ui->tableWidget->setHorizontalHeaderLabels(titu);
}


menupainel::~menupainel()
{
    delete ui;
}

void menupainel::on_btnSair_clicked()
{
    close();
}

void menupainel::on_btnCadastroCliente_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void menupainel::on_btnConfirmar_clicked()
{
    Pessoa *p=new Pessoa();


    QDate Mydate =ui->dateNasc->date();
    QString date = Mydate.toString();

    QString nome = ui->txtNome->text();
    QString idade = ui->txtIdade->text();
    QString sexo = ui->comboSexo->currentText();
    QString rg = ui->txtRG->text();
    QString email = ui->txtEmail->text();
    QString cidade = ui->txtCity->text();
    QString estado = ui->txtEstado->text();
    QString telefone = ui->txtTelefone->text();
    QString celular = ui->txtCel->text();


    p->setNome(nome.toStdString());
    p->setIdade(idade.toStdString());
    p->setSexo(sexo.toStdString());
    p->setRG(rg.toStdString());
    p->setData(date.toStdString());
    p->setEstado(estado.toStdString());
    p->setCidade(cidade.toStdString());
    p->setTelefone(telefone.toStdString());
    p->setCelular(celular.toStdString());
    p->setEmail(email.toStdString());


    QFile file("C:\\Users\\Caio\\Documents\\testeRemover.txt");

        if(!file.open(QIODevice::Append|QIODevice::Text))
            return;

        QTextStream out(&file);
            out<<
                 QString::fromStdString(p->getNome())<<"-"<<
                 QString::fromStdString(p->getIdade())<<"-"<<
                 QString::fromStdString(p->getSexo())<<"-"<<
                 QString::fromStdString(p->getRG())<<"-"<<
                 QString::fromStdString(p->getData())<<"-"<<
                 QString::fromStdString(p->getEstado())<<"-"<<
                 QString::fromStdString(p->getCidade())<<"-"<<
                 QString::fromStdString(p->getTelefone())<<"-"<<
                 QString::fromStdString(p->getCelular())<<"-"<<
                 QString::fromStdString(p->getEmail())<<"\n";
       file.close();



    ui->stackedWidget->setCurrentIndex(2);
}

void menupainel::on_btnConfirmar_2_clicked()
{

    QDate IniDate =ui->dateInicial->date();

    QDate FimDate =ui->dateFim->date();


    QString numero = ui->txtNumero->text();
    QString andar = ui->comboAndar->currentText();
    QString descricao = ui->txtDescricao->toPlainText();
    QString caracteristicas = ui->txtCaracteristicas->toPlainText();
    QString tipoQuarto = ui->comboQuarto->currentText();
    QString estado = ui->comboEstado->currentText();
    QString valor = ui->txtDiaria->text();
    QString dateIni = IniDate.toString();
    QString dateFim = FimDate.toString();
    QString pessoas = ui->comboPessoas->currentText();



    ui->stackedWidget->setCurrentIndex(0);
}

void menupainel::on_btnCancelar_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void menupainel::on_btnMenu_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void menupainel::on_btnConsulta_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void menupainel::on_btnReserva_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void menupainel::on_btnRenovar_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void menupainel::on_btnCheckout_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void menupainel::on_btnAdicionarItem_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void menupainel::borrar(){
    while(ui->tableWidget->rowCount()>0){
        ui->tableWidget->removeRow(0);
    }
}



void menupainel::on_btnBuscar_clicked()
{
    borrar();
    QString nomeBusca = ui->txtNCliente->text();
    QFile sr("C:\\Users\\Caio\\Documents\\testeRemover.txt");
        if(!sr.open(QIODevice::ReadOnly | QIODevice::Text))
                return;
     QTextStream in(&sr);
     while(!in.atEnd()){
         QString line = in.readLine();
         QStringList A = line.split("-");
         QString pro=A[0];
         if(pro.contains(nomeBusca)==true){
             lis(line);
         }
     }
     sr.close();

}

void menupainel::lis(QString linea){


    QStringList A =linea.split("-");
    QString Nome=A[0];
    QString Id=A[1];
    QString Quarto=A[2];
    QString Numero=A[3];
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0,new QTableWidgetItem(Nome));
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,1,new QTableWidgetItem(Id));
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,2,new QTableWidgetItem(Quarto));
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,3,new QTableWidgetItem(Numero));


    /*if(ui->tableWidget->rowCount() < row + 1)
        ui->tableWidget->setRowCount(row + 1);
    if(ui->tableWidget->columnCount() < A.size())
        ui->tableWidget->setColumnCount( A.size() );

    for( int column = 0; column < A.size(); column++)
    {
        QTableWidgetItem *newItem = new QTableWidgetItem( A.at(column) );
        ui->tableWidget->setItem(row, column, newItem);
    }

    row++;*/
}

void menupainel::on_btnConfirmar3_clicked()
{
    QString CNomeCliente = ui->txtCCliente->text();
    QString C=ui->txtCQuarto->text();
}

void menupainel::on_btnConfirmar4_clicked()
{
    QString RNomeCliente = ui->txtRCliente->text();
    QString RRG = ui->txtRRG->text();
    QString RNumero = ui->txtRNumero->text();

    QDate dateIn = ui->dateRInicial->date();
    QString dataInicio = dateIn.toString();

    QDate dateFi = ui->dateRFim->date();
    QString FimDate = dateFi.toString();
}

void menupainel::on_btnAdicionarItem_2_clicked()
{
    QString item =ui->txtItem->text();
    QString Idescricao=ui->txtADescricao->text();
    QString Aqntd = ui->txtAQntd->text();
    QString precoItem = ui->txtAPreco->text();
    QString TotalIt = ui->txtATotal->text();
}


void menupainel::on_btnAtualizar_clicked()
{
    borrar();

    QFile file("C:\\Users\\Caio\\Documents\\testeRemover.txt");

        if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
            return;

        QTextStream in(&file);
        while(!in.atEnd()){
            QString line =in.readLine();
            lis(line);
        }
       file.close();
}

void menupainel::on_btnRemover_clicked()
{
    QString txt = ui->tableWidget->item(ui->tableWidget->currentRow(),0)->text();
    QFile sr("C:\\Users\\Caio\\Documents\\testeRemover.txt");
        if(!sr.open(QIODevice::ReadOnly | QIODevice::Text))
            return;
     QFile sw("C:\\Users\\Caio\\Documents\\temp1.txt");
        if(!sw.open(QIODevice::Append | QIODevice::Text))
            return;

     QTextStream in(&sr);
     QTextStream out(&sw);
        while(!in.atEnd()){
            QString line = in.readLine();
            QStringList A = line.split("-");
            QString id = A[0];
            if(id.compare(txt)!=0){
                out<<line<<"\n";
            }
        }

        sr.close();
        sw.close();


        QFile sw2("C:\\Users\\Caio\\Documents\\testeRemover.txt");
            if(!sw2.open(QIODevice::WriteOnly | QIODevice::Text))
                   return;
            sw2.close();

        QFile sw3("C:\\Users\\Caio\\Documents\\testeRemover.txt");
                if(!sw3.open(QIODevice::Append | QIODevice::Text))
                    return;

        QFile sr3("C:\\Users\\Caio\\Documents\\temp1.txt");
                if(!sr3.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

    QTextStream in3(&sr3);
    QTextStream out3(&sw3);
    while(!in3.atEnd()){
        QString line = in3.readLine();
        out3<<line<<"\n";
      }
    QFile sw4("C:\\Users\\Caio\\Documents\\temp1.txt");
        if(!sw4.open(QIODevice::WriteOnly | QIODevice::Text))
                return;
        sw4.close();
        sr3.close();
        sw3.close();

}

