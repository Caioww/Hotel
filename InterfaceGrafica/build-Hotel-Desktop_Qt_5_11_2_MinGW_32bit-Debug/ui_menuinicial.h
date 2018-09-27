/********************************************************************************
** Form generated from reading UI file 'menuinicial.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUINICIAL_H
#define UI_MENUINICIAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuInicial
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MenuInicial)
    {
        if (MenuInicial->objectName().isEmpty())
            MenuInicial->setObjectName(QStringLiteral("MenuInicial"));
        MenuInicial->resize(400, 300);
        centralWidget = new QWidget(MenuInicial);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(110, 80, 221, 151));
        MenuInicial->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MenuInicial);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 26));
        MenuInicial->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MenuInicial);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MenuInicial->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MenuInicial);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MenuInicial->setStatusBar(statusBar);

        retranslateUi(MenuInicial);

        QMetaObject::connectSlotsByName(MenuInicial);
    } // setupUi

    void retranslateUi(QMainWindow *MenuInicial)
    {
        MenuInicial->setWindowTitle(QApplication::translate("MenuInicial", "MenuInicial", nullptr));
        pushButton->setText(QApplication::translate("MenuInicial", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MenuInicial: public Ui_MenuInicial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUINICIAL_H
