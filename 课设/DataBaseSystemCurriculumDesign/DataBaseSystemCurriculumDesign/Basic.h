#pragma once

#include <QtCore/QString>

namespace AddressApp
{
	struct MobileMac
	{
		MobileMac(const QString _mac, const QString _local, const QString _service)
			: mac(_mac), local(_local), service(_service) {}
		QString mac;
		QString local;
		QString service;
	};

	struct TelephoneMac
	{
		TelephoneMac(const QString _mac, const QString _local)
			: mac(_mac), local(_local) {}
		QString mac;
		QString local;
	};
}