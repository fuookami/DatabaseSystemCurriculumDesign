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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdressesWidget
{
public:
    QLabel *SiderBgi;
    QLabel *Title;
    QPushButton *AddBtn;
    QLineEdit *SearchLineEdit;
    QScrollArea *InfoContainer;
    QWidget *scrollAreaWidgetContents;
    QScrollArea *Container;
    QWidget *scrollAreaWidgetContents_2;

    void setupUi(QWidget *AdressesWidget)
    {
        if (AdressesWidget->objectName().isEmpty())
            AdressesWidget->setObjectName(QStringLiteral("AdressesWidget"));
        AdressesWidget->resize(803, 442);
        SiderBgi = new QLabel(AdressesWidget);
        SiderBgi->setObjectName(QStringLiteral("SiderBgi"));
        SiderBgi->setGeometry(QRect(0, 0, 310, 442));
        SiderBgi->setStyleSheet(QStringLiteral("background-color: rgb(204, 204, 204);"));
        Title = new QLabel(AdressesWidget);
        Title->setObjectName(QStringLiteral("Title"));
        Title->setGeometry(QRect(10, 10, 120, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font.setPointSize(28);
        Title->setFont(font);
        AddBtn = new QPushButton(AdressesWidget);
        AddBtn->setObjectName(QStringLiteral("AddBtn"));
        AddBtn->setGeometry(QRect(260, 10, 40, 40));
        QFont font1;
        font1.setFamily(QStringLiteral("Segoe UI"));
        font1.setPointSize(32);
        font1.setBold(false);
        font1.setWeight(50);
        AddBtn->setFont(font1);
        AddBtn->setCursor(QCursor(Qt::PointingHandCursor));
        AddBtn->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"	border:none;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: rgba(0, 0, 0, 0.2);\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: rgba(0, 0, 0, 0.3);\n"
"}"));
        AddBtn->setFlat(false);
        SearchLineEdit = new QLineEdit(AdressesWidget);
        SearchLineEdit->setObjectName(QStringLiteral("SearchLineEdit"));
        SearchLineEdit->setGeometry(QRect(10, 60, 290, 30));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font2.setPointSize(12);
        SearchLineEdit->setFont(font2);
        SearchLineEdit->setStyleSheet(QLatin1String("QLineEdit {\n"
"	border: 1px solid rgb(0, 0, 0);\n"
"	background-color: rgbs(255, 255, 255, 0);\n"
"}\n"
"QLineEdit:focus {\n"
"	border: 2px solid rgb(126, 132, 255);\n"
"}\n"
"QLineEdit:hover {\n"
"	border: 2px solid rgb(0, 0, 0);\n"
"}"));
        SearchLineEdit->setFrame(true);
        SearchLineEdit->setCursorPosition(0);
        SearchLineEdit->setDragEnabled(false);
        InfoContainer = new QScrollArea(AdressesWidget);
        InfoContainer->setObjectName(QStringLiteral("InfoContainer"));
        InfoContainer->setGeometry(QRect(8, 100, 293, 342));
        InfoContainer->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"border: none;"));
        InfoContainer->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        InfoContainer->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 293, 342));
        InfoContainer->setWidget(scrollAreaWidgetContents);
        Container = new QScrollArea(AdressesWidget);
        Container->setObjectName(QStringLiteral("Container"));
        Container->setGeometry(QRect(310, 0, 493, 442));
        Container->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        Container->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 491, 440));
        Container->setWidget(scrollAreaWidgetContents_2);

        retranslateUi(AdressesWidget);

        QMetaObject::connectSlotsByName(AdressesWidget);
    } // setupUi

    void retranslateUi(QWidget *AdressesWidget)
    {
        AdressesWidget->setWindowTitle(QApplication::translate("AdressesWidget", "AdressesWidget", Q_NULLPTR));
        SiderBgi->setText(QString());
        Title->setText(QApplication::translate("AdressesWidget", "\350\201\224\347\263\273\344\272\272", Q_NULLPTR));
        AddBtn->setText(QApplication::translate("AdressesWidget", "+", Q_NULLPTR));
        SearchLineEdit->setPlaceholderText(QApplication::translate("AdressesWidget", "\346\220\234\347\264\242", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AdressesWidget: public Ui_AdressesWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADRESSESWIDGET_H
