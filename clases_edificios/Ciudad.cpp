#include "Ciudad.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string PATH_EDIFICIOS = "edificios.txt";

Ciudad::Ciudad()
{
    this -> cantidad_edificios = 0;
    this -> leer_archivo_edificios();
}

void Ciudad::leer_archivo_edificios()
{
    ifstream archivo_edificios;

    archivo_edificios.open(PATH_EDIFICIOS.c_str());

    string nombre;
    int cantidad_piedra;
    int cantidad_madera;
    int cantidad_metal;
    int maximo_permitidos;


    if(!archivo_edificios)
    {
        cout<<"No se pudo leer el archivo: "<<PATH_EDIFICIOS<<endl;
        exit(1);
    }

    while (archivo_edificios >> nombre) //cargo el array
    {
        archivo_edificios >> cantidad_piedra;
        archivo_edificios >> cantidad_madera;
        archivo_edificios >> cantidad_metal;
        archivo_edificios >> maximo_permitidos;


        this -> edificios[cantidad_edificios] = new Edificio();
        this -> edificios[cantidad_edificios]-> nombre = nombre;
        this -> edificios[cantidad_edificios]-> cantidad_piedra = cantidad_piedra;
        this -> edificios[cantidad_edificios]-> cantidad_madera = cantidad_madera;
        this -> edificios[cantidad_edificios]-> cantidad_metal = cantidad_metal;
        this -> edificios[cantidad_edificios]-> maximo_permitidos = maximo_permitidos;
  

        cantidad_edificios++;

    }
    
    
    archivo_edificios.close();
}


void Ciudad::mostrar_totalidad_edificios()
{   
    for (int i = 0; i < cantidad_edificios; i++)
    {
        cout << "\n"; 
        cout << "|-----------------------------------|" << endl;
        cout << "	"<< "EDIFICIO: "<< this -> edificios[i]-> nombre  << endl;
        cout << "	"<< "PIEDRA : "<< this -> edificios[i]-> cantidad_piedra << " unidades necesarias" <<endl;
        cout << "	"<< "MADERA : "<< this -> edificios[i]-> cantidad_madera << " unidades necesarias" <<endl;
        cout << "	"<< "METAL : "<< this -> edificios[i]-> cantidad_metal << " unidades necesarias" <<endl;
        cout << "	"<< "AUN SE PUEDEN CONSTRUIR: "<< (this -> edificios[i]-> maximo_permitidos - this->edificios[i]->cantidad_construidos)<<endl; 
        cout << "|-----------------------------------|" << endl;
        cout << "\n"; 

    }

}

