/********************************************************************************
** Form generated from reading UI file 'AdressDetailInput.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADRESSDETAILINPUT_H
#define UI_ADRESSDETAILINPUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdressDetailInput
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *Name;
    QLabel *label;
    QLabel *label_6;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_7;
    QLineEdit *Mobile2;
    QLineEdit *Telephone;
    QLabel *label_8;
    QLineEdit *Identity;
    QLineEdit *Remark;
    QLabel *label_9;
    QLabel *label_10;
    QLineEdit *Mobile1;
    QLineEdit *Unit;
    QLineEdit *Email;
    QHBoxLayout *horizontalLayout;
    QPushButton *Upload;
    QPushButton *Cancel;

    void setupUi(QWidget *AdressDetailInput)
    {
        if (AdressDetailInput->objectName().isEmpty())
            AdressDetailInput->setObjectName(QStringLiteral("AdressDetailInput"));
        AdressDetailInput->resize(493, 442);
        gridLayoutWidget = new QWidget(AdressDetailInput);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 491, 281));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        Name = new QLineEdit(gridLayoutWidget);
        Name->setObjectName(QStringLiteral("Name"));
        Name->setMinimumSize(QSize(0, 20));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font.setPointSize(14);
        Name->setFont(font);

        gridLayout->addWidget(Name, 0, 1, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(50, 40));
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(50, 40));
        label_6->setFont(font);

        gridLayout->addWidget(label_6, 1, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(50, 60));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 0, 2, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(50, 30));
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 1, 2, 1, 1);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMinimumSize(QSize(50, 40));
        label_7->setFont(font);

        gridLayout->addWidget(label_7, 2, 0, 1, 1);

        Mobile2 = new QLineEdit(gridLayoutWidget);
        Mobile2->setObjectName(QStringLiteral("Mobile2"));
        Mobile2->setMinimumSize(QSize(0, 20));
        Mobile2->setFont(font);

        gridLayout->addWidget(Mobile2, 3, 3, 1, 1);

        Telephone = new QLineEdit(gridLayoutWidget);
        Telephone->setObjectName(QStringLiteral("Telephone"));
        Telephone->setMinimumSize(QSize(0, 20));
        Telephone->setFont(font);

        gridLayout->addWidget(Telephone, 4, 1, 1, 1);

        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMinimumSize(QSize(50, 40));
        label_8->setFont(font);

        gridLayout->addWidget(label_8, 3, 0, 1, 1);

        Identity = new QLineEdit(gridLayoutWidget);
        Identity->setObjectName(QStringLiteral("Identity"));
        Identity->setMinimumSize(QSize(0, 20));
        Identity->setFont(font);

        gridLayout->addWidget(Identity, 1, 3, 1, 1);

        Remark = new QLineEdit(gridLayoutWidget);
        Remark->setObjectName(QStringLiteral("Remark"));
        Remark->setMinimumSize(QSize(0, 20));
        Remark->setFont(font);

        gridLayout->addWidget(Remark, 0, 3, 1, 1);

        label_9 = new QLabel(gridLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMinimumSize(QSize(50, 30));
        label_9->setFont(font);

        gridLayout->addWidget(label_9, 3, 2, 1, 1);

        label_10 = new QLabel(gridLayoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMinimumSize(QSize(50, 40));
        label_10->setFont(font);

        gridLayout->addWidget(label_10, 4, 0, 1, 1);

        Mobile1 = new QLineEdit(gridLayoutWidget);
        Mobile1->setObjectName(QStringLiteral("Mobile1"));
        Mobile1->setMinimumSize(QSize(0, 20));
        Mobile1->setFont(font);

        gridLayout->addWidget(Mobile1, 3, 1, 1, 1);

        Unit = new QLineEdit(gridLayoutWidget);
        Unit->setObjectName(QStringLiteral("Unit"));
        Unit->setMinimumSize(QSize(0, 20));
        Unit->setFont(font);

        gridLayout->addWidget(Unit, 1, 1, 1, 1);

        Email = new QLineEdit(gridLayoutWidget);
        Email->setObjectName(QStringLiteral("Email"));
        Email->setMinimumSize(QSize(0, 20));
        Email->setFont(font);

        gridLayout->addWidget(Email, 2, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        Upload = new QPushButton(gridLayoutWidget);
        Upload->setObjectName(QStringLiteral("Upload"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font1.setPointSize(12);
        Upload->setFont(font1);
        Upload->setStyleSheet(QStringLiteral("border: 1px solid rgb(0, 0, 0);"));
        Upload->setFlat(false);

        horizontalLayout->addWidget(Upload);

        Cancel = new QPushButton(gridLayoutWidget);
        Cancel->setObjectName(QStringLiteral("Cancel"));
        Cancel->setFont(font1);
        Cancel->setStyleSheet(QStringLiteral("border: 1px solid rgb(0, 0, 0);"));

        horizontalLayout->addWidget(Cancel);


        gridLayout->addLayout(horizontalLayout, 5, 3, 1, 1);


        retranslateUi(AdressDetailInput);

        QMetaObject::connectSlotsByName(AdressDetailInput);
    } // setupUi

    void retranslateUi(QWidget *AdressDetailInput)
    {
        AdressDetailInput->setWindowTitle(QApplication::translate("AdressDetailInput", "AdressDetailInput", Q_NULLPTR));
        label->setText(QApplication::translate("AdressDetailInput", "\345\247\223\345\220\215", Q_NULLPTR));
        label_6->setText(QApplication::translate("AdressDetailInput", "\345\215\225\344\275\215", Q_NULLPTR));
        label_3->setText(QApplication::translate("AdressDetailInput", "\345\244\207\346\263\250", Q_NULLPTR));
        label_4->setText(QApplication::translate("AdressDetailInput", "\350\201\214\345\212\241", Q_NULLPTR));
        label_7->setText(QApplication::translate("AdressDetailInput", "\351\202\256\347\256\261", Q_NULLPTR));
        label_8->setText(QApplication::translate("AdressDetailInput", "\346\211\213\346\234\2721", Q_NULLPTR));
        label_9->setText(QApplication::translate("AdressDetailInput", "\346\211\213\346\234\2722", Q_NULLPTR));
        label_10->setText(QApplication::translate("AdressDetailInput", "\345\272\247\346\234\272", Q_NULLPTR));
        Upload->setText(QApplication::translate("AdressDetailInput", "\344\277\235\345\255\230", Q_NULLPTR));
        Cancel->setText(QApplication::translate("AdressDetailInput", "\346\270\205\347\251\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AdressDetailInput: public Ui_AdressDetailInput {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADRESSDETAILINPUT_H
