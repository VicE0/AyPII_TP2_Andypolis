#include "Inventario.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string PATH_MATERIALES = "materiales.txt";

Inventario::Inventario()
{
    this -> cantidad_materiales = 0;
    this -> leer_archivo_materiales();
}

void Inventario::leer_archivo_materiales()
{
    ifstream archivo_materiales;

    archivo_materiales.open(PATH_MATERIALES.c_str());
    string nombre_material;
    unsigned int cantidad;

    if(!archivo_materiales)
    {
        cout<<"No se pudo leer el archivo: "<<PATH_MATERIALES<<endl;
        exit(1);
    }

    while (archivo_materiales >> nombre_material >> cantidad) //cargo el array
    {
        this -> materiales[cantidad_materiales] = new Material();
        this -> materiales[cantidad_materiales]-> nombre_material = nombre_material;
        this -> materiales[cantidad_materiales]-> cantidad = cantidad;
        cantidad_materiales++; 
    }
    

    archivo_materiales.close();

}

// --------------------------------------------------------------------



void Inventario::mostrar_materiales()
{   
    for (int i = 0; i < cantidad_materiales; i++)
    {
        cout << "\n"; 
        cout << "|-----------------------------------|" << endl;
        cout << "	" << "MATERIAL: "<< this -> materiales[i]-> nombre_material  << endl;
        cout << "	" << "CANDTIDAD : "<< this -> materiales[i]-> cantidad <<endl;
        cout << "|-----------------------------------|" << endl;
        cout << "\n"; 

    }

}


int Inventario::obtener_material(string nombre, Material* datos_material)
{
    int posicion = 0;
    bool material_encontrado = false;
    while (!material_encontrado && posicion < cantidad_materiales)
    {
        if (this -> materiales[posicion] -> nombre_material == nombre)
        {
            datos_material = this -> materiales[posicion];
        }
        posicion ++;
    }
    return datos_material -> cantidad;
}