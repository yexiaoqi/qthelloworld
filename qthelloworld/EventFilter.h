#pragma once
#include<QObject>
#include<QEvent>
#include<qDebug>
class EventFilter : public QObject
{
public:
	EventFilter(QObject *watched, QObject *parent = 0) :
		QObject(parent),
		m_watched(watched)
	{
	}

	bool eventFilter(QObject *watched, QEvent *event)
	{
		if (watched == m_watched) {
			if (event->type() == QEvent::MouseButtonPress) {
				qDebug() << "QApplication::eventFilter";
			}
		}
		return false;
	}

private:
	QObject *m_watched;
};