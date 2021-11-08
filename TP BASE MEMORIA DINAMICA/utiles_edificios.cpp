#include <iostream>
#include <fstream>
#include "utiles_edificios.h"

using namespace std;

void agregar_edificio(Lista_edificios* lista_edificios, Edificio* edificio){

    int tope_viejo = lista_edificios -> cantidad_de_edificios;

    Edificio** nuevo_vector_edificios = new Edificio*[tope_viejo+1];

    for(int i=0; i< lista_edificios -> cantidad_de_edificios; i++){
        nuevo_vector_edificios[i] = lista_edificios -> edificios[i];
    }

    nuevo_vector_edificios[tope_viejo] = edificio;

    if(lista_edificios -> cantidad_de_edificios != 0){
        delete[] lista_edificios -> edificios;
    }

    lista_edificios -> edificios = nuevo_vector_edificios;
    lista_edificios -> cantidad_de_edificios++;

}

bool cargar_edificios(Lista_edificios * lista_edificios){

    lista_edificios -> cantidad_de_edificios=0;

    fstream archivo_edificios(PATH_EDIFICIOS,ios::in);

    if(!archivo_edificios.is_open()){
        return false;
    }

    string nombre, piedra_nes,madera_nes,metal_nes,cantidad_act,cantidad_max;

    Edificio* edificio;

    while(archivo_edificios>>nombre) {
        archivo_edificios >> piedra_nes;
        archivo_edificios >> madera_nes;
        archivo_edificios >> metal_nes;
        archivo_edificios >> cantidad_act;
        archivo_edificios >> cantidad_max;

        edificio = new Edificio;
        edificio -> nombre = nombre;
        edificio -> piedra_nes = stoi(piedra_nes);
        edificio -> madera_nes = stoi(madera_nes);
        edificio -> metal_nes = stoi(metal_nes);
        edificio -> cantidad_act = stoi(cantidad_act);
        edificio -> cantidad_max = stoi(cantidad_max);

        agregar_edificio(lista_edificios,edificio);
    }

    archivo_edificios.close();

    return true;

}

void mostrar_edificio(Lista_edificios* lista_edificios, int posicion){

    cout << "--------------------------------------------------------" << endl
    << '\t' << "Edificio: " << lista_edificios -> edificios[posicion] -> nombre << endl
    << '\t' << "Cantidad necesaria de piedra: " << lista_edificios -> edificios[posicion] -> piedra_nes << endl
    << '\t' << "Cantidad necesaria de madera: " << lista_edificios -> edificios[posicion] -> madera_nes << endl
    << '\t' << "Cantidad necesaria de metal: " << lista_edificios -> edificios[posicion] -> metal_nes << endl
    << '\t' << "Cantidad edificios construidos: " << lista_edificios -> edificios[posicion] -> cantidad_act << endl
    << '\t' << "Cantidad maxima de edificios que faltan construir: " << lista_edificios -> edificios[posicion] -> cantidad_max - lista_edificios -> edificios[posicion] -> cantidad_act << endl
    << "--------------------------------------------------------" << endl;

}

void listar_edificios(Lista_edificios* lista_edificios){

    cout << "EDIFICIOS: " << endl;

    //No se deberia entrar a este if ya que el archivo contiene como minimo 3 materiales pero se deja por seguridad
    if(lista_edificios -> cantidad_de_edificios == 0) {
        cout << "\"--------------------------------------------------------\"" << endl
             << '\t' << "No hay edificios disponibles" << endl
             << "\"--------------------------------------------------------\"" << endl;
    }

    for(int i=0; i< lista_edificios -> cantidad_de_edificios; i++){
        mostrar_edificio(lista_edificios,i);
    }

}
bool edificio_valido(Lista_edificios * lista_edificios, string nombre_edificio){

    int pos = 0;

    while ( (pos < lista_edificios->cantidad_de_edificios) && (convertir_a_minuscula(nombre_edificio) != convertir_a_minuscula(lista_edificios->edificios[pos]->nombre))){
        pos++;
    }

    if (pos >= lista_edificios->cantidad_de_edificios) {
        return false;
    }

    return true;

}
int obtener_posicion(Lista_edificios * lista_edificios, string nombre_edificio){

    int pos = 0;

    while ( (pos < lista_edificios->cantidad_de_edificios) && (convertir_a_minuscula(nombre_edificio) != convertir_a_minuscula(lista_edificios->edificios[pos]->nombre))){
        pos++;
    }

    if (pos >= lista_edificios->cantidad_de_edificios) {
        return -1;
    }

    return pos;

}


string pedir_nombre_edificio(){

    string nombre_edificio;
    cout << "Ingrese el nombre del edificio sobre el cual desea realizar la accion" << endl;
    cin >> nombre_edificio;
    return nombre_edificio;

}

string convertir_a_minuscula(string palabra){
    for(unsigned int i=0;i<palabra.length();i++){
        palabra[i] = (char)tolower(palabra[i]);
    }
    return palabra;
}

void construir_edificio(Lista_edificios * lista_edificios, Lista_materiales* lista_materiales,int pos){

    string construir_ono;

    if (lista_edificios->edificios[pos]->piedra_nes > lista_materiales->materiales[PIEDRA]->cantidad ||
        lista_edificios->edificios[pos]->madera_nes > lista_materiales->materiales[MADERA]->cantidad ||
        lista_edificios->edificios[pos]->metal_nes > lista_materiales->materiales[METAL]->cantidad) {
            cout << endl<< "No existen los materiales suficientes para construir el edificio. " <<endl;
        if(lista_edificios->edificios[pos]->cantidad_act >= lista_edificios->edificios[pos]->cantidad_max) {
            cout << endl<< "Ademas ya se construyeron la cantidad maxima de edificios de este estilo posible. " << endl;
        }
    }
    else if(lista_edificios->edificios[pos]->cantidad_act >= lista_edificios->edificios[pos]->cantidad_max){
        cout << endl << "Ya se construyeron la cantidad maxima de edificios de este estilo posible. " << endl;
    }
    else{
        cout << endl << "Estas seguro que desea construir el edificio? [y/n] " << endl;
        cin >> construir_ono;
        if(construir_ono == "y"){
            lista_edificios -> edificios[pos] -> cantidad_act++;
            cout << endl << "Edificio construido con exito!!" <<endl;
        }
        else {
            cout << "No se ha completado la construccion del edificio." <<endl;
        }
    }

}

void listar_edificios_contruidos (Lista_edificios * lista_edificios){

    bool sin_edificios = true ;

    cout << "EDIFICIOS CONSTRUIDOS: " << endl;

    //No se deberia entrar a este if ya que el archivo contiene como minimo 3 materiales pero se deja por seguridad
    if(lista_edificios -> cantidad_de_edificios == 0) {
        cout << "\"--------------------------------------------------------\"" << endl
             << '\t' << "No hay edificios disponibles" << endl
             << "\"--------------------------------------------------------\"" << endl;
    }

    for(int i=0; i< lista_edificios -> cantidad_de_edificios; i++) {
        if (lista_edificios->edificios[i]->cantidad_act != 0) {
            mostrar_edificio(lista_edificios, i);
            sin_edificios = false;
        }
    }

    if(sin_edificios){
        cout << "\"--------------------------------------------------------\"" << endl
             << '\t' << "No hay edificios construidos" << endl
             << "\"--------------------------------------------------------\"" << endl;
    }

}


void demoler_edificio(Lista_edificios* lista_edificios, Lista_materiales* lista_materiales, int pos){

    if(lista_edificios -> edificios[pos] -> cantidad_act == 0)
        cout << endl << "No existen edificios de este tipo para demoler" << endl;

    else{
        lista_edificios -> edificios[pos] -> cantidad_act--;
        lista_materiales -> materiales[PIEDRA] -> cantidad += (lista_edificios -> edificios[pos] -> piedra_nes)/FACTOR_DEVOLUCION;
        lista_materiales -> materiales[MADERA] -> cantidad += (lista_edificios -> edificios[pos] ->madera_nes)/FACTOR_DEVOLUCION;
        lista_materiales -> materiales[METAL] -> cantidad += (lista_edificios -> edificios[pos] ->metal_nes)/FACTOR_DEVOLUCION;
        cout << endl << "El edificio ha sido demolio con exito " << endl;
    }

}

void destruir_lista_edificios(Lista_edificios* lista_edificios){

    int cantidad_edificios = lista_edificios -> cantidad_de_edificios;

    for(int i = 0; i < cantidad_edificios; i++){
        delete lista_edificios -> edificios[i];
        lista_edificios -> cantidad_de_edificios--;
    }
    delete[] lista_edificios -> edificios;
    lista_edificios -> edificios = nullptr;

    delete lista_edificios;
    lista_edificios = nullptr;
}

void cerrar_edificios(Lista_edificios* lista_edificios){

    ofstream archivo_edificios(PATH_EDIFICIOS);

    for(int i = 0; i < lista_edificios -> cantidad_de_edificios; i++){
        archivo_edificios << lista_edificios -> edificios[i] -> nombre << ' '
                           << lista_edificios -> edificios[i] -> piedra_nes << ' '
                           << lista_edificios -> edificios[i] -> madera_nes << ' '
                           << lista_edificios -> edificios[i] -> metal_nes << ' '
                           << lista_edificios -> edificios[i] -> cantidad_act << ' '
                           << lista_edificios -> edificios[i] -> cantidad_max << '\n';

    }

    destruir_lista_edificios(lista_edificios);

    archivo_edificios.close();

}

