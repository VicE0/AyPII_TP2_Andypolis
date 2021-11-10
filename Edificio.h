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
        int recursos;

    public:
        Edificio();

        string obtener_nombre();

        int obtener_piedra();

        int obtener_madera();

        int obtener_metal();

        int obtener_permitidos();

        virtual int obtener_recursos() = 0;

        virtual int obtener_construidos() = 0;

        virtual void mostrar_edificios() = 0;

        virtual void mostrar_mensaje_casillero() = 0;

        // virtual void mostrar_construidos() = 0;

        // virtual ~Edificio();

};  


#endif // EDIFICIO_H