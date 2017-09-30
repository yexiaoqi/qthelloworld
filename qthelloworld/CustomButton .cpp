#include<qdebug.h>
#include"CustomButton .h"
CustomButton::CustomButton(QWidget *parent) :
	QPushButton(parent)
{
	connect(this, &CustomButton::clicked,
		this, &CustomButton::onButtonCliecked);
}

void CustomButton::onButtonCliecked()
{
	qDebug() << "You clicked this!";
}
