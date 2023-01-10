/********************************************************************************
** Form generated from reading UI file 'charts.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARTS_H
#define UI_CHARTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_charts
{
public:

    void setupUi(QWidget *charts)
    {
        if (charts->objectName().isEmpty())
            charts->setObjectName(QStringLiteral("charts"));
        charts->resize(1261, 713);
        charts->setMinimumSize(QSize(950, 200));

        retranslateUi(charts);

        QMetaObject::connectSlotsByName(charts);
    } // setupUi

    void retranslateUi(QWidget *charts)
    {
        charts->setWindowTitle(QApplication::translate("charts", "charts", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class charts: public Ui_charts {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARTS_H
