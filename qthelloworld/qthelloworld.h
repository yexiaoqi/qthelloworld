#pragma once

#include <QMainWindow>
#include <QtWidgets/QWidget>
#include "ui_qthelloworld.h"
#include "UserAgeDialog.h"

class qthelloworld : public QMainWindow
{
	Q_OBJECT
public:
	qthelloworld(QWidget *parent = 0);
	~qthelloworld();

private:
	void open();
	void showUserAgeDialog();
	void setUserAge(int age);
	int userAge;
	QAction *openAction;
};
