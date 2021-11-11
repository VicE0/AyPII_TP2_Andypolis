#include "Ciudad.h"

#include <iostream>
#include <fstream>
#include <string>

const string PIEDRA = "piedra";
const string MADERA = "madera";
const string METAL = "metal";

const string PLANTA = "planta";


const string MINA = "mina";
const string ASERRADERO = "aserradero";
const string ESCUELA = "escuela";
const string FABRICA = "fabrica";
const string OBELISCO = "obelisco";

const string YES = "y";


using namespace std;

const string PATH_EDIFICIOS = "edificios.txt";
const string PATH_UBICACIONES = "ubicaciones.txt";

Ciudad::Ciudad()
{
    this -> cantidad_edificios = 0;
    this -> cantidad_ubicaciones = 0;
    this -> leer_archivo_edificios();
    this -> leer_ubicaciones();
    
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

    while (archivo_edificios >> nombre_edificio)
    {
        if (nombre_edificio == PLANTA)
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


void Ciudad::leer_ubicaciones()
{
    ifstream archivo_ubicaciones;
    archivo_ubicaciones.open(PATH_UBICACIONES.c_str());

    string nombre_edificio_construido;
    string segundo_nombre;
    string ancho;
    string alto;
 
    if (!archivo_ubicaciones)
    {
        cout<<"No se pudo leer el archivo: "<<PATH_UBICACIONES<<endl;
        exit(1);        
    }

    while (archivo_ubicaciones >> nombre_edificio_construido)
    {
        if (nombre_edificio_construido == PLANTA)
        {
            archivo_ubicaciones >> segundo_nombre;
            nombre_edificio_construido += ' ' + segundo_nombre;
        }

        archivo_ubicaciones >> ancho;
        archivo_ubicaciones >> alto;

        this -> cargar_ubicaciones(nombre_edificio_construido, ancho, alto);

    }
    archivo_ubicaciones.close();
    
}

void Ciudad::cargar_edificios(string nombre_edificio, int cantidad_piedra, int cantidad_madera, int cantidad_metal, int maximo_permitidos)
{
   
    if(nombre_edificio == MINA)
    {
        this -> edificios[cantidad_edificios] = new Mina(nombre_edificio, cantidad_piedra, cantidad_madera, cantidad_metal, maximo_permitidos);
    }
    else if (nombre_edificio == ASERRADERO)
    {
        this -> edificios[cantidad_edificios] = new Aserradero(nombre_edificio, cantidad_piedra, cantidad_madera, cantidad_metal, maximo_permitidos);
    }
    else if (nombre_edificio == ESCUELA)
    {
        this -> edificios[cantidad_edificios] = new Escuela(nombre_edificio, cantidad_piedra, cantidad_madera, cantidad_metal, maximo_permitidos);
    }
    else if (nombre_edificio == FABRICA)
    {
        this -> edificios[cantidad_edificios] = new Fabrica(nombre_edificio, cantidad_piedra, cantidad_madera, cantidad_metal, maximo_permitidos);
    }
    else if (nombre_edificio == OBELISCO)
    {
        this -> edificios[cantidad_edificios] = new Obelisco(nombre_edificio, cantidad_piedra, cantidad_madera, cantidad_metal, maximo_permitidos);
    }
    else
    {
        this -> edificios[cantidad_edificios] = new Planta(nombre_edificio, cantidad_piedra, cantidad_madera, cantidad_metal, maximo_permitidos);
    }
    
    cantidad_edificios++;
}



void Ciudad::cargar_ubicaciones(string nombre_edificio_construido ,string ancho,string alto)
{
    if(nombre_edificio_construido == MINA)
    {
        this -> ubicaciones[cantidad_ubicaciones] = new Mina(nombre_edificio_construido, ancho, alto);
    }
    else if (nombre_edificio_construido == ASERRADERO)
    {
        this -> ubicaciones[cantidad_ubicaciones] = new Aserradero(nombre_edificio_construido, ancho, alto);
    }
    else if (nombre_edificio_construido == ESCUELA)
    {
        this -> ubicaciones[cantidad_ubicaciones] = new Escuela(nombre_edificio_construido, ancho, alto);
    }
    else if (nombre_edificio_construido == FABRICA)
    {
        this -> ubicaciones[cantidad_ubicaciones] = new Fabrica(nombre_edificio_construido, ancho, alto);
    }
    else if (nombre_edificio_construido == OBELISCO)
    {
        this -> ubicaciones[cantidad_ubicaciones] = new Obelisco(nombre_edificio_construido, ancho, alto);
    }
    else
    {
        this -> ubicaciones[cantidad_ubicaciones] = new Planta(nombre_edificio_construido, ancho, alto);
    }

    cantidad_ubicaciones++;
    
}


//-------------------------OPCIONES DEL MENU----------------------------------------- 


void Ciudad::mostrar_totalidad_edificios()
{  
    system(LIMPIAR_PANTALLA); 
    for (int i = 0; i < cantidad_edificios; i++)
    {
        this -> edificios[i] -> mostrar_edificios();
    }
    
}

void Ciudad::mostrar_edificios_construidos()
{
    system(LIMPIAR_PANTALLA);
    for (int i = 0; i < cantidad_edificios; i++)
    {
        if (this -> edificios[i] -> obtener_construidos() > 0)
        {
            this -> ubicaciones[i] -> mostrar_construidos();
        }
        
    }
}


  
int Ciudad::obtener_posicion(string ingresar_edificio_construir)
{
    int posicion = 0;

    while ((posicion < cantidad_edificios) && (ingresar_edificio_construir != this -> edificios[posicion] -> obtener_nombre()))
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




void Ciudad::construir_edificio(int posicion,Inventario* datos_material) 
{  
    system(LIMPIAR_PANTALLA);
    string decision;
    int construidos = this ->edificios[posicion] ->obtener_construidos();
    Inventario inventario;

    Material* piedra = inventario.obtener_material(PIEDRA,datos_material);
    Material* madera = inventario.obtener_material(MADERA,datos_material);
    Material* metal = inventario.obtener_material(METAL,datos_material);
        
    if (this -> edificios[posicion] -> obtener_piedra() > piedra -> cantidad ||
        this -> edificios[posicion] -> obtener_madera() > madera -> cantidad ||
        this -> edificios[posicion] -> obtener_metal() > metal -> cantidad)
    {
        cout << "No hay materiales suficientes para completar la construcción." << endl;
    }

    else if(construidos == this -> edificios[posicion] -> obtener_permitidos())
    {
        cout << "Ya se alcanzó el máximo permitido de construccion" << endl;
    }

    
    else //falta coordenadas
    {   

        cout << "Estás seguro que deseas construir? [y/n]: " ;
        cin >> decision;

        if(decision == YES)
        {
            piedra -> cantidad -= this -> edificios[posicion] -> obtener_piedra();
            madera -> cantidad -= this -> edificios[posicion] -> obtener_madera();
            metal -> cantidad -= this -> edificios[posicion] -> obtener_metal();

            cout << "Edificio construido con éxito." <<endl;

           construidos++;
         
        }

       else
        {
            cout << "No se realizó la construcción."<<endl;
        }

    }
}


void Ciudad::recolectar_recursos(int posicion, Inventario* datos_material)
{
    system(LIMPIAR_PANTALLA);
    Inventario inventario;

    Material* piedra = inventario.obtener_material(PIEDRA,datos_material);
    Material* madera = inventario.obtener_material(MADERA,datos_material);
    Material* metal = inventario.obtener_material(METAL,datos_material);

    if(this -> edificios[posicion] -> obtener_nombre() == "mina" && this ->edificios[posicion] ->obtener_construidos() > 0)
    {
        piedra ->cantidad += this -> edificios[posicion] -> obtener_recursos();
        cout << "Recibes " << this -> edificios[posicion] -> obtener_recursos() << " de piedra" << endl;
    }

    else if (this -> edificios[posicion] -> obtener_nombre() == "aserradero" && this ->edificios[posicion] ->obtener_construidos() > 0)
    {
        madera ->cantidad += this -> edificios[posicion] ->obtener_madera();
        cout << "Recibes " << this -> edificios[posicion] -> obtener_recursos() << " de madera" << endl;
    }
    else if(this -> edificios[posicion] -> obtener_nombre() == "fabrica" && this ->edificios[posicion] ->obtener_construidos() > 0 )
    {
        metal -> cantidad += this -> edificios[posicion] ->obtener_metal();
        cout << "Recibes " << this -> edificios[posicion] -> obtener_recursos() << " de metal" << endl;
    }
    else
    {
        cout << "No hay edificios construidos que brinden materiales" << endl;
    }
}

void Ciudad::guardar_edificios()
{

    ofstream archivo_edificios(PATH_EDIFICIOS);

    for (int i = 0; i < this -> cantidad_edificios; i++)
    {
        archivo_edificios << this ->edificios[i] ->obtener_nombre() << ' ';
        archivo_edificios << this ->edificios[i] ->obtener_piedra() << ' ';
        archivo_edificios << this ->edificios[i] ->obtener_madera() << ' ';
        archivo_edificios << this ->edificios[i] ->obtener_metal() << ' ';;
        archivo_edificios << this ->edificios[i] ->obtener_permitidos() << '\n';
    }


}

