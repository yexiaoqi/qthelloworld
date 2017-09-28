#include<qdialog.h>
#include"UserAgeDialog.h"
UserAgeDialog::~UserAgeDialog() {}
void UserAgeDialog::accept()
{
	emit userAgeChanged(newAge); // newAge is an int
	QDialog::accept();
}
void UserAgeDialog::userAgeChanged(int newage) {}
void UserAgeDialog::setUserAge() {}