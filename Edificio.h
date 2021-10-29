#ifndef EDIFICIO_H
#define EDIFICIO_H

#include <iostream>
#include <fstream>
#include "Material.h"

using namespace std;

class Edificio
{
    public:
        string nombre;
        int cantidad_piedra;
        int cantidad_madera;
        int cantidad_metal;
        int maximo_permitidos;
        unsigned int cantidad_construidos;


};  


#endif // EDIFICIO_H