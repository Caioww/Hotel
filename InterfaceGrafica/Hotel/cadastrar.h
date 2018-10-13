#ifndef CADASTRAR_H
#define CADASTRAR_H

#include <QDialog>
#include <QtCore>

namespace Ui {
class cadastrar;
}

class cadastrar : public QDialog
{
    Q_OBJECT

public:
    explicit cadastrar(QWidget *parent = nullptr);
    ~cadastrar();

private slots:

    void on_btnConfirmar_clicked();

    void on_btnCancelar_clicked();

private:
    Ui::cadastrar *ui;
    QFile *file;
    QTextStream stream;
};


#endif // CADASTRAR_H
