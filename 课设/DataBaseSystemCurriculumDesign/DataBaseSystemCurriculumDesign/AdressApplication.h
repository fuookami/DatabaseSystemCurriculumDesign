#pragma once

#include "Basic.h"
#include <QtCore/QVector>

class AddressApplication
{
public:
	static AddressApplication &getReference(void);

	~AddressApplication();

	inline bool isOpen() const;
	inline const QString &lastError() const;
	void run();
	void close();

private:
	AddressApplication();

	bool loadSettingDatas();
	bool connectToDatabase();

private:
	// loading window
	// main window
	bool opened;
	QString lastErrorMsg;

private:
	static QVector<AddressApp::MobileMac> mobileMacs;
	static QVector<AddressApp::TelephoneMac> telephoneMacs;
	static const QString MobileMacFilePath;
	static const QString TelephoneMacFilePath;
};