#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QtCore>

namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_btnEntrar_clicked();
    bool validacaoLogin();
    void validacaoFuncionarios();


    void on_btnCadastrar_clicked();

    void on_pushButton_clicked();

private:
    Ui::Login *ui;
    QFile *file;
    QTextStream stream;
};

#endif // LOGIN_H
