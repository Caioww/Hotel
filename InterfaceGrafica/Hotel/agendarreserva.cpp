#include "agendarreserva.h"
#include "ui_agendarreserva.h"

agendarReserva::agendarReserva(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::agendarReserva)
{
    ui->setupUi(this);
}

agendarReserva::~agendarReserva()
{
    delete ui;
}
