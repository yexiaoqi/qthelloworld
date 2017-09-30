#pragma once
#include<QObject>
#include<QTextEdit>
#include<QEvent>
#include<QDebug>
#include<QkeyEvent>
class CustomTextEdit:public QTextEdit
{
	Q_OBJECT
public:
	CustomTextEdit(QTextEdit *parent):QTextEdit (parent)
	{}
	~CustomTextEdit() {}
private:
	bool event(QEvent *e);
};