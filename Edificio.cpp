#include "Edificio.h"

using namespace std;


Edificio::Edificio(){}

string Edificio::obtener_nombre()
{
    return this -> nombre_edificio;
}

int Edificio::obtener_piedra()
{
    return this -> cantidad_piedra;
}

int Edificio::obtener_madera()
{
    return this-> cantidad_madera;
}

int Edificio::obtener_metal()
{
    return this ->cantidad_metal;
}

int Edificio::obtener_permitidos()
{
    return this -> maximo_permitidos;
}
