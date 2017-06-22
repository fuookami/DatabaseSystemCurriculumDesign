#pragma once

#include "Basic.h"
#include "RecordInfoBtn.h"
#include "InfoBtnContainer.h"
#include "RecordDetailContainer.h"
#include "ui_RecordsWidget.h"
#include <QtWidgets/QWidget>

class RecordWidget : public QWidget
{
	Q_OBJECT;

public:
	RecordWidget(const QVector<AddressApp::MobileMac> &_mobileMacs, const QVector<AddressApp::TelephoneMac> &_telephoneMacs,
		const QString &_DBName, QWidget *parent = nullptr);
	~RecordWidget();

private slots:
	void btnClickedSlot(int id);

private:
	void refreshRecordList();
	QString getLocalService(const QString &phoneNumber);

private:
	enum
	{
		ID,
		PHONE_NUMBER,
		BG_TIME,
		ED_TIME,
		ADDRESS_ID
	};

	const QVector<AddressApp::MobileMac> &mobileMacs;
	const QVector<AddressApp::TelephoneMac> &telephoneMacs;
	const QString &DBName;

	RecordDetailContainer *recordDetailContainer;
	InfoBtnContainer *infoBtnContainer;
	QVector<RecordInfoBtn *> infoBtns;
	Ui::RecordsWidget *ui;
};