/********************************************************************************
** Form generated from reading UI file 'RecordInfoWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECORDINFOWIDGET_H
#define UI_RECORDINFOWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RecordInfoWidget
{
public:
    QLabel *PhoneNumber;
    QLabel *TimeLocal;

    void setupUi(QWidget *RecordInfoWidget)
    {
        if (RecordInfoWidget->objectName().isEmpty())
            RecordInfoWidget->setObjectName(QStringLiteral("RecordInfoWidget"));
        RecordInfoWidget->resize(293, 57);
        PhoneNumber = new QLabel(RecordInfoWidget);
        PhoneNumber->setObjectName(QStringLiteral("PhoneNumber"));
        PhoneNumber->setGeometry(QRect(10, 10, 273, 25));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font.setPointSize(18);
        PhoneNumber->setFont(font);
        TimeLocal = new QLabel(RecordInfoWidget);
        TimeLocal->setObjectName(QStringLiteral("TimeLocal"));
        TimeLocal->setGeometry(QRect(10, 35, 273, 12));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font1.setPointSize(9);
        TimeLocal->setFont(font1);

        retranslateUi(RecordInfoWidget);

        QMetaObject::connectSlotsByName(RecordInfoWidget);
    } // setupUi

    void retranslateUi(QWidget *RecordInfoWidget)
    {
        RecordInfoWidget->setWindowTitle(QApplication::translate("RecordInfoWidget", "RecordInfoWidget", Q_NULLPTR));
        PhoneNumber->setText(QString());
        TimeLocal->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class RecordInfoWidget: public Ui_RecordInfoWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORDINFOWIDGET_H
