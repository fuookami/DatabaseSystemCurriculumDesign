#include "AddressWidget.h"

AddressWidget::AddressWidget(const QVector<AddressApp::MobileMac> &_mobileMacs, const QVector<AddressApp::TelephoneMac> _telephoneMacs,
	const QString &_DBName, QWidget * parent)
	: QWidget(parent), ui(new Ui::AdressesWidget()),
	mobileMacs(_mobileMacs), telephoneMacs(_telephoneMacs), DBName(_DBName)
{
	ui->setupUi(this);
}

AddressWidget::~AddressWidget()
{
}