#ifndef Escuela_H
#define Escuela_H

#include "Edificio.h"

class Escuela : public Edificio
{
    public:
        Escuela(std::string nombre_edificio, int cantidad_piedra, int cantidad_madera, int cantidad_metal,int maximo_permitidos);

        int obtener_recursos();

        int obtener_construidos();

        void mostrar_edificios();
};


#endif //Escuela_H