#ifndef CMASZYNA_H
#define CMASZYNA_H


class CMaszyna
{
public:
    CMaszyna();
    void serwisuj();
    void zbieraj();
    int jakaWydajnosc();
    int cenaSerwisu;
protected:
    int cena;
    int wydajnosc;
    int wydajnoscMAX;
     int zywotnosc;
    int zywotnoscMAX;
};

#endif // CMASZYNA_H
