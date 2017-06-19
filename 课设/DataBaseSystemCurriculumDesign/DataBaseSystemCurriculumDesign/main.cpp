#include "AdressApp.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	AddressApp &sys(AddressApp::getReference());
	sys.run();

	return a.exec();
}
