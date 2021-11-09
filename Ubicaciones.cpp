#include "Ubicaciones.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string PATH_UBICACIONES = "ubicaciones.txt";

Ubicaciones::Ubicaciones()
{
    this ->cantidad_ubicaciones = 0;
    this ->leer_ubicaciones();
}

void Ubicaciones::leer_ubicaciones()
{
    ifstream archivo_ubicaciones;
    archivo_ubicaciones.open(PATH_UBICACIONES.c_str());

    string nombre_edificio_construido;
    string ancho;
    string alto;
 
    if (!archivo_ubicaciones)
    {
        cout<<"No se pudo leer el archivo: "<<PATH_UBICACIONES<<endl;
        exit(1);        
    }

    while (archivo_ubicaciones >> nombre_edificio_construido)
    {

        archivo_ubicaciones >> ancho;
        archivo_ubicaciones >> alto;

        this -> cargar_ubicaciones(nombre_edificio_construido, ancho, alto);

    }
    archivo_ubicaciones.close();
    
}

void Ubicaciones::cargar_ubicaciones(string nombre_edificio_construido, string ancho, string alto)
{
    this -> ubicaciones[cantidad_ubicaciones] = new Coordenadas();
    this -> ubicaciones[cantidad_ubicaciones] -> nombre_edificio_construido = nombre_edificio_construido;
    this -> ubicaciones[cantidad_ubicaciones] -> ancho = ancho;
    this -> ubicaciones[cantidad_ubicaciones] -> alto = alto;
    
    cantidad_ubicaciones++;
}

