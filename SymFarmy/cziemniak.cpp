#include "cziemniak.h"

CZiemniak::CZiemniak()
{
    prawdopodobienstwoSzkodnika=0.05;


    ileDni=0;
}

void CZiemniak::Rosnij()
{
    ileDni++;

    float losowa = rand() %100;
    if(losowa<prawdopodobienstwoSzkodnika*100)
        maSzkodnika=true;
    if(maSzkodnika)
        nastepnyDzienSzkodnika();
    if(ileDniSzkodnik==5)
        zjedzona=true;
}

