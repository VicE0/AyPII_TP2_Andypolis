#include "Camion.h"

Camion::Camion(unsigned int cantidadDeRuedas)
{
    this->cantidadDeRuedas = cantidadDeRuedas;
}

void Camion::verificarTelepase(bool telepase)
{
    this->telepase = telepase;
}

float Camion::descuento()
{
    if(this->telepase)
    {
        return 0.75;
    }

    else return 0;
}
