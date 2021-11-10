#ifndef Planta_H
#define Planta_H

#include "Edificio.h"

class Planta : public Edificio
{
     public:
        Planta(std::string nombre_edificio, int cantidad_piedra, int cantidad_madera, int cantidad_metal,int maximo_permitidos);

        int obtener_recursos();

        int obtener_construidos();

        void mostrar_edificios();
};


#endif //Planta_H