#ifndef CASILLERO_H
#define CASILLERO_H

#include "Edificio.h"

class Casillero
{
    protected:
        char identificacion;

    public:

        Casillero();

        // PRE: ~
        // POST: Devuelve la letra que identifica el tipo de casillero
        virtual char identificar_casillero() = 0;

        // PRE: ~
        // POST: Muestra el mensaje del casillero y, si está ocupado, muestra el mensaje del edificio que lo ocupa
        virtual void mostrar() = 0;

        // PRE: ~
        // POST: TRUE si el casillero está ocupado, FALSE si está vacio
        virtual bool casillero_ocupado();

         // PRE: ~
        // POST: Devuelve el edificio que se encuentra en el casillero
        virtual Edificio* obtener_edificio();

        // PRE: Recibe el edificio que va a ocupar el casillero
        // POST: Ocupa el casillero 
        virtual void ocupar_casillero(Edificio* edificio);

        // PRE: ~
        // POST: Libera el casillero
        virtual void desocupar_casillero();
 
 //Ocupar / desocupar casilleros no pueden ser = 0 porque Casillero Inaccesible no los utiliza
//Simplemente las llamo en los .cpp correspondientes
};

#endif