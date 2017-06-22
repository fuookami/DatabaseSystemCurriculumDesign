#pragma once

#include "Basic.h"
#include <QtCore/QVector>
#include <QtWidgets/QTextBrowser>

class AddressDetailContainer : public QTextBrowser
{
	Q_OBJECT;

public:
	AddressDetailContainer(const QVector<AddressApp::MobileMac> &_mobileMacs, const QVector<AddressApp::TelephoneMac> &_telephoneMacs,
		const QString &_DBName, QWidget *parent = nullptr);
	~AddressDetailContainer();

	void refresh(const int id);

private:
	QString generateNewRichText(const QString &name, const QString &remark, const QString &unit, const QString &identity, const QString &email, 
		const QString &group, const QString &mobile1, const QString &mobile2, const QString &telephone, const QVector<QPair<QString, QString>> &timeStrs);
	QString getDistanceTime(const QDateTime &bgTime, const QDateTime &edTime);

private:
	static const unsigned int widWidth;
	static const unsigned int widHeight;

	const QVector<AddressApp::MobileMac> &mobileMacs;
	const QVector<AddressApp::TelephoneMac> &telephoneMacs;
	const QString &DBName;
	int currID;
};