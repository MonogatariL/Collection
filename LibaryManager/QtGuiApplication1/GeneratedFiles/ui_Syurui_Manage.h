/********************************************************************************
** Form generated from reading UI file 'Syurui_Manage.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYURUI_MANAGE_H
#define UI_SYURUI_MANAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *L_syurui_name;
    QLineEdit *LE_syurui_name;
    QPushButton *PB_add_syurui;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(309, 282);
        verticalLayout = new QVBoxLayout(Form);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableWidget = new QTableWidget(Form);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout->addWidget(tableWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        L_syurui_name = new QLabel(Form);
        L_syurui_name->setObjectName(QString::fromUtf8("L_syurui_name"));
        L_syurui_name->setMinimumSize(QSize(50, 20));
        L_syurui_name->setMaximumSize(QSize(50, 20));

        horizontalLayout->addWidget(L_syurui_name);

        LE_syurui_name = new QLineEdit(Form);
        LE_syurui_name->setObjectName(QString::fromUtf8("LE_syurui_name"));

        horizontalLayout->addWidget(LE_syurui_name);

        PB_add_syurui = new QPushButton(Form);
        PB_add_syurui->setObjectName(QString::fromUtf8("PB_add_syurui"));
        PB_add_syurui->setMinimumSize(QSize(75, 20));
        PB_add_syurui->setMaximumSize(QSize(75, 20));

        horizontalLayout->addWidget(PB_add_syurui);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        L_syurui_name->setText(QCoreApplication::translate("Form", "\347\261\273\345\220\215\357\274\232", nullptr));
        PB_add_syurui->setText(QCoreApplication::translate("Form", "\346\267\273\345\212\240\345\210\206\347\261\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYURUI_MANAGE_H
