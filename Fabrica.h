#ifndef Fabrica_H
#define Fabrica_H

#include "Edificio.h"

class Fabrica : public Edificio
{
    public:
        Fabrica(std::string nombre_edificio, int cantidad_piedra, int cantidad_madera, int cantidad_metal,int maximo_permitidos);

        int obtener_recursos();

        int obtener_construidos();

        void mostrar_edificios();

};


#endif //Fabrica_H