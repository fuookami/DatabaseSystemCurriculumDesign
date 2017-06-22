#include "AddressWidget.h"

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QtCore/QDebug>

AddressWidget::AddressWidget(const QVector<AddressApp::MobileMac> &_mobileMacs, const QVector<AddressApp::TelephoneMac> &_telephoneMacs,
	const QString &_DBName, QWidget * parent)
	: QWidget(parent), ui(new Ui::AdressesWidget()), infoBtnContainer(new InfoBtnContainer()),
	mobileMacs(_mobileMacs), telephoneMacs(_telephoneMacs), DBName(_DBName), state(Nothing)
{
	ui->setupUi(this);
	ui->InfoContainer->setWidget(infoBtnContainer);
	infoBtnContainer->show();

	connect(infoBtnContainer, SIGNAL(btnClicked(int)), this, SLOT(infoBtnClicked(int)));
	connect(ui->DelBtn, SIGNAL(clicked()), this, SLOT(deleteBtnClicked()));

	refreshAddressList();
}

AddressWidget::~AddressWidget()
{
}

void AddressWidget::infoBtnClicked(int id)
{
	currID = id;
	if (state != Nothing)
	{
		// delete input;
	}
	state = Detail;

	addressDetailContainer = new AddressDetailContainer(mobileMacs, telephoneMacs, DBName);
	ui->Container->setWidget(addressDetailContainer);
	addressDetailContainer->refresh(id);
}

void AddressWidget::deleteBtnClicked()
{
	addressDetailContainer->close();
	delete addressDetailContainer;
	state = Nothing;

	QSqlDatabase db(QSqlDatabase::database(DBName));
	QSqlQuery query(db);
	query.prepare("DELETE FROM DSCD.Addresses WHERE id = :id");
	query.bindValue(":id", currID);
	query.exec();

	currID = 0;

	refreshAddressList();
}

void AddressWidget::refreshAddressList()
{
	for (unsigned int i(0), j(infoBtns.size()); i != j; ++i)
		delete infoBtns[i];
	infoBtnContainer->clear();
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