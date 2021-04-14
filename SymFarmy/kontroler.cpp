#include "kontroler.h"
#include "ui_kontroler.h"
#include <cpoczatek.h>
#include <chektar.h>
#include <iostream>
#include <QDebug>
#include <algorithm>

Kontroler::Kontroler(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Kontroler)
{

    farmer.ustawLiczbePieniedzy(poczatek.kasa);
    ui->setupUi(this);
    QVector<Dialog*> nowe (1);
    pola.append(nowe);
    pola[0]=new Dialog();
    pola[0]->Dfarmer=&farmer;
    ui->Ustawiaj->addWidget(&poczatek);
    ui->Ustawiaj->addWidget(&hektar_zero); //3
    ui->Ustawiaj->addWidget(&urzad); //4
    ui->Ustawiaj->addWidget(&sklep); //5
    ui->Ustawiaj->addWidget(pola[0]); //6
    ui->Ustawiaj->setCurrentIndex(2);

    connect(&poczatek, SIGNAL(startKlik()),this,SLOT(idzHektar_zero()));
    connect(&urzad, SIGNAL(startKlik()),this,SLOT(idzHektar_zero()));
    connect(&hektar_zero, SIGNAL(urzad()),this,SLOT(idzUrzad()));
    connect(&urzad, SIGNAL(DodajPracownikow()),this,SLOT(DodajPracownikowFarmerowi()));
    connect(&sklep, SIGNAL(powrotHektar()),this,SLOT(idzHektar_zero()));
    connect(&hektar_zero, SIGNAL(sklep()),this,SLOT(idzSklep()));
    connect(&sklep,SIGNAL(zatZiemniaki()),this,SLOT(sklepZiemniaki()));
    connect(&sklep,SIGNAL(zatTruskawki()),this,SLOT(sklepTruskawki()));
    connect(&sklep,SIGNAL(zatPietruszki()),this,SLOT(sklepPietruszki()));
    connect(&sklep,SIGNAL(zatUrsus()),this, SLOT(sklepUrsus()));
    connect(&sklep,SIGNAL(zatUrsusX()),this,SLOT(sklepUrsusX()));
    connect(&sklep,SIGNAL(zatOprysk()),this,SLOT(sklepOprysk()));
    connect(&sklep,SIGNAL(kupHektar()),this,SLOT(kupHektar()));
    connect(&sklep,SIGNAL(zatNawadniarka()),this,SLOT(sklepNawadniarka()));
    connect(&hektar_zero,SIGNAL(przegladajHektar()),this,SLOT(podgladHektar()));
    connect(&hektar_zero,SIGNAL(nastepnyDzien()),this,SLOT(nastepnyDzien()));
    connect(pola[0],SIGNAL(wracaj()),this, SLOT(idzHektar_zero()));
    connect(&hektar_zero,SIGNAL(naprawUrsus()),this,SLOT(naprawUrsus()));
    connect(&hektar_zero,SIGNAL(naprawUrsusX()),this,SLOT(naprawUrsusX()));


}

Kontroler::~Kontroler()
{
    delete ui;
}

void Kontroler::idzHektar_zero()
{
   if(!wplacono)
       kasaPoczatek();

   for(int i=0; i<pola.size(); i++)
   {
       farmer.kupTruskawki(pola[i]->truskawkiDlaFarmera*farmer.ilePracownikow());
       pola[i]->truskawkiDlaFarmera=0;
       farmer.kupPietruszki(pola[i]->pietruszkiDlaFarmera*farmer.ilePracownikow());
       pola[i]->pietruszkiDlaFarmera=0;
       farmer.kupZiemniaki(pola[i]->ziemniakiDlaFarmera*farmer.ilePracownikow());
       pola[i]->ziemniakiDlaFarmera=0;
   }

    hektar_zero.ustalNapisPieniedzy(farmer.ilePieniedzy());
    hektar_zero.ustalNapisPracownikow(farmer.ilePracownikow());
    hektar_zero.ustalNapisTruskawek(farmer.ileTruskawek());
    hektar_zero.ustalNapisPietruszek(farmer.ilePietruszek());
    hektar_zero.ustalNapisZiemniakow(farmer.ileZiemniakow());
    hektar_zero.ustalNapisUrsus(farmer.ileUrsus());
    hektar_zero.ustalNapisUrsusX(farmer.ileUrsusx());
    hektar_zero.ustalNapisOprysk(farmer.ileOpryskow());
    hektar_zero.ustalNapisNawadniarka(farmer.ileNawadniarek());
    hektar_zero.ustalNapisHektarow(pola.size());

    ui->Ustawiaj->setCurrentIndex(3);

}

void Kontroler::idzUrzad()
{
    ui->Ustawiaj->setCurrentIndex(4);
    urzad.ustalNapisDostepnych();
    urzad.ustalNapisPosiadanych(farmer.ilePracownikow());
}

void Kontroler::DodajPracownikowFarmerowi()
{
    if(urzad.doZatrudnienia<=urzad.liczbaPracownikow)
    farmer.dodajPracownikow(urzad.doZatrudnienia);
    hektar_zero.ustalNapisPracownikow(farmer.ilePracownikow());
}

void Kontroler::idzSklep()
{
    ui->Ustawiaj->setCurrentIndex(5);
}

void Kontroler::sklepTruskawki()
{
    int kup = sklep.truskawkiKupno;
    int sprzedaj = sklep.truskawkiSprzedaz;
    if(farmer.ileTruskawek()>=sprzedaj)
    {
        farmer.dodajPieniadze(sprzedaj*CTruskawka::cena);
        farmer.sprzedajTruskawki(sprzedaj);
    }
    if(farmer.ilePieniedzy()>=kup*CTruskawka::cena)
    {
        farmer.dodajPieniadze(-kup*CTruskawka::cena);
        farmer.kupTruskawki(kup);
    }


}

void Kontroler::sklepPietruszki()
{
    int kup = sklep.pietruszkaKupno;
    int sprzedaj = sklep.pietruszkaSprzedaz;
    if(farmer.ilePietruszek()>=sprzedaj)
    {
    farmer.dodajPieniadze(sprzedaj*CPietruszka::cena);
    farmer.sprzedajPietruszki(sprzedaj);
    }
    if(farmer.ilePieniedzy()>=kup*CPietruszka::cena)
    {farmer.dodajPieniadze(-kup*CPietruszka::cena);

    farmer.kupPietruszki(kup);
    }
}

void Kontroler::sklepZiemniaki()
{
    int kup = sklep.ziemniakiKupno;
    int sprzedaj = sklep.ziemniakiSprzedaz;
    if(farmer.ileZiemniakow()>=sprzedaj)
   { farmer.dodajPieniadze(sprzedaj*CZiemniak::cena);
    farmer.sprzedajZiemniaki(sprzedaj);
    }
    if(farmer.ilePieniedzy()>=kup*CZiemniak::cena)
    {farmer.dodajPieniadze(-kup*CZiemniak::cena);
        farmer.kupZiemniaki(kup);

    }
}

void Kontroler::sklepNawadniarka()
{
    if(farmer.ileNawadniarek()>=sklep.nawadniarkaSprzedaz)
    {
        farmer.dodajPieniadze(sklep.nawadniarkaSprzedaz*CNawadniarka::cena);
        farmer.sprzedajNawadniarke(sklep.nawadniarkaSprzedaz);
    }
    if(farmer.ilePieniedzy()>=sklep.nawadniarkaKupno*CNawadniarka::cena)
    {
    farmer.dodajPieniadze(-sklep.nawadniarkaKupno*CNawadniarka::cena);
    farmer.kupNawadniarke(sklep.nawadniarkaKupno);
    }

}

void Kontroler::sklepOprysk()
{
    if(farmer.ileOpryskow()>=sklep.opryskSprzedaz)
    {
        farmer.dodajPieniadze(sklep.opryskSprzedaz*COprysk::cena);
        farmer.sprzedajOprysk(sklep.opryskSprzedaz);
    }
    if(farmer.ilePieniedzy()>=sklep.opryskKupno*COprysk::cena)
   { farmer.dodajPieniadze(-sklep.opryskKupno*COprysk::cena);

    farmer.kupOprysk(sklep.opryskKupno);
    }
}

void Kontroler::sklepUrsus()
{
    if(farmer.ileUrsus()>=sklep.ursusSprzedaz)
    {
        farmer.dodajPieniadze(sklep.ursusSprzedaz*CUrsus::cena);
        farmer.sprzedajUrsus(sklep.ursusSprzedaz);
    }
    if(farmer.ilePieniedzy()>=sklep.ursusKupno*CUrsus::cena)
   { farmer.dodajPieniadze(-sklep.ursusKupno*CUrsus::cena);
    farmer.kupUrsus(sklep.ursusKupno);
    }
}

void Kontroler::sklepUrsusX()
{
   if(farmer.ileUrsusx()>=sklep.ursusxSprzedaz)
    {
        farmer.dodajPieniadze(sklep.ursusxSprzedaz*CUrsusX::cena);
        farmer.sprzedajUrsusX(sklep.ursusxSprzedaz);
    }
    if(farmer.ilePieniedzy()>=sklep.ursusxKupno*CUrsusX::cena)
   {
            farmer.dodajPieniadze(-sklep.ursusxKupno*CUrsusX::cena);
    farmer.kupUrsusX(sklep.ursusxKupno);
    }
}

void Kontroler::podgladHektar()
{

    ui->Ustawiaj->setCurrentIndex(hektar_zero.numerHektara+5);
}

void Kontroler::nastepnyDzien()
{
    qDebug()<<"natepnyDzien";
    farmer.dodajPieniadze(-farmer.ilePracownikow()*10);
    hektar_zero.ustalNapisPieniedzy(farmer.ilePieniedzy());
    for(int i=0; i<pola.size(); i++)
    {
        pola[i]->aktualizujBrush();
    }

    ktoryDzien++;
    hektar_zero.ustalNapisDzien(ktoryDzien);
}

void Kontroler::kupHektar()
{
   if(farmer.ilePieniedzy()>=3000)
   {
    farmer.dodajPieniadze(-3000);
    QVector<Dialog*> nowe (1);
    nowe[0] = new Dialog();
    pola.append(nowe);
    ui->Ustawiaj->addWidget(pola.last());
    pola.last()->ID=pola.size()-1;

    connect(pola.last(),SIGNAL(wracaj()),this, SLOT(idzHektar_zero()));
    pola.last()->Dfarmer=&farmer;
   }
}

void Kontroler::naprawUrsus()
{
    if(hektar_zero.ursusNumer<=farmer.ileUrsus())
    {
    farmer.zwrocUrsus(hektar_zero.ursusNumer-1).serwisuj();
    farmer.dodajPieniadze(-farmer.zwrocUrsus(hektar_zero.ursusNumer-1).cenaSerwisu);
    hektar_zero.ustalNapisPieniedzy(farmer.ilePieniedzy());
    qDebug()<<"naprawiono ursus";
    }
}

void Kontroler::naprawUrsusX()
{
    if(hektar_zero.ursusXNumer<=farmer.ileUrsusx())
    {
    farmer.zwrocUrsusX(hektar_zero.ursusXNumer-1).serwisuj();
    farmer.dodajPieniadze(-farmer.zwrocUrsusX(hektar_zero.ursusXNumer-1).cenaSerwisu);
    hektar_zero.ustalNapisPieniedzy(farmer.ilePieniedzy());
    }
}

void Kontroler::kasaPoczatek()
{
    farmer.ustawLiczbePieniedzy(poczatek.kasa);
    farmer.dodajPracownikow(1);
    qDebug()<<"liczba pracownikow:"<<farmer.ilePracownikow();
    wplacono=true;
}



