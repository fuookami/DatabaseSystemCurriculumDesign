#pragma once

#include <QtCore/QString>
#include <QtCore/QStringList>

namespace AddressApp
{
	struct MobileMac
	{
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
		TelephoneMac(const QStringList &strs)
			: mac(strs[0]), local(strs[1]) {}
		TelephoneMac(const QString _mac, const QString _local)
			: mac(_mac), local(_local) {}
		QString mac;
		QString local;
	};

	bool checkMobileMac(const QString &mobileMac);
	bool checkTelephoneMac(const QString &telephoneMac);
}