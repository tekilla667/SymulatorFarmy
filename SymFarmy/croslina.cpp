#include "croslina.h"
#include <stdlib.h>
#include <time.h>
CRoslina::CRoslina()
{

}

void CRoslina::Rosnij()
{
   ileDni++;

    float losowa = rand() %100;
    if(losowa<prawdopodobienstwoSzkodnika*100)
        maSzkodnika=true;
    if(maSzkodnika)
        nastepnyDzienSzkodnika();
    if(ileDniSzkodnik==2)
        zjedzona=true;
}



int CRoslina::zwrocDni()
{
    return ileDni;
}

bool CRoslina::czyMaSzkodnika()
{
    return maSzkodnika;
}

void CRoslina::usunietoSzkodnika()
{
    ileDniSzkodnik = 0 ;
    maSzkodnika = false;
}

int CRoslina::zwrocIleDniSzkodnik()
{
    return ileDniSzkodnik;
}

void CRoslina::nastepnyDzienSzkodnika()
{
    ileDniSzkodnik++;
}
