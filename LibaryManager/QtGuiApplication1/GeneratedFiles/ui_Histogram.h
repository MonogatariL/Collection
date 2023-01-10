/********************************************************************************
** Form generated from reading UI file 'Histogram.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTOGRAM_H
#define UI_HISTOGRAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Histogram
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;

    void setupUi(QDialog *Histogram)
    {
        if (Histogram->objectName().isEmpty())
            Histogram->setObjectName(QStringLiteral("Histogram"));
        Histogram->resize(400, 300);
        gridLayout = new QGridLayout(Histogram);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));

        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(Histogram);

        QMetaObject::connectSlotsByName(Histogram);
    } // setupUi

    void retranslateUi(QDialog *Histogram)
    {
        Histogram->setWindowTitle(QApplication::translate("Histogram", "Histogram", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Histogram: public Ui_Histogram {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTOGRAM_H
