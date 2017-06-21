#include "AdressApp.h"
#include <QtCore/QFile>
#include <QtConcurrent/QtConcurrent>


AddressApplication & AddressApplication::getReference(void)
{
	static AddressApplication sys;
	return sys;
}

inline bool AddressApplication::isOpen() const
{
	return opened;
}

inline const QString & AddressApplication::lastError() const
{
	return lastErrorMsg;
}

AddressApplication::AddressApplication()
	:	opened(false),
		lastErrorMsg()
{
	if (loadSettingDatas() && connectToDatabase())
	{
		// right
	}
	else
	{
		// something wrong
	}
}

bool AddressApplication::loadSettingDatas()
{
	static const auto loadMobileMacs([]() -> bool
	{
		QFile file(MobileMacFilePath);
		if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		{
			//qDebug() << "Can not open ResourceFiles\\TelephoneMac.txt\n";
			return false;
		}
		while (!file.atEnd())
		{
			QString str(file.readLine());
			str.remove('\n');
			//telephoneMacs.push_back(str.split("\t")[0]);
		}
		file.close();

		return true;
	});

	static const auto loadTelephoneMacs([]() -> bool
	{
		QFile file(TelephoneMacFilePath);
		if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		{
			//qDebug() << "Can not open ResourceFiles\\TelephoneMac.txt\n";
			return false;
		}
		while (!file.atEnd())
		{
			QString str(file.readLine());
			str.remove('\n');
			//telephoneMacs.push_back(str.split("\t")[0]);
		}
		file.close();

		return true;
	});

	QFuture<bool> loadMobileMacsFuture(QtConcurrent::run(loadMobileMacs));
	QFuture<bool> loadTelephoneMacsFuture(QtConcurrent::run(loadTelephoneMacs));

	loadMobileMacsFuture.waitForFinished();
	loadTelephoneMacsFuture.waitForFinished();

	return loadMobileMacsFuture.result() && loadTelephoneMacsFuture.result();
}

bool AddressApplication::connectToDatabase()
{
	// set loading widget to connectToDatabase
	return false;
}