#include "AdressApplication.h"
#include <QtCore/QFile>
#include <QtConcurrent/QtConcurrent>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtWidgets/QMessageBox>
#include <memory>

QVector<AddressApp::MobileMac> AddressApplication::mobileMacs;
QVector<AddressApp::TelephoneMac> AddressApplication::telephoneMacs;
AddressApp::Setting AddressApplication::setting;

const QString AddressApplication::MobileMacFilePath("Resources\\MobileMac.txt");
const QString AddressApplication::TelephoneMacFilePath("Resources\\TelephoneMac.txt");
const QString AddressApplication::SettingFilePath("Resources\\Setting.txt");
const QString AddressApplication::DBName("DSCD");

AddressApplication & AddressApplication::getReference(void)
{
	static AddressApplication sys;
	return sys;
}

AddressApplication::~AddressApplication()
{
}

void AddressApplication::run()
{
}

void AddressApplication::close()
{
}

AddressApplication::AddressApplication()
	: opened(false), lastErrorMsg(), pLoader(new LoaderWidget()),
	pLoadThread(new LoadThread(mobileMacs, telephoneMacs, setting, MobileMacFilePath, TelephoneMacFilePath, SettingFilePath, DBName))
{
	pLoader->show();
	pLoadThread->start();

	lastErrorMsg.clear();

	connect(pLoadThread, SIGNAL(msg(const QString &)), this, SLOT(LoadingMsg(const QString &)));
	connect(pLoadThread, SIGNAL(finish(bool, const QString &)), this, SLOT(LoadingFinish(const QString &)));
}

void AddressApplication::LoadingMsg(const QString &msg)
{
	pLoader->setText(msg);
}

void AddressApplication::LoadingFinish(bool _opened, const QString &_lastErrorMsg)
{
	opened = _opened;
	lastErrorMsg = _lastErrorMsg;

	if (opened)
	{
		pLoader->setText(QString::fromLocal8Bit("正在初始化。"));
	}
	else
	{
		QMessageBox::information(nullptr, QString::fromLocal8Bit("错误"), lastErrorMsg);
		pLoader->close();
	}
}