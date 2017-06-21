#include "AddressWidget.h"

AddressWidget::AddressWidget(QWidget * parent)
	: QWidget(parent), ui(new Ui::AdressesWidget())
{
	ui->setupUi(this);
}

AddressWidget::~AddressWidget()
{
}
