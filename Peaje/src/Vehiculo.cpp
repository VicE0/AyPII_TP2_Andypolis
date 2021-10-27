#include "Vehiculo.h"

float Vehiculo::montoAPagar(unsigned int precioPorRueda)
{
    return precioPorRueda*cantidadDeRuedas*(1 - this->descuento());
}





