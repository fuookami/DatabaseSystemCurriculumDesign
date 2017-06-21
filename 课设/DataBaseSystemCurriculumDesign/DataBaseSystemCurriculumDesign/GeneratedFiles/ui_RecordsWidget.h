/********************************************************************************
** Form generated from reading UI file 'RecordsWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECORDSWIDGET_H
#define UI_RECORDSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RecordsWidget
{
public:

    void setupUi(QWidget *RecordsWidget)
    {
        if (RecordsWidget->objectName().isEmpty())
            RecordsWidget->setObjectName(QStringLiteral("RecordsWidget"));
        RecordsWidget->resize(400, 300);

        retranslateUi(RecordsWidget);

        QMetaObject::connectSlotsByName(RecordsWidget);
    } // setupUi

    void retranslateUi(QWidget *RecordsWidget)
    {
        RecordsWidget->setWindowTitle(QApplication::translate("RecordsWidget", "RecordsWidget", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RecordsWidget: public Ui_RecordsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORDSWIDGET_H
