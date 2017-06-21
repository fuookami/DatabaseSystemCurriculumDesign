#pragma once

#include "ui_RecordsWidget.h"
#include <QtWidgets/QWidget>

class RecordWidget : public QWidget
{
	Q_OBJECT;

public:
	RecordWidget(QWidget *parent = nullptr);
	~RecordWidget();

private:
	Ui::RecordsWidget *ui;
};