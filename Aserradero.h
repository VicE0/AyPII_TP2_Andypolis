#ifndef ASERRADERO_H
#define ASERRADERO_H

#include "Edificio.h"

class Aserradero : public Edificio
{
    public:
        Aserradero(std::string nombre_edificio, int cantidad_piedra, int cantidad_madera, int cantidad_metal,int maximo_permitidos);

        int obtener_recursos();

        int obtener_construidos();

        void mostrar_edificios();

        // virtual ~Aserradero();

    
};

#endif //ASERRADERO_H