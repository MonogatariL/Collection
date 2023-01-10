/********************************************************************************
** Form generated from reading UI file 'Login.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *LE1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *LE2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *LE3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QComboBox *comboBox;
    QLabel *LE_Msg;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *PB_Login;
    QPushButton *PB_Back;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(305, 326);
        Login->setStyleSheet(QStringLiteral(""));
        verticalLayout_2 = new QVBoxLayout(Login);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(Login);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(15);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QStringLiteral("Microsoft YaHei"));
        font.setBold(false);
        font.setWeight(50);
        label->setFont(font);
        label->setStyleSheet(QLatin1String("\n"
"\n"
"font-size: 18px;\n"
"font-family: Microsoft YaHei;\n"
"font-weight: 400;\n"
"color: #5786C7;"));

        horizontalLayout->addWidget(label);

        LE1 = new QLineEdit(widget);
        LE1->setObjectName(QStringLiteral("LE1"));

        horizontalLayout->addWidget(LE1);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);
        label_2->setStyleSheet(QLatin1String("\n"
"\n"
"font-size: 18px;\n"
"font-family: Microsoft YaHei;\n"
"font-weight: 400;\n"
"color: #5786C7;"));

        horizontalLayout_2->addWidget(label_2);

        LE2 = new QLineEdit(widget);
        LE2->setObjectName(QStringLiteral("LE2"));

        horizontalLayout_2->addWidget(LE2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);
        label_4->setStyleSheet(QLatin1String("\n"
"\n"
"font-size: 18px;\n"
"font-family: Microsoft YaHei;\n"
"font-weight: 400;\n"
"color: #5786C7;"));

        horizontalLayout_4->addWidget(label_4);

        LE3 = new QLineEdit(widget);
        LE3->setObjectName(QStringLiteral("LE3"));

        horizontalLayout_4->addWidget(LE3);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);
        label_5->setStyleSheet(QLatin1String("\n"
"\n"
"font-size: 18px;\n"
"font-family: Microsoft YaHei;\n"
"font-weight: 400;\n"
"color: #5786C7;"));

        horizontalLayout_5->addWidget(label_5);

        comboBox = new QComboBox(widget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setStyleSheet(QLatin1String("background: #EDF8FF;\n"
"border: 1px solid #CFDDEF;\n"
"border-top-left-radius:6px;\n"
"border-bottom-left-radius:6px;\n"
"\n"
"font-size: 14px;\n"
"font-family: Microsoft YaHei;\n"
"font-weight: 400;\n"
"color: #5786C7;"));

        horizontalLayout_5->addWidget(comboBox);


        verticalLayout->addLayout(horizontalLayout_5);

        LE_Msg = new QLabel(widget);
        LE_Msg->setObjectName(QStringLiteral("LE_Msg"));
        LE_Msg->setFont(font);
        LE_Msg->setStyleSheet(QLatin1String("\n"
"\n"
"font-size: 18px;\n"
"font-family: Microsoft YaHei;\n"
"font-weight: 400;\n"
"color: #5786C7;"));
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


        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Login", Q_NULLPTR));
        label->setText(QApplication::translate("Login", "\345\255\246\345\217\267\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("Login", "\345\247\223\345\220\215\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("Login", "\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("Login", "\346\235\203\351\231\220\357\274\232", Q_NULLPTR));
        LE_Msg->setText(QString());
        PB_Login->setText(QApplication::translate("Login", "\346\263\250\345\206\214\344\277\241\346\201\257", Q_NULLPTR));
        PB_Back->setText(QApplication::translate("Login", "\350\277\224\345\233\236", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
