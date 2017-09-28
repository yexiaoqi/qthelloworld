#pragma once

#include <QMainWindow>
#include <QtWidgets/QWidget>
#include<qlineedit.h>
#include<qdialog.h>
class UserAgeDialog:public QDialog
{
	Q_OBJECT
public:
	UserAgeDialog(QWidget *parent = 0);
	~UserAgeDialog();
	signals:
		void userAgeChanged(int newage);
private:
	void accept();
	int newAge;
};