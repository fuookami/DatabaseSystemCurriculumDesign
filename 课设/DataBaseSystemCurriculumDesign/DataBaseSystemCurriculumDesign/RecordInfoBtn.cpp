#include "RecordInfoBtn.h"

RecordInfoBtn::RecordInfoBtn(int _id, const QString & _phoneNumber, const QString &_addressName, 
	const QDateTime & _bgTime, const QDateTime & _edTime, const QString & _localService, QWidget * parent)
	: id(_id), phoneNumber(_phoneNumber), timeLocal(_bgTime.toLocalTime().toString("yyyy-M-d h:m:s")
		+ QString(" - ") + _edTime.toLocalTime().toString("h:m:s")),
	ui(new Ui::RecordInfoBtn()), QPushButton(parent)
{
	ui->setupUi(this);
	this->setStyleSheet(QString(
		"QPushButton { background-color: rgba(255, 255, 255, 0); border:none; }"
		"QPushButton:hover { background-color: rgba(0, 0, 0, 0.2); }"
		"QPushButton:pressed {background-color: rgba(0, 0, 0, 0.3); }"));

	if (!_addressName.isEmpty())
		phoneNumber += QString::fromLocal8Bit(" £¨") + _addressName + QString::fromLocal8Bit("£©");

	if (!_localService.isEmpty())
		timeLocal += QString(" ") + _localService;

	ui->PhoneNumber->setText(phoneNumber);
	ui->TimeLocal->setText(timeLocal);
	connect(this, SIGNAL(clicked()), this, SLOT(clickedSlot()));
}

RecordInfoBtn::~RecordInfoBtn()
{

}

void RecordInfoBtn::clickedSlot()
{
	emit clicked(id);
}