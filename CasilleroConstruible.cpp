#include "CasilleroConstruible.h"

using namespace std;

CasilleroConstruible::CasilleroConstruible(char identidicacion) 
{
    this -> edificio = 0;
    this -> identificacion = identidicacion;
}


void CasilleroConstruible::mostrar() 
{
    if (this -> casillero_ocupado()) 
    {
        cout << "Soy un casillero construible y no me encuentro vacio" <<endl;
        this -> edificio -> mostrar_mensaje_casillero();
    }

    else 
    {
        cout << "Soy un casillero construible y me encuentro vacío" << endl;
    }
}


char CasilleroConstruible::identificar_casillero() 
{
    return this -> identificacion;
}


void CasilleroConstruible::ocupar_casillero(Edificio* edificio) 
{
    this -> edificio = edificio;
}


void CasilleroConstruible::desocupar_casillero() 
{
    this -> edificio = 0;
}


bool CasilleroConstruible::casillero_ocupado() 
{
    return this -> edificio != 0;
}



Edificio* CasilleroConstruible::obtener_edificio() 
{
    return this -> edificio;
}


