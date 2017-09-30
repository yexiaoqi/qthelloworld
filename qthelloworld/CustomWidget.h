#pragma once
#include<QOBject>
#include<QWidget>
#include<qDebug>
class CustomWidget : public QWidget
{
	Q_OBJECT
public:
	CustomWidget(QWidget *parent) : QWidget(parent)
	{
	}
protected:
	void mousePressEvent(QMouseEvent *event)
	{
		qDebug() << "CustomWidget";
	}
};