#pragma once
#include<QOBject>
#include<QWidget>
#include<QEvent>
#include<QKeyEvent>
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
		QWidget::mousePressEvent(event);
		qDebug() << "CustomWidget";
	}
private:
	bool event(QEvent *e);//����protected�л���ʾδ�ҵ���������
};