#include <QtWidgets/QApplication>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
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
	}

	return a.exec();
}