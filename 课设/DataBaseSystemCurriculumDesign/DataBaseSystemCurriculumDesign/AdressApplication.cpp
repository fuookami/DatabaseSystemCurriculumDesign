#include "AdressApplication.h"
#include <QtCore/QFile>
#include <QtConcurrent/QtConcurrent>
#include <memory>

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
	static const auto loadMobileMacs([](QString *errorMsg) -> bool
	{
		QFile file(MobileMacFilePath);
		if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		{
			*errorMsg += QString("Can not open ") + MobileMacFilePath + '\n';
			return false;
		}
		while (!file.atEnd())
		{
			QString str(file.readLine());
			str.remove('\n');

			QStringList strs(str.split("\t"));
			if (strs.size() == 3)
			{
				if (AddressApp::checkMobileMac(strs[0]))
				{
					mobileMacs.append(std::move(AddressApp::MobileMac(strs)));
				}
				else
				{
					*errorMsg += generateLoadErrorMsg(MobileMacFilePath, mobileMacs.size() + 1, "mac is invalid");
					file.close();
					mobileMacs.clear();
					return false;
				}
			}
			else
			{
				*errorMsg += generateLoadErrorMsg(MobileMacFilePath, mobileMacs.size() + 1, "data is wrong");
				file.close();
				mobileMacs.clear();
				return false;
			}
		}
		file.close();

		return true;
	});

	static const auto loadTelephoneMacs([](QString *errorMsg) -> bool
	{
		QFile file(TelephoneMacFilePath);
		if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		{
			*errorMsg += QString("Can not open ") + TelephoneMacFilePath + '\n';
			return false;
		}
		while (!file.atEnd())
		{
			QString str(file.readLine());
			str.remove('\n');

			QStringList strs(str.split("\t"));
			if (strs.size() == 2)
			{
				if (AddressApp::checkTelephoneMac(strs[0]))
				{
					telephoneMacs.append(std::move(AddressApp::TelephoneMac(strs)));
				}
				else
				{
					*errorMsg += generateLoadErrorMsg(TelephoneMacFilePath, mobileMacs.size() + 1, "mac is invalid");
					file.close();
					telephoneMacs.clear();
					return false;
				}
			}
			else
			{
				*errorMsg += generateLoadErrorMsg(TelephoneMacFilePath, mobileMacs.size() + 1, "data is wrong");
				file.close();
				telephoneMacs.clear();
				return false;
			}
		}
		file.close();

		return true;
	});

	lastErrorMsg.clear();
	QFuture<bool> loadMobileMacsFuture(QtConcurrent::run(loadMobileMacs, &lastErrorMsg));
	QFuture<bool> loadTelephoneMacsFuture(QtConcurrent::run(loadTelephoneMacs, &lastErrorMsg));

	loadMobileMacsFuture.waitForFinished();
	loadTelephoneMacsFuture.waitForFinished();

	return loadMobileMacsFuture.result() && loadTelephoneMacsFuture.result();
}

QString AddressApplication::generateLoadErrorMsg(const QString & filePath, unsigned long line, const QString & msg)
{
	QString newErrorMsg;
	/*
	*errorMsg += QString("In file \"") + MobileMacFilePath + QString("\" ");
	*errorMsg += QString("Line ") + QString::fromStdString(std::to_string()) + QString(": ");
	*errorMsg += QString("mac is invalid.\n");
	*/
	return std::move(newErrorMsg);
}

bool AddressApplication::connectToDatabase()
{
	// set loading widget to connectToDatabase
	return false;
}