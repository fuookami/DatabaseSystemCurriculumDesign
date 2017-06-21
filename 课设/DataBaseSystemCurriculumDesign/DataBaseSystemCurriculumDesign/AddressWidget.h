#pragma once

#include "ui_AdressesWidget.h"
#include <QtWidgets/QWidget>

class AddressWidget : public QWidget
{
	Q_OBJECT;

public:
	AddressWidget(QWidget *parent = nullptr);
	~AddressWidget();

private:
	Ui::AdressesWidget *ui;
};