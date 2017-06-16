#include <QtWidgets/QApplication>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QtCore/QDebug>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QTextCodec>
#include <QtCore/QFile>
#include <QtCore/QSharedPointer>

QStringList familyNames;
QStringList names;
QStringList mobileMacs;
QStringList telephoneMacs;

QSharedPointer<QSqlDatabase> createConnectTo(const QString &dataType, const QString &host, const unsigned int port, const QString &dbName, const QString &user, const QString &password)
{
	QSharedPointer<QSqlDatabase> db(&QSqlDatabase::addDatabase(dataType));
	db->setHostName(host);
	db->setPort(port);
	db->setDatabaseName(dbName);
	db->setUserName(user);
	db->setPassword(password);

	return db;
}

bool loadNames()
{
	QFile file("ResourceFiles\\FamilyNames.txt");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		qDebug() << "Can not open ResourceFiles\\FamilyNames.txt\n";
		return false;
	}
	while (!file.atEnd())
	{
		QString str(file.readLine());
		familyNames.append(str.split(" "));
	}
	file.close();

	file.setFileName("ResourceFiles\\FamilyNames.txt");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		qDebug() << "Can not open ResourceFiles\\FamilyNames.txt\n";
		return false;
	}
	while (!file.atEnd())
	{
		QString str(file.readLine());
		names.append(str.split(" "));
	}
	file.close();

	return true;
}

bool loadMobileMacs()
{
	QFile file("ResourceFiles\\MobileMac.txt");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		qDebug() << "Can not open ResourceFiles\\MobileMac.txt\n";
		return false;
	}
	while (!file.atEnd())
	{
		QString str(file.readLine());
		mobileMacs.push_back(str.split("\t")[0]);
	}
	file.close();

	return true;
}

bool loadTelephoneMacs()
{
	QFile file("ResourceFiles\\TelephoneMac.txt");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		qDebug() << "Can not open ResourceFiles\\MobileMac.txt\n";
		return false;
	}
	while (!file.atEnd())
	{
		QString str(file.readLine());
		telephoneMacs.push_back(str.split("\t")[0]);
	}
	file.close();

	return true;
}

bool loadData()
{
	return loadNames()
		&& loadMobileMacs()
		&& loadTelephoneMacs();
}

void generateDatas()
{

}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QTextCodec *codec = QTextCodec::codecForName("UTF-8");
	QTextCodec::setCodecForLocale(codec);
	
	if (!loadData())
	{
		qDebug() << "Load datas wrong.";
		return 1;
	}

	QSharedPointer<QSqlDatabase> db(createConnectTo("QOCI", "127.0.0.1", 1521, "fuookamiDBSD", "fuookami", "a08040228a"));
	if (!db->open())
	{
		qDebug() << "DB connection wrong: " << db->lastError().text();
		return 1;
	}

	return a.exec();
}