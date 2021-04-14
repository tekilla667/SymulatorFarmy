#ifndef CTRUSKAWKA_H
#define CTRUSKAWKA_H
#include <croslina.h>

class CTruskawka : public CRoslina
{

public:
    CTruskawka();
    void Rosnij() override;
    static const int cena =5;
    static const int wzrost=9;
    static const int plon = 10;
    static const int ileWody=70;
private:


};

#endif // CTRUSKAWKA_H
