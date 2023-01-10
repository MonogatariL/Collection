/********************************************************************************
** Form generated from reading UI file 'Book_Manager.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOK_MANAGER_H
#define UI_BOOK_MANAGER_H

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
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Book_Manager
{
public:
    QHBoxLayout *horizontalLayout_11;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_10;
    QTableWidget *TableW_book;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *LE_Book_Name;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *LE_Book_Author;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QSpinBox *SB_Price;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpinBox *SB_Book_Num;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QSpinBox *SB_Time;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QComboBox *CB_Book_Syurui;
    QLabel *L_message;
    QPushButton *PB_Add_Book;
    QPushButton *PB_Back;

    void setupUi(QWidget *Book_Manager)
    {
        if (Book_Manager->objectName().isEmpty())
            Book_Manager->setObjectName(QStringLiteral("Book_Manager"));
        Book_Manager->resize(1111, 300);
        horizontalLayout_11 = new QHBoxLayout(Book_Manager);
        horizontalLayout_11->setSpacing(0);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(Book_Manager);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout_10 = new QHBoxLayout(widget);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        TableW_book = new QTableWidget(widget);
        TableW_book->setObjectName(QStringLiteral("TableW_book"));
        TableW_book->setMinimumSize(QSize(600, 250));
        TableW_book->setStyleSheet(QLatin1String("QTableWidget{\n"
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

        horizontalLayout_10->addWidget(TableW_book);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 60, -1, -1);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(40, 20));
        label->setMaximumSize(QSize(40, 20));
        QFont font;
        font.setFamily(QStringLiteral("Axure Handwriting"));
        font.setPointSize(11);
        font.setBold(false);
        font.setWeight(50);
        label->setFont(font);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(label);

        LE_Book_Name = new QLineEdit(widget);
        LE_Book_Name->setObjectName(QStringLiteral("LE_Book_Name"));

        horizontalLayout->addWidget(LE_Book_Name);


        horizontalLayout_6->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(40, 20));
        label_2->setMaximumSize(QSize(40, 20));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_2);

        LE_Book_Author = new QLineEdit(widget);
        LE_Book_Author->setObjectName(QStringLiteral("LE_Book_Author"));

        horizontalLayout_2->addWidget(LE_Book_Author);


        horizontalLayout_6->addLayout(horizontalLayout_2);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(40, 20));
        label_6->setMaximumSize(QSize(40, 20));
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_7->addWidget(label_6);

        SB_Price = new QSpinBox(widget);
        SB_Price->setObjectName(QStringLiteral("SB_Price"));
        SB_Price->setMaximum(2147483647);
        SB_Price->setValue(30);

        horizontalLayout_7->addWidget(SB_Price);


        horizontalLayout_8->addLayout(horizontalLayout_7);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(40, 20));
        label_3->setMaximumSize(QSize(40, 20));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_3);

        SB_Book_Num = new QSpinBox(widget);
        SB_Book_Num->setObjectName(QStringLiteral("SB_Book_Num"));
        SB_Book_Num->setMaximum(2147483647);
        SB_Book_Num->setValue(10);

        horizontalLayout_3->addWidget(SB_Book_Num);


        horizontalLayout_8->addLayout(horizontalLayout_3);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(70, 20));
        label_5->setMaximumSize(QSize(70, 20));
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label_5);

        SB_Time = new QSpinBox(widget);
        SB_Time->setObjectName(QStringLiteral("SB_Time"));
        SB_Time->setMinimum(0);
        SB_Time->setMaximum(2025);
        SB_Time->setValue(2000);

        horizontalLayout_5->addWidget(SB_Time);


        horizontalLayout_9->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(40, 20));
        label_4->setMaximumSize(QSize(40, 20));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_4);

        CB_Book_Syurui = new QComboBox(widget);
        CB_Book_Syurui->setObjectName(QStringLiteral("CB_Book_Syurui"));

        horizontalLayout_4->addWidget(CB_Book_Syurui);


        horizontalLayout_9->addLayout(horizontalLayout_4);


        verticalLayout->addLayout(horizontalLayout_9);


        verticalLayout_2->addLayout(verticalLayout);

        L_message = new QLabel(widget);
        L_message->setObjectName(QStringLiteral("L_message"));
        L_message->setMinimumSize(QSize(0, 20));
        L_message->setMaximumSize(QSize(16777215, 20));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221 Light"));
        font1.setPointSize(14);
        L_message->setFont(font1);
        L_message->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(L_message);

        PB_Add_Book = new QPushButton(widget);
        PB_Add_Book->setObjectName(QStringLiteral("PB_Add_Book"));
        PB_Add_Book->setStyleSheet(QLatin1String("width: 74px;\n"
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

        verticalLayout_2->addWidget(PB_Add_Book);

        PB_Back = new QPushButton(widget);
        PB_Back->setObjectName(QStringLiteral("PB_Back"));
        PB_Back->setStyleSheet(QLatin1String("width: 74px;\n"
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

        verticalLayout_2->addWidget(PB_Back);


        horizontalLayout_10->addLayout(verticalLayout_2);

        horizontalLayout_10->setStretch(0, 3);
        horizontalLayout_10->setStretch(1, 1);

        horizontalLayout_11->addWidget(widget);


        retranslateUi(Book_Manager);

        QMetaObject::connectSlotsByName(Book_Manager);
    } // setupUi

    void retranslateUi(QWidget *Book_Manager)
    {
        Book_Manager->setWindowTitle(QApplication::translate("Book_Manager", "Book_Manager", Q_NULLPTR));
        label->setText(QApplication::translate("Book_Manager", "\344\271\246\345\220\215:", Q_NULLPTR));
        label_2->setText(QApplication::translate("Book_Manager", "\344\275\234\350\200\205:", Q_NULLPTR));
        label_6->setText(QApplication::translate("Book_Manager", "\344\273\267\346\240\274:", Q_NULLPTR));
        label_3->setText(QApplication::translate("Book_Manager", "\346\225\260\351\207\217:", Q_NULLPTR));
        label_5->setText(QApplication::translate("Book_Manager", "\345\217\221\350\241\214\346\227\245(\345\271\264):", Q_NULLPTR));
        label_4->setText(QApplication::translate("Book_Manager", "\345\210\206\347\261\273:", Q_NULLPTR));
        L_message->setText(QString());
        PB_Add_Book->setText(QApplication::translate("Book_Manager", "\346\267\273\345\212\240\344\271\246\347\261\215", Q_NULLPTR));
        PB_Back->setText(QApplication::translate("Book_Manager", "\350\277\224\345\233\236\344\270\212\344\270\200\345\261\202", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Book_Manager: public Ui_Book_Manager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOK_MANAGER_H
