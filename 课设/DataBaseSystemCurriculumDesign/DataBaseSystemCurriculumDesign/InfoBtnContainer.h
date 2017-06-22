#pragma once

#include "Basic.h"
#include <QtWidgets/QWidget>
#include <QtCore/QVector>

class InfoBtnContainer : public QWidget
{
	Q_OBJECT;

public:
	InfoBtnContainer(QWidget *parent = nullptr);
	~InfoBtnContainer();

	void addWidget(QWidget *w);
	void clear(void);

signals:
	void btnClicked(int id);

private:
	static const unsigned int widWidth = 293;
	unsigned int widHieght = 0;
	QVector<QWidget *> widgets;

private slots :
	void btnClickedSlot(int id);
};