#include "RecordWidget.h"

RecordWidget::RecordWidget(QWidget * parent)
	: QWidget(parent), ui(new Ui::RecordsWidget())
{
	ui->setupUi(this);
}

RecordWidget::~RecordWidget()
{
}
