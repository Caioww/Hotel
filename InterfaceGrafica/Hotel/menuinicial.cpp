#include "menuinicial.h"
#include "ui_menuinicial.h"
#include <QPixmap>
#include <QIcon>
#include "cadastroclientes.h"
#include "cadastroquarto.h"

MenuInicial::MenuInicial(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MenuInicial)
{
    ui->setupUi(this);

}

MenuInicial::~MenuInicial()
{
    delete ui;
}



void MenuInicial::on_btnCadastroCliente_clicked()
{
    cadastroclientes clientes;
    clientes.exec();

}

void MenuInicial::on_btnBuscar_clicked()
{
    cadastroQuarto quarto;
    quarto.exec();
}
