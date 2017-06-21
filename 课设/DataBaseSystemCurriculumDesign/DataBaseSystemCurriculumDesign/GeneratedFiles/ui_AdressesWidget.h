/********************************************************************************
** Form generated from reading UI file 'AdressesWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADRESSESWIDGET_H
#define UI_ADRESSESWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdressesWidget
{
public:

    void setupUi(QWidget *AdressesWidget)
    {
        if (AdressesWidget->objectName().isEmpty())
            AdressesWidget->setObjectName(QStringLiteral("AdressesWidget"));
        AdressesWidget->resize(400, 300);

        retranslateUi(AdressesWidget);

        QMetaObject::connectSlotsByName(AdressesWidget);
    } // setupUi

    void retranslateUi(QWidget *AdressesWidget)
    {
        AdressesWidget->setWindowTitle(QApplication::translate("AdressesWidget", "AdressesWidget", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AdressesWidget: public Ui_AdressesWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADRESSESWIDGET_H
