#pragma once

#include "Basic.h"
#include "ui_MainWidget.h"
#include "AddressWidget.h"
#include "RecordWidget.h"
#include <QtWidgets/QMainWindow>
#include <QtCore/QString>
#include <QtGui/QPixmap>
#include <QPropertyAnimation>
#include <QEasingCurve>

class MainWidget : public QMainWindow
{
	Q_OBJECT;

public:
	MainWidget(const QVector<AddressApp::MobileMac> &_mobileMacs, const QVector<AddressApp::TelephoneMac> _telephoneMacs,
	const QString &_DBName, QWidget *parent = nullptr);
	~MainWidget();

private slots:
	void closeSlot(void);
	void addressSlot(void);
	void recordSlot(void);

private:
	void setBtnSiderActivePalette(QLabel *l);
	void setBtnSiderUnactivePalette(QLabel *l);

private:
	static const unsigned int winHeight;
	static const unsigned int winWidth;
	static const QString MainWidgetBgiFilePath;

	const QVector<AddressApp::MobileMac> &mobileMacs;
	const QVector<AddressApp::TelephoneMac> &telephoneMacs; 
	const QString &DBName;

	QPropertyAnimation *winFadeIn;
	QPixmap *bgiPix;

	Ui::MainWidget *ui;
	AddressWidget *addressWidget;
	RecordWidget *recordWidget;

private slots:
	void winFadeInOver();
};