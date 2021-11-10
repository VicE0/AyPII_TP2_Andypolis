#ifndef Obelisco_H
#define Obelisco_H

#include "Edificio.h"

class Obelisco : public Edificio
{
    public:
        Obelisco(std::string nombre_edificio, int cantidad_piedra, int cantidad_madera, int cantidad_metal,int maximo_permitidos);

        int obtener_recursos();

        int obtener_construidos();

        void mostrar_edificios();
};


#endif //Obelisco_H