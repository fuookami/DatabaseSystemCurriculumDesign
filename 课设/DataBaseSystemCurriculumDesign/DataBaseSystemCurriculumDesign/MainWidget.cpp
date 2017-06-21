#include "MainWidget.h"

const QString MainWidgetBgiFilePath("Resources\\MainWidgetBgi.jpg");
const unsigned int winWidth = 480;
const unsigned int winHeight = 848;

MainWidget::MainWidget(QWidget *parent = nullptr)
	: QMainWindow(parent), ui(new Ui::MainWidget()), 
	bgiPix(new QPixMap(MainWidgetBgiFilePath)),
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
	connect(winFadeIn, SIGNAL(finished()), this, SLOT(winFadeInOver()));
}

MainWidget::~MainWidget()
{
}

void MainWidget::winFadeIn()
{
	disconnect(winFadeIn);
	delete winFadeIn;
	winFadeIn = nullptr;
}