#include "Ciudad.h"
#include "Material.h"
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

    string nombre_edificio;
    int cantidad_piedra;
    int cantidad_madera;
    int cantidad_metal;
    int maximo_permitidos;



    if(!archivo_edificios)
    {
        cout<<"No se pudo leer el archivo: "<<PATH_EDIFICIOS<<endl;
        exit(1);
    }

    while (archivo_edificios >> nombre_edificio) //cargo el array
    {
        archivo_edificios >> cantidad_piedra;
        archivo_edificios >> cantidad_madera;
        archivo_edificios >> cantidad_metal;
        archivo_edificios >> maximo_permitidos;

        this -> edificios[cantidad_edificios] = new Edificio();
        this -> edificios[cantidad_edificios]-> nombre_edificio = nombre_edificio;
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
        cout << "\t"<< "EDIFICIO: "<< this -> edificios[i]-> nombre_edificio  << endl;
        cout << "\t"<< "PIEDRA : "<< this -> edificios[i]-> cantidad_piedra << " unidades necesarias" <<endl;
        cout << "\t"<< "MADERA : "<< this -> edificios[i]-> cantidad_madera << " unidades necesarias" <<endl;
        cout << "\t"<< "METAL : "<< this -> edificios[i]-> cantidad_metal << " unidades necesarias" <<endl;
        cout << "\t"<< "CONSTRUIDOS: " << this -> edificios[i] -> cantidad_construidos <<endl;
        cout << "\t"<< "AUN SE PUEDEN CONSTRUIR: "<< (this -> edificios[i]-> maximo_permitidos - this -> edificios[i] -> cantidad_construidos)<<endl; 
        cout << "|-----------------------------------|" << endl;
        cout << "\n"; 

    }

}

void Ciudad::mostrar_edificios_construidos()
{
    for (int i = 0; i < cantidad_edificios; i++)
    {
        if (this -> edificios[i] -> cantidad_construidos > 0)
        {
            cout << "\n"; 
            cout << "|-----------------------------------|" << endl;
            cout << "\t"<< "EDIFICIO: "<< this -> edificios[i]-> nombre_edificio  << endl;
            cout << "\t"<< "CONSTRUIDOS: " << this -> edificios[i] -> cantidad_construidos <<endl;
            cout << "\t"<< "AUN SE PUEDEN CONSTRUIR: "<< (this -> edificios[i]-> maximo_permitidos - this -> edificios[i] -> cantidad_construidos)<<endl; 
            //agregar coordenadas
            cout << "|-----------------------------------|" << endl;
            cout << "\n"; 
        }
    }
    
}


// --------------------------------------------------------------------

bool Ciudad::edificio_valido()
{
    int posicion = 0;

    while(posicion < cantidad_edificios)
    {
        posicion++;
    }

    if (posicion >= cantidad_edificios)
    {
        return false;
    }
    return true;
}
  
int Ciudad::obtener_posicion()
{
    int posicion = 0;

    while (posicion < cantidad_edificios)
    {
        posicion++;
    }

    if (posicion >= cantidad_edificios)
    {
        return -1;
    }
    return posicion;
}

string Ciudad::pedir_edificio()
{
    string ingresar_edificio;
    cout << "Ingrese el edificio: " << endl;
    return ingresar_edificio;
}


void Ciudad::construir_edificio(int posicion) //agregar posicion a procesar opcion
{
    string decision;

    if (this -> edificios[posicion] -> cantidad_piedra > this -> materiales[0]-> cantidad ||
        this -> edificios[posicion] -> cantidad_madera > this -> materiales[1]-> cantidad ||
        this -> edificios[posicion] -> cantidad_metal> this -> materiales[2]-> cantidad)
    {
        cout << "No hay suficientes materiales para realizar la construccion"<<endl;
    }

    else if(this->edificios[posicion] -> cantidad_construidos == this -> edificios[posicion] ->maximo_permitidos)
    {
        cout << "Ya se alcanzó el máximo permitido de construccion" << endl;
    }
    else //falta coordenadas
    {   
        cout << "Estás seguro que deseas construir? [y/n]" << endl;
        cin >> decision;
        if(decision == "y")
        {
            this -> edificios[posicion] -> cantidad_construidos++;
            this -> materiales[0]-> cantidad -= this -> edificios[posicion] -> cantidad_piedra;
            this -> materiales[1]-> cantidad -= this -> edificios[posicion] -> cantidad_madera;
            this -> materiales[2]-> cantidad -= this -> edificios[posicion] -> cantidad_metal;

            cout << "Edificio construido con éxito." <<endl;
        }
        else
        {
            cout << "No se realizó la construcción."<<endl;
        }

    }
}