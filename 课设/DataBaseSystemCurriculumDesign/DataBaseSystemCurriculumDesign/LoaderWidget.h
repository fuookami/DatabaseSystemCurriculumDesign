#pragma once

#include <QtWidgets/QMainWindow>
#include <QtGui/QPixmap>
#include <QPropertyAnimation>
#include <QEasingCurve>

#include "ui_LoaderWidget.h"

class LoaderWidget : public QMainWindow
{
	Q_OBJECT;

public:
	LoaderWidget(QWidget *parent = nullptr);
	~LoaderWidget();

public:
	void setText(const QString &str);

private:
	static const quint32 _width = 438;
	static const quint32 _height = 269;
	static const QString LoaderWidgetBgiFilePath;

	quint32 winWidth;
	quint32 winHeight;
	QPropertyAnimation *winFadeIn;
	QPixmap *bgiPix;

	Ui::Loader *ui;

private slots:
	void winFadeInOver();
};