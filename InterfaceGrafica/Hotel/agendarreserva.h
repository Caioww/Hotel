#ifndef AGENDARRESERVA_H
#define AGENDARRESERVA_H

#include <QDialog>

namespace Ui {
class agendarReserva;
}

class agendarReserva : public QDialog
{
    Q_OBJECT

public:
    explicit agendarReserva(QWidget *parent = nullptr);
    ~agendarReserva();

private:
    Ui::agendarReserva *ui;
};

#endif // AGENDARRESERVA_H
