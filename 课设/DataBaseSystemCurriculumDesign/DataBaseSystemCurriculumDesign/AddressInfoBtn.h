#pragma once

#include "Basic.h"
#include "ui_AdressInfoBtn.h"
#include <QtWidgets/QPushButton>

class AddressInfoBtn : public QPushButton
{
	Q_OBJECT;

public:
	AddressInfoBtn(int _id, const QString &_name, const QString _remark, 
		const QString &_unit, const QString &_identity, QWidget *parent = nullptr);
	~AddressInfoBtn();

signals:
	void clicked(int id);

private slots:
	void clickedSlot(void);

private:
	int id;
	QString nameRemark;
	QString unitIdentity;
	Ui::AdressInfoBtn *ui;
};