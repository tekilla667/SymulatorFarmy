#ifndef CPOLE_H
#define CPOLE_H
#include <csegment.h>
#include <QVector>
#include "coprysk.h"
#include "cnawadniarka.h"
#include "cursus.h"
#include "cursusx.h"
class CPole
{
public:
    CPole();
QVector <CSegment*> segmenty;
int wilgotnosc=50;
void nastepnyDzien();
void uzyjOprysku();
void uzyjNawadniarki();
int wydajnoscUrsus();
int wydajnoscUrsusX();
void zbierajUrsus();
void zbierajUrsusX();
private:
COprysk *oprysk;
CNawadniarka *nawadniarka;
CUrsus * ursus;
CUrsusX * ursusX;
};

#endif // CPOLE_H
