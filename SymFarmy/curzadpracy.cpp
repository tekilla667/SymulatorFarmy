#include "curzadpracy.h"
#include "ui_curzadpracy.h"
#include <string>
#include <iostream>
CUrzadpracy::CUrzadpracy(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CUrzadpracy)
{
    ui->setupUi(this);
}

CUrzadpracy::~CUrzadpracy()
{
    delete ui;
}

void CUrzadpracy::ustalNapisDostepnych()
{
   liczbaPracownikow = rand() %4+1;
    ui->ileDostPrac->setText(QString::number(liczbaPracownikow));
}

void CUrzadpracy::ustalNapisPosiadanych(int liczba)
{
    ui->ilePosPrac->setText(QString::number(liczba));
}

void CUrzadpracy::on_pushButton_clicked()
{
    emit startKlik();
}

void CUrzadpracy::on_pushButton_2_clicked()
{
   QString tekst = ui->ileZatrudnic->toPlainText();
   doZatrudnienia = tekst.toInt();

    emit DodajPracownikow();
}
