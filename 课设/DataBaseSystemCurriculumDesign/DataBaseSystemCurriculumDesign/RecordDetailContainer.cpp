#include "RecordDetailContainer.h"
#include <QtSql/QSqlQuery>
#include <QtCore/QDateTime>
#include <memory>

const unsigned int RecordDetailContainer::widWidth(493);
const unsigned int RecordDetailContainer::widHeight(442);

RecordDetailContainer::RecordDetailContainer(const QString &_DBName, QWidget * parent)
	: DBName(_DBName), QTextBrowser(parent)
{
	this->setGeometry(0, 0, widWidth, widHeight);
}

RecordDetailContainer::~RecordDetailContainer()
{

}

void RecordDetailContainer::refresh(const int id)
{
	currID = id;

	QSqlDatabase db(QSqlDatabase::database(DBName));
	this->clear();

	QSqlQuery query(db);
	query.prepare("SELECT Records.phone_number, Addresses.name "
		"FROM DSCD.Records LEFT OUTER JOIN DSCD.Addresses on DSCD.Records.address_id = DSCD.Addresses.id "
		"WHERE Records.id = :id");
	query.bindValue(":id", currID);
	query.exec();

	query.next();
	QString currPhoneNumber(query.value("phone_number").toString());
	QString currName(query.value("name").toString());

	query.prepare("SELECT bg_time, ed_time FROM DSCD.Records WHERE phone_number = :phone_number order by id DESC");
	query.bindValue(":phone_number", currPhoneNumber);
	query.exec();

	QVector<QString> timeStrs;
	while (query.next())
		timeStrs.append(getDistanceTime(query.value("bg_time").toDateTime(), query.value("ed_time").toDateTime()));

	this->setText(generateNewRichText(currPhoneNumber, currName, timeStrs));
}

QString RecordDetailContainer::generateNewRichText(const QString & phoneNumber, const QString & name, const QVector<QString>& timeStrs)
{
	QString newRichText("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">"
		"<html><head><meta name = \"qrichtext\" content = \"1\" / ><style type = \"text/css\">"
		"p, li{ white - space: pre - wrap; }"
		"</style></head><body style = \"font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">");
	newRichText += QString::fromLocal8Bit("<p style = \"margin-top:12px; margin-bottom:0px; margin-left:12px; margin-right:0px;"
		"-qt-block-indent:0; text-indent:0px;\"><span style = \"font-size:24pt;\">%1</span>     "
		"<span style = \"font-size:18pt;\">%2</span></p><hr/>"
		"<p style=\"margin-top:18px; margin-bottom:0px; margin-left:12px; margin-right:0px;"
		"-qt-block-indent:0; text-indent:0px; \"><span style=\"font-size:24pt; \">通话记录：</span></p>")
		.arg(phoneNumber).arg(name);
	
	for (unsigned int i(0), j(timeStrs.size()); i != j; ++i)
	{
		newRichText += QString("<p style = \"margin-top:18px; margin-bottom:0px; margin-left:12px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">"
			"<span style = \"font-size:12pt;\">%1</span></p>").arg(timeStrs[i]);
	}

	newRichText += QString("</body></html>");

	return std::move(newRichText);
}

QString RecordDetailContainer::getDistanceTime(const QDateTime & bg_time, const QDateTime & ed_time)
{
	int distanceSec = bg_time.secsTo(ed_time);
	QString distance;
	if (distanceSec >= 3600)
		distance = QString::fromLocal8Bit("%1时%2分%3秒").arg(distanceSec / 3600)
		.arg(distanceSec % 3600 / 60).arg(distanceSec % 60);
	else if (distanceSec >= 60)
		distance = QString::fromLocal8Bit("%1分%2秒").arg(distanceSec / 60).arg(distanceSec % 60);
	else
		distance = QString::fromLocal8Bit("%1秒").arg(distanceSec);

	return bg_time.toLocalTime().toString("yyyy-M-d h:m:s") + QString(" - ") + 
		ed_time.toLocalTime().toString("h:m:s") + QString::fromLocal8Bit("， 时长：") + distance;
}