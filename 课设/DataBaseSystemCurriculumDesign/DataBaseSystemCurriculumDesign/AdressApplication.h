#pragma once

#include "Basic.h"
#include "LoadThread.h"
#include "LoaderWidget.h"
#include <QtCore/QObject>
#include <QtCore/QVector>

class AddressApplication : public QObject
{
	Q_OBJECT;

public:
	static AddressApplication &getReference(void);

	~AddressApplication();

private:
	AddressApplication();

	bool connectToDatabase();

private slots:
	void LoadingMsg(const QString &msg);
	void LoadingFinish(bool _opened, const QString &_lastErrorMsg);

private:
	LoadThread *pLoadThread;
	LoaderWidget *pLoader;

	// main window
	bool opened;
	QString lastErrorMsg;

private:
	static QVector<AddressApp::MobileMac> mobileMacs;
	static QVector<AddressApp::TelephoneMac> telephoneMacs;
	static AddressApp::Setting setting;

	static const QString MobileMacFilePath;
	static const QString TelephoneMacFilePath;
	static const QString SettingFilePath;
	static const QString DBName;
};