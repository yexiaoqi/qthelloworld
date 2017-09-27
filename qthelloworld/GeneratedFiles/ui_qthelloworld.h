/********************************************************************************
** Form generated from reading UI file 'qthelloworld.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTHELLOWORLD_H
#define UI_QTHELLOWORLD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_qthelloworldClass
{
public:

    void setupUi(QWidget *qthelloworldClass)
    {
        if (qthelloworldClass->objectName().isEmpty())
            qthelloworldClass->setObjectName(QStringLiteral("qthelloworldClass"));
        qthelloworldClass->resize(600, 400);

        retranslateUi(qthelloworldClass);

        QMetaObject::connectSlotsByName(qthelloworldClass);
    } // setupUi

    void retranslateUi(QWidget *qthelloworldClass)
    {
        qthelloworldClass->setWindowTitle(QApplication::translate("qthelloworldClass", "qthelloworld", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class qthelloworldClass: public Ui_qthelloworldClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTHELLOWORLD_H
