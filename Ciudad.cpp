#include "Ciudad.h"

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

        this ->cargar_edificios(nombre_edificio, cantidad_piedra, cantidad_madera, cantidad_metal, maximo_permitidos);

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
        this -> edificios[cantidad_edificios] -> cantidad_construidos = 0;
        cantidad_edificios++;
}


void Ciudad::mostrar_totalidad_edificios(Ciudad* datos_ciudad)
{   
    for (int i = 0; i < cantidad_edificios; i++)
    {
        cout << "\n"; 
        cout << "|-----------------------------------|" << endl;
        cout << "\t"<< "EDIFICIO: "<< datos_ciudad -> edificios[i]-> nombre_edificio  << endl;
        cout << "\t"<< "PIEDRA : "<< datos_ciudad -> edificios[i]-> cantidad_piedra << " unidades necesarias" <<endl;
        cout << "\t"<< "MADERA : "<< datos_ciudad -> edificios[i]-> cantidad_madera << " unidades necesarias" <<endl;
        cout << "\t"<< "METAL : "<< datos_ciudad -> edificios[i]-> cantidad_metal << " unidades necesarias" <<endl;
        cout << "\t"<< "CONSTRUIDOS: " << datos_ciudad -> edificios[i] -> cantidad_construidos <<endl;
        cout << "\t"<< "AUN SE PUEDEN CONSTRUIR: "<< (datos_ciudad -> edificios[i]-> maximo_permitidos)<<endl; 
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


void Ciudad::construir_edificio(int posicion,int &piedra, int &madera, int &metal, Ciudad* datos_ciudad) 
{
    Inventario inventario;
    
  
    string decision;
    
    if (datos_ciudad -> edificios[posicion] -> cantidad_piedra > piedra ||
        datos_ciudad -> edificios[posicion] -> cantidad_madera > madera ||
        datos_ciudad -> edificios[posicion] -> cantidad_metal > metal)
    {
        cout << "No hay materiales suficientes para completar la construcción." << endl;
    }
    else if(datos_ciudad -> edificios[posicion] -> cantidad_construidos == datos_ciudad -> edificios[posicion] -> maximo_permitidos)
    {
        cout << "Ya se alcanzó el máximo permitido de construccion" << endl;
    }
    else //falta coordenadas
    {   
    cout << datos_ciudad -> edificios[posicion] -> cantidad_piedra << "piedra" << endl;
       cout << "Estás seguro que deseas construir? [y/n]" << endl;
       cin >> decision;
        if(decision == "y")
        {
            piedra -= datos_ciudad -> edificios[posicion] -> cantidad_piedra;
            madera -= datos_ciudad -> edificios[posicion] -> cantidad_madera;
            metal -= datos_ciudad -> edificios[posicion] -> cantidad_metal;

            cout << "Edificio construido con éxito." <<endl;
     
            datos_ciudad -> edificios[posicion] -> cantidad_construidos++;
            cout << datos_ciudad -> edificios[posicion] -> cantidad_construidos << "construidos" << endl;
          
            // sumar_construidos(posicion, aserradero, fabrica, escuela, yacimiento, mina, obelisco, planta);

        }
       else
        {
            cout << "No se realizó la construcción."<<endl;
        }

    }
}

// void Ciudad::sumar_construidos(int posicion, Aserradero &aserradero,Fabrica &fabrica, Escuela &escuela,  
//                        Yacimiento &yacimiento, Mina &mina, Obelisco &obelisco, Planta &planta )
// {
//     switch(posicion)
//     {
//         case 0:
//             // aserradero.aserraderos_construidos ++;
//             // cout << aserradero.aserraderos_construidos<<endl;
//             break;

//         case 1:
//             fabrica.fabricas_construidas ++;
//             cout << fabrica.fabricas_construidas<< endl;
//             break;

//         case 2:
//             escuela.escuelas_construidas ++;
//             break;

//         case 3:
//             yacimiento.yacimientos_construidas ++;
//             break;

//         case 4:
//             mina.minas_construidas ++;
//             break ;    

//         case 5:
//             obelisco.obeliscos_construidas ++;
//             break;   

//         case 6:
//             planta.plantas_construidas ++;
//             break;
//     }
// }