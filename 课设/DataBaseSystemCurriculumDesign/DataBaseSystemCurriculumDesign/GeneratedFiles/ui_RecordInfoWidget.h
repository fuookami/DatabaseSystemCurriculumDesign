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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RecordInfoWidget
{
public:

    void setupUi(QWidget *RecordInfoWidget)
    {
        if (RecordInfoWidget->objectName().isEmpty())
            RecordInfoWidget->setObjectName(QStringLiteral("RecordInfoWidget"));
        RecordInfoWidget->resize(400, 300);

        retranslateUi(RecordInfoWidget);

        QMetaObject::connectSlotsByName(RecordInfoWidget);
    } // setupUi

    void retranslateUi(QWidget *RecordInfoWidget)
    {
        RecordInfoWidget->setWindowTitle(QApplication::translate("RecordInfoWidget", "RecordInfoWidget", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RecordInfoWidget: public Ui_RecordInfoWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORDINFOWIDGET_H
