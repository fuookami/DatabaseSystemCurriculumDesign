#pragma once

#include "Basic.h"
#include "ui_RecordInfoBtn.h"
#include <QtWidgets/QPushButton>
#include <QtCore/QDateTime>

class RecordInfoBtn : public QPushButton
{
	Q_OBJECT;

public:
	RecordInfoBtn(int _id, const QString &_phoneNumber, const QDateTime &_bgTime, 
		const QDateTime &_edTime, const QString &_localService, QWidget *parent = nullptr);
	~RecordInfoBtn();

signals:
	void clicked(int id);

private slots:
	void clickedSlot(void);

private:
	int id;
	QString phoneNumber;
	QString timeLocal;
	Ui::RecordInfoBtn *ui;
};