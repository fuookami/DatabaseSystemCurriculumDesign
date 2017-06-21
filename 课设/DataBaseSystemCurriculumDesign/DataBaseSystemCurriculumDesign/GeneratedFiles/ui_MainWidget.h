/********************************************************************************
** Form generated from reading UI file 'MainWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QLabel *bgi;
    QWidget *Container;
    QPushButton *AddressBtn;
    QPushButton *RecoredBtn;
    QLabel *AddressSider;
    QLabel *RecordSider;
    QPushButton *CloseBtn;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName(QStringLiteral("MainWidget"));
        MainWidget->resize(848, 480);
        bgi = new QLabel(MainWidget);
        bgi->setObjectName(QStringLiteral("bgi"));
        bgi->setGeometry(QRect(0, 0, 848, 480));
        Container = new QWidget(MainWidget);
        Container->setObjectName(QStringLiteral("Container"));
        Container->setGeometry(QRect(45, 38, 803, 442));
        AddressBtn = new QPushButton(MainWidget);
        AddressBtn->setObjectName(QStringLiteral("AddressBtn"));
        AddressBtn->setGeometry(QRect(0, 40, 45, 40));
        AddressBtn->setCursor(QCursor(Qt::PointingHandCursor));
        AddressBtn->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"	border:none;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: rgba(255, 255, 255, 0.3);\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: rgba(255, 255, 255, 0.5);\n"
"}"));
        RecoredBtn = new QPushButton(MainWidget);
        RecoredBtn->setObjectName(QStringLiteral("RecoredBtn"));
        RecoredBtn->setGeometry(QRect(0, 90, 45, 40));
        RecoredBtn->setCursor(QCursor(Qt::PointingHandCursor));
        RecoredBtn->setContextMenuPolicy(Qt::DefaultContextMenu);
        RecoredBtn->setAutoFillBackground(false);
        RecoredBtn->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"	border:none;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: rgba(255, 255, 255, 0.3);\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: rgba(255, 255, 255, 0.5);\n"
"}"));
        RecoredBtn->setAutoRepeat(false);
        RecoredBtn->setAutoExclusive(false);
        RecoredBtn->setFlat(false);
        AddressSider = new QLabel(MainWidget);
        AddressSider->setObjectName(QStringLiteral("AddressSider"));
        AddressSider->setGeometry(QRect(0, 45, 5, 30));
        RecordSider = new QLabel(MainWidget);
        RecordSider->setObjectName(QStringLiteral("RecordSider"));
        RecordSider->setGeometry(QRect(0, 95, 5, 30));
        CloseBtn = new QPushButton(MainWidget);
        CloseBtn->setObjectName(QStringLiteral("CloseBtn"));
        CloseBtn->setGeometry(QRect(824, 8, 15, 15));
        CloseBtn->setCursor(QCursor(Qt::PointingHandCursor));
        CloseBtn->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);"));
        Container->raise();
        bgi->raise();
        AddressBtn->raise();
        RecoredBtn->raise();
        AddressSider->raise();
        RecordSider->raise();
        CloseBtn->raise();

        retranslateUi(MainWidget);

        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QApplication::translate("MainWidget", "MainWidget", Q_NULLPTR));
        bgi->setText(QString());
        AddressBtn->setText(QString());
        RecoredBtn->setText(QString());
        AddressSider->setText(QString());
        RecordSider->setText(QString());
        CloseBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
