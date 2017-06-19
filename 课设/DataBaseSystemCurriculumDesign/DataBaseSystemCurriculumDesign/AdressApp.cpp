#include "AdressApp.h"
#include <QtCore/QFile>

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
	// use qthread
	// set loading widget to load phoneMacs;
	// set loading widget to load telephoneMacs;
	return true;
}

bool AddressApp::connectToDatabase()
{
	// set loading widget to connectToDatabase
	return false;
}