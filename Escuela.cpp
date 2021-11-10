#include "Escuela.h"

Escuela::Escuela(string nombre_edificio, int cantidad_piedra, int cantidad_madera, int cantidad_metal,int maximo_permitidos)
{
    this -> nombre_edificio = nombre_edificio;
    this -> cantidad_piedra = cantidad_piedra;
    this -> cantidad_madera = cantidad_madera;
    this -> cantidad_metal = cantidad_metal;
    this -> maximo_permitidos = maximo_permitidos;
    
}

Escuela::Escuela(string nombre_edificio_construido, string ancho, string alto)
{
    this -> nombre_edificio_construido = nombre_edificio_construido;
    this -> ancho = ancho;
    this -> alto = alto;
}

int Escuela::obtener_recursos()
{
    return this -> recursos = 0;
}

int Escuela::obtener_construidos()
{
    return this -> cantidad_construidos;
}

void Escuela::mostrar_edificios()
{
    cout << "\n"; 
    cout << "0-----------------------------------------0" << endl;
    cout << "\t"<< "EDIFICIO: "<< this -> nombre_edificio  << endl;
    cout << "\t"<< "PIEDRA : "<< this -> cantidad_piedra << " unidades necesarias" <<endl;
    cout << "\t"<< "MADERA : "<< this -> cantidad_madera << " unidades necesarias" <<endl;
    cout << "\t"<< "METAL : "<< this -> cantidad_metal << " unidades necesarias" <<endl;
    cout << "\t"<< "CONSTRUIDOS: " << this -> cantidad_construidos <<endl;
    cout << "\t"<< "AUN SE PUEDEN CONSTRUIR: "<< (this -> maximo_permitidos - this -> cantidad_construidos)<<endl; 
    cout << "\t"<< "MATERIAL QUE BRINDA: "<< "no brinda materiales" <<endl; 
    cout << "0-----------------------------------------0" << endl;
    cout << "\n"; 
}

void Escuela::mostrar_construidos()
{
    cout << "\n"; 
    cout << "0-----------------------------------------0" << endl;
    cout << "\t"<< "EDIFICIO: "<< this -> nombre_edificio_construido  << endl;
    cout << "\t"<< "COORDENADAS : "<< this -> ancho << this -> alto <<endl;
    cout << "0-----------------------------------------0" << endl;
    cout << "\n";  
}