#pragma once
#include<QObject>//������object.h
#include<QMouseEvent>
#include<qpushbutton.h>
#include<qdebug.h>
class CustomButton : public QPushButton
{
	Q_OBJECT
public:
	CustomButton(QWidget *parent = 0);
protected:
	void mousePressEvent(QMouseEvent *event)
	{
		qDebug() << "CustomButton";
	}
private:
	void onButtonCliecked();
};