#pragma once

#include <QtCore/QVector>
#include <QtWidgets/QTextBrowser>

class RecordDetailContainer : public QTextBrowser
{
	Q_OBJECT;

public:
	RecordDetailContainer(const QString &_DBName, QWidget *parent = nullptr);
	~RecordDetailContainer();

	void refresh(const int id);

private:
	QString generateNewRichText(const QString &phoneNumber, const QString &name, const QVector<QString> &timeStrs);
	QString getDistanceTime(const QDateTime &bgTime, const QDateTime &edTime);

private:
	static const unsigned int widWidth;
	static const unsigned int widHeight;

	const QString &DBName;
	int currID;
};