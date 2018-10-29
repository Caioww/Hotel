#include "menupainel.h"
#include "ui_menupainel.h"
#include <QMessageBox>
#include "Pessoa.hpp"
#include <QFile>
#include <QTextStream>
#include <memory>
#include "Quarto.hpp"
#include "Item.hpp"
#include "login.h"



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
    Quarto *q = new Quarto();

    QDate IniDate =ui->dateInicial->date();
    QDate FimDate =ui->dateFim->date();


    QString numero = ui->txtNumero->text();
    QString andar = ui->comboAndar->currentText();
    QString tipoQuarto = ui->comboQuarto->currentText();
    QString estado = ui->comboEstado->currentText();
    QString valor = ui->txtDiaria->text();
    QString dateIni = IniDate.toString();
    QString dateFim = FimDate.toString();
    QString pessoas = ui->comboPessoas->currentText();

   /* q->setNumero(numero.toStdString());
    q->setAndar(andar.toStdString());
    q->setTipoQuarto(tipoQuarto.toStdString());
    q->setEstado(estado.toStdString());
    q->setValor(valor.toStdString());
    q->setDateInicial(dateIni.toStdString());
    q->setDateFim(dateFim.toStdString());
    q->setPessoas(pessoas.toStdString());*/

    QString valorTotal = QString::number(FimDate.daysTo(IniDate) * valor.toFloat()) ;

    QFile file("C:\\Users\\Caio\\Documents\\cadastroQuarto.txt");

        if(!file.open(QIODevice::Append|QIODevice::Text))
            return;

        QTextStream out(&file);
            out<<
                 QString::fromStdString(numero.toStdString())<<"-"<<
                  QString::fromStdString(andar.toStdString())<<"-"<<
                  QString::fromStdString(tipoQuarto.toStdString())<<"-"<<
                  QString::fromStdString(estado.toStdString())<<"-"<<
                  QString::fromStdString(valor.toStdString())<<"-"<<
                  QString::fromStdString(dateIni.toStdString())<<"-"<<
                  QString::fromStdString(dateFim.toStdString())<<"-"<<
                  QString::fromStdString(valorTotal.toStdString())<<"-"<<
                  QString::fromStdString(pessoas.toStdString())<<"\n";



       file.close();





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

void menupainel::borrarItem(){
    while(ui->tableWidget_2->rowCount()>0){
        ui->tableWidget_2->removeRow(0);
    }
}

void menupainel::borrarFunc(){
    while(ui->tableWidget_3->rowCount()>0){
        ui->tableWidget_3->removeRow(0);
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


     QFile arch("C:\\Users\\Caio\\Documents\\cadastroQuarto.txt");
         if(!arch.open(QIODevice::ReadOnly | QIODevice::Text))
                 return;
      QTextStream file(&arch);

     while(!in.atEnd() && !file.atEnd()){
         QString line = in.readLine();
         QStringList A = line.split("-");

         QString linha = file.readLine();
         QStringList B = linha.split("-");

         QString pro=A[0];
         if(pro.contains(nomeBusca)==true){
             lis(line,linha);
         }
     }
     sr.close();
     arch.close();

}

void menupainel::lis(QString linea,QString line){


    QStringList A =linea.split("-");
    QString Nome=A[0];


    QStringList B = line.split("-");
    QString numero = B[0];
    QString tipoQ = B[2];
    QString quarto = B[6];

    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0,new QTableWidgetItem(Nome));
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,1,new QTableWidgetItem(tipoQ));
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,2,new QTableWidgetItem(numero));
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,3,new QTableWidgetItem(quarto));

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




void menupainel::on_btnAtualizar_clicked()
{
    borrar();

    QFile arch("C:\\Users\\Caio\\Documents\\cadastroQuarto.txt");
        if(!arch.open(QIODevice::ReadOnly | QIODevice::Text))
                return;

     QTextStream files(&arch);

    QFile file("C:\\Users\\Caio\\Documents\\testeRemover.txt");

        if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
            return;

        QTextStream in(&file);

        while(!in.atEnd()){
            QString line =in.readLine();
            QString linha =files.readLine();

            lis(line,linha);
        }

       file.close();
       arch.close();
}

void menupainel::on_btnRemover_clicked()
{
    QString txt = ui->tableWidget->item(ui->tableWidget->currentRow(),0)->text();

    //CLIENTE
    QFile sr("C:\\Users\\Caio\\Documents\\testeRemover.txt");
        if(!sr.open(QIODevice::ReadOnly | QIODevice::Text))
            return;
     QFile sw("C:\\Users\\Caio\\Documents\\temp1.txt");
        if(!sw.open(QIODevice::Append | QIODevice::Text))
            return;

     //QUARTO
        QFile qr("C:\\Users\\Caio\\Documents\\cadastroQuarto.txt");
            if(!qr.open(QIODevice::ReadOnly | QIODevice::Text))
                return;
         QFile qrto("C:\\Users\\Caio\\Documents\\temp10.txt");
            if(!qrto.open(QIODevice::Append | QIODevice::Text))
                return;


     //CLIENTE
     QTextStream in(&sr);
     QTextStream out(&sw);

     //QUARTO
     QTextStream cd(&qr);
     QTextStream cd1(&qrto);

        while(!in.atEnd()&&!qr.atEnd()){
            QString line = in.readLine();
            QStringList A = line.split("-");
            QString id = A[0];

            QString linea = in.readLine();
            QStringList B = linea.split("-");
            QString idd = B[0];

            if(id.compare(txt)!=0&&idd.compare(txt)!=0){
                out<<line<<"\n";
                cd1<<linea<<"\n";
            }
        }

        sr.close();
        sw.close();

        qr.close();
        qrto.close();

        //QUARTO
        QFile qrto1("C:\\Users\\Caio\\Documents\\cadastroQuarto.txt");
            if(!qrto1.open(QIODevice::WriteOnly | QIODevice::Text))
                   return;
            qrto1.close();

        QFile qrto2("C:\\Users\\Caio\\Documents\\cadastroQuarto.txt");
                if(!qrto2.open(QIODevice::Append | QIODevice::Text))
                    return;

        QFile qr1("C:\\Users\\Caio\\Documents\\temp10.txt");
                if(!qr1.open(QIODevice::ReadOnly | QIODevice::Text))
            return;



        //CLIENTE
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


     QTextStream cdd1(&qr1);
    QTextStream cdd2(&qrto2);
    QTextStream in3(&sr3);
    QTextStream out3(&sw3);

    while(!in3.atEnd()&&!cdd1.atEnd()){
        QString line = in3.readLine();
        QString linea = cdd1.readLine();

        out3<<line<<"\n";
        cdd2<<linea<<"\n";
      }


    QFile qrto3("C:\\Users\\Caio\\Documents\\temp1.txt");
        if(!qrto3.open(QIODevice::WriteOnly | QIODevice::Text))
                return;
        qrto3.close();
        qrto2.close();
        qr1.close();

    QFile sw4("C:\\Users\\Caio\\Documents\\temp1.txt");
        if(!sw4.open(QIODevice::WriteOnly | QIODevice::Text))
                return;
        sw4.close();
        sr3.close();
        sw3.close();

}


void menupainel::on_btnAdicionarItem2_clicked()
{

    Item *it = new Item();


    QString descricaoI = ui->txtADescricao->text();
    QString qntd=ui->txtAQntd->text();
    QString precoUnit = ui->txtAPreco->text();




    it->setDescricao(descricaoI.toStdString());
    it->setPreco(precoUnit.toFloat());
    it->setQntd(qntd.toFloat());
    it->setTotal(it->getQntd(),it->getPreco());




    QFile file("C:\\Users\\Caio\\Documents\\cadastroItem.txt");

        if(!file.open(QIODevice::Append|QIODevice::Text))
            return;

        QTextStream out(&file);
            out<<
                 QString::fromStdString(it->getDescricao())<<"-"<<
                 QString::number(it->getQntd())<<"-"<<
                 QString::number(it->getPreco())<<"-"<<
                 QString::number(it->getTotal())<<"\n";
       file.close();


       ui->stackedWidget->setCurrentIndex(7);




}

void menupainel::on_btnAttItem_clicked()
{
    borrarItem();

    QFile file("C:\\Users\\Caio\\Documents\\cadastroItem.txt");

        if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
            return;

        QTextStream in(&file);
        while(!in.atEnd()){
            QString line =in.readLine();
            listar(line);
        }
       file.close();

}

void menupainel::listar(QString linea){


    QStringList A =linea.split("-");
    QString Descricao=A[0];
    QString Qntd=A[1];
    QString Preco=A[2];
    QString Total=A[3];

    ui->tableWidget_2->insertRow(ui->tableWidget_2->rowCount());
    ui->tableWidget_2->setItem(ui->tableWidget_2->rowCount()-1,0,new QTableWidgetItem(Descricao));
    ui->tableWidget_2->setItem(ui->tableWidget_2->rowCount()-1,1,new QTableWidgetItem(Qntd));
    ui->tableWidget_2->setItem(ui->tableWidget_2->rowCount()-1,2,new QTableWidgetItem(Preco));
    ui->tableWidget_2->setItem(ui->tableWidget_2->rowCount()-1,3,new QTableWidgetItem(Total));


    int sum=0;
        for (int i=0;i< ui->tableWidget_2->rowCount();i++) {
                    QTableWidgetItem *item =  ui->tableWidget_2->item(i,3);
                    int value = item->text().toFloat();
                   sum+=value;
                }



        ui->txtTotalValor->setText("R$"+QString::number(sum));


}

void menupainel::on_btnConfig_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);

}

void menupainel::on_btnEntrarV_clicked()
{
    QString edtNome = ui->edtNome->text();
    QString edtSenha = ui->edtSenha->text();

    QFile sr("C:\\Users\\Caio\\Documents\\cadastrar.txt");

        if(!sr.open(QIODevice::ReadOnly|QIODevice::Text))
            return;

        QTextStream in(&sr);
        while(!in.atEnd()){
            QString line = in.readLine();
            QStringList A = line.split("-");
            QString pro=A[0];
            QString cargo =A[2];
            if(pro.contains(edtNome)==true&&cargo.contains("Gerente")==true){
                ui->stackedWidget->setCurrentIndex(9);

            }


       }

        /*QString line = in.readLine();
        QStringList A = line.split("-");
        QString pro=A[0];
        QString cargo =A[2];
        if(pro.contains(edtNome)==false&&cargo.contains("Gerente")==false){
            QMessageBox::warning(this,"Login","Você não tem autorização para acessar essa funcionalidade");

        }*/

}

void menupainel::on_btnFAtualizar_clicked()
{
    borrarFunc();

    QFile func("C:\\Users\\Caio\\Documents\\cadastrar.txt");

        if(!func.open(QIODevice::ReadOnly|QIODevice::Text))
            return;

        QTextStream list(&func);
        while(!list.atEnd()){
            QString line =list.readLine();
            listarFuncionario(line);
        }
       func.close();
}

void menupainel::listarFuncionario(QString linea){


    QStringList A =linea.split("-");
    QString Nome=A[0];
    QString Cargo=A[1];


    ui->tableWidget_3->insertRow(ui->tableWidget_3->rowCount());
    ui->tableWidget_3->setItem(ui->tableWidget_3->rowCount()-1,0,new QTableWidgetItem(Nome));
    ui->tableWidget_3->setItem(ui->tableWidget_3->rowCount()-1,1,new QTableWidgetItem(Cargo));
}

void menupainel::on_btnFBuscar_clicked()
{
    borrar();

    QString nomeBusca = ui->txtNCliente->text();
    QFile sr("C:\\Users\\Caio\\Documents\\cadastrar.txt");
        if(!sr.open(QIODevice::ReadOnly | QIODevice::Text))
                return;
     QTextStream in(&sr);



     while(!in.atEnd()){
         QString line = in.readLine();
         QStringList A = line.split("-");

         QString pro=A[0];
         if(pro.contains(nomeBusca)==true){
             listarFuncionario(line);
         }
     }
     sr.close();

}

void menupainel::on_btnFRemover_clicked()
{
    QString txt = ui->tableWidget_3->item(ui->tableWidget_3->currentRow(),0)->text();

    //CLIENTE
    QFile sr("C:\\Users\\Caio\\Documents\\cadastrar.txt");
        if(!sr.open(QIODevice::ReadOnly | QIODevice::Text))
            return;
     QFile sw("C:\\Users\\Caio\\Documents\\temp30.txt");
        if(!sw.open(QIODevice::Append | QIODevice::Text))
            return;



     //CLIENTE
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


        QFile sw2("C:\\Users\\Caio\\Documents\\cadastrar.txt");
            if(!sw2.open(QIODevice::WriteOnly | QIODevice::Text))
                   return;
            sw2.close();

        QFile sw3("C:\\Users\\Caio\\Documents\\cadastrar.txt");
                if(!sw3.open(QIODevice::Append | QIODevice::Text))
                    return;

        QFile sr3("C:\\Users\\Caio\\Documents\\temp30.txt");
                if(!sr3.open(QIODevice::ReadOnly | QIODevice::Text))
            return;


    QTextStream in3(&sr3);
    QTextStream out3(&sw3);

    while(!in3.atEnd()){
        QString line = in3.readLine();
        out3<<line<<"\n";

      }

    QFile sw4("C:\\Users\\Caio\\Documents\\temp30.txt");
        if(!sw4.open(QIODevice::WriteOnly | QIODevice::Text))
                return;
        sw4.close();
        sr3.close();
        sw3.close();

}

void menupainel::on_btnCalcularValor_clicked()
{
    QDate IniDate =ui->dateInicial->date();
    QDate FimDate =ui->dateFim->date();

    QString valor = ui->txtDiaria->text();

    QString valorTotal = QString::number(IniDate.daysTo(FimDate) * valor.toFloat()) ;

    ui->txtvalorTotal->setText("R$"+valorTotal);
}


