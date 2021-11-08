#include "Ubicaciones.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

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

    string nombre;
    string ancho;
    string alto;
 
    if (!archivo_ubicaciones)
    {
        cout<<"No se pudo leer el archivo: "<<PATH_UBICACIONES<<endl;
        exit(1);        
    }

    while (archivo_ubicaciones >> nombre)
    {

        archivo_ubicaciones >> ancho;
        archivo_ubicaciones >> alto;
        
        // getline(archivo_ubicaciones, nombre, '(');
        // getline(archivo_ubicaciones, ancho, ',');
        // getline(archivo_ubicaciones, alto, ')');
        // getline(archivo_ubicaciones, aux);

        this -> cargar_ubicaciones(nombre, ancho, alto);

    }
    archivo_ubicaciones.close();
    
}

void Ubicaciones::cargar_ubicaciones(string nombre, string ancho, string alto)
{
    this -> ubicaciones[cantidad_ubicaciones] = new Coordenadas();
    this -> ubicaciones[cantidad_ubicaciones] -> nombre = nombre;
    this -> ubicaciones[cantidad_ubicaciones] -> ancho = ancho;
    this -> ubicaciones[cantidad_ubicaciones] -> alto = alto;
    

    cantidad_ubicaciones++;
}

void Ubicaciones::consultar_coordenada()
{
    for(int i = 0; i < cantidad_ubicaciones; i++)
    {
        cout << this -> ubicaciones[i] -> nombre << endl;
        cout << this -> ubicaciones[i] -> ancho << endl;
        cout << this -> ubicaciones[i] -> alto << endl;
        cout << this -> ubicaciones[i] -> aux << endl;
    }
}