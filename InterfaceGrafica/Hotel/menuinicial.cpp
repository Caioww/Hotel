#include "menuinicial.h"
#include "ui_menuinicial.h"

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
