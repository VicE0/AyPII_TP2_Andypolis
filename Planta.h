#ifndef Planta_H
#define Planta_H

#include "Edificio.h"
#include "Ubicacion.h"

class Planta : public Edificio, public Coordenadas
{
     public:
        Planta(std::string nombre_edificio, int cantidad_piedra, int cantidad_madera, int cantidad_metal,int maximo_permitidos);

        Planta(string nombre_edificio_construido, string ancho, string alto);

        int obtener_recursos();

        int obtener_construidos();

        void mostrar_edificios();

        void mostrar_construidos();

        void mostrar_mensaje_casillero();
};


#endif //Planta_H