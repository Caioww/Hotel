/********************************************************************************
** Form generated from reading UI file 'cadastroclientes.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CADASTROCLIENTES_H
#define UI_CADASTROCLIENTES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_cadastroclientes
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_13;
    QPushButton *btnConfirmar;
    QPushButton *btnLimpar;
    QPushButton *btnCancelar;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QLineEdit *txtNome;
    QHBoxLayout *horizontalLayout_12;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_8;
    QLineEdit *txtIdade;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_9;
    QComboBox *comboSexo;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_10;
    QLineEdit *txtRG;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_11;
    QLineEdit *txtTelefone;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_12;
    QLineEdit *txtEmail;

    void setupUi(QDialog *cadastroclientes)
    {
        if (cadastroclientes->objectName().isEmpty())
            cadastroclientes->setObjectName(QStringLiteral("cadastroclientes"));
        cadastroclientes->resize(523, 416);
        layoutWidget = new QWidget(cadastroclientes);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(120, 370, 295, 30));
        horizontalLayout_13 = new QHBoxLayout(layoutWidget);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(0, 0, 0, 0);
        btnConfirmar = new QPushButton(layoutWidget);
        btnConfirmar->setObjectName(QStringLiteral("btnConfirmar"));

        horizontalLayout_13->addWidget(btnConfirmar);

        btnLimpar = new QPushButton(layoutWidget);
        btnLimpar->setObjectName(QStringLiteral("btnLimpar"));

        horizontalLayout_13->addWidget(btnLimpar);

        btnCancelar = new QPushButton(layoutWidget);
        btnCancelar->setObjectName(QStringLiteral("btnCancelar"));

        horizontalLayout_13->addWidget(btnCancelar);

        layoutWidget_2 = new QWidget(cadastroclientes);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 10, 501, 311));
        verticalLayout_3 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_7 = new QLabel(layoutWidget_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_6->addWidget(label_7);

        txtNome = new QLineEdit(layoutWidget_2);
        txtNome->setObjectName(QStringLiteral("txtNome"));

        horizontalLayout_6->addWidget(txtNome);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_8 = new QLabel(layoutWidget_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_7->addWidget(label_8);

        txtIdade = new QLineEdit(layoutWidget_2);
        txtIdade->setObjectName(QStringLiteral("txtIdade"));

        horizontalLayout_7->addWidget(txtIdade);


        horizontalLayout_12->addLayout(horizontalLayout_7);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_4);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_3);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_9 = new QLabel(layoutWidget_2);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_11->addWidget(label_9);

        comboSexo = new QComboBox(layoutWidget_2);
        comboSexo->addItem(QString());
        comboSexo->addItem(QString());
        comboSexo->setObjectName(QStringLiteral("comboSexo"));

        horizontalLayout_11->addWidget(comboSexo);


        horizontalLayout_12->addLayout(horizontalLayout_11);


        verticalLayout_3->addLayout(horizontalLayout_12);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_10 = new QLabel(layoutWidget_2);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_8->addWidget(label_10);

        txtRG = new QLineEdit(layoutWidget_2);
        txtRG->setObjectName(QStringLiteral("txtRG"));

        horizontalLayout_8->addWidget(txtRG);


        verticalLayout_3->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_11 = new QLabel(layoutWidget_2);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_9->addWidget(label_11);

        txtTelefone = new QLineEdit(layoutWidget_2);
        txtTelefone->setObjectName(QStringLiteral("txtTelefone"));

        horizontalLayout_9->addWidget(txtTelefone);


        verticalLayout_3->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_12 = new QLabel(layoutWidget_2);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_10->addWidget(label_12);

        txtEmail = new QLineEdit(layoutWidget_2);
        txtEmail->setObjectName(QStringLiteral("txtEmail"));

        horizontalLayout_10->addWidget(txtEmail);


        verticalLayout_3->addLayout(horizontalLayout_10);


        retranslateUi(cadastroclientes);

        QMetaObject::connectSlotsByName(cadastroclientes);
    } // setupUi

    void retranslateUi(QDialog *cadastroclientes)
    {
        cadastroclientes->setWindowTitle(QApplication::translate("cadastroclientes", "Dialog", nullptr));
        btnConfirmar->setText(QApplication::translate("cadastroclientes", "Confimar", nullptr));
        btnLimpar->setText(QApplication::translate("cadastroclientes", "Limpar", nullptr));
        btnCancelar->setText(QApplication::translate("cadastroclientes", "Cancelar", nullptr));
        label_7->setText(QApplication::translate("cadastroclientes", "Nome", nullptr));
        label_8->setText(QApplication::translate("cadastroclientes", "Idade", nullptr));
        label_9->setText(QApplication::translate("cadastroclientes", "Sexo", nullptr));
        comboSexo->setItemText(0, QApplication::translate("cadastroclientes", "M", nullptr));
        comboSexo->setItemText(1, QApplication::translate("cadastroclientes", "F", nullptr));

        label_10->setText(QApplication::translate("cadastroclientes", "RG", nullptr));
        label_11->setText(QApplication::translate("cadastroclientes", "Telefone", nullptr));
        label_12->setText(QApplication::translate("cadastroclientes", "E-mail", nullptr));
    } // retranslateUi

};

namespace Ui {
    class cadastroclientes: public Ui_cadastroclientes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CADASTROCLIENTES_H
