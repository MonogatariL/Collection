/********************************************************************************
** Form generated from reading UI file 'Syurui_Manager.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYURUI_MANAGER_H
#define UI_SYURUI_MANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Syurui_Manager
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QLabel *L_message;
    QHBoxLayout *horizontalLayout;
    QLabel *L_syurui_name;
    QLineEdit *LE_syurui_name;
    QPushButton *PB_add_syurui;
    QPushButton *PB_quit;

    void setupUi(QWidget *Syurui_Manager)
    {
        if (Syurui_Manager->objectName().isEmpty())
            Syurui_Manager->setObjectName(QStringLiteral("Syurui_Manager"));
        Syurui_Manager->resize(335, 417);
        Syurui_Manager->setStyleSheet(QStringLiteral(""));
        verticalLayout_2 = new QVBoxLayout(Syurui_Manager);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(Syurui_Manager);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(10, 10, 10, 10);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tableWidget = new QTableWidget(widget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setStyleSheet(QLatin1String("QTableWidget{\n"
"color:#DCDCDC;\n"
"background:#444444;\n"
"border:1px solid #242424;\n"
"alternate-background-color:#525252;\n"
"gridline-color:#242424;\n"
"}\n"
"QTableWidget::item:selected{\n"
"color:#DCDCDC;\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #484848,stop:1 #383838);\n"
"}\n"
"QTableWidget::item:hover{\n"
"background:#5B5B5B;\n"
"}\n"
"QHeaderView::section{\n"
"text-align:center;\n"
"background:#5E5E5E;\n"
"padding:3px;\n"
"margin:0px;\n"
"color:#DCDCDC;\n"
"border:1px solid #242424;\n"
"border-left-width:0;\n"
"}\n"
"QScrollBar:vertical{\n"
"background:#484848;\n"
"padding:0px;\n"
"border-radius:6px;\n"
"max-width:12px;\n"
"}\n"
"QScrollBar::handle:vertical{\n"
"background:#CCCCCC;\n"
"}\n"
"QScrollBar::handle:hover:vertical,QScrollBar::handle:pressed:vertical{\n"
"background:#A7A7A7;\n"
"}\n"
"QScrollBar::sub-page:vertical{\n"
"background:444444;\n"
"}\n"
"QScrollBar::add-page:vertical{\n"
"background:5B5B5B;\n"
"}\n"
"QScrollBar::add-line:vertical{\n"
"background:none;"
                        "\n"
"}\n"
"QScrollBar::sub-line:vertical{\n"
"background:none;\n"
"}"));

        verticalLayout->addWidget(tableWidget);

        L_message = new QLabel(widget);
        L_message->setObjectName(QStringLiteral("L_message"));
        L_message->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(L_message);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        L_syurui_name = new QLabel(widget);
        L_syurui_name->setObjectName(QStringLiteral("L_syurui_name"));
        L_syurui_name->setMinimumSize(QSize(50, 20));
        L_syurui_name->setMaximumSize(QSize(50, 20));
        L_syurui_name->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(L_syurui_name);

        LE_syurui_name = new QLineEdit(widget);
        LE_syurui_name->setObjectName(QStringLiteral("LE_syurui_name"));
        LE_syurui_name->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(LE_syurui_name);

        PB_add_syurui = new QPushButton(widget);
        PB_add_syurui->setObjectName(QStringLiteral("PB_add_syurui"));
        PB_add_syurui->setMinimumSize(QSize(70, 20));
        PB_add_syurui->setMaximumSize(QSize(70, 20));
        PB_add_syurui->setStyleSheet(QLatin1String("width: 74px;\n"
"height: 21px;\n"
"background: #F3F7FD;\n"
"border: 1px solid #92A8C6;\n"
"border-radius: 2px;\n"
"\n"
"font-size: 12px;\n"
"font-family: Microsoft YaHei;\n"
"font-weight: 400;\n"
"color: #1A1A1A;\n"
"line-height: 60px;"));

        horizontalLayout->addWidget(PB_add_syurui);

        PB_quit = new QPushButton(widget);
        PB_quit->setObjectName(QStringLiteral("PB_quit"));
        PB_quit->setMinimumSize(QSize(70, 20));
        PB_quit->setMaximumSize(QSize(70, 20));
        PB_quit->setStyleSheet(QLatin1String("width: 74px;\n"
"height: 21px;\n"
"background: #F3F7FD;\n"
"border: 1px solid #92A8C6;\n"
"border-radius: 2px;\n"
"\n"
"font-size: 12px;\n"
"font-family: Microsoft YaHei;\n"
"font-weight: 400;\n"
"color: #1A1A1A;\n"
"line-height: 60px;"));

        horizontalLayout->addWidget(PB_quit);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout);


        verticalLayout_2->addWidget(widget);


        retranslateUi(Syurui_Manager);

        QMetaObject::connectSlotsByName(Syurui_Manager);
    } // setupUi

    void retranslateUi(QWidget *Syurui_Manager)
    {
        Syurui_Manager->setWindowTitle(QApplication::translate("Syurui_Manager", "Syurui_Manager", Q_NULLPTR));
        L_message->setText(QString());
        L_syurui_name->setText(QApplication::translate("Syurui_Manager", "\347\261\273\345\220\215\357\274\232", Q_NULLPTR));
        PB_add_syurui->setText(QApplication::translate("Syurui_Manager", "\346\267\273\345\212\240\345\210\206\347\261\273", Q_NULLPTR));
        PB_quit->setText(QApplication::translate("Syurui_Manager", "\344\277\235\345\255\230\351\200\200\345\207\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Syurui_Manager: public Ui_Syurui_Manager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYURUI_MANAGER_H
