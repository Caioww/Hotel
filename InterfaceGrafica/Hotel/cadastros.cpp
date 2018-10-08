#include "cadastros.h"
#include "ui_cadastros.h"
#include "cadastroclientes.h"
#include "cadastroquarto.h"

cadastros::cadastros(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cadastros)
{
    ui->setupUi(this);
}

cadastros::~cadastros()
{
    delete ui;
}

void cadastros::on_pushButton_clicked()
{
    cadastros cadastros;
    cadastros.close();
    cadastroclientes cliente;
    cliente.exec();
}

void cadastros::on_btnQuarto_clicked()
{
    cadastros cadastros;
    cadastros.close();
    cadastroQuarto quarto;
    quarto.exec();
}
