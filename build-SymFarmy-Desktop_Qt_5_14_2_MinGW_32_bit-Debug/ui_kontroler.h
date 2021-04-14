/********************************************************************************
** Form generated from reading UI file 'kontroler.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KONTROLER_H
#define UI_KONTROLER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Kontroler
{
public:
    QWidget *widget;
    QStackedWidget *Ustawiaj;
    QWidget *page_3;
    QWidget *page_4;

    void setupUi(QMainWindow *Kontroler)
    {
        if (Kontroler->objectName().isEmpty())
            Kontroler->setObjectName(QString::fromUtf8("Kontroler"));
        Kontroler->resize(800, 600);
        widget = new QWidget(Kontroler);
        widget->setObjectName(QString::fromUtf8("widget"));
        Ustawiaj = new QStackedWidget(widget);
        Ustawiaj->setObjectName(QString::fromUtf8("Ustawiaj"));
        Ustawiaj->setGeometry(QRect(0, 0, 801, 601));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        Ustawiaj->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        Ustawiaj->addWidget(page_4);
        Kontroler->setCentralWidget(widget);

        retranslateUi(Kontroler);

        QMetaObject::connectSlotsByName(Kontroler);
    } // setupUi

    void retranslateUi(QMainWindow *Kontroler)
    {
        Kontroler->setWindowTitle(QCoreApplication::translate("Kontroler", "Kontroler", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Kontroler: public Ui_Kontroler {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KONTROLER_H
