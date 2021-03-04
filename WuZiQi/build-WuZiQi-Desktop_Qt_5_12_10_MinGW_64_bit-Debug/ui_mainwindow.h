/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *New_Game;
    QAction *skin1;
    QAction *skin2;
    QAction *skin3;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *Change_Theme;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        New_Game = new QAction(MainWindow);
        New_Game->setObjectName(QString::fromUtf8("New_Game"));
        skin1 = new QAction(MainWindow);
        skin1->setObjectName(QString::fromUtf8("skin1"));
        skin2 = new QAction(MainWindow);
        skin2->setObjectName(QString::fromUtf8("skin2"));
        skin3 = new QAction(MainWindow);
        skin3->setObjectName(QString::fromUtf8("skin3"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        Change_Theme = new QMenu(menu);
        Change_Theme->setObjectName(QString::fromUtf8("Change_Theme"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(New_Game);
        menu->addAction(Change_Theme->menuAction());
        Change_Theme->addAction(skin1);
        Change_Theme->addAction(skin2);
        Change_Theme->addAction(skin3);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        New_Game->setText(QApplication::translate("MainWindow", "New Game", nullptr));
        skin1->setText(QApplication::translate("MainWindow", "\345\216\237\347\211\210", nullptr));
        skin2->setText(QApplication::translate("MainWindow", "DIO.VS.\347\251\272\346\235\241\346\211\277\345\244\252\351\203\216", nullptr));
        skin3->setText(QApplication::translate("MainWindow", "\345\220\211\345\205\213.VS.\345\210\251\345\250\201", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\351\200\211\351\241\271", nullptr));
        Change_Theme->setTitle(QApplication::translate("MainWindow", "Change Theme", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
