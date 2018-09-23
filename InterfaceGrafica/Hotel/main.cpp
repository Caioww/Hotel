#include "menuinicial.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MenuInicial w;
    w.show();

    return a.exec();
}
