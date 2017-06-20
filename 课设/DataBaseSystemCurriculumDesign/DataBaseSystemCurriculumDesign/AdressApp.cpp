#include "AdressApp.h"
#include <QtCore/QFile>
#include <QtConcurrent/QtConcurrent>

const QString AddressApp::MobileMacFilePath(QString("Resources\\MobileMac.txt"));
const QString AddressApp::TelephoneMacFilePath(QString("Resources\\TelephoneMac.txt"));

AddressApp & AddressApp::getReference(void)
{
	static AddressApp sys;
	return sys;
}

inline bool AddressApp::isOpen() const
{
	return opened;
}

inline const QString & AddressApp::lastError() const
{
	return lastErrorMsg;
}

AddressApp::AddressApp()
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

bool AddressApp::loadSettingDatas()
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

bool AddressApp::connectToDatabase()
{
	// set loading widget to connectToDatabase
	return false;
}