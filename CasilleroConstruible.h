#ifndef CASILLERO_CONSTRUIBLE_H
#define CASILLERO_CONSTRUIBLE_H

#include "Casillero.h"

class CasilleroConstruible: public Casillero 

{
    private:
        Edificio* edificio;

    public:

        CasilleroConstruible(char identidicacion);

        // PRE: ~
        // POST: muestra el mensaje del casillero y, si está ocupado, muestra el mensaje del edificio que lo ocupa
        void mostrar();

        // PRE: ~
        // POST: Devuelve la letra que identifica el tipo de casillero
        char identificar_casillero();

        // PRE: Recibe el edificio que va a ocupar el casillero
        // POST: Ocupa el casillero
        void ocupar_casillero(Edificio* edificio);

        // PRE: ~
        // POST: Libera el casillero
        void desocupar_casillero();

        // PRE: ~
        // POST: TRUE si el casillero está ocupado, FALSE si está vacio
        bool casillero_ocupado();


        // PRE: ~
        // POST: Devuelve el edificio que se encuentra en el casillero
        Edificio* obtener_edificio();

};

#endif