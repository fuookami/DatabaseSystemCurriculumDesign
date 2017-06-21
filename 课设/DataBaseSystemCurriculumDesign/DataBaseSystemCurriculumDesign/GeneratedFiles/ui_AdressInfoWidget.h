/********************************************************************************
** Form generated from reading UI file 'AdressInfoWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADRESSINFOWIDGET_H
#define UI_ADRESSINFOWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdressInfoWidget
{
public:

    void setupUi(QWidget *AdressInfoWidget)
    {
        if (AdressInfoWidget->objectName().isEmpty())
            AdressInfoWidget->setObjectName(QStringLiteral("AdressInfoWidget"));
        AdressInfoWidget->resize(400, 300);

        retranslateUi(AdressInfoWidget);

        QMetaObject::connectSlotsByName(AdressInfoWidget);
    } // setupUi

    void retranslateUi(QWidget *AdressInfoWidget)
    {
        AdressInfoWidget->setWindowTitle(QApplication::translate("AdressInfoWidget", "AdressInfoWidget", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AdressInfoWidget: public Ui_AdressInfoWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADRESSINFOWIDGET_H
