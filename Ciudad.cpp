#include "Ciudad.h"
#include "Inventario.h"
#include "Aserradero.h"
#include <iostream>
#include <fstream>
#include <string>

const string PIEDRA = "piedra";
const string MADERA = "madera";
const string METAL = "metal";

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

        this ->cargar_edificios(nombre_edificio, cantidad_piedra, cantidad_madera, cantidad_metal, maximo_permitidos );

    }
    

    archivo_edificios.close();
}


void Ciudad::cargar_edificios(string nombre_edificio, int cantidad_piedra, int cantidad_madera, int cantidad_metal, int maximo_permitidos)
{
        this -> edificios[cantidad_edificios] = new Edificio();
        this -> edificios[cantidad_edificios]-> nombre_edificio = nombre_edificio;
        this -> edificios[cantidad_edificios]-> cantidad_piedra = cantidad_piedra;
        this -> edificios[cantidad_edificios]-> cantidad_madera = cantidad_madera;
        this -> edificios[cantidad_edificios]-> cantidad_metal = cantidad_metal;
        this -> edificios[cantidad_edificios]-> maximo_permitidos = maximo_permitidos;
  
        cantidad_edificios++;
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
        // cout << "\t"<< "CONSTRUIDOS: " << this -> edificios[i] -> cantidad_construidos <<endl;
        cout << "\t"<< "AUN SE PUEDEN CONSTRUIR: "<< (this -> edificios[i]-> maximo_permitidos)<<endl; 
        cout << "|-----------------------------------|" << endl;
        cout << "\n"; 

    }

}

// void Ciudad::mostrar_edificios_construidos()
// {
//     for (int i = 0; i < cantidad_edificios; i++)
//     {
//         if (this -> edificios[i] -> cantidad_construidos > 0)
//         {
//             cout << "\n"; 
//             cout << "|-----------------------------------|" << endl;
//             cout << "\t"<< "EDIFICIO: "<< this -> edificios[i]-> nombre_edificio  << endl;
//             cout << "\t"<< "CONSTRUIDOS: " << this -> edificios[i] -> cantidad_construidos <<endl;
//             cout << "\t"<< "AUN SE PUEDEN CONSTRUIR: "<< (this -> edificios[i]-> maximo_permitidos - this -> edificios[i] -> cantidad_construidos)<<endl; 
//             //agregar coordenadas
//             cout << "|-----------------------------------|" << endl;
//             cout << "\n"; 
//         }
//     }
    
// }


// --------------------------------------------------------------------
  
int Ciudad::obtener_posicion(string ingresar_edificio_construir)
{
    int posicion = 0;

    while ((posicion < cantidad_edificios) && (ingresar_edificio_construir != this -> edificios[posicion] -> nombre_edificio))
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
    cout << "Ingrese el edificio: ";
    cin >> ingresar_edificio;
    return ingresar_edificio;
}


void Ciudad::construir_edificio(int posicion, Aserradero &construidos_aserradero ) 
{
    Inventario inventario;
   
    string decision;
    
    int piedra = inventario.obtener_material(PIEDRA);
    int madera = inventario.obtener_material(MADERA);
    int metal = inventario.obtener_material(METAL);
 
    if (this -> edificios[posicion] -> cantidad_piedra > piedra ||
        this -> edificios[posicion] -> cantidad_madera > madera ||
        this -> edificios[posicion] -> cantidad_metal > metal)
    {
        cout << "No hay materiales suficientes para completar la construcción." << endl;
    }
    else if(construidos_aserradero.aserraderos_construidos == this -> edificios[posicion] ->maximo_permitidos)
    {
        cout << "Ya se alcanzó el máximo permitido de construccion" << endl;
    }
    else //falta coordenadas
    {   
       cout << "Estás seguro que deseas construir? [y/n]" << endl;
       cin >> decision;
        if(decision == "y")
        {
            
            piedra -= this -> edificios[posicion] -> cantidad_piedra;
            madera -= this -> edificios[posicion] -> cantidad_madera;
            metal -= this -> edificios[posicion] -> cantidad_metal;

            cout << "Edificio construido con éxito." <<endl;
            cout << piedra << endl;
            construidos_aserradero.aserraderos_construidos ++ ;
            cout << construidos_aserradero.aserraderos_construidos << endl;
        }
       else
        {
            cout << "No se realizó la construcción."<<endl;
        }

    }
}

//creo que se va a necesitar una funcion construir para cada edificio nooooo