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
	qthelloworld();
	//qthelloworld(QWidget *parent = 0);
	~qthelloworld();
	
	//~qthelloworld();
protected:
	void mousePressEvent(QMouseEvent *event)
	{
		qDebug() << "MainWindow";
	}
	bool eventFilter(QObject *obj, QEvent *event);
private:
	void open();
	void openFile();
	void saveFile();
	void closeEvent(QCloseEvent *event);
	QAction *openAction;
	QAction *saveAction;
	QTextEdit *textEdit;
};
