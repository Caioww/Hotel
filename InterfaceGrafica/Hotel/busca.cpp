#include "busca.h"
#include "ui_busca.h"

Busca::Busca(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Busca)
{
    ui->setupUi(this);
}

Busca::~Busca()
{
    delete ui;
}
