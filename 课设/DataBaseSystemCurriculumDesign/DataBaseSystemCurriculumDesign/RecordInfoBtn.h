#pragma once

#include "Basic.h"
#include "ui_RecordInfoWidget.h"
#include <QtWidgets/QPushButton>
#include <QtCore/QDateTime>

class RecordInfoBtn : public QPushButton
{
	Q_OBJECT;

public:
	RecordInfoBtn(int id, const QString &phoneNumber, const QDateTime &bgTime, const QDateTime &edTime,
		const QVector<AddressApp::MobileMac> &mobileMacs, const QVector<AddressApp::TelephoneMac> &telephoneMacs,
		QWidget *parent = nullptr);
	~RecordInfoBtn();

signals:
	void clicked(int id);

private slots:
	void clickedSlot(void);

private:
	const QVector<AddressApp::MobileMac> &mobileMacs;
	const QVector<AddressApp::TelephoneMac> &telephoneMacs;

	int id;
	QString phoneNumber;
	QString timeLocal;
	Ui::RecordInfoWidget *ui;
};