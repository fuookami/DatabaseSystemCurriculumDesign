#include "InfoBtnContainer.h"

InfoBtnContainer::InfoBtnContainer(QWidget * parent)
	: widHieght(0), QWidget(parent)
{
}

InfoBtnContainer::~InfoBtnContainer()
{
}

void InfoBtnContainer::addWidget(QWidget * w)
{
	if (w != nullptr)
	{
		w->setParent(this);
		this->setGeometry(0, 0, widWidth, widHieght + w->height() + 5);
		w->setGeometry(0, widHieght, w->width(), w->height());
		widHieght += w->height() + 5;
		connect(w, SIGNAL(clicked(int)), this, SLOT(btnClickedSlot(int)));
	}
}

void InfoBtnContainer::btnClickedSlot(int id)
{
	emit btnClicked(id);
}