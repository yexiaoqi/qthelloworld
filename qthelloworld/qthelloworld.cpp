#include <QAction>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QToolBar>
#include <QTextEdit>
#include<qdebug.h>
#include "qthelloworld.h"

#if 0
qthelloworld::qthelloworld(QWidget *parent) : QMainWindow(parent)
{
	CustomWidget *widget = new CustomWidget(this);
	CustomButton *cbex = new CustomButton(widget);
	cbex->setText(tr("CustomButton"));
	CustomButtonEx *cb = new CustomButtonEx(widget);
	cb->setText(tr("CustomButtonEx"));
	QVBoxLayout *widgetLayout = new QVBoxLayout(widget);
	widgetLayout->addWidget(cbex);
	widgetLayout->addWidget(cb);
	this->setCentralWidget(widget);
}
#endif


qthelloworld::qthelloworld()
{
	textEdit = new QTextEdit;
	setCentralWidget(textEdit);

	textEdit->installEventFilter(this);
}

#if 0
qthelloworld::qthelloworld(QWidget *parent) :
	QMainWindow(parent)
{
	setWindowTitle(tr("Main Window"));

	openAction = new QAction(QIcon(":/images/test"), tr("&Open..."), this);
	openAction->setShortcuts(QKeySequence::Open);//��ݼ�
	openAction->setStatusTip(tr("Open an existing file"));

	saveAction = new QAction(QIcon(":/images/test2"), tr("&Save..."), this);
	saveAction->setShortcuts(QKeySequence::Save);
	saveAction->setStatusTip(tr("Save a new file"));

	//connect(openAction, &QAction::triggered, this, &qthelloworld::open);

	connect(openAction, &QAction::triggered, this, &qthelloworld::openFile);
	connect(saveAction, &QAction::triggered, this, &qthelloworld::saveFile);

	QMenu *file = menuBar()->addMenu(tr("&File"));
	file->addAction(openAction);
	file->addAction(saveAction);

	QToolBar *toolBar = addToolBar(tr("&File"));
	toolBar->addAction(openAction);
	toolBar->addAction(saveAction);
#if 0
	QToolBar *toolBar2 = addToolBar(tr("Tool Bar 2"));//�Ҽ����icon����ʾtoolbar���ƣ�������ͨ����ѡѡ����ʾ�ļ���toobar
	toolBar2->addAction(openAction);
#endif

	textEdit = new QTextEdit(this);
	setCentralWidget(textEdit);
	connect(textEdit, &QTextEdit::textChanged, [=]() {
		this->setWindowModified(true);
	});//�ڴ������ݷ����ı�ʱ��ͨ��setWindowModified(true)����֪ͨ����Qt ���Զ��ڱ�������� [] λ���滻�� * ��

	setWindowTitle("TextPad [*]");

	statusBar();
}
#endif
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

#if 0
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


void qthelloworld::openFile()
{
	QString path = QFileDialog::getOpenFileName(this,
												tr("Open File"),
												".",
												tr("Text Files(*.txt)"));
	if (!path.isEmpty()) 
	{
		QFile file(path);
		if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) 
		{
			QMessageBox::warning(this, tr("Read File"),
									tr("Cannot open file:\n%1").arg(path));
			return;
		}
		QTextStream in(&file);
		textEdit->setText(in.readAll());
		file.close();
	}
	else 
	{
		QMessageBox::warning(this, tr("Path"),
							tr("You did not select any file."));
	}
}

void qthelloworld::saveFile()
{
	QString path = QFileDialog::getSaveFileName(this,
												tr("Open File"),
												".",
												tr("Text Files(*.txt)"));
	if (!path.isEmpty()) 
	{
		QFile file(path);
		if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) 
		{
			QMessageBox::warning(this, tr("Write File"),
								tr("Cannot open file:\n%1").arg(path));
			return;
		}
		QTextStream out(&file);
		out << textEdit->toPlainText();
		file.close();
	}
	else 
	{
		QMessageBox::warning(this, tr("Path"),
							tr("You did not select any file."));
	}
}
void qthelloworld::closeEvent(QCloseEvent *event)
{
	if (isWindowModified()) {
		bool exit = QMessageBox::question(this,
			tr("Quit"),
			tr("Are you sure to quit this application?"),
			QMessageBox::Yes | QMessageBox::No,
			QMessageBox::No) == QMessageBox::Yes;
		if (exit) {
			event->accept();
		}
		else {
			event->ignore();
		}
	}
	else {
		event->accept();
	}
}

bool qthelloworld::eventFilter(QObject *obj, QEvent *event)
{
	if (obj == textEdit) {
		if (event->type() == QEvent::KeyPress) {
			QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
			qDebug() << "Ate key press" << keyEvent->key();
			return true;
		}
		else {
			return false;
		}
	}
	else {
		// pass the event on to the parent class
		return QMainWindow::eventFilter(obj, event);
	}
}