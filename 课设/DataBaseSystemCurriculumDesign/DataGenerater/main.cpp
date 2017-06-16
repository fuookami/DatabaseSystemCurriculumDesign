#include <QtWidgets/QApplication>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QtCore/QDebug>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QTextCodec>
#include <QtCore/QFile>

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

bool loadNames()
{
	QFile file("ResourceFiles\\FamilyNames.txt");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		qDebug() << "Can not open ResourceFiles\\FamilyNames.txt\n";
		return false;
	}
	while (file.atEnd())
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
	while (file.atEnd())
	{
		QString str(file.readLine());
		names.append(str.split(" "));
	}
	file.close();

	return true;
}

bool loadMobileMacs()
{
	return true;
}

bool loadTelephoneMacs()
{
	return true;
}

bool loadData()
{
	return loadNames()
		&& loadMobileMacs()
		&& loadTelephoneMacs();
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