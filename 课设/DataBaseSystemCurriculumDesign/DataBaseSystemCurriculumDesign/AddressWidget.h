#pragma once

#include "Basic.h"
#include "AddressInfoBtn.h"
#include "InfoBtnContainer.h"
#include "ui_AdressesWidget.h"
#include <QtWidgets/QWidget>

class AddressWidget : public QWidget
{
	Q_OBJECT;

public:
	AddressWidget(const QVector<AddressApp::MobileMac> &_mobileMacs, const QVector<AddressApp::TelephoneMac> &_telephoneMacs,
		const QString &_DBName, QWidget *parent = nullptr);
	~AddressWidget();

private:
	void refreshAddressList();

private:
	const QVector<AddressApp::MobileMac> &mobileMacs;
	const QVector<AddressApp::TelephoneMac> &telephoneMacs;
	const QString &DBName;

	InfoBtnContainer *infoBtnContainer;
	QVector<AddressInfoBtn *> infoBtns;
	Ui::AdressesWidget *ui;
};