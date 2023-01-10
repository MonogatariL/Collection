/********************************************************************************
** Form generated from reading UI file 'QtGuiApplication1.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTGUIAPPLICATION1_H
#define UI_QTGUIAPPLICATION1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtGuiApplication1Class
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QTreeView *TreeV_syurui;
    QTreeView *TreeV_libary;
    QTableWidget *TableW_book;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_5;
    QLabel *L_current_honndana;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QWidget *widget;

    void setupUi(QWidget *QtGuiApplication1Class)
    {
        if (QtGuiApplication1Class->objectName().isEmpty())
            QtGuiApplication1Class->setObjectName(QStringLiteral("QtGuiApplication1Class"));
        QtGuiApplication1Class->resize(1000, 500);
        verticalLayout = new QVBoxLayout(QtGuiApplication1Class);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        TreeV_syurui = new QTreeView(QtGuiApplication1Class);
        TreeV_syurui->setObjectName(QStringLiteral("TreeV_syurui"));
        TreeV_syurui->setEnabled(true);
        TreeV_syurui->setMinimumSize(QSize(150, 250));
        TreeV_syurui->setMaximumSize(QSize(150, 16777215));
        TreeV_syurui->setStyleSheet(QLatin1String("background: #F3F7FD;\n"
"border: 1px solid #CEDDEE;"));

        horizontalLayout_2->addWidget(TreeV_syurui);

        TreeV_libary = new QTreeView(QtGuiApplication1Class);
        TreeV_libary->setObjectName(QStringLiteral("TreeV_libary"));
        TreeV_libary->setMinimumSize(QSize(300, 250));
        TreeV_libary->setStyleSheet(QLatin1String("background: #F3F7FD;\n"
"border: 1px solid #CEDDEE;"));

        horizontalLayout_2->addWidget(TreeV_libary);

        TableW_book = new QTableWidget(QtGuiApplication1Class);
        TableW_book->setObjectName(QStringLiteral("TableW_book"));
        TableW_book->setMinimumSize(QSize(500, 250));

        horizontalLayout_2->addWidget(TableW_book);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_5 = new QPushButton(QtGuiApplication1Class);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setStyleSheet(QLatin1String("width: 120px;\n"
"height: 28px;\n"
"background: #FFFFFF;\n"
"border-radius: 4px;\n"
"font-size: 12px;\n"
"font-family: Microsoft YaHei;\n"
"font-weight: 400;\n"
"color: #000000;\n"
"line-height: 60px;"));

        horizontalLayout->addWidget(pushButton_5);

        L_current_honndana = new QLabel(QtGuiApplication1Class);
        L_current_honndana->setObjectName(QStringLiteral("L_current_honndana"));

        horizontalLayout->addWidget(L_current_honndana);

        pushButton = new QPushButton(QtGuiApplication1Class);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setStyleSheet(QLatin1String("width: 120px;\n"
"height: 28px;\n"
"background: #7470BC;\n"
"border-radius: 4px;\n"
"font-size: 12px;\n"
"font-family: Microsoft YaHei;\n"
"font-weight: 400;\n"
"color: #FEFEFE;\n"
"line-height: 60px;"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(QtGuiApplication1Class);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setStyleSheet(QLatin1String("width: 120px;\n"
"height: 28px;\n"
"background: #286DB5;\n"
"border-radius: 4px;\n"
"font-size: 12px;\n"
"font-family: Microsoft YaHei;\n"
"font-weight: 400;\n"
"color: #FEFEFE;\n"
"line-height: 60px;"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton_4 = new QPushButton(QtGuiApplication1Class);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setStyleSheet(QLatin1String("width: 120px;\n"
"height: 28px;\n"
"background: #31B880;\n"
"border-radius: 4px;\n"
"font-size: 12px;\n"
"font-family: Microsoft YaHei;\n"
"font-weight: 400;\n"
"color: #FEFEFE;\n"
"line-height: 60px;"));

        horizontalLayout->addWidget(pushButton_4);

        pushButton_3 = new QPushButton(QtGuiApplication1Class);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setStyleSheet(QLatin1String("width: 120px;\n"
"height: 28px;\n"
"background: #E0463E;\n"
"border-radius: 4px;\n"
"font-size: 12px;\n"
"font-family: Microsoft YaHei;\n"
"font-weight: 400;\n"
"color: #FEFEFE;\n"
"line-height: 60px;"));

        horizontalLayout->addWidget(pushButton_3);


        verticalLayout->addLayout(horizontalLayout);

        widget = new QWidget(QtGuiApplication1Class);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(950, 200));

        verticalLayout->addWidget(widget);


        retranslateUi(QtGuiApplication1Class);

        QMetaObject::connectSlotsByName(QtGuiApplication1Class);
    } // setupUi

    void retranslateUi(QWidget *QtGuiApplication1Class)
    {
        QtGuiApplication1Class->setWindowTitle(QApplication::translate("QtGuiApplication1Class", "QtGuiApplication1", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("QtGuiApplication1Class", "PushButton", Q_NULLPTR));
        L_current_honndana->setText(QApplication::translate("QtGuiApplication1Class", "\345\275\223\345\211\215\357\274\232", Q_NULLPTR));
        pushButton->setText(QApplication::translate("QtGuiApplication1Class", "PushButton", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("QtGuiApplication1Class", "PushButton", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("QtGuiApplication1Class", "PushButton", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("QtGuiApplication1Class", "PushButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtGuiApplication1Class: public Ui_QtGuiApplication1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTGUIAPPLICATION1_H
