#include "Aserradero.h"

Aserradero::Aserradero()
{
    this ->cantidad_construidos ++;

}

int Aserradero::aserraderos_construidos()
{
    int aserradero = this ->cantidad_construidos;
    return aserradero;
}
