/********************************************************************************
** Form generated from reading UI file 'RecordInfoBtn.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECORDINFOBTN_H
#define UI_RECORDINFOBTN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RecordInfoBtn
{
public:
    QLabel *PhoneNumber;
    QLabel *TimeLocal;

    void setupUi(QWidget *RecordInfoBtn)
    {
        if (RecordInfoBtn->objectName().isEmpty())
            RecordInfoBtn->setObjectName(QStringLiteral("RecordInfoBtn"));
        RecordInfoBtn->resize(293, 57);
        PhoneNumber = new QLabel(RecordInfoBtn);
        PhoneNumber->setObjectName(QStringLiteral("PhoneNumber"));
        PhoneNumber->setGeometry(QRect(10, 10, 273, 25));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font.setPointSize(14);
        PhoneNumber->setFont(font);
        TimeLocal = new QLabel(RecordInfoBtn);
        TimeLocal->setObjectName(QStringLiteral("TimeLocal"));
        TimeLocal->setGeometry(QRect(10, 35, 273, 12));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font1.setPointSize(9);
        TimeLocal->setFont(font1);

        retranslateUi(RecordInfoBtn);

        QMetaObject::connectSlotsByName(RecordInfoBtn);
    } // setupUi

    void retranslateUi(QWidget *RecordInfoBtn)
    {
        RecordInfoBtn->setWindowTitle(QApplication::translate("RecordInfoBtn", "RecordInfoBtn", Q_NULLPTR));
        PhoneNumber->setText(QString());
        TimeLocal->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class RecordInfoBtn: public Ui_RecordInfoBtn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORDINFOBTN_H
