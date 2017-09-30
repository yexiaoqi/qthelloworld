#pragma once
#include<QObject>
#include<QEvent>
#include<QKeyEvent>
#include<qDebug>
class FilterObject
{
	Q_OBJECT
public:
	FilterObject(QObject *parent) {}
	~FilterObject() {}
private:
	bool eventFilter(QObject *object, QEvent *event);
};