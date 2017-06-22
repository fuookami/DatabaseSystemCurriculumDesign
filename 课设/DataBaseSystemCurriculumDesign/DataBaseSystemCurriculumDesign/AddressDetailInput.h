#pragma once

#include "ui_AdressDetailInput.h"
#include <QtWidgets/QWidget>

struct AddressData
{
	int id;
	QString name;
	QString remark;
	QString unit;
	QString identity;
	QString email;
	QString mobile;
	QString mobile2;
	QString telephone;
};

class AddressDetailInput : public QWidget
{
	Q_OBJECT;

public:
	AddressDetailInput(QWidget *parent = nullptr);
	~AddressDetailInput();

	void set(const AddressData &data);
	void clear();

signals:
	void upload(const AddressData &data);

private slots:
	void mobileTexteditHandler(const QString &str);
	void uploadSlot(void);
	void clearSlot(void);

private:
	int currID;
	Ui::AdressDetailInput *ui;
};