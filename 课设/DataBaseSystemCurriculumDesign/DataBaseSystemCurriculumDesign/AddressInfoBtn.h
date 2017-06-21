#pragma once

#include "Basic.h"
#include "ui_AdressInfoWidget.h"
#include <QtWidgets/QPushButton>

class AddressInfoBtn : public QPushButton
{
	Q_OBJECT;

public:
	AddressInfoBtn(int id, const QString &name, const QString &unit, const QString &identity,
		QWidget *parent = nullptr);
	~AddressInfoBtn();

signals:
	void clicked(int id);

private slots:
	void clickedSlot(void);

private:
	int id;
	QString name;
	QString unitIdentity;
	Ui::AdressInfoWidget *ui;
};