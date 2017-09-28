#pragma once

#include <QMainWindow>
#include <QtWidgets/QWidget>
#include "ui_qthelloworld.h"
#include <qfiledialog.h>

class qthelloworld : public QMainWindow
{
	Q_OBJECT
public:
	qthelloworld(QWidget *parent = 0);
	~qthelloworld();
	

private:
	void open();
	void openFile();
	void saveFile();
	QAction *openAction;
	QAction *saveAction;
	QTextEdit *textEdit;
};
