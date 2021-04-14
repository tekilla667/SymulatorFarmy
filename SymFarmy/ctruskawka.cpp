#include "ctruskawka.h"

CTruskawka::CTruskawka()
{

     prawdopodobienstwoSzkodnika=0.12;


     ileDni=0;
}

void CTruskawka::Rosnij()
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
