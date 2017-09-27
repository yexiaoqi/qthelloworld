#pragma once

#include <QtWidgets/QWidget>
#include "ui_qthelloworld.h"

class qthelloworld : public QWidget
{
	Q_OBJECT

public:
	qthelloworld(QWidget *parent = Q_NULLPTR);

private:
	Ui::qthelloworldClass ui;
};
