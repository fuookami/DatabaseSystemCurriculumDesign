#pragma once

#include "Basic.h"
#include <QtCore/QThread>
#include <QtCore/QVector>

class LoadThread : public QThread
{
	Q_OBJECT;

public:
	LoadThread(QVector<AddressApp::MobileMac> &_mobileMacs, QVector<AddressApp::TelephoneMac> &_telephoneMacs,
		AddressApp::Setting &_setting, const QString &_MobileMacFilePath, const QString &_TelephoneMacFilePath,
		const QString &_SettingFilePathQObject, const QString &_DBName, QObject *parent = nullptr);
	~LoadThread() {};

signals:
	void msg(const QString &);
	void finish(bool opened, const QString &lastErrorMsg);

protected:
	void run();

private:
	bool loadSettingDatas();
	static QString generateLoadErrorMsg(const QString &filePath, const quint64 line, const QString &msg);
	bool connectToDatabase();

private:
	bool opened;
	QString lastErrorMsg;

	QVector<AddressApp::MobileMac> &mobileMacs;
	QVector<AddressApp::TelephoneMac> &telephoneMacs;
	AddressApp::Setting &setting;
	
	const QString & MobileMacFilePath; 
	const QString & TelephoneMacFilePath;
	const QString & SettingFilePath;
	const QString & DBName;
};