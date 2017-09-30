#pragma once
#include<QObject>
#include<QWidget>
#include<QEvent>
#include<qDebug>
class Label : public QWidget
{
public:
	Label()
	{
		installEventFilter(this);
	}

	bool eventFilter(QObject *watched, QEvent *event)
	{
		if (watched == this) {
			if (event->type() == QEvent::MouseButtonPress) {
				qDebug() << "eventFilter";
			}
		}
		return false;
	}

protected:
	void mousePressEvent(QMouseEvent *)
	{
		qDebug() << "mousePressEvent";
	}

	bool event(QEvent *e)
	{
		if (e->type() == QEvent::MouseButtonPress) {
			qDebug() << "event";
		}
		return QWidget::event(e);
	}
};