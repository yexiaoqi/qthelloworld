
#if 0
//exp1:helloqt
#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	QLabel label("Hello, world");
	label.show();

	return app.exec();
}
#endif

#if 0
//exp2:信号槽
#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	QPushButton button("Quit");
	QObject::connect(&button, &QPushButton::clicked, &QApplication::quit);
	button.show();

	return app.exec();
}
#endif

#if 0
//exp3:信号槽2
#include <QApplication>
#include <QPushButton>
#include <QDebug>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	QPushButton button("Quit");
	QObject::connect(&button, &QPushButton::clicked, [](bool) {
		qDebug() << "You clicked me!";
	});
	button.show();

	return app.exec();
}
#endif


#if 0
//exp4:信号槽3，加入reader.h和newspaper.h
#include <QCoreApplication>

#include "newspaper.h"
#include "reader.h"

int main(int argc, char *argv[])
{
	QCoreApplication app(argc, argv);

	Newspaper newspaper("Newspaper A");
	Reader reader;
	QObject::connect(&newspaper, &Newspaper::newPaper,
		&reader, &Reader::receiveNewspaper);
	newspaper.send();

	return app.exec();
}
#endif


#if 0
//exp5:主窗口1
#include <QApplication>
#include "qthelloworld.h"

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);

	qthelloworld win;
	win.show();

	return app.exec();
}
#endif

#if 0
//exp6:布局管理器
#include <QApplication>
#include <QSpinBox>
#include <QHBoxLayout>
#include "qthelloworld.h"
int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	QWidget window;
	window.setWindowTitle("Enter your age");

	QSpinBox *spinBox = new QSpinBox(&window);
	QSlider *slider = new QSlider(Qt::Horizontal, &window);
	spinBox->setRange(0, 130);
	slider->setRange(0, 130);

	QObject::connect(slider, &QSlider::valueChanged, spinBox, &QSpinBox::setValue);
	void (QSpinBox:: *spinBoxSignal)(int) = &QSpinBox::valueChanged;
	QObject::connect(spinBox, spinBoxSignal, slider, &QSlider::setValue);
	spinBox->setValue(35);

	QHBoxLayout *layout = new QHBoxLayout;
	layout->addWidget(spinBox);
	layout->addWidget(slider);
	window.setLayout(layout);

	window.show();

	return app.exec();
}
#endif

#if 0
//exp7:鼠标控制事件（包括移动，点击和松开）
#include <QApplication>
#include"EventLabel.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	EventLabel *label = new EventLabel;
	label->setWindowTitle("MouseEvent Demo");
	label->setMouseTracking(true);//加上这一句则不用再开始的时候点击鼠标就可以追踪鼠标
	label->resize(300, 200);
	label->show();

	return a.exec();
}
#endif

#if 1
#include <QApplication>
#include"qthelloworld.h"
//#include"CustomButton .h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	CustomButton btn;
	btn.setText("This is a Button!");
	btn.show();

	return a.exec();
}
#endif

