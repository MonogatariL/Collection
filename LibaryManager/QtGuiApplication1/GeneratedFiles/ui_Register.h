/********************************************************************************
** Form generated from reading UI file 'Register.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *LE1;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *LE2;
    QLabel *LE_Msg;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *PB_Login;
    QPushButton *PB_Back;

    void setupUi(QWidget *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName(QStringLiteral("Register"));
        Register->resize(276, 269);
        Register->setStyleSheet(QLatin1String("#Register\n"
"{\n"
"border-image: url(:/page_preview/Resources/BackGround2.png);\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(Register);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(Register);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(30, 30, 30, 20);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QStringLiteral("Microsoft YaHei"));
        font.setPointSize(15);
        font.setBold(false);
        font.setWeight(50);
        label->setFont(font);
        label->setStyleSheet(QLatin1String("\n"
"\n"
"font-family: Microsoft YaHei;\n"
"font-weight: 400;\n"
"color: #5786C7;"));

        horizontalLayout->addWidget(label);

        LE1 = new QLineEdit(widget);
        LE1->setObjectName(QStringLiteral("LE1"));

        horizontalLayout->addWidget(LE1);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);
        label_4->setStyleSheet(QLatin1String("\n"
"\n"
"font-family: Microsoft YaHei;\n"
"font-weight: 400;\n"
"color: #5786C7;"));

        horizontalLayout_4->addWidget(label_4);

        LE2 = new QLineEdit(widget);
        LE2->setObjectName(QStringLiteral("LE2"));

        horizontalLayout_4->addWidget(LE2);


        verticalLayout->addLayout(horizontalLayout_4);

        LE_Msg = new QLabel(widget);
        LE_Msg->setObjectName(QStringLiteral("LE_Msg"));
        QFont font1;
        font1.setFamily(QStringLiteral("Microsoft YaHei"));
        font1.setPointSize(13);
        LE_Msg->setFont(font1);
        LE_Msg->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(LE_Msg);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        PB_Login = new QPushButton(widget);
        PB_Login->setObjectName(QStringLiteral("PB_Login"));
        PB_Login->setStyleSheet(QLatin1String("background: #EDF8FF;\n"
"border: 1px solid #CFDDEF;\n"
"border-top-left-radius:6px;\n"
"border-bottom-left-radius:6px;\n"
"\n"
"font-size: 14px;\n"
"font-family: Microsoft YaHei;\n"
"font-weight: 400;\n"
"color: #5786C7;"));

        horizontalLayout_3->addWidget(PB_Login);

        PB_Back = new QPushButton(widget);
        PB_Back->setObjectName(QStringLiteral("PB_Back"));
        PB_Back->setStyleSheet(QLatin1String("background: #EDF8FF;\n"
"border: 1px solid #CFDDEF;\n"
"border-top-left-radius:6px;\n"
"border-bottom-left-radius:6px;\n"
"\n"
"font-size: 14px;\n"
"font-family: Microsoft YaHei;\n"
"font-weight: 400;\n"
"color: #5786C7;"));

        horizontalLayout_3->addWidget(PB_Back);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addWidget(widget);


        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QWidget *Register)
    {
        Register->setWindowTitle(QApplication::translate("Register", "Register", Q_NULLPTR));
        label->setText(QApplication::translate("Register", "\345\255\246\345\217\267\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("Register", "\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        LE_Msg->setText(QString());
        PB_Login->setText(QApplication::translate("Register", "\347\231\273\345\275\225", Q_NULLPTR));
        PB_Back->setText(QApplication::translate("Register", "\350\277\224\345\233\236", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
