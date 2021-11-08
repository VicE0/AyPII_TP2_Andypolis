#ifndef EDIFICIO_H
#define EDIFICIO_H

#include <iostream>
#include <fstream>

using namespace std;

class Edificio
{
    protected:
        string nombre_edificio;
        int cantidad_piedra;
        int cantidad_madera;
        int cantidad_metal;
        int maximo_permitidos;
        int cantidad_construidos;

    public:
        friend class Ciudad;

};  


#endif // EDIFICIO_H