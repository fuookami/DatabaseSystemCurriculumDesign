#include "AddressWidget.h"

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QtCore/QDebug>
#include <QtWidgets/QMessageBox>

AddressWidget::AddressWidget(const QVector<AddressApp::MobileMac> &_mobileMacs, const QVector<AddressApp::TelephoneMac> &_telephoneMacs,
	const QString &_DBName, QWidget * parent)
	: QWidget(parent), ui(new Ui::AdressesWidget()), infoBtnContainer(new InfoBtnContainer()),
	mobileMacs(_mobileMacs), telephoneMacs(_telephoneMacs), DBName(_DBName), state(Nothing)
{
	ui->setupUi(this);
	ui->InfoContainer->setWidget(infoBtnContainer);
	infoBtnContainer->show();
	ui->ModifyBtn->setEnabled(false);

	connect(infoBtnContainer, SIGNAL(btnClicked(int)), this, SLOT(infoBtnClicked(int)));
	connect(ui->AddBtn, SIGNAL(clicked()), this, SLOT(addBtnClicked()));
	connect(ui->ModifyBtn, SIGNAL(clicked()), this, SLOT(modifyBtnClicked()));
	connect(ui->DelBtn, SIGNAL(clicked()), this, SLOT(deleteBtnClicked()));

	refreshAddressList();
}

AddressWidget::~AddressWidget()
{
}

void AddressWidget::infoBtnClicked(int id)
{
	currID = id;
	if (state != Nothing && state != Detail)
	{
		disconnect(addressDetailInput);
		addressDetailInput->close();
		delete addressDetailInput;
	}
	state = Detail;
	ui->ModifyBtn->setEnabled(true);

	addressDetailContainer = new AddressDetailContainer(mobileMacs, telephoneMacs, DBName);
	ui->Container->setWidget(addressDetailContainer);
	addressDetailContainer->show();
	addressDetailContainer->refresh(id);
}

void AddressWidget::uploadDataSlot(const AddressData &data)
{
	QSqlDatabase db(QSqlDatabase::database(DBName));

	if (data.id == 0)
	{
		QString sql(QString("INSERT INTO DSCD.Addresses (id, name, mobile, mobile2, telephone, unit, identity, remark, email) "
			"VALUES (DSCD.SEQ_DSCD_ADDRESS_ID.nextval, %1, %2, %3, %4, %5, %6, %7, %8)")
			.arg(data.name.isEmpty() ? "NULL" : QString("'%1'").arg(data.name))
			.arg(data.mobile.isEmpty() ? "NULL" : QString("'%1'").arg(data.mobile))
			.arg(data.mobile2.isEmpty() ? "NULL" : QString("'%1'").arg(data.mobile2))
			.arg(data.telephone.isEmpty() ? "NULL" : QString("'%1'").arg(data.telephone))
			.arg(data.unit.isEmpty() ? "NULL" : QString("'%1'").arg(data.unit))
			.arg(data.identity.isEmpty() ? "NULL" : QString("'%1'").arg(data.identity))
			.arg(data.remark.isEmpty() ? "NULL" : QString("'%1'").arg(data.remark))
			.arg(data.email.isEmpty() ? "NULL" : QString("'%1'").arg(data.email))
		);

		QSqlQuery query(db);
		query.exec(sql);

		QMessageBox::information(nullptr, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("添加成功"));
	}
	else
	{
		QString sql(QString("UPDATE DSCD.Addresses SET name = %1, mobile = %2, mobile2 = %3, telephone = %4"
			"unit = %5, identity = %6, remark = %7, email = %8 WHERE id = %9")
			.arg(data.name.isEmpty() ? "NULL" : QString("'%1'").arg(data.name))
			.arg(data.mobile.isEmpty() ? "NULL" : QString("'%1'").arg(data.mobile))
			.arg(data.mobile2.isEmpty() ? "NULL" : QString("'%1'").arg(data.mobile2))
			.arg(data.telephone.isEmpty() ? "NULL" : QString("'%1'").arg(data.telephone))
			.arg(data.unit.isEmpty() ? "NULL" : QString("'%1'").arg(data.unit))
			.arg(data.identity.isEmpty() ? "NULL" : QString("'%1'").arg(data.identity))
			.arg(data.remark.isEmpty() ? "NULL" : QString("'%1'").arg(data.remark))
			.arg(data.email.isEmpty() ? "NULL" : QString("'%1'").arg(data.email))
			.arg(data.id)
		);

		QSqlQuery query(db);
		query.exec(sql);

		QMessageBox::information(nullptr, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("修改成功"));
	}

	disconnect(addressDetailInput);
	addressDetailInput->close();
	delete addressDetailInput;
	state = Nothing;
	refreshAddressList();
}

void AddressWidget::addBtnClicked()
{
	ui->ModifyBtn->setEnabled(false);
	if (state == Modify)
	{
		addressDetailInput->clear();
	}
	else 
	{
		if (state == Detail)
		{
			addressDetailContainer->close();
			delete addressDetailContainer;
		}

		addressDetailInput = new AddressDetailInput();
		ui->Container->setWidget(addressDetailInput);
		addressDetailInput->show();
		connect(addressDetailInput, SIGNAL(upload(const AddressData &)), this, SLOT(uploadDataSlot(const AddressData &)));
	}

	state = Add;
}

void AddressWidget::modifyBtnClicked()
{
	ui->ModifyBtn->setEnabled(false);
	if (state == Detail)
	{
		addressDetailContainer->close();
		delete addressDetailContainer;

		addressDetailInput = new AddressDetailInput();
		ui->Container->setWidget(addressDetailInput);
		addressDetailInput->show();
		connect(addressDetailInput, SIGNAL(upload(const AddressData &)), this, SLOT(uploadDataSlot(const AddressData &)));

		// set data

		state = Modify;
	}
}

void AddressWidget::deleteBtnClicked()
{
	addressDetailContainer->close();
	delete addressDetailContainer;
	state = Nothing;
	ui->ModifyBtn->setEnabled(false);

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