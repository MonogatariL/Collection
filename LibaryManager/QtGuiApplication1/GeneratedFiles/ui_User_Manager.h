/********************************************************************************
** Form generated from reading UI file 'User_Manager.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USER_MANAGER_H
#define UI_USER_MANAGER_H

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

class Ui_User_Manager
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *PB_clean;
    QComboBox *CB_user;
    QTableWidget *tableWidget;

    void setupUi(QWidget *User_Manager)
    {
        if (User_Manager->objectName().isEmpty())
            User_Manager->setObjectName(QStringLiteral("User_Manager"));
        User_Manager->resize(770, 700);
        verticalLayout = new QVBoxLayout(User_Manager);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        PB_clean = new QPushButton(User_Manager);
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

        CB_user = new QComboBox(User_Manager);
        CB_user->setObjectName(QStringLiteral("CB_user"));
        CB_user->setMinimumSize(QSize(100, 0));

        horizontalLayout->addWidget(CB_user);


        verticalLayout->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(User_Manager);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setMinimumSize(QSize(0, 0));
        tableWidget->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

        verticalLayout->addWidget(tableWidget);


        retranslateUi(User_Manager);

        QMetaObject::connectSlotsByName(User_Manager);
    } // setupUi

    void retranslateUi(QWidget *User_Manager)
    {
        User_Manager->setWindowTitle(QApplication::translate("User_Manager", "User_Manager", Q_NULLPTR));
        PB_clean->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class User_Manager: public Ui_User_Manager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USER_MANAGER_H
