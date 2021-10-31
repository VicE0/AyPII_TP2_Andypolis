#include "Posiciones.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

const string PATH_UBICACIONES = "ubicaciones.txt";

Posiciones::Posiciones()
{
    this -> cantidad_ubicaciones = 0;
    this -> leer_archivo_posiciones();
}

void Posiciones::leer_archivo_posiciones()
{
    ifstream archivo_ubicaciones;

    archivo_ubicaciones.open(PATH_UBICACIONES.c_str());

    string nombre;
    char parentesis_abierto;
    char parentesis_cerrado;
    
    if(!archivo_ubicaciones)
    {
        cout<<"No se pudo leer el archivo: "<<PATH_UBICACIONES<<endl;
        exit(1);
    }
    
    // while ()
    // {

    // }

    
    
    
    archivo_ubicaciones.close();
}

void Posiciones::consultar_coordenada()
{
    for (int i = 0; i < cantidad_ubicaciones; i++)
    {
        cout << this -> ubicaciones[i]-> nombre  << endl;
        cout << this -> ubicaciones[cantidad_ubicaciones] -> parentesis_abierto << endl;
        cout << this -> ubicaciones[cantidad_ubicaciones] -> parentesis_cerrado << endl;

    }
}