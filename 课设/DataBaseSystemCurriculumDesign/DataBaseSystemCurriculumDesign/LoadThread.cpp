#include "LoadThread.h"

#include <QtCore/QFile>
#include <QtConcurrent/QtConcurrent>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <memory>

LoadThread::LoadThread(QVector<AddressApp::MobileMac>& _mobileMacs, QVector<AddressApp::TelephoneMac>& _telephoneMacs, 
	AddressApp::Setting & _setting, const QString & _MobileMacFilePath, const QString & _TelephoneMacFilePath, 
	const QString & _SettingFilePath, QObject * parent)
	: opened(false), lastErrorMsg(),
	mobileMacs(_mobileMacs), telephoneMacs(_telephoneMacs), setting(_setting),
	MobileMacFilePath(_MobileMacFilePath), TelephoneMacFilePath(_TelephoneMacFilePath), 
	SettingFilePath(_SettingFilePath), QThread(parent)
{
	
}

void LoadThread::run()
{
	opened = loadSettingDatas();

	emit finish(opened, lastErrorMsg);
}

bool LoadThread::loadSettingDatas()
{
	static const auto loadMobileMacs([this]() -> bool
	{
		QFile file(MobileMacFilePath);
		if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		{
			this->lastErrorMsg += QString("Can not open ") + MobileMacFilePath + '\n';
			return false;
		}
		while (!file.atEnd())
		{
			QString str(file.readLine().trimmed());

			QStringList strs(str.split("\t"));
			if (strs.size() == 3)
			{
				if (AddressApp::checkMobileMac(strs[0]))
				{
					mobileMacs.append(std::move(AddressApp::MobileMac(strs)));
				}
				else
				{
					this->lastErrorMsg += generateLoadErrorMsg(MobileMacFilePath, mobileMacs.size() + 1, "mac is invalid");
					file.close();
					mobileMacs.clear();
					return false;
				}
			}
			else
			{
				this->lastErrorMsg += generateLoadErrorMsg(MobileMacFilePath, mobileMacs.size() + 1, "data is wrong");
				file.close();
				mobileMacs.clear();
				return false;
			}
		}
		file.close();

		return true;
	});

	static const auto loadTelephoneMacs([this]() -> bool
	{
		QFile file(TelephoneMacFilePath);
		if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		{
			this->lastErrorMsg += QString("Can not open ") + TelephoneMacFilePath + '\n';
			return false;
		}
		while (!file.atEnd())
		{
			QString str(file.readLine().trimmed());

			QStringList strs(str.split("\t"));
			if (strs.size() == 2)
			{
				if (AddressApp::checkTelephoneMac(strs[0]))
				{
					telephoneMacs.append(std::move(AddressApp::TelephoneMac(strs)));
				}
				else
				{
					this->lastErrorMsg += generateLoadErrorMsg(TelephoneMacFilePath, mobileMacs.size() + 1, "mac is invalid");
					file.close();
					telephoneMacs.clear();
					return false;
				}
			}
			else
			{
				this->lastErrorMsg += generateLoadErrorMsg(TelephoneMacFilePath, mobileMacs.size() + 1, "data is wrong");
				file.close();
				telephoneMacs.clear();
				return false;
			}
		}
		file.close();

		return true;
	});

	static const auto loadSetting([this]() -> bool
	{
		QFile file(SettingFilePath);
		if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		{
			this->lastErrorMsg += QString("Can not open ") + SettingFilePath + "\n";
			return false;
		}

		QStringList settingStrs;
		while (!file.atEnd())
		{
			QString str(file.readLine().trimmed());

			QStringList strs(str.split(" "));
			if (strs.size() == 3)
			{
				settingStrs.append(strs[2]);
			}
			else
			{
				this->lastErrorMsg += generateLoadErrorMsg(SettingFilePath, settingStrs.size() + 1, "data is wrong");
				file.close();
				settingStrs.clear();
				return false;
			}
		}
		file.close();

		if (settingStrs.size() != 6)
		{
			this->lastErrorMsg += QString("In file \"") + SettingFilePath + QString("\": Data has been inserted or deleted.\n");
			settingStrs.clear();
			return false;
		}

		setting = AddressApp::Setting(settingStrs[0], settingStrs[1], settingStrs[2].toUInt(), settingStrs[3], settingStrs[4],
			settingStrs[5]);
		settingStrs.clear();
		return true;
	});

	QFuture<bool> loadMobileMacsFuture(QtConcurrent::run(loadMobileMacs));
	QFuture<bool> loadTelephoneMacsFuture(QtConcurrent::run(loadTelephoneMacs));
	QFuture<bool> loadSettingFuture(QtConcurrent::run(loadSetting));

	emit msg(QString::fromLocal8Bit("正在读取系统设置。"));
	bool result3(loadSettingFuture.result());

	emit msg(QString::fromLocal8Bit("正在读取座机区位码数据。"));
	bool result2(loadTelephoneMacsFuture.result());

	emit msg(QString::fromLocal8Bit("正在读取手机区位码数据。"));
	bool result1(loadMobileMacsFuture.result());

	return result1 && result2 && result3;
}

QString LoadThread::generateLoadErrorMsg(const QString & filePath, const quint64 line, const QString & msg)
{
	return QString("In file \"%1\" Line %2: %3.\n")
		.arg(filePath).arg(line).arg(msg);
}