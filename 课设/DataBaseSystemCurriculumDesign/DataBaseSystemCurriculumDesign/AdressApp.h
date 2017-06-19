#pragma once

#include <QtCore/QString>

class AddressApp
{
public:
	static AddressApp &getReference(void);

	~AddressApp();

	inline bool isOpen() const;
	inline const QString &lastError() const;
	void run();
	void close();

private:
	AddressApp();

	bool loadSettingDatas();
	bool connectToDatabase();

private:
	// loading window
	// main window
	bool opened;
	QString lastErrorMsg;
};