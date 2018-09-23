#ifndef CADASTROQUARTO_H
#define CADASTROQUARTO_H

#include <QDialog>

namespace Ui {
class cadastroQuarto;
}

class cadastroQuarto : public QDialog
{
    Q_OBJECT

public:
    explicit cadastroQuarto(QWidget *parent = nullptr);
    ~cadastroQuarto();

private slots:
    void on_btnConfirmar_clicked();

    void on_btnLimpar_clicked();

private:
    Ui::cadastroQuarto *ui;
};

#endif // CADASTROQUARTO_H
