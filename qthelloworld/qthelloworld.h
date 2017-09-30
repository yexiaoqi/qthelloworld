#pragma once

#include <QMainWindow>
#include <QtWidgets/QWidget>
#include <QTextEdit>
#include<QVBoxLayout>
#include "ui_qthelloworld.h"
#include <qfiledialog.h>
#include"CustomButtonEx .h"
#include"CustomWidget.h"

class qthelloworld : public QMainWindow
{
	Q_OBJECT
public:
	qthelloworld(QWidget *parent = 0);
	~qthelloworld();
	
	//~qthelloworld();
protected:
	void mousePressEvent(QMouseEvent *event)
	{
		qDebug() << "MainWindow";
	}
private:
	void open();
	void openFile();
	void saveFile();
	QAction *openAction;
	QAction *saveAction;
	QTextEdit *textEdit;
};
