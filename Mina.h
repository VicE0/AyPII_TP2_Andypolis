#ifndef MINA_H
#define MINA_H

#include "Edificio.h"
#include "Ubicacion.h"

class Mina : public Edificio, public Coordenadas
{
    public:
        Mina(std::string nombre_edificio, int cantidad_piedra, int cantidad_madera, int cantidad_metal,int maximo_permitidos);
        
        Mina(string nombre_edificio_construido, string ancho, string alto);
        
        int obtener_recursos();

        int obtener_construidos();

        void mostrar_edificios();

        void mostrar_construidos();

        void mostrar_mensaje_casillero();

        // virtual ~Mina();

    
};


#endif //Mina_H