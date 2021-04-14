#include "cpietruszka.h"

CPietruszka::CPietruszka()
{
    prawdopodobienstwoSzkodnika=0.1;


    ileDni=0;
}

void CPietruszka::Rosnij()
{
    ileDni++;

    float losowa = rand() %100;
    if(losowa<prawdopodobienstwoSzkodnika*100)
        maSzkodnika=true;
    if(maSzkodnika)
        nastepnyDzienSzkodnika();
    if(ileDniSzkodnik==4)
        zjedzona=true;
}

