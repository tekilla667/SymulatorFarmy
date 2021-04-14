#ifndef CFARMER_H
#define CFARMER_H
#include <cursus.h>
#include <cursusx.h>
#include <cnawadniarka.h>
#include <coprysk.h>
#include <ctruskawka.h>
#include <cziemniak.h>
#include <cpietruszka.h>
#include <QVector>
class CFarmer
{
private:
    int liczbaPieniedzy;
    int liczbaPracownikow;
    QVector <CUrsus*> Ursus;
    QVector <CUrsusX*> UrsusX;
    QVector <CNawadniarka*> Nawadniarki;
    QVector <COprysk*> Opryski;
    QVector <CTruskawka*> Truskawki;
    QVector <CZiemniak*> Ziemniaki;
    QVector <CPietruszka*> Pietruszki;



public:
    CFarmer();
    void ustawLiczbePieniedzy(int liczba);
    void dodajPieniadze(int liczba);
    int ilePieniedzy();
    int ilePracownikow();
    void dodajPracownikow(int liczba);
    void kupUrsus(int ile);
    void sprzedajUrsus(int ile);
    int ileUrsus();
    void sprzedajUrsusX(int ile);
    void kupUrsusX(int ile);
    int ileUrsusx();
    void sprzedajNawadniarke(int ile);
    void kupNawadniarke(int ile);
    int ileNawadniarek();
    void kupOprysk(int ile);
    void sprzedajOprysk(int ile);
    int ileOpryskow();
    void sprzedajTruskawki(int ile);
    void kupTruskawki(int ile);
    int ileTruskawek();
    void sprzedajZiemniaki(int ile);
    void kupZiemniaki(int ile);
    int ileZiemniakow();
    void sprzedajPietruszki(int ile);
    void kupPietruszki(int ile);
    int ilePietruszek();
    CUrsus zwrocUrsus(int ktory);
    CUrsusX zwrocUrsusX(int ktory);
};

#endif // CFARMER_H
