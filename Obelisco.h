#ifndef Obelisco_H
#define Obelisco_H

#include "Edificio.h"
#include "Ubicacion.h"

class Obelisco : public Edificio, public Coordenadas
{
    public:
        Obelisco(std::string nombre_edificio, int cantidad_piedra, int cantidad_madera, int cantidad_metal,int maximo_permitidos);

        Obelisco(string nombre_edificio_construido, string ancho, string alto);

        int obtener_recursos();

        int obtener_construidos();

        void mostrar_edificios();

        void mostrar_construidos();
};


#endif //Obelisco_H