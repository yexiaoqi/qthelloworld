#include <QAction>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QToolBar>
#include<qdebug.h>
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

void qthelloworld::open()
{
	//QMessageBox::information(this, tr("Information"), tr("Open"));
#if 0
	//exp:对话框QMessageBox应用1
	if (QMessageBox::Yes == QMessageBox::question(this,
		tr("Question"),
		tr("Are you OK?"),
		QMessageBox::Yes | QMessageBox::No,
		QMessageBox::Yes)) // this，即 qthelloworld（或者其他 QWidget 指针）
	{
		QMessageBox::information(this, tr("Hmmm..."), tr("I'm glad to hear that!"));
	}
	else 
	{
		QMessageBox::information(this, tr("Hmmm..."), tr("I'm sorry!"));
	}
#endif

#if 1
	//exp:对话框QMessageBox应用2
	QMessageBox msgBox;
	msgBox.setText(tr("The document has been modified."));
	msgBox.setInformativeText(tr("Do you want to save your changes?"));
	msgBox.setDetailedText(tr("Differences here..."));
	msgBox.setStandardButtons(QMessageBox::Save
		| QMessageBox::Discard
		| QMessageBox::Cancel);
	msgBox.setDefaultButton(QMessageBox::Save);
	int ret = msgBox.exec();
	switch (ret) {
	case QMessageBox::Save:
		qDebug() << "Save document!";
		break;
	case QMessageBox::Discard:
		qDebug() << "Discard changes!";
		break;
	case QMessageBox::Cancel:
		qDebug() << "Close document!";
		break;
	}
#endif

#if 0
	//QDialog dialog;
	QDialog dialog(this);
	dialog.setWindowTitle(tr("Hello, dialog!"));
	dialog.exec();//模态对话框，会阻塞同一应用程序中其它窗口的输入
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