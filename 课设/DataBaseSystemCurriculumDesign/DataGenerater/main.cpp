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
		qDebug() << "Can not open ResourceFiles\\TelephoneMac.txt\n";
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

bool initDatabase()
{
	QFile file("ResourceFiles\\InitDatabaseScript.sql");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		qDebug() << "Can not open ResourceFiles\\InitDatabaseScript.sql\n";
		return false;
	}
	QString str(file.readAll());
	QStringList sqls(str.split("--"));

	QSqlDatabase db(QSqlDatabase::database("DSCD"));
	db.transaction();
	QSqlQuery query(db);

	for (unsigned long i(0), j(sqls.size()); i != j; ++i)
	{
		if (!query.exec(sqls[i]))
		{
			qDebug() << "Wrong: " << sqls[i] << '\n';
			qDebug() << query.lastError().text();
			return false;
		}
	}

	return true;
}

void injectDatas()
{
	std::random_device rd;

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

	for (unsigned long i(0), j(groups.size()); i != j; ++i)
	{
		query.prepare("INSERT INTO DSCD.GROUPS (id, name) "
			"VALUES (DSCD.SEQ_DSCD_GROUP_ID.nextval, :name)");
		query.bindValue(":name", groups[i]);

		if (!query.exec())
		{
			qDebug() << "Wrong" << i << ": " << query.lastError().text() << "\n";
		}
	}

	for (unsigned long i(0), j(addresses.size()); i != j; ++i)
	{
		switch (rd() % 4)
		{
		case 0:
			query.prepare("INSERT INTO DSCD.ADDRESSES (id, name) "
				"VALUES (DSCD.SEQ_DSCD_ADDRESS_ID.nextval, :name)");
			query.bindValue(":name", addresses[i].Name);
			break;
		case 1:
			query.prepare("INSERT INTO DSCD.ADDRESSES (id, name, mobile) "
				"VALUES (DSCD.SEQ_DSCD_ADDRESS_ID.nextval, :name, :mobile)");
			query.bindValue(":name", addresses[i].Name);
			query.bindValue(":mobile", addresses[i].mobile);
			break;
		case 2:
			query.prepare("INSERT INTO DSCD.ADDRESSES (id, name, mobile, mobile2) "
				"VALUES (DSCD.SEQ_DSCD_ADDRESS_ID.nextval, :name, :mobile, :mobile2)");
			query.bindValue(":name", addresses[i].Name);
			query.bindValue(":mobile", addresses[i].mobile);
			query.bindValue(":mobile2", addresses[i].mobile2);
			break;
		default:
			query.prepare("INSERT INTO DSCD.ADDRESSES (id, name, mobile, mobile2, telephone) "
				"VALUES (DSCD.SEQ_DSCD_ADDRESS_ID.nextval, :name, :mobile, :mobile2, :telephone)");
			query.bindValue(":name", addresses[i].Name);
			query.bindValue(":mobile", addresses[i].mobile);
			query.bindValue(":mobile2", addresses[i].mobile2);
			query.bindValue(":telephone", addresses[i].telephone);
			break;
		}

		if (!query.exec())
		{
			qDebug() << "Wrong" << i << ": " << query.lastError().text() << "\n";
		}

		if (rd() % 2 == 0)
		{
			unsigned int groupId(1 + rd() % groups.size());
			query.prepare("UPDATE DSCD.ADDRESSES SET group_id = :group_id "
				"WHERE id = :id");
			query.bindValue(":group_id", groupId);
			query.bindValue(":id", (unsigned int)i);

			if (!query.exec())
			{
				qDebug() << "Wrong" << i << ": " << query.lastError().text() << "\n";
			}
		}
	}

	unsigned int month(1);
	unsigned int day(rd() % 10);
	unsigned int hour(0), min(0), sec(0);

	for (; month <= 12;)
	{
		hour = rd() % 24;
		min = rd() % 40;
		sec = rd() % 60;
		QString dateTime1;
		dateTime1.sprintf("2017-%02d-%02d %02d:%02d:%02d", month, day, hour, min, sec);
		QString dateTime2;
		min += rd() % (60 - min);
		sec = rd() % 60;
		dateTime2.sprintf("2017-%02d-%02d %02d:%02d:%02d", month, day, hour, min, sec);

		query.prepare("INSERT INTO DSCD.RECORDS (id, phone_number, bg_time, ed_time) "
			"VALUES (DSCD.SEQ_DSCD_RECORD_ID.nextval, :phone_number, "
			"to_date(:bg_time, 'YYYY-MM-DD HH24:MI:SS'), "
			"to_date(:ed_time, 'YYYY-MM-DD HH24:MI:SS'))");
		if (rd() % 3 == 0)
			switch (rd() % 3 == 0)
			{
			case 0:
				query.bindValue(":phone_number", addresses[rd() % addresses.size()].mobile);
				break;
			case 1:
				query.bindValue(":phone_number", addresses[rd() % addresses.size()].mobile2);
				break;
			default:
				query.bindValue(":phone_number", addresses[rd() % addresses.size()].telephone);
				break;
			}
		else if (rd() % 2 == 0)
			query.bindValue(":phone_number", generateMobile());
		else
			query.bindValue(":phone_number", generateTelephone());
		query.bindValue(":bg_time", dateTime1);
		query.bindValue(":ed_time", dateTime2);
		
		if (!query.exec())
		{
			qDebug() << "Wrong" << dateTime1 << ": " << query.lastError().text() << "\n";
		}

		day += rd() % 10;
		if (day > 28)
		{
			day -= 28;
			month += 1;
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

	if (initDatabase())
	{
		injectDatas();
	}

	return a.exec();
}