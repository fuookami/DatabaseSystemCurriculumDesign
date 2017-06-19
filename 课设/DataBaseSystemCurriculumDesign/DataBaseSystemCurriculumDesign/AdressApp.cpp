#include "AdressApp.h"

AddressApp & AddressApp::getReference(void)
{
	static AddressApp sys;
	return sys;
}
