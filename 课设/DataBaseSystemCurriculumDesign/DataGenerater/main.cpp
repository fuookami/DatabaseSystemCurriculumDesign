#include <QtWidgets/QApplication>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QtCore/QDebug>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QTextCodec>
#include <QtCore/QFile>
#include <random>
#include <memory>

QStringList familyNames;
QStringList names;
QStringList mobileMacs;
QStringList telephoneMacs;

struct Address
{
	QString Name;
	QString mobile;
	QString mobile2;
	QString telephone;
};
QVector<Address> addresses;
QVector<QString> groups;

void createConnectTo(const QString &dataType, const QString &host, const unsigned int port, const QString &dbName, const QString &user, const QString &password)
{
	QSqlDatabase db(QSqlDatabase::addDatabase(dataType, "DSCD"));
	db.setHostName(host);
	db.setPort(port);
	db.setDatabaseName(dbName);
	db.setUserName(user);
	db.setPassword(password);
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
		str.remove('\n');
		familyNames.append(str.split(" "));
	}
	file.close();

	file.setFileName("ResourceFiles\\Names.txt");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		qDebug() << "Can not open ResourceFiles\\Names.txt\n";
		return false;
	}
	while (!file.atEnd())
	{
		QString str(file.readLine());
		str.remove('\n');
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
		str.remove('\n');
		mobileMacs.push_back(str.split("\t")[0]);
	}
	file.close();

	return true;
}

bool loadGroups()
{
	QFile file("ResourceFiles\\Groups.txt");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		qDebug() << "Can not open ResourceFiles\\Groups.txt\n";
		return false;
	}
	while (!file.atEnd())
	{
		QString str(file.readLine());
		str.remove('\n');
		groups.push_back(str);
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
		str.remove('\n');
		telephoneMacs.push_back(str.split("\t")[0]);
	}
	file.close();

	return true;
}

bool loadData()
{
	return loadNames()
		&& loadGroups()
		&& loadMobileMacs()
		&& loadTelephoneMacs();
}

QString generateMobile()
{
	static std::random_device rd;
	static const unsigned long mobileMacsNum(mobileMacs.size());
	
	QString ret("+86");
	ret += mobileMacs[rd() % mobileMacsNum];
	for (unsigned int i(0); i != 4; ++i)
		ret.push_back('0' + rd() % 10);
	return std::move(ret);
}

QString generateTelephone()
{
	static std::random_device rd;
	static const unsigned long telephoneMacsNum(telephoneMacs.size());

	QString ret(telephoneMacs[rd() % telephoneMacsNum]);
	ret.push_back('1' + rd() % 9);
	for (unsigned int i(0); i != 7; ++i)
		ret.push_back('0' + rd() % 10);
	return std::move(ret);
}

void generateDatas()
{
	std::random_device rd;
	static const unsigned long familyNamesNum(familyNames.size());
	static const unsigned long namesNum(names.size());
	
	unsigned int addressNum(50 + rd() % 50);
	for (unsigned int i(0); i != addressNum; ++i)
	{
		addresses.push_back(Address({
			familyNames[rd() % familyNamesNum] + names[rd() % namesNum],
			generateMobile(),
			generateMobile(),
			generateTelephone()
		}));
	}
}

void injectDatas()
{
	QSqlDatabase db(QSqlDatabase::database("DSCD"));
	db.transaction();
	QSqlQuery query(db);

	query.exec("DELETE FROM DSCD.ADDRESSES");
	query.exec("DELETE FROM DSCD.GROUP");
	query.exec("DELETE FROM DSCD.RECORDS");

	query.prepare("INSERT INTO DSCD.ADDRESSES (id, name, mobile, mobile2, telephone) "
		"VALUES (:id, :name, :mobile, :mobile2, :telephone)");
	query.bindValue(":id", 0);
	query.bindValue(":name", QString::fromLocal8Bit("李伟文"));
	query.bindValue(":mobile", "+8618051018256");
	query.bindValue(":mobile2", "+8615150666878");
	query.bindValue(":telephone", "02037361150");
	if (!query.exec())
	{
		qDebug() << "Wrong0: " << query.lastError().text() << "\n";
	}

	for (unsigned long i(0), j(addresses.size()); i != j; ++i)
	{
		query.prepare("INSERT INTO DSCD.ADDRESSES (id, name, mobile, mobile2, telephone) "
			"VALUES (SYSTEM.SEQ_DSCD_ADDRESS_ID.nextval, :name, :mobile, :mobile2, :telephone)");
		query.bindValue(":name", addresses[i].Name);
		query.bindValue(":mobile", addresses[i].mobile);
		query.bindValue(":mobile2", addresses[i].mobile2);
		query.bindValue(":telephone", addresses[i].telephone);

		if (!query.exec())
		{
			qDebug() << "Wrong" << i << ": " << query.lastError().text() << "\n";
		}
	}

	db.commit();
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QTextCodec *codec = QTextCodec::codecForName("GB2312");
	QTextCodec::setCodecForLocale(codec);
	
	if (!loadData())
	{
		qDebug() << "Load datas wrong.";
		return 1;
	}
	generateDatas();

	createConnectTo("QOCI", "127.0.0.1", 1521, "fuookamiDBSD", "DSCD", "a08040228a");
	if (!QSqlDatabase::database("DSCD").open())
	{
		qDebug() << "DB connection wrong: " << QSqlDatabase::database("DSCD").lastError().text();
		return 1;
	}
	injectDatas();

	return a.exec();
}