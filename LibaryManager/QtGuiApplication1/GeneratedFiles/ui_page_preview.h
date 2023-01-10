/********************************************************************************
** Form generated from reading UI file 'page_preview.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGE_PREVIEW_H
#define UI_PAGE_PREVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_page_previewClass
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *Top;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_9;
    QLineEdit *LE1;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_10;
    QLineEdit *LE2;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_11;
    QLineEdit *LE3;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_12;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_18;
    QCheckBox *checkBox;
    QHBoxLayout *Down;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_16;
    QSpinBox *SP1;
    QFrame *line_2;
    QSpinBox *SP2;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_15;
    QSpinBox *SP3;
    QFrame *line;
    QSpinBox *SP4;
    QPushButton *PB_search;
    QPushButton *PB_clean;
    QLabel *Label_Src_Msg;
    QHBoxLayout *horizontalLayout_2;
    QTableWidget *TableW_book;
    QHBoxLayout *horizontalLayout;
    QLabel *L_current_honndana;
    QSpacerItem *horizontalSpacer;
    QPushButton *PB_syurui_manager;
    QPushButton *PB_book_manager;
    QHBoxLayout *horizontalLayout_5;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label;
    QLabel *LB1;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_3;
    QLabel *LB2;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_5;
    QLabel *LB3;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_7;
    QLabel *LB4;
    QSpacerItem *horizontalSpacer_5;
    QTableWidget *TableW_book2;

    void setupUi(QWidget *page_previewClass)
    {
        if (page_previewClass->objectName().isEmpty())
            page_previewClass->setObjectName(QStringLiteral("page_previewClass"));
        page_previewClass->resize(764, 810);
        page_previewClass->setStyleSheet(QLatin1String("#page_previewClass\n"
"{\n"
"    border-image: url(:/page_preview/Resources/BackGround2.png);\n"
"}"));
        verticalLayout = new QVBoxLayout(page_previewClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(page_previewClass);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(0, 100));
        widget_2->setStyleSheet(QLatin1String("#widget_2\n"
"{\n"
"    border-image: url(:/page_preview/Resources/BackGround2.png);\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(widget_2);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(-1, 0, -1, 0);
        Top = new QHBoxLayout();
        Top->setSpacing(6);
        Top->setObjectName(QStringLiteral("Top"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_9 = new QLabel(widget_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        QFont font;
        font.setFamily(QStringLiteral("Microsoft YaHei"));
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        label_9->setFont(font);

        horizontalLayout_10->addWidget(label_9);

        LE1 = new QLineEdit(widget_2);
        LE1->setObjectName(QStringLiteral("LE1"));

        horizontalLayout_10->addWidget(LE1);


        Top->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_10 = new QLabel(widget_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font);

        horizontalLayout_11->addWidget(label_10);

        LE2 = new QLineEdit(widget_2);
        LE2->setObjectName(QStringLiteral("LE2"));

        horizontalLayout_11->addWidget(LE2);


        Top->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_11 = new QLabel(widget_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font);

        horizontalLayout_12->addWidget(label_11);

        LE3 = new QLineEdit(widget_2);
        LE3->setObjectName(QStringLiteral("LE3"));

        horizontalLayout_12->addWidget(LE3);


        Top->addLayout(horizontalLayout_12);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        label_12 = new QLabel(widget_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setMaximumSize(QSize(30, 16777215));
        label_12->setFont(font);

        horizontalLayout_16->addWidget(label_12);

        comboBox = new QComboBox(widget_2);
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

        horizontalLayout_16->addWidget(comboBox);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        checkBox = new QCheckBox(widget_2);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setMinimumSize(QSize(120, 0));
        checkBox->setMaximumSize(QSize(120, 16777215));
        checkBox->setStyleSheet(QLatin1String("font-size: 12px;\n"
"font-family: Microsoft YaHei;"));

        horizontalLayout_18->addWidget(checkBox);


        horizontalLayout_16->addLayout(horizontalLayout_18);


        Top->addLayout(horizontalLayout_16);


        verticalLayout_3->addLayout(Top);

        Down = new QHBoxLayout();
        Down->setSpacing(6);
        Down->setObjectName(QStringLiteral("Down"));
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        label_16 = new QLabel(widget_2);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setMinimumSize(QSize(40, 0));
        label_16->setMaximumSize(QSize(40, 16777215));
        label_16->setFont(font);

        horizontalLayout_15->addWidget(label_16);

        SP1 = new QSpinBox(widget_2);
        SP1->setObjectName(QStringLiteral("SP1"));
        SP1->setMinimumSize(QSize(0, 0));
        SP1->setStyleSheet(QLatin1String("\n"
"border: 1px solid #CFDDEF;\n"
"border-top-left-radius:6px;\n"
"border-bottom-left-radius:6px;\n"
"\n"
"font-size: 14px;\n"
"font-family: Microsoft YaHei;\n"
"font-weight: 400;\n"
"color: #5786C7;"));
        SP1->setMaximum(4396);

        horizontalLayout_15->addWidget(SP1);

        line_2 = new QFrame(widget_2);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setMinimumSize(QSize(10, 0));
        line_2->setMaximumSize(QSize(10, 16777215));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_15->addWidget(line_2);

        SP2 = new QSpinBox(widget_2);
        SP2->setObjectName(QStringLiteral("SP2"));
        SP2->setStyleSheet(QLatin1String("\n"
"border: 1px solid #CFDDEF;\n"
"border-top-left-radius:6px;\n"
"border-bottom-left-radius:6px;\n"
"\n"
"font-size: 14px;\n"
"font-family: Microsoft YaHei;\n"
"font-weight: 400;\n"
"color: #5786C7;"));
        SP2->setMinimum(-4);
        SP2->setMaximum(4396);
        SP2->setValue(4396);

        horizontalLayout_15->addWidget(SP2);


        Down->addLayout(horizontalLayout_15);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label_15 = new QLabel(widget_2);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setMinimumSize(QSize(50, 0));
        label_15->setMaximumSize(QSize(50, 16777215));
        label_15->setFont(font);

        horizontalLayout_13->addWidget(label_15);

        SP3 = new QSpinBox(widget_2);
        SP3->setObjectName(QStringLiteral("SP3"));
        SP3->setMinimumSize(QSize(0, 0));
        SP3->setStyleSheet(QLatin1String("\n"
"border: 1px solid #CFDDEF;\n"
"border-top-left-radius:6px;\n"
"border-bottom-left-radius:6px;\n"
"\n"
"font-size: 14px;\n"
"font-family: Microsoft YaHei;\n"
"font-weight: 400;\n"
"color: #5786C7;"));
        SP3->setMinimum(0);
        SP3->setMaximum(2025);
        SP3->setValue(0);

        horizontalLayout_13->addWidget(SP3);

        line = new QFrame(widget_2);
        line->setObjectName(QStringLiteral("line"));
        line->setMinimumSize(QSize(10, 0));
        line->setMaximumSize(QSize(10, 16777215));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_13->addWidget(line);

        SP4 = new QSpinBox(widget_2);
        SP4->setObjectName(QStringLiteral("SP4"));
        SP4->setStyleSheet(QLatin1String("\n"
"border: 1px solid #CFDDEF;\n"
"border-top-left-radius:6px;\n"
"border-bottom-left-radius:6px;\n"
"\n"
"font-size: 14px;\n"
"font-family: Microsoft YaHei;\n"
"font-weight: 400;\n"
"color: #5786C7;"));
        SP4->setMinimum(1800);
        SP4->setMaximum(2025);
        SP4->setValue(2025);

        horizontalLayout_13->addWidget(SP4);

        horizontalLayout_13->setStretch(1, 1);
        horizontalLayout_13->setStretch(3, 1);

        Down->addLayout(horizontalLayout_13);

        PB_search = new QPushButton(widget_2);
        PB_search->setObjectName(QStringLiteral("PB_search"));
        QFont font1;
        font1.setFamily(QStringLiteral("Microsoft YaHei"));
        font1.setBold(false);
        font1.setWeight(50);
        PB_search->setFont(font1);
        PB_search->setStyleSheet(QLatin1String("background: #EDF8FF;\n"
"border: 1px solid #CFDDEF;\n"
"border-top-left-radius:6px;\n"
"border-bottom-left-radius:6px;\n"
"\n"
"font-size: 14px;\n"
"font-family: Microsoft YaHei;\n"
"font-weight: 400;\n"
"color: #5786C7;"));

        Down->addWidget(PB_search);

        PB_clean = new QPushButton(widget_2);
        PB_clean->setObjectName(QStringLiteral("PB_clean"));
        PB_clean->setFont(font1);
        PB_clean->setStyleSheet(QLatin1String("background: #EDF8FF;\n"
"border: 1px solid #CFDDEF;\n"
"border-top-left-radius:6px;\n"
"border-bottom-left-radius:6px;\n"
"\n"
"font-size: 14px;\n"
"font-family: Microsoft YaHei;\n"
"font-weight: 400;\n"
"color: #5786C7;"));

        Down->addWidget(PB_clean);

        Down->setStretch(0, 2);
        Down->setStretch(1, 2);
        Down->setStretch(2, 1);
        Down->setStretch(3, 1);

        verticalLayout_3->addLayout(Down);

        Label_Src_Msg = new QLabel(widget_2);
        Label_Src_Msg->setObjectName(QStringLiteral("Label_Src_Msg"));
        Label_Src_Msg->setMaximumSize(QSize(16777215, 20));
        QFont font2;
        font2.setFamily(QStringLiteral("Microsoft YaHei"));
        font2.setPointSize(15);
        Label_Src_Msg->setFont(font2);
        Label_Src_Msg->setStyleSheet(QStringLiteral(""));
        Label_Src_Msg->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(Label_Src_Msg);


        verticalLayout->addWidget(widget_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        TableW_book = new QTableWidget(page_previewClass);
        TableW_book->setObjectName(QStringLiteral("TableW_book"));
        TableW_book->setMinimumSize(QSize(600, 250));
        TableW_book->setStyleSheet(QStringLiteral("border-image: url(:/page_preview/Resources/BackGround4.png);"));
        TableW_book->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        TableW_book->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

        horizontalLayout_2->addWidget(TableW_book);

        horizontalLayout_2->setStretch(0, 600);

        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        L_current_honndana = new QLabel(page_previewClass);
        L_current_honndana->setObjectName(QStringLiteral("L_current_honndana"));
        L_current_honndana->setMinimumSize(QSize(100, 0));
        L_current_honndana->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(L_current_honndana);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        PB_syurui_manager = new QPushButton(page_previewClass);
        PB_syurui_manager->setObjectName(QStringLiteral("PB_syurui_manager"));
        PB_syurui_manager->setStyleSheet(QLatin1String("width: 120px;\n"
"height: 28px;\n"
"background: #06d2ff;\n"
"border-radius: 4px;\n"
"font-size: 12px;\n"
"font-family: Microsoft YaHei;\n"
"font-weight: 400;\n"
"color: #ffffff;\n"
"line-height: 60px;\n"
"\n"
""));

        horizontalLayout->addWidget(PB_syurui_manager);

        PB_book_manager = new QPushButton(page_previewClass);
        PB_book_manager->setObjectName(QStringLiteral("PB_book_manager"));
        PB_book_manager->setStyleSheet(QLatin1String("width: 120px;\n"
"height: 28px;\n"
"background: #7470BC;\n"
"border-radius: 4px;\n"
"font-size: 12px;\n"
"font-family: Microsoft YaHei;\n"
"font-weight: 400;\n"
"color: #FEFEFE;\n"
"line-height: 60px;"));

        horizontalLayout->addWidget(PB_book_manager);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        widget = new QWidget(page_previewClass);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setStyleSheet(QLatin1String("#widget\n"
"{\n"
"    border-image: url(:/page_preview/Resources/BackGround2.png);\n"
"}"));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(70, 30));
        label->setMaximumSize(QSize(70, 30));
        label->setStyleSheet(QLatin1String("	font-size: 14px;\n"
"	font-family: Microsoft YaHei;"));

        horizontalLayout_6->addWidget(label);

        LB1 = new QLabel(widget);
        LB1->setObjectName(QStringLiteral("LB1"));
        LB1->setMinimumSize(QSize(70, 30));
        LB1->setMaximumSize(QSize(70, 30));
        LB1->setStyleSheet(QLatin1String("	font-size: 18px;\n"
"	font-family: Microsoft YaHei;\n"
"color: rgb(85, 170, 0);"));
        LB1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(LB1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(70, 30));
        label_3->setMaximumSize(QSize(70, 30));
        label_3->setStyleSheet(QLatin1String("	font-size: 14px;\n"
"	font-family: Microsoft YaHei;"));

        horizontalLayout_7->addWidget(label_3);

        LB2 = new QLabel(widget);
        LB2->setObjectName(QStringLiteral("LB2"));
        LB2->setMinimumSize(QSize(70, 30));
        LB2->setMaximumSize(QSize(70, 30));
        LB2->setStyleSheet(QLatin1String("	font-size: 18px;\n"
"	font-family: Microsoft YaHei;\n"
"color: rgb(85, 170, 0);"));
        LB2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_7->addWidget(LB2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(70, 30));
        label_5->setMaximumSize(QSize(70, 30));
        label_5->setStyleSheet(QLatin1String("	font-size: 14px;\n"
"	font-family: Microsoft YaHei;"));

        horizontalLayout_8->addWidget(label_5);

        LB3 = new QLabel(widget);
        LB3->setObjectName(QStringLiteral("LB3"));
        LB3->setMinimumSize(QSize(70, 30));
        LB3->setMaximumSize(QSize(70, 30));
        LB3->setStyleSheet(QLatin1String("	font-size: 18px;\n"
"	font-family: Microsoft YaHei;\n"
"color: rgb(85, 170, 0);"));
        LB3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_8->addWidget(LB3);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_7 = new QLabel(widget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMinimumSize(QSize(70, 30));
        label_7->setMaximumSize(QSize(70, 30));
        label_7->setStyleSheet(QLatin1String("	font-size: 14px;\n"
"	font-family: Microsoft YaHei;"));

        horizontalLayout_9->addWidget(label_7);

        LB4 = new QLabel(widget);
        LB4->setObjectName(QStringLiteral("LB4"));
        LB4->setMinimumSize(QSize(70, 30));
        LB4->setMaximumSize(QSize(70, 30));
        LB4->setStyleSheet(QLatin1String("	font-size: 18px;\n"
"	font-family: Microsoft YaHei;\n"
"color: rgb(85, 170, 0);"));
        LB4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_9->addWidget(LB4);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_5);


        verticalLayout_2->addLayout(horizontalLayout_9);


        horizontalLayout_3->addLayout(verticalLayout_2);

        TableW_book2 = new QTableWidget(widget);
        TableW_book2->setObjectName(QStringLiteral("TableW_book2"));
        TableW_book2->setMinimumSize(QSize(600, 100));
        TableW_book2->setStyleSheet(QStringLiteral(""));
        TableW_book2->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        TableW_book2->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);

        horizontalLayout_3->addWidget(TableW_book2);


        horizontalLayout_5->addWidget(widget);

        horizontalLayout_5->setStretch(0, 100);

        verticalLayout->addLayout(horizontalLayout_5);

        verticalLayout->setStretch(1, 500);
        verticalLayout->setStretch(3, 300);

        retranslateUi(page_previewClass);

        QMetaObject::connectSlotsByName(page_previewClass);
    } // setupUi

    void retranslateUi(QWidget *page_previewClass)
    {
        page_previewClass->setWindowTitle(QApplication::translate("page_previewClass", "page_preview", Q_NULLPTR));
        label_9->setText(QApplication::translate("page_previewClass", "\344\271\246\345\220\215", Q_NULLPTR));
        label_10->setText(QApplication::translate("page_previewClass", "\344\275\234\350\200\205", Q_NULLPTR));
        label_11->setText(QApplication::translate("page_previewClass", "\345\207\272\347\211\210\347\244\276", Q_NULLPTR));
        label_12->setText(QApplication::translate("page_previewClass", "\345\210\206\347\261\273", Q_NULLPTR));
        checkBox->setText(QApplication::translate("page_previewClass", "\344\273\205\346\230\276\347\244\272\346\234\211\344\275\231\344\271\246\347\261\215", Q_NULLPTR));
        label_16->setText(QApplication::translate("page_previewClass", "\344\273\267\346\240\274", Q_NULLPTR));
        label_15->setText(QApplication::translate("page_previewClass", "\345\207\272\347\211\210\346\227\245", Q_NULLPTR));
        PB_search->setText(QApplication::translate("page_previewClass", "\346\237\245\350\257\242", Q_NULLPTR));
        PB_clean->setText(QApplication::translate("page_previewClass", "\346\270\205\347\251\272", Q_NULLPTR));
        Label_Src_Msg->setText(QString());
        L_current_honndana->setText(QApplication::translate("page_previewClass", "\345\275\223\345\211\215\357\274\232", Q_NULLPTR));
        PB_syurui_manager->setText(QApplication::translate("page_previewClass", "\345\210\206\347\261\273\347\256\241\347\220\206", Q_NULLPTR));
        PB_book_manager->setText(QApplication::translate("page_previewClass", "\344\271\246\347\261\215\347\256\241\347\220\206", Q_NULLPTR));
        label->setText(QApplication::translate("page_previewClass", "\344\271\246\347\261\215\346\200\273\346\225\260\357\274\232", Q_NULLPTR));
        LB1->setText(QApplication::translate("page_previewClass", "10\347\247\215", Q_NULLPTR));
        label_3->setText(QApplication::translate("page_previewClass", "\345\210\206\347\261\273\346\200\273\346\225\260\357\274\232", Q_NULLPTR));
        LB2->setText(QApplication::translate("page_previewClass", "4396\347\247\215", Q_NULLPTR));
        label_5->setText(QApplication::translate("page_previewClass", "\345\272\223\345\255\230\346\200\273\346\225\260:", Q_NULLPTR));
        LB3->setText(QApplication::translate("page_previewClass", "1000\346\234\254", Q_NULLPTR));
        label_7->setText(QApplication::translate("page_previewClass", "\347\247\237\350\265\201\346\200\273\346\225\260\357\274\232", Q_NULLPTR));
        LB4->setText(QApplication::translate("page_previewClass", "10\346\234\254", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class page_previewClass: public Ui_page_previewClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGE_PREVIEW_H
