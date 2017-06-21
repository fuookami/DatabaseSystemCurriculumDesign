#include "LoaderWidget.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QDesktopWidget>


const QString LoaderWidget::LoaderWidgetBgiFilePath("Resources\\Loader.jpg");

LoaderWidget::LoaderWidget(QWidget *parent /* = nullptr */)
	: QMainWindow(parent), ui(new Ui::Loader()),
	winWidth((QApplication::desktop()->screenGeometry().width() / 1920.0) * _width),
	winHeight((QApplication::desktop()->screenGeometry().height() / 1080.0) * _height), 
	bgiPix(new QPixmap(LoaderWidgetBgiFilePath)), 
	winFadeIn(new QPropertyAnimation(this, "windowOpacity"))
{
	ui->setupUi(this);
	ui->LoadingMsg->hide();

	setMinimumSize(QSize(winWidth, winHeight));
	setMaximumSize(QSize(winWidth, winHeight));
	setGeometry(QApplication::desktop()->screenGeometry().width() / 2.0 - winWidth / 2.0, 
		QApplication::desktop()->screenGeometry().height() / 2.0 - winHeight / 2.0, 
		winWidth, winHeight);
	setWindowFlags(Qt::FramelessWindowHint);

	*bgiPix = bgiPix->scaled(QSize(winWidth, winHeight));
	ui->bgi->setPixmap(*bgiPix);
	ui->bgi->setGeometry(0, 0, winWidth, winHeight);

	winFadeIn->setDuration(700);
	winFadeIn->setStartValue(0);
	winFadeIn->setEndValue(1);
	winFadeIn->setEasingCurve(QEasingCurve::InOutCubic);
	winFadeIn->start();
	connect(winFadeIn, SIGNAL(finished()), this, SLOT(winFadeInOver()));
}

LoaderWidget::~LoaderWidget()
{

}

void LoaderWidget::setText(const QString & str)
{
	ui->LoadingMsg->setText(str);
}

void LoaderWidget::winFadeInOver(void)
{
	delete winFadeIn;
	winFadeIn = nullptr;

	ui->LoadingMsg->show();
}