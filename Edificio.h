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

        //PRE: ~
        //POST: Devuelve el nombre del edificio
        string obtener_nombre();

        //PRE: ~
        //POST: Devuelve la cantidad de piedra
        int obtener_piedra();

        //PRE: ~
        //POST: Devuelve la cantidad de madera
        int obtener_madera();

        //PRE: ~
        //POST: Devuelve la cantidad de metal
        int obtener_metal();

        //PRE: ~
        //POST: Devuelve los maximos permitidos para construir
        int obtener_permitidos();

        //PRE: ~
        //POST: Devuelve los recursos generados
        virtual int obtener_recursos() = 0;

        //PRE: ~
        //POST: Devuelve la cantidad de edificios construidos
        virtual int obtener_construidos() = 0;

        //PRE: ~
        //POST: Muestra los datos del archivo edificios.txt
        virtual void mostrar_edificios() = 0;

        //PRE: ~
        //POST: Muestra el mensaje que le corresponde a cada edificio en los casilleros
        virtual void mostrar_mensaje_casillero() = 0;



};  


#endif // EDIFICIO_H