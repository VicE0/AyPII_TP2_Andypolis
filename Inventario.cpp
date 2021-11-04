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



void Inventario::mostrar_materiales(Inventario* datos_material)
{   
    for (int i = 0; i < cantidad_materiales; i++)
    {
        cout << "\n"; 
        cout << "|-----------------------------------|" << endl;
        cout << "	" << "MATERIAL: "<< datos_material -> materiales[i]-> nombre_material  << endl;
        cout << "	" << "CANDTIDAD : "<< datos_material -> materiales[i]-> cantidad <<endl;
        cout << "|-----------------------------------|" << endl;
        cout << "\n"; 

    }

}

Material* Inventario::obtener_material(string nombre, Inventario* datos_material)
{
    Material* material = NULL;
    
    int posicion = 0;
    bool material_encontrado = false;

    while (!material_encontrado && posicion < datos_material -> cantidad_materiales)
    {
        if (datos_material -> materiales[posicion] -> nombre_material == nombre)
        {
            material = datos_material -> materiales[posicion];
            material_encontrado = true;
        }
        posicion ++;
    }
    return material;
}