#include "AddressWidget.h"

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlRecord>
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
	infoBtns.clear();

	QSqlDatabase db(QSqlDatabase::database(DBName));
	QSqlTableModel model(nullptr, db);
	model.setTable("Addresses");
	model.setFilter("id > 0");
	model.select();

	for (unsigned int i(0), j(model.rowCount()); i != j; ++i)
	{
		QSqlRecord record(model.record(i));
		AddressInfoBtn *newInfoBtn(new AddressInfoBtn(record.value("id").toInt(),
			record.value("name").toString(), record.value("remark").toString(),
			record.value("unit").toString(), record.value("identity").toString()));
		infoBtns.append(newInfoBtn);
		infoBtnContainer->addWidget(newInfoBtn);
	}
}