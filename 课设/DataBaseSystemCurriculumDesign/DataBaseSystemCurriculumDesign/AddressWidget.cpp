#include "AddressWidget.h"

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QtCore/QDebug>

AddressWidget::AddressWidget(const QVector<AddressApp::MobileMac> &_mobileMacs, const QVector<AddressApp::TelephoneMac> &_telephoneMacs,
	const QString &_DBName, QWidget * parent)
	: QWidget(parent), ui(new Ui::AdressesWidget()), infoBtnContainer(new InfoBtnContainer()),
	mobileMacs(_mobileMacs), telephoneMacs(_telephoneMacs), DBName(_DBName)
{
	ui->setupUi(this);
	ui->InfoContainer->setWidget(infoBtnContainer);

	refreshAddressList();
}

AddressWidget::~AddressWidget()
{
}

void AddressWidget::refreshAddressList()
{
	infoBtnContainer->clear();
	for (unsigned int i(0), j(infoBtns.size()); i != j; ++i)
		delete infoBtns[i];
	infoBtns.clear();

	QSqlDatabase db(QSqlDatabase::database(DBName));
	QSqlQuery query(db);
	query.exec("SELECT id, name, unit, identity, remark FROM DSCD.Addresses WHERE id > 0");

	while (query.next())
	{
		AddressInfoBtn *newInfoBtn(new AddressInfoBtn(query.value("id").toInt(),
			query.value("name").toString(), query.value("remark").toString(),
			query.value("unit").toString(), query.value("identity").toString()));

		infoBtns.append(newInfoBtn);
		infoBtnContainer->addWidget(newInfoBtn);
	}
}