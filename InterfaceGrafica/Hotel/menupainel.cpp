#include "menupainel.h"
#include "ui_menupainel.h"
#include <QMessageBox>
#include <fstream>


menupainel::menupainel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menupainel)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
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



    QDate Mydate =ui->dateNasc->date();
    QString date = Mydate.toString();

    QString nome = ui->txtNome->text();
    QString idade = ui->txtIdade->text();
    QString sexo = ui->comboSexo->currentText();
    QString rg = ui->txtRG->text();
    QString cidade = ui->txtCity->text();
    QString estado = ui->txtEstado->text();
    QString telefone = ui->txtTelefone->text();
    QString celular = ui->txtCel->text();


    using namespace std;
    ofstream fout("C:\\Users\\Caio\\Documents\\testessssss.txt", ios::app);

    fout <<nome.toStdString()<<endl;
    fout <<idade.toStdString()<<endl;
    fout <<date.toStdString()<<endl;
    fout <<sexo.toStdString()<<endl;
    fout <<rg.toStdString()<<endl;
    fout <<cidade.toStdString()<<endl;
    fout <<estado.toStdString()<<endl;
    fout <<telefone.toStdString()<<endl;
    fout <<celular.toStdString()<<endl;

    updateClients(true);

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

void menupainel::updateClients(bool){

    using namespace std;
    ifstream fin("C:\\Users\\Caio\\Documents\\teste.txt");
    char temp;
    QString buffer;
    while (fin.get(temp)) {
        buffer.push_back(QChar(temp));

    }
}

void menupainel::on_btnBuscar_clicked()
{
    QString NomeCliente = ui->txtNCliente->text();
    QString NumeroQuarto =ui->txtNQuarto->text();
    QString TipoQuarto =ui->txtTQuarto->text();
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
