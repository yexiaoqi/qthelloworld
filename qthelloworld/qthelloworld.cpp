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
	openAction->setShortcuts(QKeySequence::Open);//快捷键
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
	QToolBar *toolBar2 = addToolBar(tr("Tool Bar 2"));//右键点击icon，显示toolbar名称，并可以通过勾选选择显示哪几个toobar
	toolBar2->addAction(openAction);
#endif

	textEdit = new QTextEdit(this);
	setCentralWidget(textEdit);
	connect(textEdit, &QTextEdit::textChanged, [=]() {
		this->setWindowModified(true);
	});//在窗口内容发生改变时（通过setWindowModified(true)函数通知），Qt 会自动在标题上面的 [] 位置替换成 * 号

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

#if 0
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