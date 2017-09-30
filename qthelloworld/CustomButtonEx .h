#pragma once
#include<QOBject>
#include"CustomButton .h"
class CustomButtonEx : public CustomButton
{
	Q_OBJECT
public:
	CustomButtonEx(QWidget *parent) : CustomButton(parent)
	{
	}
protected:
	void mousePressEvent(QMouseEvent *event)
	{
		qDebug() << "CustomButtonEx";
	}
	//void mousePressEvent(QMouseEvent *event);
};