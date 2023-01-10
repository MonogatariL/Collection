/********************************************************************************
** Form generated from reading UI file 'console.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONSOLE_H
#define UI_CONSOLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "borrowed_manager.h"
#include "page_preview.h"
#include "user_manager.h"

QT_BEGIN_NAMESPACE

class Ui_console
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QPushButton *PB_library;
    QPushButton *PB_record;
    QPushButton *PB_user;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QHBoxLayout *horizontalLayout;
    page_preview *page1_preview;
    QWidget *page_2;
    QGridLayout *gridLayout_2;
    Borrowed_Manager *widget;
    QWidget *page_3;
    QGridLayout *gridLayout_3;
    User_Manager *widget_2;

    void setupUi(QWidget *console)
    {
        if (console->objectName().isEmpty())
            console->setObjectName(QStringLiteral("console"));
        console->resize(807, 900);
        console->setMinimumSize(QSize(800, 750));
        console->setStyleSheet(QLatin1String("#console\n"
"{\n"
"    border-image: url(:/page_preview/Resources/BackGround2.png);\n"
"}"));
        verticalLayout = new QVBoxLayout(console);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_3 = new QWidget(console);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMinimumSize(QSize(800, 750));
        verticalLayout_2 = new QVBoxLayout(widget_3);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(widget_3);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QLatin1String("font-size: 16px;\n"
"font-family: Microsoft YaHei;"));

        horizontalLayout_2->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        PB_library = new QPushButton(widget_3);
        PB_library->setObjectName(QStringLiteral("PB_library"));
        PB_library->setStyleSheet(QLatin1String("width: 120px;\n"
"height: 28px;\n"
"background: #E0463E;\n"
"border-radius: 4px;\n"
"font-size: 12px;\n"
"font-family: Microsoft YaHei;\n"
"font-weight: 400;\n"
"color: #FEFEFE;\n"
"line-height: 60px;"));

        horizontalLayout_2->addWidget(PB_library);

        PB_record = new QPushButton(widget_3);
        PB_record->setObjectName(QStringLiteral("PB_record"));
        PB_record->setStyleSheet(QLatin1String("width: 120px;\n"
"height: 28px;\n"
"background: #286DB5;\n"
"border-radius: 4px;\n"
"font-size: 12px;\n"
"font-family: Microsoft YaHei;\n"
"font-weight: 400;\n"
"color: #FEFEFE;\n"
"line-height: 60px;"));

        horizontalLayout_2->addWidget(PB_record);

        PB_user = new QPushButton(widget_3);
        PB_user->setObjectName(QStringLiteral("PB_user"));
        PB_user->setStyleSheet(QLatin1String("QPushButton#PB_user\n"
"{\n"
"width: 120px;\n"
"height: 28px;\n"
"background: #31B880;\n"
"border-radius: 4px;\n"
"font-size: 12px;\n"
"font-family: Microsoft YaHei;\n"
"font-weight: 400;\n"
"color: #FEFEFE;\n"
"line-height: 60px;\n"
"}\n"
"QPushButton#PB_user:hover\n"
"{\n"
"width: 120px;\n"
"height: 28px;\n"
"background: #31B880;\n"
"border-radius: 4px;\n"
"font-size: 12px;\n"
"font-family: Microsoft YaHei;\n"
"font-weight: 400;\n"
"color: #000000;\n"
"line-height: 60px;\n"
"}\n"
"\n"
"QPushButton#PB_user:pressed\n"
"{\n"
"width: 120px;\n"
"height: 28px;\n"
"background: #31B880;\n"
"border-radius: 4px;\n"
"font-size: 12px;\n"
"font-family: Microsoft YaHei;\n"
"font-weight: 400;\n"
"color: #FEFEFE;\n"
"line-height: 60px;\n"
"}"));

        horizontalLayout_2->addWidget(PB_user);


        verticalLayout_2->addLayout(horizontalLayout_2);

        stackedWidget = new QStackedWidget(widget_3);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setMinimumSize(QSize(770, 700));
        stackedWidget->setStyleSheet(QStringLiteral(""));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setStyleSheet(QStringLiteral(""));
        horizontalLayout = new QHBoxLayout(page);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        page1_preview = new page_preview(page);
        page1_preview->setObjectName(QStringLiteral("page1_preview"));
        page1_preview->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(page1_preview);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        page_2->setStyleSheet(QStringLiteral(""));
        gridLayout_2 = new QGridLayout(page_2);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        widget = new Borrowed_Manager(page_2);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setStyleSheet(QStringLiteral(""));

        gridLayout_2->addWidget(widget, 0, 0, 1, 1);

        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        gridLayout_3 = new QGridLayout(page_3);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        widget_2 = new User_Manager(page_3);
        widget_2->setObjectName(QStringLiteral("widget_2"));

        gridLayout_3->addWidget(widget_2, 0, 0, 1, 1);

        stackedWidget->addWidget(page_3);

        verticalLayout_2->addWidget(stackedWidget);


        verticalLayout->addWidget(widget_3);


        retranslateUi(console);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(console);
    } // setupUi

    void retranslateUi(QWidget *console)
    {
        console->setWindowTitle(QApplication::translate("console", "console", Q_NULLPTR));
        label->setText(QApplication::translate("console", "\346\254\242\350\277\216\344\275\240", Q_NULLPTR));
        PB_library->setText(QApplication::translate("console", "\345\233\276\344\271\246\347\256\241\347\220\206", Q_NULLPTR));
        PB_record->setText(QApplication::translate("console", "(\345\200\237\351\230\205/\345\275\222\350\277\230)\350\256\260\345\275\225", Q_NULLPTR));
        PB_user->setText(QApplication::translate("console", "\347\224\250\346\210\267\345\210\227\350\241\250", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class console: public Ui_console {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONSOLE_H
