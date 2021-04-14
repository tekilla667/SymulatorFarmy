#include "cmaszyna.h"

CMaszyna::CMaszyna()
{

}

void CMaszyna::serwisuj()
{
    zywotnosc=zywotnoscMAX;
    wydajnosc=wydajnoscMAX;
}

void CMaszyna::zbieraj()
{
    zywotnosc--;
    if(zywotnosc==0)
        wydajnosc=0;
}

int CMaszyna::jakaWydajnosc()
{
    return wydajnosc;
}
