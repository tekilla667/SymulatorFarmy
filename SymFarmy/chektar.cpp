#include "chektar.h"
#include "ui_chektar.h"
#include <QDebug>
CHektar::CHektar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CHektar)
{
    ui->setupUi(this);
}

CHektar::~CHektar()
{
    delete ui;
}

void CHektar::ustalNapisPieniedzy(int liczba)
{
    ui->tekstPieniadze->setText(QString::number(liczba));
}

void CHektar::ustalNapisPracownikow(int liczba)
{
    ui->tekstPracownicy->setText(QString::number(liczba));
}

void CHektar::ustalNapisPietruszek(int liczba)
{
    ui->tekstPietruszki->setText(QString::number(liczba));
}

void CHektar::ustalNapisTruskawek(int liczba)
{
    ui->tekstTruskawki->setText(QString::number(liczba));
}

void CHektar::ustalNapisZiemniakow(int liczba)
{
    ui->tekstZiemniaki->setText(QString::number(liczba));
}

void CHektar::ustalNapisNawadniarka(int liczba)
{
    ui->tekstNawadniarki->setText(QString::number(liczba));
}

void CHektar::ustalNapisOprysk(int liczba)
{
     ui->tekstOpryski->setText(QString::number(liczba));
}

void CHektar::ustalNapisUrsus(int liczba)
{
     ui->tekstUrsus->setText(QString::number(liczba));
}

void CHektar::ustalNapisUrsusX(int liczba)
{
    ui->tekstUrsusX->setText(QString::number(liczba));
}

void CHektar::ustalNapisHektarow(int liczba)
{
    ui->ileHektarow->setText(QString::number(liczba));
}

void CHektar::ustalNapisDzien(int liczba)
{
    ui->ktoryDzien->setText(QString::number(liczba));
}



void CHektar::on_pushButtonUrzad_clicked()
{
    emit urzad();
}

void CHektar::on_pushButton_clicked()
{
    emit sklep();
}

void CHektar::on_przegladajHektar_clicked()
{
   numerHektara = ui->nrHektara->text().toInt();
   qDebug()<<numerHektara;
    emit przegladajHektar();
}

void CHektar::on_nastepnyDzien_clicked()
{
    emit nastepnyDzien();
}

void CHektar::on_naprawUrsus_clicked()
{
    ursusNumer=ui->ursusNumer->text().toInt();
    emit naprawUrsus();
}

void CHektar::on_naprawUrsusX_clicked()
{
    ursusXNumer=ui->ursusXNumer->text().toInt();
    emit naprawUrsusX();
}
