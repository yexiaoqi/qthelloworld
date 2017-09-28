#include <QAction>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QToolBar>
#include <QDebug>
#include "qthelloworld.h"


qthelloworld::qthelloworld(QWidget *parent) :
	QMainWindow(parent)
{
	setWindowTitle(tr("Main Window"));

	openAction = new QAction(QIcon(":/images/test"), tr("&Open..."), this);
	openAction->setShortcuts(QKeySequence::Open);//快捷键
	openAction->setStatusTip(tr("Open an existing file"));
	connect(openAction, &QAction::triggered, this, &qthelloworld::open);

	QMenu *file = menuBar()->addMenu(tr("&File"));
	file->addAction(openAction);

	QToolBar *toolBar = addToolBar(tr("&File"));
	toolBar->addAction(openAction);
	QToolBar *toolBar2 = addToolBar(tr("Tool Bar 2"));//右键点击icon，显示toolbar名称，并可以通过勾选选择显示哪几个toobar
	toolBar2->addAction(openAction);

	statusBar();
}

qthelloworld::~qthelloworld()
{
}

void qthelloworld::showUserAgeDialog()
{
	UserAgeDialog *dialog = new UserAgeDialog(this);
	connect(dialog, &UserAgeDialog::userAgeChanged, this, &qthelloworld::setUserAge);
	dialog->show();
}

void qthelloworld::setUserAge(int age)
{
	userAge = age;
}

void qthelloworld::open()
{
	//QMessageBox::information(this, tr("Information"), tr("Open"));
#if 1
	//QDialog dialog;
	QDialog dialog(this);
	dialog.setWindowTitle(tr("Hello, dialog!"));
	dialog.exec();//模态对话框，会阻塞同一应用程序中其它窗口的输入
	qDebug() << dialog.result();//对话框关闭，exec()函数返回，此时取得对话框的数据。(为0）
#if 0
	if (dialog.exec() == QDialog::Accepted) 
	{
		//qDebug() << dialog.result();
		qDebug() << "accepted";
	}
	else {
		qDebug() << "rejected";
	}
#endif
	//dialog.show();//在栈上建立，show()函数返回，MainWindow::open()函数结束，dialog 超出作用域被析构，因此对话框消失
#endif
#if 0
	QDialog *dialog = new QDialog;
	dialog->setWindowTitle(tr("Hello, dialog!"));
	dialog->show();//改为在堆上建立  非模态对话框   没有delete，存在内存泄漏
#endif

#if 0
	QDialog *dialog = new QDialog;
	dialog->setAttribute(Qt::WA_DeleteOnClose);//setAttribute()函数设置对话框关闭时，自动销毁对话框
	dialog->setWindowTitle(tr("Hello, dialog!"));
	dialog->show();
#endif


}