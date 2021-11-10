#include "Mapa.h"
#include <iostream>
#include <fstream>

using namespace std;

const string PATH_MAPA = "mapa.txt";

Mapa::Mapa() 
{
    this -> leer_archivo_mapa();
}


void Mapa::leer_archivo_mapa() 
{
    ifstream archivo_mapa;
    archivo_mapa.open(PATH_MAPA.c_str());

    char identificacion;
    int filas;
    int columnas;

    if(!archivo_mapa) 
    {
        cout<<"No se pudo leer el archivo: "<<PATH_MAPA<<endl;
        exit(1);
    }

    archivo_mapa >> filas;
    archivo_mapa >> columnas;

    this -> formato_matriz();

    for (int fila = 0; fila < this -> filas; fila++) 
    {
        for (int columna = 0; columna < this -> columnas; columna++) 
        {
            archivo_mapa >> identificacion;

            if (identificacion == 'T') 
            {
                this -> mapa[fila][columna] = new CasilleroConstruible(identificacion);
            }
            // CASILLERO TRANSITABLE DA MATERIALES

            else if (identificacion == 'L')
            {
                this -> mapa[fila][columna] = new CasilleroInaccesible(identificacion);
            }
        }
    }

    archivo_mapa.close();
}


void Mapa::formato_matriz() 
{
    this -> mapa = new Casillero** [filas];

    for (int fila = 0; fila < filas; fila++) 
    {
        this -> mapa[fila] = new Casillero*[columnas];
    }

    for (int i = 0; i <  filas; i++) 
    {
        for (int j  = 0; j  < columnas; j ++) 
        {
            this -> mapa[i][j] = 0;
        }
    }
}


void Mapa::consultar_coordenada(int x, int y) 
{
    if(x > filas || y > columnas)
    {
        cout << "Coordenada fuera de rango" << endl;
    }

    else
    {
        this -> mapa[x][y] -> mostrar();
    }
}



char Mapa::obtener_casillero(int x, int y)
{
    return this -> mapa[x][y] -> casillero_ocupado();
}


Edificio* Mapa::obtener_elemento(int x, int y)
{
    return this -> mapa[x][y] -> obtener_edificio();
}


bool Mapa::casillero_ocupado(int x, int y)
{
    return this -> mapa[x][y] -> casillero_ocupado();
}


void Mapa::actualizar_casillero_ocupado(Edificio* edificio, int x, int y) 
{
    this -> mapa[x][y] -> ocupar_casillero(edificio);
}


void Mapa::sacar_edificio_construido(int x, int y) 
{
    this -> mapa[x][y] -> desocupar_casillero();
}


int Mapa::pedir_coordenada_x()
{   
    int x;
    cout << "Ingrese la fila: ";
    cin >> x;
    return x;
}

int Mapa::pedir_coordenada_y()
{  
    int y; 
    cout << "Ingrese la columna: ";
    cin >> y;
    return y;
}



void Mapa::mostrar_mapa()
{
  	for(int i = 0; i < this -> filas; i++){
		for(int j = 0; j < this -> columnas; j++){
            cout << mapa[i][j] -> identificar_casillero();
		}
		cout << endl;
	}
	cout << endl;

}

// Mapa::~Mapa() 
// {
//     for (int fila = 0; fila < filas; fila++) 
//     {
//         for (int columna = 0; columna < columnas; columna++)
//         {
//             delete this -> mapa[fila][columna];
//         }

//         delete [] this -> mapa[fila];
//     }
//     delete [] this -> mapa;
//     this -> mapa = 0;
// }