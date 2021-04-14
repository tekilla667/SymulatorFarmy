#ifndef CROSLINA_H
#define CROSLINA_H
#include <QString>

class CRoslina
{
public:
    CRoslina();
    QString nazwa;
    virtual void Rosnij()=0;
     int zwrocDni();
     bool czyMaSzkodnika();
     bool zjedzona=false;
     void usunietoSzkodnika();
     int zwrocIleDniSzkodnik();
     void nastepnyDzienSzkodnika();
protected:
    int cena;
    float prawdopodobienstwoSzkodnika;
    int ileWody;
    int plon;
    int ileDni;
    int ileDniSzkodnik=0;
    bool maSzkodnika=false;

};

#endif // CROSLINA_H
