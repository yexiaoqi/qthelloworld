#pragma once

#include <QMainWindow>
#include <QtWidgets/QWidget>
class UserAgeDialog:public QDialog
{
	Q_OBJECT
public:
	UserAgeDialog(QWidget *parent = 0);
	~UserAgeDialog();
private:
	void accept();
	void userAgeChanged(int newage);
	void setUserAge();
};