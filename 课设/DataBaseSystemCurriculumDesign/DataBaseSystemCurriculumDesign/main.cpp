#include "AdressApplication.h"
#include <QtWidgets/QApplication>
#include <QtCore/QTextCodec>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QTextCodec *codec = QTextCodec::codecForName("GB2312");
	QTextCodec::setCodecForLocale(codec);

	AddressApplication &sys(AddressApplication::getReference());
	if (!sys.isOpen())
		return 1;

	sys.run();
	return a.exec();
}