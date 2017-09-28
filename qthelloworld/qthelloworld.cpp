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
	openAction->setShortcuts(QKeySequence::Open);//��ݼ�
	openAction->setStatusTip(tr("Open an existing file"));
	connect(openAction, &QAction::triggered, this, &qthelloworld::open);

	QMenu *file = menuBar()->addMenu(tr("&File"));
	file->addAction(openAction);

	QToolBar *toolBar = addToolBar(tr("&File"));
	toolBar->addAction(openAction);
	QToolBar *toolBar2 = addToolBar(tr("Tool Bar 2"));//�Ҽ����icon����ʾtoolbar���ƣ�������ͨ����ѡѡ����ʾ�ļ���toobar
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
	dialog.exec();//ģ̬�Ի��򣬻�����ͬһӦ�ó������������ڵ�����
	qDebug() << dialog.result();//�Ի���رգ�exec()�������أ���ʱȡ�öԻ�������ݡ�(Ϊ0��
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
	//dialog.show();//��ջ�Ͻ�����show()�������أ�MainWindow::open()����������dialog ������������������˶Ի�����ʧ
#endif
#if 0
	QDialog *dialog = new QDialog;
	dialog->setWindowTitle(tr("Hello, dialog!"));
	dialog->show();//��Ϊ�ڶ��Ͻ���  ��ģ̬�Ի���   û��delete�������ڴ�й©
#endif

#if 0
	QDialog *dialog = new QDialog;
	dialog->setAttribute(Qt::WA_DeleteOnClose);//setAttribute()�������öԻ���ر�ʱ���Զ����ٶԻ���
	dialog->setWindowTitle(tr("Hello, dialog!"));
	dialog->show();
#endif


}