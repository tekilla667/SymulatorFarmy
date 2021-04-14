#include "csklep.h"
#include "ui_csklep.h"
#include <QString>
CSklep::CSklep(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CSklep)
{
    ui->setupUi(this);
}

CSklep::~CSklep()
{
    delete ui;
}

void CSklep::on_pushButton_clicked()
{
    emit powrotHektar();
}

void CSklep::on_ZatZiemniaki_clicked()
{
   QString ziemniakiKup = ui->kupZiemniaki->text();
   QString ziemniakiSprzed = ui->sprzedajZiemniaki->text();
           ziemniakiKupno = ziemniakiKup.toInt();
           ziemniakiSprzedaz=ziemniakiSprzed.toInt();
    emit zatZiemniaki();
}

void CSklep::on_zatPietruszki_clicked()
{
    QString PietrKup = ui->kupPietruszki->text();
    QString PietrSprzed = ui->sprzedajPietruszki->text();
            pietruszkaKupno = PietrKup.toInt();
            pietruszkaSprzedaz=PietrSprzed.toInt();
    emit zatPietruszki();
}

void CSklep::on_zatTruskawki_clicked()
{
    QString TrusKup = ui->kupTruskawki->text();
    QString TrusSprzed = ui->sprzedajTruskawki->text();
            truskawkiKupno = TrusKup.toInt();
            truskawkiSprzedaz=TrusSprzed.toInt();
    emit zatTruskawki();
}

void CSklep::on_zatOprysk_clicked()
{
    opryskKupno = ui->kupOprysk->text().toInt();
    opryskSprzedaz = ui->sprzedajOprysk->text().toInt();
    emit zatOprysk();
}

void CSklep::on_zatNawadniarka_clicked()
{
    nawadniarkaKupno = ui->kupNawadniarka->text().toInt();
    nawadniarkaSprzedaz = ui->sprzedajNawadniarka->text().toInt();
    emit zatNawadniarka();
}

void CSklep::on_zatUrsus_clicked()
{
    ursusKupno = ui->kupUrsus->text().toInt();
    ursusSprzedaz = ui->sprzedajUrsus->text().toInt();
    emit zatUrsus();
}

void CSklep::on_zatUrsusX_clicked()
{
    ursusxKupno=ui->kupUrsusX->text().toInt();
    ursusxSprzedaz=ui->sprzedajUrsusX->text().toInt();
    emit zatUrsusX();
}

void CSklep::on_pushButton_2_clicked()
{
    emit kupHektar();
}
