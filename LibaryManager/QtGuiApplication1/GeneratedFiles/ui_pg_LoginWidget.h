/********************************************************************************
** Form generated from reading UI file 'pg_LoginWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PG_LOGINWIDGET_H
#define UI_PG_LOGINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pg_LoginWidget
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_2;
    QWidget *widget_center;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_AppIcon;
    QFrame *line;
    QLabel *label_AppName;
    QWidget *widget_Right;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_AppHello;
    QPushButton *pB_onlineMode;
    QPushButton *pB_onlineAnalyzeMode;
    QPushButton *pB_offlineTestMode;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *pg_LoginWidget)
    {
        if (pg_LoginWidget->objectName().isEmpty())
            pg_LoginWidget->setObjectName(QStringLiteral("pg_LoginWidget"));
        pg_LoginWidget->resize(876, 556);
        gridLayout = new QGridLayout(pg_LoginWidget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);

        widget_center = new QWidget(pg_LoginWidget);
        widget_center->setObjectName(QStringLiteral("widget_center"));
        widget_center->setMinimumSize(QSize(846, 526));
        widget_center->setMaximumSize(QSize(846, 526));
        widget_center->setStyleSheet(QLatin1String("#widget_center\n"
"{\n"
"	border-image:url(./Resources/LoginResource/bg2.png) ;\n"
"}\n"
"\n"
""));
        horizontalLayout_2 = new QHBoxLayout(widget_center);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(98, 0, 74, -1);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(70, 125, 73, 24);
        label_AppIcon = new QLabel(widget_center);
        label_AppIcon->setObjectName(QStringLiteral("label_AppIcon"));
        label_AppIcon->setStyleSheet(QStringLiteral(""));
        label_AppIcon->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_AppIcon);


        verticalLayout->addLayout(horizontalLayout);

        line = new QFrame(widget_center);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        label_AppName = new QLabel(widget_center);
        label_AppName->setObjectName(QStringLiteral("label_AppName"));
        label_AppName->setStyleSheet(QLatin1String("font-size: 24px;\n"
"font-family: Microsoft YaHei;\n"
"font-weight: bold;\n"
"color: #1A1A1A;\n"
"line-height: 16px;"));
        label_AppName->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        verticalLayout->addWidget(label_AppName);


        horizontalLayout_2->addLayout(verticalLayout);

        widget_Right = new QWidget(widget_center);
        widget_Right->setObjectName(QStringLiteral("widget_Right"));
        widget_Right->setStyleSheet(QLatin1String("#widget_Right\n"
"{\n"
"\n"
"}"));
        horizontalLayout_4 = new QHBoxLayout(widget_Right);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(29);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(50, 50, 65, 85);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_AppHello = new QLabel(widget_Right);
        label_AppHello->setObjectName(QStringLiteral("label_AppHello"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_AppHello->sizePolicy().hasHeightForWidth());
        label_AppHello->setSizePolicy(sizePolicy);
        label_AppHello->setMinimumSize(QSize(115, 23));
        label_AppHello->setMaximumSize(QSize(115, 23));
        label_AppHello->setStyleSheet(QString::fromUtf8("#label_AppHello\n"
"{\n"
"    border-image:url(./Resources/LoginResource/\346\254\242\350\277\216\350\277\233\345\205\245.png) ;\n"
"}"));
        label_AppHello->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_AppHello);


        verticalLayout_2->addLayout(horizontalLayout_3);

        pB_onlineMode = new QPushButton(widget_Right);
        pB_onlineMode->setObjectName(QStringLiteral("pB_onlineMode"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pB_onlineMode->sizePolicy().hasHeightForWidth());
        pB_onlineMode->setSizePolicy(sizePolicy1);
        pB_onlineMode->setMinimumSize(QSize(297, 80));
        pB_onlineMode->setStyleSheet(QLatin1String("QPushButton#pB_onlineMode\n"
"{\n"
"    border-image:url(./Resources/LoginResource/onlineDefault.png) ;\n"
"	font-size: 20px;\n"
"	font-family: Microsoft YaHei;\n"
"	font-weight: 400;\n"
"	color: #1A1A1A;\n"
"	line-height: 32px;\n"
"}\n"
"\n"
"QPushButton#pB_onlineMode:hover\n"
"{\n"
"    border-image:url(./Resources/LoginResource/onlineDefault.png) ;\n"
"	font-size: 20px;\n"
"	font-family: Microsoft YaHei;\n"
"	font-weight: 400;\n"
"	color: #2C84CA;\n"
"	line-height: 32px;\n"
"}\n"
"\n"
"QPushButton#pB_onlineMode:pressed\n"
"{\n"
"    border-image:url(./Resources/LoginResource/onlineDown.png) ;\n"
"	font-size: 20px;\n"
"	font-family: Microsoft YaHei;\n"
"	font-weight: 400;\n"
"	color: #2C84CA;\n"
"	line-height: 32px;\n"
"}"));

        verticalLayout_2->addWidget(pB_onlineMode);

        pB_onlineAnalyzeMode = new QPushButton(widget_Right);
        pB_onlineAnalyzeMode->setObjectName(QStringLiteral("pB_onlineAnalyzeMode"));
        sizePolicy1.setHeightForWidth(pB_onlineAnalyzeMode->sizePolicy().hasHeightForWidth());
        pB_onlineAnalyzeMode->setSizePolicy(sizePolicy1);
        pB_onlineAnalyzeMode->setMinimumSize(QSize(297, 80));
        pB_onlineAnalyzeMode->setStyleSheet(QLatin1String("QPushButton#pB_onlineAnalyzeMode\n"
"{\n"
"    border-image:url(./Resources/LoginResource/onlineAnalyzeDefault.png) ;\n"
"	font-size: 20px;\n"
"	font-family: Microsoft YaHei;\n"
"	font-weight: 400;\n"
"	color: #1A1A1A;\n"
"	line-height: 32px;\n"
"}\n"
"\n"
"QPushButton#pB_onlineAnalyzeMode:hover\n"
"{\n"
"    border-image:url(./Resources/LoginResource/onlineAnalyzeDefault.png) ;\n"
"	font-size: 20px;\n"
"	font-family: Microsoft YaHei;\n"
"	font-weight: 400;\n"
"	color: #47A777;\n"
"	line-height: 32px;\n"
"}\n"
"\n"
"QPushButton#pB_onlineAnalyzeMode:pressed\n"
"{\n"
"    border-image:url(./Resources/LoginResource/onlineAnalyzeDown.png) ;\n"
"	font-size: 20px;\n"
"	font-family: Microsoft YaHei;\n"
"	font-weight: 400;\n"
"	color: #47A777;\n"
"	line-height: 32px;\n"
"}"));

        verticalLayout_2->addWidget(pB_onlineAnalyzeMode);

        pB_offlineTestMode = new QPushButton(widget_Right);
        pB_offlineTestMode->setObjectName(QStringLiteral("pB_offlineTestMode"));
        pB_offlineTestMode->setMinimumSize(QSize(297, 80));
        pB_offlineTestMode->setStyleSheet(QLatin1String("QPushButton#pB_offlineTestMode\n"
"{\n"
"    border-image:url(./Resources/LoginResource/offLineTestDefault.png) ;\n"
"	font-size: 20px;\n"
"	font-family: Microsoft YaHei;\n"
"	font-weight: 400;\n"
"	color: #1A1A1A;\n"
"	line-height: 32px;\n"
"}\n"
"\n"
"QPushButton#pB_offlineTestMode:hover\n"
"{\n"
"    border-image:url(./Resources/LoginResource/offLineTestDefault.png) ;\n"
"	font-size: 20px;\n"
"	font-family: Microsoft YaHei;\n"
"	font-weight: 400;\n"
"	color: #D99B17;\n"
"	line-height: 32px;\n"
"}\n"
"\n"
"QPushButton#pB_offlineTestMode:pressed\n"
"{\n"
"    border-image:url(./Resources/LoginResource/offLineTestDown.png) ;\n"
"	font-size: 20px;\n"
"	font-family: Microsoft YaHei;\n"
"	font-weight: 400;\n"
"	color: #D99B17;\n"
"	line-height: 32px;\n"
"}"));

        verticalLayout_2->addWidget(pB_offlineTestMode);


        horizontalLayout_4->addLayout(verticalLayout_2);


        horizontalLayout_2->addWidget(widget_Right);


        gridLayout->addWidget(widget_center, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);


        retranslateUi(pg_LoginWidget);

        QMetaObject::connectSlotsByName(pg_LoginWidget);
    } // setupUi

    void retranslateUi(QWidget *pg_LoginWidget)
    {
        pg_LoginWidget->setWindowTitle(QApplication::translate("pg_LoginWidget", "pg_LoginWidget", Q_NULLPTR));
        label_AppIcon->setText(QString());
        label_AppName->setText(QApplication::translate("pg_LoginWidget", "TextLabel", Q_NULLPTR));
        label_AppHello->setText(QString());
        pB_onlineMode->setText(QApplication::translate("pg_LoginWidget", "PushButton", Q_NULLPTR));
        pB_onlineAnalyzeMode->setText(QApplication::translate("pg_LoginWidget", "PushButton", Q_NULLPTR));
        pB_offlineTestMode->setText(QApplication::translate("pg_LoginWidget", "PushButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class pg_LoginWidget: public Ui_pg_LoginWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PG_LOGINWIDGET_H
