#ifndef MOTO_H
#define MOTO_H

#include "Vehiculo.h"
class Moto : public Vehiculo
{
    public:
        Moto();
        void verificarTelepase(bool telepase);
        float descuento();
};

#endif // MOTO_H
