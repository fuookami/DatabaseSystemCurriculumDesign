#include "AdressApplication.h"
#include <QtCore/QFile>
#include <QtConcurrent/QtConcurrent>
#include <QtSql/QSqlDatabase>
#include <QtWidgets/QMessageBox>
#include <memory>

const QString AddressApplication::MobileMacFilePath("Resources\\MobileMac.txt");
const QString AddressApplication::TelephoneMacFilePath("Resources\\TelephoneMac.txt");
const QString AddressApplication::SettingFilePath("Resources\\Setting.txt");

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
	lastErrorMsg.clear();
	if (loadSettingDatas() && connectToDatabase())
	{
		opened = true;
		// set loading widget to init
	}
	else
		QMessageBox::information(nullptr, QString::fromLocal8Bit("´íÎó"), lastErrorMsg);
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

	static const auto loadSetting([](QString *errorMsg) -> bool
	{
		QFile file(SettingFilePath);
		if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		{
			*errorMsg += QString("Can not open ") + SettingFilePath + "\n";
			return false;
		}

		QStringList settingStrs;
		while (!file.atEnd())
		{
			QString str(file.readLine());
			str.remove('\n');

			QStringList strs(str.split(" "));
			if (strs.size() == 3)
			{
				settingStrs.append(strs[2]);
			}
			else
			{
				*errorMsg += generateLoadErrorMsg(SettingFilePath, settingStrs.size() + 1, "data is wrong");
				file.close();
				settingStrs.clear();
				return false;
			}
		}
		file.close();

		if (settingStrs.size() != 6)
		{
			*errorMsg += QString("In file \"") + SettingFilePath + QString("\": Data has been inserted or deleted.\n");
			settingStrs.clear();
			return false;
		}

		setting = AddressApp::Setting(settingStrs[0], settingStrs[1], settingStrs[2].toUInt(), settingStrs[3], settingStrs[4],
			settingStrs[5]);
		settingStrs.clear();
		return true;
	});

	QFuture<bool> loadMobileMacsFuture(QtConcurrent::run(loadMobileMacs, &lastErrorMsg));
	QFuture<bool> loadTelephoneMacsFuture(QtConcurrent::run(loadTelephoneMacs, &lastErrorMsg));
	QFuture<bool> loadSettingFuture(QtConcurrent::run(loadSetting, &lastErrorMsg));

	loadMobileMacsFuture.waitForFinished();
	// set loading widget to load mobile mac
	loadTelephoneMacsFuture.waitForFinished();
	// set loading widget to load mobile mac
	loadSettingFuture.waitForFinished();
	// set loading widget to load mobile mac

	return loadMobileMacsFuture.result() && loadTelephoneMacsFuture.result() && loadSettingFuture.result();
}

QString AddressApplication::generateLoadErrorMsg(const QString & filePath, const quint64 line, const QString & msg)
{
	QByteArray block;
	QDataStream out(&block, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_5_8);

	out << "In file \"" << filePath << "\" ";
	out << "Line " << line << ": ";
	out << msg << ".\n";

	return std::move(QString(block));
}

bool AddressApplication::connectToDatabase()
{
	QSqlDatabase db(QSqlDatabase::addDatabase(setting.databaseType, DBName));
	db.setHostName(setting.host);
	db.setPort(setting.port);
	db.setDatabaseName(setting.databaseName);
	db.setUserName(setting.user);
	db.setPassword(setting.password);

	if (!db.open())
	{
		lastErrorMsg += QString("DB connection wrong: ") + db.lastError().text();
		lastErrorMsg += ".\n";
		return false;
	}

	return true;
}