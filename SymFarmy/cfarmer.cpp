#include "cfarmer.h"
#include <cziemniak.h>
#include <cpietruszka.h>
#include <ctruskawka.h>
#include <iostream>
CFarmer::CFarmer()
{
    liczbaPracownikow=0;
}

void CFarmer::ustawLiczbePieniedzy(int liczba)
{
    liczbaPieniedzy = liczba;
}

void CFarmer::dodajPieniadze(int liczba)
{
    liczbaPieniedzy+=liczba;
}

int CFarmer::ilePieniedzy()
{
    return liczbaPieniedzy;
}

int CFarmer::ilePracownikow()
{
    return liczbaPracownikow;
}

void CFarmer::dodajPracownikow(int liczba)
{
    liczbaPracownikow+=liczba;
}

void CFarmer::kupUrsus(int ile)
{
    QVector<CUrsus*> nowe (ile);
    for(int i=0; i<ile; i++)
    {
        nowe[i] = new  CUrsus;
    }
    Ursus.append(nowe);
}

void CFarmer::sprzedajUrsus(int ile)
{
    for(int i = 0; i<ile; i++)
    {
        Ursus.removeLast();
    }
}

int CFarmer::ileUrsus()
{
    return Ursus.size();
}

void CFarmer::sprzedajUrsusX(int ile)
{
    for(int i = 0; i<ile; i++)
    {
        UrsusX.removeLast();
    }
}

void CFarmer::kupUrsusX(int ile)
{
    QVector<CUrsusX*> nowe (ile);
    for(int i=0; i<ile; i++)
    {
        nowe[i] = new  CUrsusX;
    }
    UrsusX.append(nowe);
}

int CFarmer::ileUrsusx()
{
    return UrsusX.size();
}

void CFarmer::sprzedajNawadniarke(int ile)
{
    for(int i = 0; i<ile; i++)
    {
        Nawadniarki.removeLast();
    }
}

void CFarmer::kupNawadniarke(int ile)
{
    QVector<CNawadniarka*> nowe (ile);
    Nawadniarki.append(nowe);
}

int CFarmer::ileNawadniarek()
{
    return Nawadniarki.size();
}

void CFarmer::kupOprysk(int ile)
{
    QVector<COprysk*> nowe (ile);
    Opryski.append(nowe);
}

void CFarmer::sprzedajOprysk(int ile)
{
    for(int i = 0; i<ile; i++)
    {
        Opryski.removeLast();
    }
}

int CFarmer::ileOpryskow()
{
    return Opryski.size();
}

void CFarmer::sprzedajTruskawki(int ile)
{
    for(int i = 0; i<ile; i++)
    {
        Truskawki.removeLast();
    }
}

void CFarmer::kupTruskawki(int ile)
{
    QVector<CTruskawka*> nowe (ile);
    Truskawki.append(nowe);
}

int CFarmer::ileTruskawek()
{
    return Truskawki.size();
}

void CFarmer::sprzedajZiemniaki(int ile)
{
    for(int i = 0; i<ile; i++)
    {
       Ziemniaki.removeLast();
    }
}

void CFarmer::kupZiemniaki(int ile)
{
    QVector<CZiemniak*> nowe (ile);
    Ziemniaki.append(nowe);
}

int CFarmer::ileZiemniakow()
{
    return Ziemniaki.size();
}

void CFarmer::sprzedajPietruszki(int ile)
{
    for(int i = 0; i<ile; i++)
    {
        Pietruszki.removeLast();
    }
}

void CFarmer::kupPietruszki(int ile)
{
    QVector<CPietruszka*> nowe (ile);
    Pietruszki.append(nowe);
}

int CFarmer::ilePietruszek()
{
    return Pietruszki.size();
}

CUrsus CFarmer::zwrocUrsus(int ktory)
{
    if(Ursus.size()<ktory)
    {
        CUrsus *nowy = new CUrsus();
        return *nowy;
    }
    else
        return *Ursus[ktory];
}

CUrsusX CFarmer::zwrocUrsusX(int ktory)
{
    if(UrsusX.size()<ktory)
    {
        CUrsusX *nowy = new CUrsusX();
        return *nowy;
    }
    else
        return *UrsusX[ktory];
}
