#ifndef CADASTROQUARTO_H
#define CADASTROQUARTO_H

#include <QDialog>
#include <QtCore>
#include <QMainWindow>

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
    void updateClients(bool);

    void on_btnLimpar_clicked();

private:
    Ui::cadastroQuarto *ui;
    QFile *file;
    QTextStream stream;
};

#endif // CADASTROQUARTO_H
