#pragma once
#include<QObject>
#include <QMouseEvent>  
//#include<qstring.h>
#include<qlabel.h>
class EventLabel : public QLabel
{
	Q_OBJECT
public:
	EventLabel() {}
	~EventLabel() {}
protected:
	void mouseMoveEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
};