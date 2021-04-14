#ifndef CPIETRUSZKA_H
#define CPIETRUSZKA_H
#include <croslina.h>

class CPietruszka : public CRoslina
{
public:
    CPietruszka();
    void Rosnij() override;
    static const int cena =2;
    static const int wzrost=6;
    static const int plon=15;
    static const int ileWody=50;
private:

};

#endif // CPIETRUSZKA_H
