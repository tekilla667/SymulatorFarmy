/********************************************************************************
** Form generated from reading UI file 'curzadpracy.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CURZADPRACY_H
#define UI_CURZADPRACY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CUrzadpracy
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QLabel *ileDostPrac;
    QLabel *label_3;
    QLabel *ilePosPrac;
    QLabel *label_5;
    QTextEdit *ileZatrudnic;
    QPushButton *pushButton_2;
    QLabel *label_2;

    void setupUi(QWidget *CUrzadpracy)
    {
        if (CUrzadpracy->objectName().isEmpty())
            CUrzadpracy->setObjectName(QString::fromUtf8("CUrzadpracy"));
        CUrzadpracy->resize(800, 600);
        pushButton = new QPushButton(CUrzadpracy);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(680, 190, 75, 23));
        label = new QLabel(CUrzadpracy);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(120, 150, 171, 16));
        ileDostPrac = new QLabel(CUrzadpracy);
        ileDostPrac->setObjectName(QString::fromUtf8("ileDostPrac"));
        ileDostPrac->setGeometry(QRect(300, 150, 47, 13));
        label_3 = new QLabel(CUrzadpracy);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(120, 180, 161, 21));
        ilePosPrac = new QLabel(CUrzadpracy);
        ilePosPrac->setObjectName(QString::fromUtf8("ilePosPrac"));
        ilePosPrac->setGeometry(QRect(300, 180, 47, 13));
        label_5 = new QLabel(CUrzadpracy);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(120, 210, 141, 16));
        ileZatrudnic = new QTextEdit(CUrzadpracy);
        ileZatrudnic->setObjectName(QString::fromUtf8("ileZatrudnic"));
        ileZatrudnic->setGeometry(QRect(250, 210, 141, 21));
        pushButton_2 = new QPushButton(CUrzadpracy);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(280, 240, 75, 23));
        label_2 = new QLabel(CUrzadpracy);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(110, 30, 631, 81));
        QFont font;
        font.setFamily(QString::fromUtf8("Script MT Bold"));
        font.setPointSize(50);
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);

        retranslateUi(CUrzadpracy);

        QMetaObject::connectSlotsByName(CUrzadpracy);
    } // setupUi

    void retranslateUi(QWidget *CUrzadpracy)
    {
        CUrzadpracy->setWindowTitle(QCoreApplication::translate("CUrzadpracy", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("CUrzadpracy", "Powrot", nullptr));
        label->setText(QCoreApplication::translate("CUrzadpracy", "Liczba dost\304\231pnych pracownik\303\263w:", nullptr));
        ileDostPrac->setText(QCoreApplication::translate("CUrzadpracy", "-", nullptr));
        label_3->setText(QCoreApplication::translate("CUrzadpracy", "Liczba posiadanych pracownik\303\263w:", nullptr));
        ilePosPrac->setText(QCoreApplication::translate("CUrzadpracy", "-", nullptr));
        label_5->setText(QCoreApplication::translate("CUrzadpracy", "Zatrudnij pracownik\303\263w:", nullptr));
        pushButton_2->setText(QCoreApplication::translate("CUrzadpracy", "Zatrudnij", nullptr));
        label_2->setText(QCoreApplication::translate("CUrzadpracy", "URZAD PRACY", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CUrzadpracy: public Ui_CUrzadpracy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CURZADPRACY_H
