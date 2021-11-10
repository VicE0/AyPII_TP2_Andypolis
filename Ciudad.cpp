#include "Ciudad.h"

#include <iostream>
#include <fstream>
#include <string>

const string PIEDRA = "piedra";
const string MADERA = "madera";
const string METAL = "metal";

using namespace std;

const string PATH_EDIFICIOS = "edificios.txt";
const string PATH_UBICACIONES = "ubicaciones.txt";

Ciudad::Ciudad()
{
    this -> cantidad_edificios = 0;
    this -> cantidad_ubicaciones = 0;
    this -> leer_archivo_edificios();
    
}

void Ciudad::leer_archivo_edificios()
{

    ifstream archivo_edificios;

    archivo_edificios.open(PATH_EDIFICIOS.c_str());

    string nombre_edificio;
    string segundo_nombre;
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
        if (nombre_edificio == "planta")
        {
            archivo_edificios >> segundo_nombre;
            nombre_edificio += ' ' + segundo_nombre;
        }
        archivo_edificios >> cantidad_piedra;
        archivo_edificios >> cantidad_madera;
        archivo_edificios >> cantidad_metal;
        archivo_edificios >> maximo_permitidos;

        this -> cargar_edificios(nombre_edificio, cantidad_piedra, cantidad_madera, cantidad_metal, maximo_permitidos);

    }
    

    archivo_edificios.close();
}



// void Ciudad::leer_ubicaciones()
// {
//     ifstream archivo_ubicaciones;
//     archivo_ubicaciones.open(PATH_UBICACIONES.c_str());

//     string nombre_edificio_construido;
//     string segundo_nombre;
//     string ancho;
//     string alto;
 
//     if (!archivo_ubicaciones)
//     {
//         cout<<"No se pudo leer el archivo: "<<PATH_UBICACIONES<<endl;
//         exit(1);        
//     }

//     while (archivo_ubicaciones >> nombre_edificio_construido)
//     {
//         if (nombre_edificio_construido == "planta")
//         {
//             archivo_ubicaciones >> segundo_nombre;
//             nombre_edificio_construido += ' ' + segundo_nombre;
//         }

//         archivo_ubicaciones >> ancho;
//         archivo_ubicaciones >> alto;

//         this -> cargar_ubicaciones(nombre_edificio_construido, ancho, alto);

//     }
//     archivo_ubicaciones.close();
    
// }

void Ciudad::cargar_edificios(string nombre_edificio, int cantidad_piedra, int cantidad_madera, int cantidad_metal, int maximo_permitidos)
{
   
    if(nombre_edificio == "mina")
    {
        this -> edificios[cantidad_edificios] = new Mina(nombre_edificio, cantidad_piedra, cantidad_madera, cantidad_metal, maximo_permitidos);
    }
    else if (nombre_edificio == "aserradero")
    {
        this -> edificios[cantidad_edificios] = new Aserradero(nombre_edificio, cantidad_piedra, cantidad_madera, cantidad_metal, maximo_permitidos);
    }
    else if (nombre_edificio == "escuela")
    {
        this -> edificios[cantidad_edificios] = new Escuela(nombre_edificio, cantidad_piedra, cantidad_madera, cantidad_metal, maximo_permitidos);
    }
    else if (nombre_edificio == "fabrica")
    {
        this -> edificios[cantidad_edificios] = new Fabrica(nombre_edificio, cantidad_piedra, cantidad_madera, cantidad_metal, maximo_permitidos);
    }
    else if (nombre_edificio == "obelisco")
    {
        this -> edificios[cantidad_edificios] = new Obelisco(nombre_edificio, cantidad_piedra, cantidad_madera, cantidad_metal, maximo_permitidos);
    }
    else
    {
        this -> edificios[cantidad_edificios] = new Planta(nombre_edificio, cantidad_piedra, cantidad_madera, cantidad_metal, maximo_permitidos);
    }
    
    cantidad_edificios++;
}



//-------------------------OPCIONES DEL MENU----------------------------------------- 


void Ciudad::mostrar_totalidad_edificios()
{   
    for (int i = 0; i < cantidad_edificios; i++)
    {
        this -> edificios[i] -> mostrar_edificios();
    }
    
}




  
// int Ciudad::obtener_posicion(string ingresar_edificio_construir)
// {
//     int posicion = 0;

//     while ((posicion < cantidad_edificios) && (ingresar_edificio_construir != this -> edificios[posicion] -> nombre_edificio))
//     {
//         posicion++;
//     }

//     if (posicion >= cantidad_edificios)
//     {
//         return -1;
//     }
//     return posicion;
// }

string Ciudad::pedir_edificio()
{
    string ingresar_edificio;
    cout << "Ingrese el edificio: ";
    cin >> ingresar_edificio;
    return ingresar_edificio;
}


// void Ciudad::construir_edificio(int posicion,Inventario* datos_material, Ciudad* datos_ciudad, Ciudad* datos_ubicaciones) 
// {  

//     string decision;
//     Inventario inventario;

//     Material* piedra = inventario.obtener_material(PIEDRA,datos_material);
//     Material* madera = inventario.obtener_material(MADERA,datos_material);
//     Material* metal = inventario.obtener_material(METAL,datos_material);
        
//     if (datos_ciudad -> edificios[posicion] -> cantidad_piedra > piedra -> cantidad ||
//         datos_ciudad -> edificios[posicion] -> cantidad_madera > madera -> cantidad ||
//         datos_ciudad -> edificios[posicion] -> cantidad_metal > metal -> cantidad)
//     {
//         cout << "No hay materiales suficientes para completar la construcción." << endl;
//     }

//     else if(datos_ubicaciones -> ubicaciones[posicion] -> cantidad_construidos == datos_ciudad -> edificios[posicion] -> maximo_permitidos)
//     {
//         cout << "Ya se alcanzó el máximo permitido de construccion" << endl;
//     }

    
//     else //falta coordenadas
//     {   

//         cout << "Estás seguro que deseas construir? [y/n]" << endl;
//         cin >> decision;

//         if(decision == "y")
//         {
//             piedra -> cantidad -= datos_ciudad -> edificios[posicion] -> cantidad_piedra;
//             madera -> cantidad -= datos_ciudad -> edificios[posicion] -> cantidad_madera;
//             metal -> cantidad -= datos_ciudad -> edificios[posicion] -> cantidad_metal;

//             cout << "Edificio construido con éxito." <<endl;
     
//             datos_ubicaciones -> ubicaciones[posicion] -> cantidad_construidos++;     
//         }

//        else
//         {
//             cout << "No se realizó la construcción."<<endl;
//         }

//     }
// }

