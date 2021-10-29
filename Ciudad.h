#ifndef CIUDAD_H
#define CIUDAD_H

#include "Edificio.h"

const int MAX_EDIFICIOS = 100;

class Ciudad
{
    private:
        Edificio* edificios[MAX_EDIFICIOS];
        int cantidad_edificios;

    public:
        Ciudad();
        void leer_archivo_edificios();
        void mostrar_totalidad_edificios();
        void mostrar_edificios_construidos();
        void construir_edificio();
        void guardar_edificios();


};


#endif //CIUDAD_H