
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
//exp2:�źŲ�
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
//exp3:�źŲ�2
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
//exp4:�źŲ�3������reader.h��newspaper.h
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


#if 1
//exp5:������1
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

