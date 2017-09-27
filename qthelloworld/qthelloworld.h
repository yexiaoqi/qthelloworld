#pragma once

#include <QMainWindow>
#include <QtWidgets/QWidget>
#include "ui_qthelloworld.h"

class qthelloworld : public QMainWindow
{
	Q_OBJECT
public:
	qthelloworld(QWidget *parent = 0);
	~qthelloworld();

private:
	void open();

	QAction *openAction;
};
