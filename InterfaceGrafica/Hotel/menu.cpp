#include "menu.h"
#include "ui_menu.h"
#include "cadastroquarto.h"

Menu::Menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_btnBuscar_clicked()
{
    cadastroQuarto quarto;
    quarto.exec();
}
