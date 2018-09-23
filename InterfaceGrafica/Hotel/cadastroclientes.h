#ifndef CADASTROCLIENTES_H
#define CADASTROCLIENTES_H

#include <QDialog>

namespace Ui {
class cadastroclientes;
}

class cadastroclientes : public QDialog
{
    Q_OBJECT

public:
    explicit cadastroclientes(QWidget *parent = nullptr);
    ~cadastroclientes();

private slots:
    void on_btnConfirmar_clicked();

    void on_btnLimpar_clicked();

private:
    Ui::cadastroclientes *ui;
};

#endif // CADASTROCLIENTES_H
