#ifndef MINA_H
#define MINA_H

#include "Edificio.h"

class Mina : public Edificio
{
    public:
        Mina(std::string nombre_edificio, int cantidad_piedra, int cantidad_madera, int cantidad_metal,int maximo_permitidos);

        int obtener_recursos();

        int obtener_construidos();

        void mostrar_edificios();

        // virtual ~Mina();

    
};


#endif //Mina_H