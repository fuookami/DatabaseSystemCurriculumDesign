#include <QtWidgets/QApplication>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QtCore/QDebug>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QSqlDatabase db(QSqlDatabase::addDatabase("QOCI"));
	db.setPort(1521);
	db.setHostName("127.0.0.1");
	db.setDatabaseName("fuookamiDBSD");
	db.setUserName("fuookami");
	db.setPassword("a08040228a");
	if (db.open())
	{
		qDebug() << "ok";
		QSqlQuery query;
		query.exec("SELECT SNO, SNAME FROM FUOOKAMI.S");

		if (!query.isActive())
		{
			qDebug() << query.lastError().text();
		}
		else 
		{
			while (query.next())
			{
				QString sno = query.value(0).toString();
				QString sname = query.value(1).toString();
				qDebug() << sno << ' ' << sname << '\n';
			}
		}
	}

	return a.exec();
}