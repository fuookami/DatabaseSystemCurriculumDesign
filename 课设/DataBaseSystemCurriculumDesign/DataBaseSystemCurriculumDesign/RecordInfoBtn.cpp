#include "RecordInfoBtn.h"

RecordInfoBtn::RecordInfoBtn(int _id, const QString & _phoneNumber, const QDateTime & _bgTime, 
	const QDateTime & _edTime, const QString & _localService, QWidget * parent)
	: id(_id), phoneNumber(_phoneNumber), timeLocal(_bgTime.toLocalTime().toString("YYYY-MM-DD HH:MI:SS")
		+ QString(" - ") + _edTime.toLocalTime().toString("HH:MI:SS") + QString(" ") + _localService),
	ui(new Ui::RecordInfoBtn()), QPushButton(parent)
{
	ui->setupUi(this);
	this->setStyleSheet(QString(
		"QPushButton { background-color: rgba(255, 255, 255, 0); border:none; }"
		"QPushButton:hover { background-color: rgba(0, 0, 0, 0.2); }"
		"QPushButton:pressed {background-color: rgba(0, 0, 0, 0.3); }"));

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