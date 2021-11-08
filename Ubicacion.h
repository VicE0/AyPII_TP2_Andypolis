#ifndef UBICACION_H
#define UBICACION_H

#include <iostream>
#include <fstream>


class Coordenadas
{
    protected:
        std::string nombre;
        std::string alto;
        std::string ancho;
        std::string aux;

    public:
        friend class Ubicaciones;

};



#endif // UBICACION_H