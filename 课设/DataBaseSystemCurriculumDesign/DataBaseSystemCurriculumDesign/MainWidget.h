#pragma once

#include "ui_MainWidget.h"
#include <QtWidgets/QMainWindow>
#include <QtCore/QString>
#include <QtGui/QPixmap>
#include <QPropertyAnimation>
#include <QEasingCurve>

class MainWidget : public QMainWindow
{
	Q_OBJECT;

public:
	MainWidget(QWidget *parent = nullptr);
	~MainWidget();

private slots:
	void closeSlot(void);

private:
	static const unsigned int winHeight;
	static const unsigned int winWidth;
	static const QString MainWidgetBgiFilePath;

	QPropertyAnimation *winFadeIn;
	QPixmap *bgiPix;

	Ui::MainWidget *ui;

private slots:
	void winFadeInOver();
};