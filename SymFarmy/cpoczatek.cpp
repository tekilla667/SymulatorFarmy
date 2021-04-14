#include "cpoczatek.h"
#include "ui_cpoczatek.h"
#include <string>
#include <iostream>
CPoczatek::CPoczatek(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CPoczatek)
{
    ui->setupUi(this);
}

CPoczatek::~CPoczatek()
{
    delete ui;
}

void CPoczatek::on_pushButton_clicked()
{
  QString napis = ui->textEdit->toPlainText();
  kasa = napis.toInt();
    emit startKlik();
}
