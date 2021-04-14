/********************************************************************************
** Form generated from reading UI file 'cpoczatek.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CPOCZATEK_H
#define UI_CPOCZATEK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CPoczatek
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QTextEdit *textEdit;
    QLabel *label_3;

    void setupUi(QWidget *CPoczatek)
    {
        if (CPoczatek->objectName().isEmpty())
            CPoczatek->setObjectName(QString::fromUtf8("CPoczatek"));
        CPoczatek->resize(800, 600);
        pushButton = new QPushButton(CPoczatek);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(370, 380, 75, 23));
        label = new QLabel(CPoczatek);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(370, 120, 91, 16));
        label_2 = new QLabel(CPoczatek);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(350, 210, 131, 16));
        textEdit = new QTextEdit(CPoczatek);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(320, 280, 171, 51));
        label_3 = new QLabel(CPoczatek);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(370, 240, 81, 16));

        retranslateUi(CPoczatek);

        QMetaObject::connectSlotsByName(CPoczatek);
    } // setupUi

    void retranslateUi(QWidget *CPoczatek)
    {
        CPoczatek->setWindowTitle(QCoreApplication::translate("CPoczatek", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("CPoczatek", "Start", nullptr));
        label->setText(QCoreApplication::translate("CPoczatek", "Symulator Farmy", nullptr));
        label_2->setText(QCoreApplication::translate("CPoczatek", "Ilo\305\233\304\207 pieni\304\231dzy na start:", nullptr));
        label_3->setText(QCoreApplication::translate("CPoczatek", "(zalecane 1000)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CPoczatek: public Ui_CPoczatek {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CPOCZATEK_H
