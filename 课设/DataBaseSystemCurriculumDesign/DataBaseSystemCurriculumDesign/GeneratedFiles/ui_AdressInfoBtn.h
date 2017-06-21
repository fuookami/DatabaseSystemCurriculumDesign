/********************************************************************************
** Form generated from reading UI file 'AdressInfoBtn.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADRESSINFOBTN_H
#define UI_ADRESSINFOBTN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdressInfoBtn
{
public:
    QLabel *NameRemark;
    QLabel *UnitIndentity;

    void setupUi(QWidget *AdressInfoBtn)
    {
        if (AdressInfoBtn->objectName().isEmpty())
            AdressInfoBtn->setObjectName(QStringLiteral("AdressInfoBtn"));
        AdressInfoBtn->resize(293, 57);
        NameRemark = new QLabel(AdressInfoBtn);
        NameRemark->setObjectName(QStringLiteral("NameRemark"));
        NameRemark->setGeometry(QRect(10, 10, 273, 25));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font.setPointSize(18);
        NameRemark->setFont(font);
        UnitIndentity = new QLabel(AdressInfoBtn);
        UnitIndentity->setObjectName(QStringLiteral("UnitIndentity"));
        UnitIndentity->setGeometry(QRect(10, 35, 273, 12));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font1.setPointSize(9);
        UnitIndentity->setFont(font1);

        retranslateUi(AdressInfoBtn);

        QMetaObject::connectSlotsByName(AdressInfoBtn);
    } // setupUi

    void retranslateUi(QWidget *AdressInfoBtn)
    {
        AdressInfoBtn->setWindowTitle(QApplication::translate("AdressInfoBtn", "AdressInfoBtn", Q_NULLPTR));
        NameRemark->setText(QString());
        UnitIndentity->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AdressInfoBtn: public Ui_AdressInfoBtn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADRESSINFOBTN_H
