#include"UserAgeDialog.h"
UserAgeDialog::~UserAgeDialog() {}
void UserAgeDialog::accept()
{
	emit userAgeChanged(newAge); // newAge is an int
	QDialog::accept();
}
