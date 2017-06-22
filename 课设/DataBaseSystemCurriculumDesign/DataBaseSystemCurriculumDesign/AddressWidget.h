#pragma once

#include "Basic.h"
#include "AddressInfoBtn.h"
#include "InfoBtnContainer.h"
#include "AddressDetailContainer.h"
#include "AddressDetailInput.h"
#include "ui_AdressesWidget.h"
#include <QtWidgets/QWidget>

class AddressWidget : public QWidget
{
	Q_OBJECT;

public:
	AddressWidget(const QVector<AddressApp::MobileMac> &_mobileMacs, const QVector<AddressApp::TelephoneMac> &_telephoneMacs,
		const QString &_DBName, QWidget *parent = nullptr);
	~AddressWidget();

private slots:
	void infoBtnClicked(int id);
	void uploadDataSlot(const AddressData &);
	void addBtnClicked(void);
	void modifyBtnClicked(void);
	void deleteBtnClicked(void);

private:
	void refreshAddressList();

private:
	enum 
	{
		Nothing,
		Detail,
		Modify,
		Add
	};
	
	const QVector<AddressApp::MobileMac> &mobileMacs;
	const QVector<AddressApp::TelephoneMac> &telephoneMacs;
	const QString &DBName;

	unsigned int state;
	unsigned int currID;
	AddressDetailInput *addressDetailInput;
	AddressDetailContainer *addressDetailContainer;
	InfoBtnContainer *infoBtnContainer;
	QVector<AddressInfoBtn *> infoBtns;
	Ui::AdressesWidget *ui;
};