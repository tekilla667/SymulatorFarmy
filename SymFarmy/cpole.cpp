#include "cpole.h"

#include <QDebug>
#include <stdlib.h>
#include <time.h>
CPole::CPole()
{
    oprysk = new COprysk();
    nawadniarka = new CNawadniarka();
    ursus = new CUrsus();
    ursusX = new CUrsusX();
    QVector<CSegment*> nowe (18);
   for (int i=0; i<18; i++)
       nowe[i] = new CSegment;
    segmenty.append(nowe);

   int rzad=0;
   for (int i=0; i<6; i++)
   {

      segmenty[i]->guiSegment->x=80+80*i+CSegment::offset;
      segmenty[i]->guiSegment->y=CSegment::offset/2+rzad;
   }
   rzad+=150;
   for (int i=0; i<6; i++)
   {

      segmenty[i+6]->guiSegment->x=80+80*i+CSegment::offset;
      segmenty[i+6]->guiSegment->y=CSegment::offset/2+rzad;
   }
   rzad+=150;
   for (int i=0; i<6; i++)
   {

      segmenty[i+12]->guiSegment->x=80+80*i+CSegment::offset;
      segmenty[i+12]->guiSegment->y=CSegment::offset/2+rzad;
   }
}

void CPole::nastepnyDzien()
{
    for (int i=0; i<18; i++)
    {
        if(segmenty[i]->ziemniak!=NULL)
        {
            if(wilgotnosc>=CZiemniak::ileWody)
            segmenty[i]->ziemniak->Rosnij();
            if(segmenty[i]->ziemniak->zjedzona)
                 {
                     segmenty[i]->posiane=false;

                     segmenty[i]->ziemniak=NULL;

                 }
        }
        if(segmenty[i]->truskawka!=NULL)
        {
            if(wilgotnosc>=CTruskawka::ileWody)
            segmenty[i]->truskawka->Rosnij();
            if(segmenty[i]->truskawka->zjedzona)
                 {
                     segmenty[i]->posiane=false;

                     segmenty[i]->truskawka=NULL;

                 }
        }
        if(segmenty[i]->pietruszka!=NULL)
        {
            if(wilgotnosc>=CPietruszka::ileWody)
            segmenty[i]->pietruszka->Rosnij();
            if(segmenty[i]->pietruszka->zjedzona)
                 {
                     segmenty[i]->posiane=false;

                     segmenty[i]->pietruszka=NULL;

                 }
        }
    }

    int losowa = rand() %100+1;
    wilgotnosc=losowa+15;
    if (wilgotnosc>99)
        wilgotnosc=99;
    qDebug()<<wilgotnosc;
}

void CPole::uzyjOprysku()
{
    oprysk->Spryskaj();
}

void CPole::uzyjNawadniarki()
{
    nawadniarka->Nawadniaj();
    wilgotnosc+=20;
    if (wilgotnosc>99)
        wilgotnosc=99;
}

int CPole::wydajnoscUrsus()
{
    return ursus->jakaWydajnosc();
}

int CPole::wydajnoscUrsusX()
{
    return ursusX->jakaWydajnosc();
}

void CPole::zbierajUrsus()
{
    ursus->zbieraj();
}

void CPole::zbierajUrsusX()
{
    ursusX->zbieraj();
}
