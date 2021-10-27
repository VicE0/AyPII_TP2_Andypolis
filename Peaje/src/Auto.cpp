#include "Auto.h"

Auto::Auto()
{
    this->cantidadDeRuedas = 4;
}

void Auto::verificarTelepase(bool telepase)
{
    this->telepase = telepase;
}

float Auto::descuento()
{
    if(this->telepase)
    {
        return 0.5;
    }

    else return 0;

}


