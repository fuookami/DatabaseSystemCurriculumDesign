/********************************************************************************
** Form generated from reading UI file 'LoaderWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADERWIDGET_H
#define UI_LOADERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Loader
{
public:
    QWidget *centralwidget;
    QLabel *bgi;
    QLabel *LoadingMsg;

    void setupUi(QMainWindow *Loader)
    {
        if (Loader->objectName().isEmpty())
            Loader->setObjectName(QStringLiteral("Loader"));
        Loader->resize(438, 269);
        Loader->setMinimumSize(QSize(438, 269));
        Loader->setMaximumSize(QSize(438, 269));
        centralwidget = new QWidget(Loader);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        bgi = new QLabel(centralwidget);
        bgi->setObjectName(QStringLiteral("bgi"));
        bgi->setGeometry(QRect(0, 0, 438, 269));
        bgi->setMinimumSize(QSize(0, 0));
        bgi->setMaximumSize(QSize(1752, 1076));
        LoadingMsg = new QLabel(centralwidget);
        LoadingMsg->setObjectName(QStringLiteral("LoadingMsg"));
        LoadingMsg->setGeometry(QRect(10, 220, 421, 41));
        QFont font;
        font.setPointSize(16);
        LoadingMsg->setFont(font);
        LoadingMsg->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        Loader->setCentralWidget(centralwidget);

        retranslateUi(Loader);

        QMetaObject::connectSlotsByName(Loader);
    } // setupUi

    void retranslateUi(QMainWindow *Loader)
    {
        Loader->setWindowTitle(QApplication::translate("Loader", "Loader", Q_NULLPTR));
        bgi->setText(QString());
        LoadingMsg->setText(QApplication::translate("Loader", "\345\212\240\350\275\275\344\270\255\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Loader: public Ui_Loader {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADERWIDGET_H
