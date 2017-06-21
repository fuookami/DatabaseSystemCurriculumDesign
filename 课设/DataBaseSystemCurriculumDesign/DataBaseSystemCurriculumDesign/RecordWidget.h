#pragma once

#include "Basic.h"
#include "ui_RecordsWidget.h"
#include <QtWidgets/QWidget>

class RecordWidget : public QWidget
{
	Q_OBJECT;

public:
	RecordWidget(const QVector<AddressApp::MobileMac> &_mobileMacs, const QVector<AddressApp::TelephoneMac> _telephoneMacs,
		const QString &_DBName, QWidget *parent = nullptr);
	~RecordWidget();

private:
	const QVector<AddressApp::MobileMac> &mobileMacs;
	const QVector<AddressApp::TelephoneMac> &telephoneMacs;
	const QString &DBName;

	Ui::RecordsWidget *ui;
};