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
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RecordsWidget
{
public:
    QLabel *SiderBgi;
    QScrollArea *Container;
    QWidget *scrollAreaWidgetContents_2;
    QLabel *Title;
    QScrollArea *InfoContainer;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QWidget *RecordsWidget)
    {
        if (RecordsWidget->objectName().isEmpty())
            RecordsWidget->setObjectName(QStringLiteral("RecordsWidget"));
        RecordsWidget->resize(803, 442);
        SiderBgi = new QLabel(RecordsWidget);
        SiderBgi->setObjectName(QStringLiteral("SiderBgi"));
        SiderBgi->setGeometry(QRect(2, 0, 310, 442));
        SiderBgi->setAutoFillBackground(true);
        SiderBgi->setStyleSheet(QStringLiteral("background-color: rgb(204, 204, 204);"));
        Container = new QScrollArea(RecordsWidget);
        Container->setObjectName(QStringLiteral("Container"));
        Container->setGeometry(QRect(312, 0, 493, 442));
        Container->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        Container->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 491, 440));
        Container->setWidget(scrollAreaWidgetContents_2);
        Title = new QLabel(RecordsWidget);
        Title->setObjectName(QStringLiteral("Title"));
        Title->setGeometry(QRect(12, 10, 151, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font.setPointSize(28);
        Title->setFont(font);
        InfoContainer = new QScrollArea(RecordsWidget);
        InfoContainer->setObjectName(QStringLiteral("InfoContainer"));
        InfoContainer->setGeometry(QRect(10, 60, 293, 382));
        InfoContainer->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"border: none;"));
        InfoContainer->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        InfoContainer->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 293, 382));
        InfoContainer->setWidget(scrollAreaWidgetContents);

        retranslateUi(RecordsWidget);

        QMetaObject::connectSlotsByName(RecordsWidget);
    } // setupUi

    void retranslateUi(QWidget *RecordsWidget)
    {
        RecordsWidget->setWindowTitle(QApplication::translate("RecordsWidget", "RecordsWidget", Q_NULLPTR));
        SiderBgi->setText(QString());
        Title->setText(QApplication::translate("RecordsWidget", "\351\200\232\350\257\235\350\256\260\345\275\225", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RecordsWidget: public Ui_RecordsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORDSWIDGET_H
