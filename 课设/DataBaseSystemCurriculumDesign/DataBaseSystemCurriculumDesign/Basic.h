#pragma once

#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QDateTime>

namespace AddressApp
{
	struct MobileMac
	{
		MobileMac() {};
		MobileMac(const QStringList &strs)
			: mac(strs[0]), local(strs[1]), service(strs[2]) {}
		MobileMac(const QString &_mac, const QString &_local, const QString &_service)
			: mac(_mac), local(_local), service(_service) {}

		QString mac;
		QString local;
		QString service;
	};

	struct TelephoneMac
	{
		TelephoneMac() {};
		TelephoneMac(const QStringList &strs)
			: mac(strs[0]), local(strs[1]) {}
		TelephoneMac(const QString _mac, const QString _local)
			: mac(_mac), local(_local) {}
		QString mac;
		QString local;
	};

	struct Setting
	{
		Setting() {};
		Setting(const QString &_databaseType, const QString &_host, quint64 _port, const QString &_databaseName,
			const QString &_user, const QString _password)
			: databaseType(_databaseType), host(_host), port(_port), databaseName(_databaseName),
			user(_user), password(_password) {};
		QString databaseType;
		QString host;
		quint64 port = 0;
		QString databaseName;
		QString user;
		QString password;
	};

	namespace Modules
	{
		struct Group
		{
			QString name;
		};

		struct Address
		{
			int id;
			QString name;
			QString mobile1;
			QString mobile2;
			QString telephone;
			QString unit;
			QString identity;
			QString remark;
			QString email;
			QString group_name;
		};

		struct Records
		{
			int id;
			QString phone_number;
			QDateTime bg_time;
			QDateTime ed_time;
			QString address_name;
		};
	}

	bool checkMobileMac(const QString &mobileMac);
	bool checkTelephoneMac(const QString &telephoneMac);
}