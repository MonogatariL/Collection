/********************************************************************************
** Form generated from reading UI file 'Borrowed_Manager.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BORROWED_MANAGER_H
#define UI_BORROWED_MANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Borrowed_Manager
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *PB_clean;
    QComboBox *CB_syurui;
    QTableWidget *tableWidget;

    void setupUi(QWidget *Borrowed_Manager)
    {
        if (Borrowed_Manager->objectName().isEmpty())
            Borrowed_Manager->setObjectName(QStringLiteral("Borrowed_Manager"));
        Borrowed_Manager->resize(770, 700);
        verticalLayout = new QVBoxLayout(Borrowed_Manager);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        PB_clean = new QPushButton(Borrowed_Manager);
        PB_clean->setObjectName(QStringLiteral("PB_clean"));
        PB_clean->setMinimumSize(QSize(20, 20));
        PB_clean->setMaximumSize(QSize(20, 20));
        PB_clean->setStyleSheet(QLatin1String("width: 120px;\n"
"height: 28px;\n"
"background: #E0463E;\n"
"border-radius: 4px;\n"
"font-size: 12px;\n"
"font-family: Microsoft YaHei;\n"
"font-weight: 400;\n"
"color: #FEFEFE;\n"
"line-height: 60px;"));

        horizontalLayout->addWidget(PB_clean);

        CB_syurui = new QComboBox(Borrowed_Manager);
        CB_syurui->setObjectName(QStringLiteral("CB_syurui"));
        CB_syurui->setMinimumSize(QSize(70, 0));

        horizontalLayout->addWidget(CB_syurui);


        verticalLayout->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(Borrowed_Manager);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setMinimumSize(QSize(0, 0));
        tableWidget->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

        verticalLayout->addWidget(tableWidget);


        retranslateUi(Borrowed_Manager);

        QMetaObject::connectSlotsByName(Borrowed_Manager);
    } // setupUi

    void retranslateUi(QWidget *Borrowed_Manager)
    {
        Borrowed_Manager->setWindowTitle(QApplication::translate("Borrowed_Manager", "Borrowed_Manager", Q_NULLPTR));
        PB_clean->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Borrowed_Manager: public Ui_Borrowed_Manager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BORROWED_MANAGER_H
