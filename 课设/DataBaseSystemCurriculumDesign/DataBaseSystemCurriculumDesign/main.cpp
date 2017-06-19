#include "AdressApp.h"
#include <QtWidgets/QApplication>
#include <QtCore/QTextCodec>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QTextCodec *codec = QTextCodec::codecForName("GB2312");
	QTextCodec::setCodecForLocale(codec);

	AddressApp &sys(AddressApp::getReference());
	if (!sys.isOpen())
	{
		// warning
		// show lastError
		return 1;
	}

	sys.run();
	return a.exec();
}