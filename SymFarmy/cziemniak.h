#ifndef CZIEMNIAK_H
#define CZIEMNIAK_H
#include<croslina.h>

class CZiemniak : public CRoslina
{
public:
    CZiemniak();
    void Rosnij() override;
    static const int cena =1;
    static const int wzrost=3;
    static const int plon=20;
    static const int ileWody=30;
private:

};

#endif // CZIEMNIAK_H
