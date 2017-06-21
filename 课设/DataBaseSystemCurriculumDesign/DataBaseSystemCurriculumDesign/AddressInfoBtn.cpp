#include "AddressInfoBtn.h"

AddressInfoBtn::AddressInfoBtn(int _id, const QString &_name, const QString _remark,
	const QString &_unit, const QString &_identity, QWidget *parent /* = nullptr */)
	: id(_id), nameRemark(_name + QString::fromLocal8Bit(" £¨") + _remark + QString::fromLocal8Bit("£©")), 
	unitIdentity(_unit + QString(" ") + _identity), ui(new Ui::AdressInfoBtn()), QPushButton(parent)
{
	ui->setupUi(this);
	this->setStyleSheet(QString(
		"QPushButton { background-color: rgba(255, 255, 255, 0); border:none; }"
		"QPushButton:hover { background-color: rgba(0, 0, 0, 0.2); }"
		"QPushButton:pressed {background-color: rgba(0, 0, 0, 0.3); }"));

	ui->NameRemark->setText(nameRemark);
	ui->UnitIndentity->setText(unitIdentity);
	connect(this, SIGNAL(clicked()), this, SLOT(clickedSlot()));
}

AddressInfoBtn::~AddressInfoBtn()
{

}

void AddressInfoBtn::clickedSlot()
{
	emit clicked(id);
}