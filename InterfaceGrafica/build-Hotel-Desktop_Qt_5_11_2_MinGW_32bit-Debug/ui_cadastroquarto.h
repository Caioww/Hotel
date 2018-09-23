/********************************************************************************
** Form generated from reading UI file 'cadastroquarto.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CADASTROQUARTO_H
#define UI_CADASTROQUARTO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_cadastroQuarto
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_8;
    QLineEdit *txtNumero;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_10;
    QComboBox *comboAndar;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_11;
    QTextEdit *txtDescricao;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_4;
    QTextEdit *txtCaracteristicas;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_12;
    QComboBox *comboPessoas;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_7;
    QLineEdit *txtDiaria;
    QWidget *layoutWidget_5;
    QHBoxLayout *horizontalLayout_12;
    QPushButton *btnConfirmar;
    QSpacerItem *horizontalSpacer_12;
    QPushButton *btnLimpar;
    QPushButton *btnCancelar;
    QWidget *layoutWidget_6;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_6;
    QComboBox *comboQuarto;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_9;
    QComboBox *comboEstado;

    void setupUi(QDialog *cadastroQuarto)
    {
        if (cadastroQuarto->objectName().isEmpty())
            cadastroQuarto->setObjectName(QStringLiteral("cadastroQuarto"));
        cadastroQuarto->resize(507, 393);
        layoutWidget = new QWidget(cadastroQuarto);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 10, 491, 31));
        horizontalLayout_9 = new QHBoxLayout(layoutWidget);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_10->addWidget(label_8);

        txtNumero = new QLineEdit(layoutWidget);
        txtNumero->setObjectName(QStringLiteral("txtNumero"));

        horizontalLayout_10->addWidget(txtNumero);


        horizontalLayout_9->addLayout(horizontalLayout_10);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_3);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_11->addWidget(label_10);

        comboAndar = new QComboBox(layoutWidget);
        comboAndar->addItem(QString());
        comboAndar->addItem(QString());
        comboAndar->addItem(QString());
        comboAndar->addItem(QString());
        comboAndar->addItem(QString());
        comboAndar->setObjectName(QStringLiteral("comboAndar"));

        horizontalLayout_11->addWidget(comboAndar);


        horizontalLayout_9->addLayout(horizontalLayout_11);

        layoutWidget_2 = new QWidget(cadastroQuarto);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(0, 50, 441, 89));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(layoutWidget_2);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_7->addWidget(label_11);

        txtDescricao = new QTextEdit(layoutWidget_2);
        txtDescricao->setObjectName(QStringLiteral("txtDescricao"));

        horizontalLayout_7->addWidget(txtDescricao);

        layoutWidget_3 = new QWidget(cadastroQuarto);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(0, 136, 441, 89));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget_3);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_8->addWidget(label_4);

        txtCaracteristicas = new QTextEdit(layoutWidget_3);
        txtCaracteristicas->setObjectName(QStringLiteral("txtCaracteristicas"));

        horizontalLayout_8->addWidget(txtCaracteristicas);

        layoutWidget_4 = new QWidget(cadastroQuarto);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(0, 260, 501, 31));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_12 = new QLabel(layoutWidget_4);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_5->addWidget(label_12);

        comboPessoas = new QComboBox(layoutWidget_4);
        comboPessoas->addItem(QString());
        comboPessoas->addItem(QString());
        comboPessoas->addItem(QString());
        comboPessoas->addItem(QString());
        comboPessoas->addItem(QString());
        comboPessoas->setObjectName(QStringLiteral("comboPessoas"));

        horizontalLayout_5->addWidget(comboPessoas);


        horizontalLayout_6->addLayout(horizontalLayout_5);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_7 = new QLabel(layoutWidget_4);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_4->addWidget(label_7);

        txtDiaria = new QLineEdit(layoutWidget_4);
        txtDiaria->setObjectName(QStringLiteral("txtDiaria"));

        horizontalLayout_4->addWidget(txtDiaria);


        horizontalLayout_6->addLayout(horizontalLayout_4);

        layoutWidget_5 = new QWidget(cadastroQuarto);
        layoutWidget_5->setObjectName(QStringLiteral("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(140, 320, 302, 41));
        horizontalLayout_12 = new QHBoxLayout(layoutWidget_5);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        btnConfirmar = new QPushButton(layoutWidget_5);
        btnConfirmar->setObjectName(QStringLiteral("btnConfirmar"));

        horizontalLayout_12->addWidget(btnConfirmar);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_12);

        btnLimpar = new QPushButton(layoutWidget_5);
        btnLimpar->setObjectName(QStringLiteral("btnLimpar"));

        horizontalLayout_12->addWidget(btnLimpar);

        btnCancelar = new QPushButton(layoutWidget_5);
        btnCancelar->setObjectName(QStringLiteral("btnCancelar"));

        horizontalLayout_12->addWidget(btnCancelar);

        layoutWidget_6 = new QWidget(cadastroQuarto);
        layoutWidget_6->setObjectName(QStringLiteral("layoutWidget_6"));
        layoutWidget_6->setGeometry(QRect(0, 210, 501, 31));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget_6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_6 = new QLabel(layoutWidget_6);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout->addWidget(label_6);

        comboQuarto = new QComboBox(layoutWidget_6);
        comboQuarto->addItem(QString());
        comboQuarto->addItem(QString());
        comboQuarto->addItem(QString());
        comboQuarto->setObjectName(QStringLiteral("comboQuarto"));

        horizontalLayout->addWidget(comboQuarto);


        horizontalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        label_9 = new QLabel(layoutWidget_6);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_2->addWidget(label_9);

        comboEstado = new QComboBox(layoutWidget_6);
        comboEstado->addItem(QString());
        comboEstado->addItem(QString());
        comboEstado->addItem(QString());
        comboEstado->setObjectName(QStringLiteral("comboEstado"));

        horizontalLayout_2->addWidget(comboEstado);


        horizontalLayout_3->addLayout(horizontalLayout_2);


        retranslateUi(cadastroQuarto);

        QMetaObject::connectSlotsByName(cadastroQuarto);
    } // setupUi

    void retranslateUi(QDialog *cadastroQuarto)
    {
        cadastroQuarto->setWindowTitle(QApplication::translate("cadastroQuarto", "Dialog", nullptr));
        label_8->setText(QApplication::translate("cadastroQuarto", "N\303\272mero", nullptr));
        label_10->setText(QApplication::translate("cadastroQuarto", "Andar", nullptr));
        comboAndar->setItemText(0, QApplication::translate("cadastroQuarto", "1\302\272", nullptr));
        comboAndar->setItemText(1, QApplication::translate("cadastroQuarto", "2\302\272", nullptr));
        comboAndar->setItemText(2, QApplication::translate("cadastroQuarto", "3\302\272", nullptr));
        comboAndar->setItemText(3, QApplication::translate("cadastroQuarto", "4\302\272", nullptr));
        comboAndar->setItemText(4, QApplication::translate("cadastroQuarto", "5\302\272", nullptr));

        label_11->setText(QApplication::translate("cadastroQuarto", "Descri\303\247\303\243o", nullptr));
        label_4->setText(QApplication::translate("cadastroQuarto", "Caracteristicas", nullptr));
        label_12->setText(QApplication::translate("cadastroQuarto", "Limite Pessoas", nullptr));
        comboPessoas->setItemText(0, QApplication::translate("cadastroQuarto", "1", nullptr));
        comboPessoas->setItemText(1, QApplication::translate("cadastroQuarto", "2", nullptr));
        comboPessoas->setItemText(2, QApplication::translate("cadastroQuarto", "3", nullptr));
        comboPessoas->setItemText(3, QApplication::translate("cadastroQuarto", "4", nullptr));
        comboPessoas->setItemText(4, QApplication::translate("cadastroQuarto", "5", nullptr));

        label_7->setText(QApplication::translate("cadastroQuarto", "Valor Di\303\241ria", nullptr));
        btnConfirmar->setText(QApplication::translate("cadastroQuarto", "Confirmar", nullptr));
        btnLimpar->setText(QApplication::translate("cadastroQuarto", "Limpar", nullptr));
        btnCancelar->setText(QApplication::translate("cadastroQuarto", "Cancelar", nullptr));
        label_6->setText(QApplication::translate("cadastroQuarto", "Tipo de Quarto", nullptr));
        comboQuarto->setItemText(0, QApplication::translate("cadastroQuarto", "Individual", nullptr));
        comboQuarto->setItemText(1, QApplication::translate("cadastroQuarto", "Fam\303\255lia", nullptr));
        comboQuarto->setItemText(2, QApplication::translate("cadastroQuarto", "Presidencial", nullptr));

        label_9->setText(QApplication::translate("cadastroQuarto", "Estado", nullptr));
        comboEstado->setItemText(0, QApplication::translate("cadastroQuarto", "Dispon\303\255vel", nullptr));
        comboEstado->setItemText(1, QApplication::translate("cadastroQuarto", "Ocupado", nullptr));
        comboEstado->setItemText(2, QApplication::translate("cadastroQuarto", "Em Manuten\303\247\303\243o", nullptr));

    } // retranslateUi

};

namespace Ui {
    class cadastroQuarto: public Ui_cadastroQuarto {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CADASTROQUARTO_H
