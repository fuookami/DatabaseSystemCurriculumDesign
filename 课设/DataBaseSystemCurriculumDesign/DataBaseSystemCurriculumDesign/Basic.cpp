#include "Basic.h"

#include <QtCore/QChar>

bool AddressApp::checkMobileMac(const QString & mobileMac)
{
	if (mobileMac.size() != 7)
		return false;

	for (unsigned int i(0), j(mobileMac.size()); i != j; ++i)
	{
		if (!mobileMac[i].isDigit())
			return false;
	}

	return true;
}

bool AddressApp::checkTelephoneMac(const QString & telephoneMac)
{
	if ((telephoneMac.size() != 3 
		&& telephoneMac.size() != 4) 
		|| telephoneMac[0] != QChar('0')
		|| telephoneMac[1] == QChar('0'))
	{
		return false;
	}

	for (unsigned int i(2), j(telephoneMac.size()); i != j; ++i)
	{
		if (!telephoneMac[i].isDigit())
			return false;
	}

	return true;
}
