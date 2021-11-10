#ifndef POSICIONES_H
#define POSICIONES_H

#include "Ubicaciones.h"

const int MAX_UBICACIONES = 100;

class Posiciones
{
    private:
        Ubicacion* ubicaciones[MAX_UBICACIONES];
        int cantidad_ubicaciones;

    public:
        Posiciones();
        void leer_archivo_posiciones();
        void consultar_coordenada();



};


#endif //POSICIONES_H