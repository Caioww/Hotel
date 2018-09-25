#ifndef BUSCA_H
#define BUSCA_H

#include <QDialog>

namespace Ui {
class Busca;
}

class Busca : public QDialog
{
    Q_OBJECT

public:
    explicit Busca(QWidget *parent = nullptr);
    ~Busca();

private:
    Ui::Busca *ui;
};

#endif // BUSCA_H
