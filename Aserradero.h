#ifndef ASERRADERO_H
#define ASERRADERO_H

#include "Edificio.h"
#include "Ubicacion.h"

class Aserradero : public Edificio, public Coordenadas
{
    public:
        Aserradero(std::string nombre_edificio, int cantidad_piedra, int cantidad_madera, int cantidad_metal,int maximo_permitidos);

        Aserradero(string nombre_edificio_construido, string ancho, string alto);

        int obtener_recursos();

        int obtener_construidos();

        void mostrar_edificios();

        void mostrar_construidos();

        void mostrar_mensaje_casillero();

        // virtual ~Aserradero();

    
};

#endif //ASERRADERO_H