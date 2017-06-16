#include <QtWidgets/QApplication>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QtCore/QDebug>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <memory>

QStringList familyNames;
QStringList names;
QStringList mobileMacs;
QStringList telephoneMacs;

QSqlDatabase *createConnectTo(const QString &dataType, const QString &host, const unsigned int port, const QString &dbName, const QString &user, const QString &password)
{
	QSqlDatabase *db(&QSqlDatabase::addDatabase(dataType));
	db->setHostName(host);
	db->setPort(port);
	db->setDatabaseName(dbName);
	db->setUserName(user);
	db->setPassword(password);

	return db;
}

void loadNames()
{

}

void loadMobileMacs()
{

}

void loadTelephoneMacs()
{

}

void loadData()
{
	loadNames();
	loadMobileMacs();
	loadTelephoneMacs();
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	loadData();

	QSqlDatabase *db(createConnectTo("QOCI", "127.0.0.1", 1521, "fuookamiDBSD", "fuookami", "a08040228a"));
	if (!db->open())
	{
		qDebug() << "DB connection wrong: " << db->lastError().text();
		delete db;
		return 1;
	}

	delete db;
	return a.exec();
}