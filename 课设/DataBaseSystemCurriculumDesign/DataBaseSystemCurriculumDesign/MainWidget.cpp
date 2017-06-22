#include "MainWidget.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QDesktopWidget>

const QString MainWidget::MainWidgetBgiFilePath("Resources\\MainWidgetBgi.jpg");
const unsigned int MainWidget::winWidth = 848;
const unsigned int MainWidget::winHeight = 480;

MainWidget::MainWidget(const QVector<AddressApp::MobileMac> &_mobileMacs, const QVector<AddressApp::TelephoneMac> &_telephoneMacs,
	const QString &_DBName, QWidget *parent /* = nullptr */)
	: QMainWindow(parent), ui(new Ui::MainWidget()),
	mobileMacs(_mobileMacs), telephoneMacs(_telephoneMacs), DBName(_DBName),
	bgiPix(new QPixmap(MainWidgetBgiFilePath)),
	winFadeIn(new QPropertyAnimation(this, "windowOpacity"))
{
	ui->setupUi(this);

	setMinimumSize(QSize(winWidth, winHeight));
	setMaximumSize(QSize(winWidth, winHeight));
	setGeometry(QApplication::desktop()->screenGeometry().width() / 2.0 - winWidth / 2.0,
		QApplication::desktop()->screenGeometry().height() / 2.0 - winHeight / 2.0,
		winWidth, winHeight);
	setWindowFlags(Qt::FramelessWindowHint);

	ui->bgi->setPixmap(*bgiPix);
	ui->bgi->setGeometry(0, 0, winWidth, winHeight);

	winFadeIn->setDuration(700);
	winFadeIn->setStartValue(0);
	winFadeIn->setEndValue(1);
	winFadeIn->setEasingCurve(QEasingCurve::InOutCubic);
	winFadeIn->start();

	setBtnSiderUnactivePalette(ui->AddressSider);
	setBtnSiderUnactivePalette(ui->RecordSider);

	connect(winFadeIn, SIGNAL(finished()), this, SLOT(winFadeInOver()));
}

MainWidget::~MainWidget()
{
}

void MainWidget::addressSlot(void)
{
	setBtnSiderActivePalette(ui->AddressSider);
	setBtnSiderUnactivePalette(ui->RecordSider);

	addressWidget = new AddressWidget(mobileMacs, telephoneMacs, DBName);
	ui->Container->setWidget(addressWidget);
	addressWidget->show();
}

void MainWidget::recordSlot(void)
{
	setBtnSiderUnactivePalette(ui->AddressSider);
	setBtnSiderActivePalette(ui->RecordSider);

	recordWidget = new RecordWidget(mobileMacs, telephoneMacs, DBName);
	ui->Container->setWidget(recordWidget);
	recordWidget->show();
}

void MainWidget::setBtnSiderActivePalette(QLabel *l)
{
	QPalette palette(l->palette());
	palette.setColor(QPalette::Background, QColor(163, 73, 73));
	l->setPalette(palette);
}

void MainWidget::setBtnSiderUnactivePalette(QLabel *l)
{
	QPalette palette(l->palette());
	palette.setColor(QPalette::Background, QColor(135, 133, 136));
	l->setPalette(palette);
}

void MainWidget::closeSlot()
{
	this->close();
}

void MainWidget::winFadeInOver()
{
	disconnect(winFadeIn);
	delete winFadeIn;
	winFadeIn = nullptr;

	connect(ui->CloseBtn, SIGNAL(clicked()), this, SLOT(closeSlot()));
	connect(ui->AddressBtn, SIGNAL(clicked()), this, SLOT(addressSlot()));
	connect(ui->RecoredBtn, SIGNAL(clicked()), this, SLOT(recordSlot()));
}