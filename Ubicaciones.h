#ifndef UBICACIONES_H
#define UBICACIONES_H

#include "Ubicacion.h"


const int MAX_UBICACIONES = 100;
const int MAX_EDIFICIOS_U = 100;


class Ubicaciones
{
    private:
        Coordenadas* ubicaciones[MAX_UBICACIONES];
        int cantidad_ubicaciones;

    public:
        Ubicaciones();
        void leer_ubicaciones();
        void cargar_ubicaciones(std::string nombre, std::string ancho, std::string alto);

        
        
        

};

#endif //UBICACIONES_H