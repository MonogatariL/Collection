/********************************************************************************
** Form generated from reading UI file 'Quantity_Manager.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUANTITY_MANAGER_H
#define UI_QUANTITY_MANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Quantity_manager
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *LB_Msg;
    QLabel *LB_Msg_2;
    QSpinBox *SB_Value;
    QHBoxLayout *horizontalLayout;
    QPushButton *PB_Ok;
    QPushButton *PB_Close;

    void setupUi(QWidget *Quantity_manager)
    {
        if (Quantity_manager->objectName().isEmpty())
            Quantity_manager->setObjectName(QStringLiteral("Quantity_manager"));
        Quantity_manager->resize(244, 149);
        Quantity_manager->setMinimumSize(QSize(200, 100));
        Quantity_manager->setStyleSheet(QLatin1String("#Quantity_manager{\n"
"	background-color: rgb(170, 170, 255);\n"
"}"));
        verticalLayout = new QVBoxLayout(Quantity_manager);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        LB_Msg = new QLabel(Quantity_manager);
        LB_Msg->setObjectName(QStringLiteral("LB_Msg"));
        QFont font;
        font.setFamily(QStringLiteral("Microsoft YaHei"));
        font.setBold(false);
        font.setWeight(50);
        LB_Msg->setFont(font);
        LB_Msg->setStyleSheet(QLatin1String("\n"
"font-size: 16px;\n"
"font-family: Microsoft YaHei;\n"
"font-weight: 400;\n"
"color: #ffffff;"));

        verticalLayout->addWidget(LB_Msg);

        LB_Msg_2 = new QLabel(Quantity_manager);
        LB_Msg_2->setObjectName(QStringLiteral("LB_Msg_2"));
        LB_Msg_2->setFont(font);
        LB_Msg_2->setStyleSheet(QLatin1String("\n"
"font-size: 16px;\n"
"font-family: Microsoft YaHei;\n"
"font-weight: 400;\n"
"color: #ffffff;"));

        verticalLayout->addWidget(LB_Msg_2);

        SB_Value = new QSpinBox(Quantity_manager);
        SB_Value->setObjectName(QStringLiteral("SB_Value"));
        SB_Value->setMinimumSize(QSize(0, 0));
        SB_Value->setStyleSheet(QLatin1String("\n"
"border: 1px solid #CFDDEF;\n"
"border-top-left-radius:6px;\n"
"border-bottom-left-radius:6px;\n"
"\n"
"font-size: 14px;\n"
"font-family: Microsoft YaHei;\n"
"font-weight: 400;\n"
"color: #5786C7;"));

        verticalLayout->addWidget(SB_Value);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        PB_Ok = new QPushButton(Quantity_manager);
        PB_Ok->setObjectName(QStringLiteral("PB_Ok"));
        PB_Ok->setStyleSheet(QLatin1String("background: #EDF8FF;\n"
"border: 1px solid #CFDDEF;\n"
"border-top-left-radius:6px;\n"
"border-bottom-left-radius:6px;\n"
"\n"
"font-size: 14px;\n"
"font-family: Microsoft YaHei;\n"
"font-weight: 400;\n"
"color: #5786C7;"));

        horizontalLayout->addWidget(PB_Ok);

        PB_Close = new QPushButton(Quantity_manager);
        PB_Close->setObjectName(QStringLiteral("PB_Close"));
        PB_Close->setStyleSheet(QLatin1String("background: #EDF8FF;\n"
"border: 1px solid #CFDDEF;\n"
"border-top-left-radius:6px;\n"
"border-bottom-left-radius:6px;\n"
"\n"
"font-size: 14px;\n"
"font-family: Microsoft YaHei;\n"
"font-weight: 400;\n"
"color: #5786C7;"));

        horizontalLayout->addWidget(PB_Close);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Quantity_manager);

        QMetaObject::connectSlotsByName(Quantity_manager);
    } // setupUi

    void retranslateUi(QWidget *Quantity_manager)
    {
        Quantity_manager->setWindowTitle(QApplication::translate("Quantity_manager", "Quantity_manager", Q_NULLPTR));
        LB_Msg->setText(QApplication::translate("Quantity_manager", "\350\257\267\351\200\211\346\213\251\345\275\222\350\277\230\346\225\260\351\207\217\357\274\232", Q_NULLPTR));
        LB_Msg_2->setText(QApplication::translate("Quantity_manager", "\350\257\267\351\200\211\346\213\251\345\275\222\350\277\230\346\225\260\351\207\217\357\274\232", Q_NULLPTR));
        PB_Ok->setText(QApplication::translate("Quantity_manager", "\347\241\256\345\256\232", Q_NULLPTR));
        PB_Close->setText(QApplication::translate("Quantity_manager", "\345\205\263\351\227\255", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Quantity_manager: public Ui_Quantity_manager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUANTITY_MANAGER_H
