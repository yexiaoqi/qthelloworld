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

void qthelloworld::open()
{
	//QMessageBox::information(this, tr("Information"), tr("Open"));
#if 0
	//exp:�Ի���QMessageBoxӦ��1
	if (QMessageBox::Yes == QMessageBox::question(this,
		tr("Question"),
		tr("Are you OK?"),
		QMessageBox::Yes | QMessageBox::No,
		QMessageBox::Yes)) // this���� qthelloworld���������� QWidget ָ�룩
	{
		QMessageBox::information(this, tr("Hmmm..."), tr("I'm glad to hear that!"));
	}
	else 
	{
		QMessageBox::information(this, tr("Hmmm..."), tr("I'm sorry!"));
	}
#endif

#if 1
	//exp:�Ի���QMessageBoxӦ��2
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
	dialog.exec();//ģ̬�Ի��򣬻�����ͬһӦ�ó������������ڵ�����
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