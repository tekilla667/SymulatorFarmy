#ifndef CSEGMENT_H
#define CSEGMENT_H
#include <QGraphicsItem>
#include <croslina.h>
#include<QMouseEvent>
#include "ctruskawka.h"
#include "cpietruszka.h"
#include "cziemniak.h"
#include "gui_csegment.h"
class CSegment
{
public:
    CSegment();

    static const int offset = 40;
    CTruskawka * truskawka;
    CZiemniak * ziemniak;
    CPietruszka * pietruszka;
    gui_CSegment * guiSegment;
    void posiej(int ktoraRoslina);
    void kliknieto();
    bool posiane = false;
    bool czySzkodnik = false;

};

#endif // CSEGMENT_H
