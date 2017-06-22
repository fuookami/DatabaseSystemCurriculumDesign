#include "AddressDetailContainer.h"
#include <QtSql/QSqlQuery>
#include <QtCore/QDateTime>
#include <QtCore/QPair>
#include <memory>

const unsigned int AddressDetailContainer::widWidth(493);
const unsigned int AddressDetailContainer::widHeight(442);

AddressDetailContainer::AddressDetailContainer(const QVector<AddressApp::MobileMac>& _mobileMacs, const QVector<AddressApp::TelephoneMac>& _telephoneMacs, 
	const QString & _DBName, QWidget * parent)
	: mobileMacs(_mobileMacs), telephoneMacs(_telephoneMacs), DBName(_DBName), QTextBrowser(parent)
{
	this->setGeometry(0, 0, widWidth, widHeight);
}

AddressDetailContainer::~AddressDetailContainer()
{

}

void AddressDetailContainer::refresh(const int id)
{
	currID = id;

	QSqlDatabase db(QSqlDatabase::database(DBName));
	this->clear();

	QSqlQuery query(db);
	query.prepare("SELECT Addresses.name, Addresses.remark, Addresses.unit, Addresses.identity, Addresses.email, Groups.name as group_name, "
		"Addresses.mobile, Addresses.mobile2, Addresses.telephone "
		"FROM DSCD.Addresses LEFT OUTER JOIN DSCD.Groups ON DSCD.Addresses.group_id = DSCD.Groups.id "
		"WHERE Addresses.id = :id");
	query.bindValue(":id", currID);
	query.exec();
	
	query.next();
	QString name(query.value("name").toString());
	QString remark(query.value("remark").toString());
	QString unit(query.value("unit").toString());
	QString identity(query.value("identity").toString());
	QString email(query.value("email").toString());
	QString group(query.value("group_name").toString());
	QString mobile1(query.value("mobile").toString());
	QString mobile2(query.value("mobile2").toString());
	QString telephone(query.value("telephone").toString());

	query.prepare("SELECT phone_number, bg_time, ed_time FROM DSCD.Records WHERE address_id = :id");
	query.bindValue(":id", currID);
	query.exec();
	
	QVector<QPair<QString, QString>> timeStrs;
	while (query.next())
		timeStrs.append(QPair<QString, QString>(query.value("phone_number").toString(), 
			getDistanceTime(query.value("bg_time").toDateTime(), query.value("ed_time").toDateTime())));

	this->setText(generateNewRichText(name, remark, unit, identity, email, group, mobile1, mobile2, telephone, timeStrs));
}

QString AddressDetailContainer::generateNewRichText(const QString &name, const QString &remark, const QString &unit, 
	const QString &identity, const QString &email, const QString &group, const QString &mobile1, const QString &mobile2, 
	const QString &telephone, const QVector<QPair<QString, QString>> &timeStrs)
{
	QString newRichText("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">"
		"<html><head><meta name = \"qrichtext\" content = \"1\" / ><style type = \"text/css\">"
		"p, li{ white - space: pre - wrap; }"
		"</style></head><body style = \"font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">");

	newRichText += QString::fromLocal8Bit("<p style = \" margin-top:12px; margin-bottom:0px; margin-left:12px; margin-right:0px; "
		"-qt-block-indent:0; text-indent:0px;\"><span style = \" font-size:24pt;\">%1"
		"</span>").arg(name);

	if (!remark.isEmpty())
		newRichText += QString::fromLocal8Bit("<span style = \" font-size:18pt;\">（%2）</span>").arg(remark);

	newRichText += QString("</p><hr/>");

	if (!unit.isEmpty())
		newRichText += QString::fromLocal8Bit("<p style = \" margin-top:18px; margin-bottom:0px; margin-left:12px; margin-right:0px; "
			"-qt-block-indent:0; text-indent:0px;\"><span style = \" font-size:16pt;\">单位：%1</span></p>").arg(unit);

	if (!identity.isEmpty())
		newRichText += QString::fromLocal8Bit("<p style = \" margin-top:18px; margin-bottom:0px; margin-left:12px; margin-right:0px; "
			"-qt-block-indent:0; text-indent:0px;\"><span style = \" font-size:16pt;\">职务：%1</span></p>").arg(identity);

	if (!email.isEmpty())
		newRichText += QString::fromLocal8Bit("<p style = \" margin-top:18px; margin-bottom:0px; margin-left:12px; margin-right:0px; "
			"-qt-block-indent:0; text-indent:0px;\"><span style = \" font-size:16pt;\">邮箱：%1</span></p>").arg(email);

	if (!group.isEmpty())
		newRichText += QString::fromLocal8Bit("<p style = \" margin-top:18px; margin-bottom:0px; margin-left:12px; margin-right:0px; "
			"-qt-block-indent:0; text-indent:0px;\"><span style = \" font-size:16pt;\">分组：%1</span></p>").arg(group);

	if (!mobile1.isEmpty())
		newRichText += QString::fromLocal8Bit("<p style = \" margin-top:18px; margin-bottom:0px; margin-left:12px; margin-right:0px; "
			"-qt-block-indent:0; text-indent:0px;\"><span style = \" font-size:16pt;\">手机1：%1</span></p>").arg(mobile1);

	if (!mobile2.isEmpty())
		newRichText += QString::fromLocal8Bit("<p style = \" margin-top:18px; margin-bottom:0px; margin-left:12px; margin-right:0px; "
			"-qt-block-indent:0; text-indent:0px;\"><span style = \" font-size:16pt;\">手机2：%1</span></p>").arg(mobile2);

	if (!telephone.isEmpty())
		newRichText += QString::fromLocal8Bit("<p style = \" margin-top:18px; margin-bottom:0px; margin-left:12px; margin-right:0px; "
			"-qt-block-indent:0; text-indent:0px;\"><span style = \" font-size:16pt;\">座机：%1</span></p>").arg(telephone);

	newRichText += QString::fromLocal8Bit("<hr/><p style=\"margin-top:18px; margin-bottom:0px; margin-left:12px; margin-right:0px;"
		"-qt-block-indent:0; text-indent:0px; \"><span style=\"font-size:24pt; \">通话记录：</span></p>");

	for (unsigned int i(0), j(timeStrs.size()); i != j; ++i)
	{
		newRichText += QString("<p style = \"margin-top:18px; margin-bottom:0px; margin-left:12px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">"
			"<span style = \"font-size:16pt;\">%1</span></p>").arg(timeStrs[i].first);
		newRichText += QString("<p style = \"margin-top:6px; margin-bottom:0px; margin-left:12px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">"
			"<span style = \"font-size:12pt;\">%1</span></p>").arg(timeStrs[i].second);
	}

	return QString(newRichText);
}

QString AddressDetailContainer::getDistanceTime(const QDateTime & bgTime, const QDateTime & edTime)
{
	int distanceSec = bgTime.secsTo(edTime);
	QString distance;
	if (distanceSec >= 3600)
		distance = QString::fromLocal8Bit("%1时%2分%3秒").arg(distanceSec / 3600)
		.arg(distanceSec % 3600 / 60).arg(distanceSec % 60);
	else if (distanceSec >= 60)
		distance = QString::fromLocal8Bit("%1分%2秒").arg(distanceSec / 60).arg(distanceSec % 60);
	else
		distance = QString::fromLocal8Bit("%1秒").arg(distanceSec);

	return bgTime.toLocalTime().toString("yyyy-M-d h:m:s") + QString(" - ") +
		edTime.toLocalTime().toString("h:m:s") + QString::fromLocal8Bit("， 时长：") + distance;
}
