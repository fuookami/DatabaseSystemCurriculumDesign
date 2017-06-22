#include "AddressDetailInput.h"

AddressDetailInput::AddressDetailInput(QWidget * parent)
	: ui(new Ui::AdressDetailInput()), QWidget(parent), currID(0)
{
	ui->setupUi(this);
	ui->label_9->hide();
	ui->Mobile2->hide();

	connect(ui->Mobile1, SIGNAL(textChanged(const QString &)), this, SLOT(mobileTexteditHandler(const QString &)));
	connect(ui->Upload, SIGNAL(clicked()), this, SLOT(uploadSlot()));
	connect(ui->Cancel, SIGNAL(clicked()), this, SLOT(clearSlot()));
}

AddressDetailInput::~AddressDetailInput()
{
}

void AddressDetailInput::set(const AddressData & data)
{
	currID = data.id;
	ui->Name->setText(data.name);
	ui->Remark->setText(data.remark);
	ui->Unit->setText(data.unit);
	ui->Identity->setText(data.identity);
	ui->Email->setText(data.email);
	ui->Mobile1->setText(data.mobile);
	ui->Mobile2->setText(data.mobile2);
	ui->Telephone->setText(data.telephone);
}

void AddressDetailInput::clear()
{
	currID = 0;
	ui->Name->clear();
	ui->Remark->clear();
	ui->Unit->clear();
	ui->Identity->clear();
	ui->Email->clear();
	ui->Mobile1->clear();
	ui->Mobile2->clear();
	ui->Telephone->clear();
}

void AddressDetailInput::mobileTexteditHandler(const QString &str)
{
	if (!str.isEmpty())
	{
		ui->label_9->show();
		ui->Mobile2->show();
	}
	else
	{
		ui->label_9->hide();
		ui->Mobile2->hide();
		ui->Mobile2->clear();
	}
}

void AddressDetailInput::uploadSlot(void)
{
	AddressData data = {
		currID,
		ui->Name->text(),
		ui->Remark->text(),
		ui->Unit->text(),
		ui->Identity->text(),
		ui->Email->text(),
		ui->Mobile1->text(),
		ui->Mobile2->text(),
		ui->Telephone->text()
	};

	emit upload(std::move(data));
}

void AddressDetailInput::clearSlot(void)
{
	clear();
}