/********************************************************************************
** Form generated from reading UI file 'tetris.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TETRIS_H
#define UI_TETRIS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tetris
{
public:
    QAction *actionNew_Game;
    QAction *New_Game;
    QAction *Shadow_Block;
    QAction *actionClassic;
    QAction *actionMonogatari;
    QAction *Classic;
    QAction *Monogatari;
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *Change_theme;

    void setupUi(QMainWindow *Tetris)
    {
        if (Tetris->objectName().isEmpty())
            Tetris->setObjectName(QString::fromUtf8("Tetris"));
        Tetris->resize(900, 900);
        actionNew_Game = new QAction(Tetris);
        actionNew_Game->setObjectName(QString::fromUtf8("actionNew_Game"));
        New_Game = new QAction(Tetris);
        New_Game->setObjectName(QString::fromUtf8("New_Game"));
        Shadow_Block = new QAction(Tetris);
        Shadow_Block->setObjectName(QString::fromUtf8("Shadow_Block"));
        actionClassic = new QAction(Tetris);
        actionClassic->setObjectName(QString::fromUtf8("actionClassic"));
        actionMonogatari = new QAction(Tetris);
        actionMonogatari->setObjectName(QString::fromUtf8("actionMonogatari"));
        Classic = new QAction(Tetris);
        Classic->setObjectName(QString::fromUtf8("Classic"));
        Monogatari = new QAction(Tetris);
        Monogatari->setObjectName(QString::fromUtf8("Monogatari"));
        centralwidget = new QWidget(Tetris);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 800, 501, 71));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(21);
        label->setFont(font);
        label->setLineWidth(9);
        label->setMidLineWidth(5);

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        horizontalLayout->addWidget(label_2);

        Tetris->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(Tetris);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 900, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        Change_theme = new QMenu(menu);
        Change_theme->setObjectName(QString::fromUtf8("Change_theme"));
        Tetris->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(New_Game);
        menu->addAction(Shadow_Block);
        menu->addAction(Change_theme->menuAction());
        Change_theme->addAction(Classic);
        Change_theme->addAction(Monogatari);

        retranslateUi(Tetris);

        QMetaObject::connectSlotsByName(Tetris);
    } // setupUi

    void retranslateUi(QMainWindow *Tetris)
    {
        Tetris->setWindowTitle(QApplication::translate("Tetris", "Tetris", nullptr));
        actionNew_Game->setText(QApplication::translate("Tetris", "New_Game", nullptr));
        New_Game->setText(QApplication::translate("Tetris", "New_Game", nullptr));
        Shadow_Block->setText(QApplication::translate("Tetris", "Shadow_Block", nullptr));
        actionClassic->setText(QApplication::translate("Tetris", "Classic", nullptr));
        actionMonogatari->setText(QApplication::translate("Tetris", "Monogatari", nullptr));
        Classic->setText(QApplication::translate("Tetris", "Classic", nullptr));
        Monogatari->setText(QApplication::translate("Tetris", "Monogatari", nullptr));
        label->setText(QApplication::translate("Tetris", "dsa f ", nullptr));
        label_2->setText(QApplication::translate("Tetris", "d adf ad ", nullptr));
        menu->setTitle(QApplication::translate("Tetris", "\351\200\211\351\241\271", nullptr));
        Change_theme->setTitle(QApplication::translate("Tetris", "Change_theme", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tetris: public Ui_Tetris {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TETRIS_H
