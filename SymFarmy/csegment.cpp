#include "csegment.h"
#include <QtDebug>

bool klik = false;
void wyswietl(){

}
CSegment::CSegment()
{
    truskawka=NULL;
    ziemniak=NULL;
    pietruszka=NULL;
    klik = false;
    guiSegment = new gui_CSegment();
}

void CSegment::posiej(int ktoraRoslina)
{
    if(ktoraRoslina==1)
        truskawka = new CTruskawka();
    else if(ktoraRoslina==2)
        ziemniak = new CZiemniak();
    else if(ktoraRoslina==3)
        pietruszka = new CPietruszka();
}



void QGraphicsItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    qDebug()<<"kliknieto";
  this->setZValue(this->zValue()+1);
    qDebug()<<"Z Value:";
    qDebug()<<this->zValue();
}
