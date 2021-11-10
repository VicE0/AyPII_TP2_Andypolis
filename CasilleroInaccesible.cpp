#include "CasilleroInaccesible.h"

using namespace std;

CasilleroInaccesible::CasilleroInaccesible(char identificacion)
{
    this -> identificacion = identificacion;
}

void CasilleroInaccesible::mostrar()
{
    cout << "Soy un casillero inaccesible" << endl;
}

char CasilleroInaccesible::identificar_casillero()
{
    return this -> identificacion;
}

void CasilleroInaccesible::ocupar_casillero(Edificio* edificio){}

void CasilleroInaccesible::desocupar_casillero(){}