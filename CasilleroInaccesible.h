
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

        void ocupar_casillero(Edificio* edificio);

        void desocupar_casillero();
};

#endif