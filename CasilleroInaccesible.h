
#ifndef CASILLERO_INACCESIBLE_H
#define CASILLERO_INACCESIBLE_H

#include "Casillero.h"

class CasilleroInaccesible: public Casillero 
{
    public:

        CasilleroInaccesible(char identificacion);

        // PRE: ~
        // POST: Devuelve la letra que identifica el tipo de casillero
        char identificar_casillero();

        // PRE: ~
        // POST: Muestra el mensaje del casillero y, si está ocupado, muestra el mensaje del edificio que lo ocupa
        void mostrar();
        
//-------------------------------
        //Si bien estas dos funciones no son utilizadas por este tipo de casillero, les agregro PRE y POST condiciones

        // PRE: Recibe el edificio que va a ocupar el casillero
        // POST: Ocupa el casillero
        void ocupar_casillero(Edificio* edificio);

        // PRE: ~
        // POST: Libera el casillero
        void desocupar_casillero();
};

#endif