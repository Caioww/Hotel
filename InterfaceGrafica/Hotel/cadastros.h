#ifndef CADASTROS_H
#define CADASTROS_H

#include <QDialog>

namespace Ui {
class cadastros;
}

class cadastros : public QDialog
{
    Q_OBJECT

public:
    explicit cadastros(QWidget *parent = nullptr);
    ~cadastros();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_btnQuarto_clicked();

private:
    Ui::cadastros *ui;
};

#endif // CADASTROS_H
