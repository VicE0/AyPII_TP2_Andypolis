#ifndef CAMION_H
#define CAMION_H

#include "Vehiculo.h"


class Camion : public Vehiculo
{
    public:
        Camion(unsigned int cantidadDeRuedas);
        void verificarTelepase(bool telepase);
        float descuento();
};

#endif // CAMION_H
