#ifndef AUTO_H
#define AUTO_H

#include "Vehiculo.h"

class Auto : public Vehiculo
{
    public:
        Auto();
        void verificarTelepase(bool telepase);
        float descuento();
};

#endif // AUTO_H
