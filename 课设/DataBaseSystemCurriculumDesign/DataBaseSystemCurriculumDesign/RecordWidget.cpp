#include "RecordWidget.h"
#include <QtSql/QSqlQuery>

RecordWidget::RecordWidget(const QVector<AddressApp::MobileMac> &_mobileMacs, const QVector<AddressApp::TelephoneMac> &_telephoneMacs,
	const QString &_DBName, QWidget * parent)
	: QWidget(parent), ui(new Ui::RecordsWidget()), infoBtnContainer(new InfoBtnContainer()), 
	recordDetailContainer(new RecordDetailContainer(_DBName)),
	mobileMacs(_mobileMacs), telephoneMacs(_telephoneMacs), DBName(_DBName)
{
	ui->setupUi(this);
	ui->InfoContainer->setWidget(infoBtnContainer);
	ui->Container->setWidget(recordDetailContainer);
	connect(infoBtnContainer, SIGNAL(btnClicked(int)), this, SLOT(btnClickedSlot(int)));

	refreshRecordList();
}

RecordWidget::~RecordWidget()
{
}

void RecordWidget::btnClickedSlot(int id)
{
	recordDetailContainer->refresh(id);
}

void RecordWidget::refreshRecordList()
{
	infoBtnContainer->clear();
	for (unsigned int i(0), j(infoBtns.size()); i != j; ++i)
		delete infoBtns[i];
	infoBtns.clear();

	QSqlDatabase db(QSqlDatabase::database(DBName));
	QSqlQuery query(db);
	query.exec("SELECT Records.id, Records.phone_number, Records.bg_time, Records.ed_time, Addresses.name "
		"FROM DSCD.Records LEFT OUTER JOIN DSCD.Addresses on DSCD.Records.address_id = DSCD.Addresses.id "
		"order by Records.id DESC");

	while (query.next())
	{
		QString phoneNumber(query.value("phone_number").toString());
		RecordInfoBtn *newInfoBtn(new RecordInfoBtn(query.value("id").toInt(),
			phoneNumber, query.value("name").toString(),
			query.value("bg_time").toDateTime(), query.value("ed_time").toDateTime(),
			getLocalService(phoneNumber)));

		infoBtns.append(newInfoBtn);
		infoBtnContainer->addWidget(newInfoBtn);
	}
}

QString RecordWidget::getLocalService(const QString & phoneNumber)
{
	for (unsigned int i(0), j(mobileMacs.size()); i != j; ++i)
		if (phoneNumber.mid(3).startsWith(mobileMacs[i].mac))
			return mobileMacs[i].service + QString(" ") + mobileMacs[i].local;
	
	if (phoneNumber.isEmpty() || phoneNumber[0] == QChar('+'))
		return QString();

	for (unsigned int i(0), j(mobileMacs.size()); i != j; ++i)
		if (phoneNumber.startsWith(telephoneMacs[i].mac))
			return telephoneMacs[i].local;

	return QString();
}