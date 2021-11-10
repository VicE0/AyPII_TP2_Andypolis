#ifndef Fabrica_H
#define Fabrica_H

#include "Edificio.h"
#include "Ubicacion.h"

class Fabrica : public Edificio, public Coordenadas
{
    public:
        Fabrica(std::string nombre_edificio, int cantidad_piedra, int cantidad_madera, int cantidad_metal,int maximo_permitidos);

        Fabrica(string nombre_edificio_construido, string ancho, string alto);
        
        int obtener_recursos();

        int obtener_construidos();

        void mostrar_edificios();

        void mostrar_construidos();

        void mostrar_mensaje_casillero();
};


#endif //Fabrica_H