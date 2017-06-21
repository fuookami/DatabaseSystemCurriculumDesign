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
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdressInfoWidget
{
public:
    QLabel *NameRemark;
    QLabel *UnitIndentity;

    void setupUi(QWidget *AdressInfoWidget)
    {
        if (AdressInfoWidget->objectName().isEmpty())
            AdressInfoWidget->setObjectName(QStringLiteral("AdressInfoWidget"));
        AdressInfoWidget->resize(293, 57);
        NameRemark = new QLabel(AdressInfoWidget);
        NameRemark->setObjectName(QStringLiteral("NameRemark"));
        NameRemark->setGeometry(QRect(10, 10, 273, 25));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font.setPointSize(18);
        NameRemark->setFont(font);
        UnitIndentity = new QLabel(AdressInfoWidget);
        UnitIndentity->setObjectName(QStringLiteral("UnitIndentity"));
        UnitIndentity->setGeometry(QRect(10, 35, 273, 12));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font1.setPointSize(9);
        UnitIndentity->setFont(font1);

        retranslateUi(AdressInfoWidget);

        QMetaObject::connectSlotsByName(AdressInfoWidget);
    } // setupUi

    void retranslateUi(QWidget *AdressInfoWidget)
    {
        AdressInfoWidget->setWindowTitle(QApplication::translate("AdressInfoWidget", "AdressInfoWidget", Q_NULLPTR));
        NameRemark->setText(QString());
        UnitIndentity->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AdressInfoWidget: public Ui_AdressInfoWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADRESSINFOWIDGET_H
