#include "Planta.h"

Planta::Planta(string nombre_edificio, int cantidad_piedra, int cantidad_madera, int cantidad_metal,int maximo_permitidos)
{
    this -> nombre_edificio = nombre_edificio;
    this -> cantidad_piedra = cantidad_piedra;
    this -> cantidad_madera = cantidad_madera;
    this -> cantidad_metal = cantidad_metal;
    this -> maximo_permitidos = maximo_permitidos;
    
}

int Planta::obtener_recursos()
{
    return this -> recursos = 25;
}

int Planta::obtener_construidos()
{
    return this -> cantidad_construidos;
}

void Planta::mostrar_edificios()
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