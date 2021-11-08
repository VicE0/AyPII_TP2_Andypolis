#ifndef __UTILES_EDIFICIOS_H__
#define __UTILES_EDIFICIOS_H__

#include <string>
#include "utiles_materiales.h"

using namespace std;

const string PATH_EDIFICIOS = "edificios.txt";

struct Edificio{
    string nombre;
    int piedra_nes;
    int madera_nes;
    int metal_nes;
    int cantidad_act;
    int cantidad_max;
};

struct Lista_edificios{
    Edificio** edificios;
    int cantidad_de_edificios;
};


//pre: El edificio debe estar bien cargado
//post: Carga el edificio a la lista de edificios
void agregar_edificio(Lista_edificios* lista_edificios, Edificio* edificio);

//pre: -
//post: Carga la lista de edificios con los valores del archivo edificios.txt
bool cargar_edificios(Lista_edificios * lista_edificios);

//pre: La posicion debe existir dentro de la lista de edificios
//post: Muestra por pantalla los datos del edificio que se encuentra en la lista de edificios
void mostrar_edificio(Lista_edificios* lista_edificios, int posicion);

//pre: el puntero lista_edificios debe ser valido (no nulo)
//post: Imprime por pantalla los edificios que contiene la lista de edificios o un mensaje si esta vacia
void listar_edificios(Lista_edificios* lista_edificios);

//pre: -
//post: Indica si el nombre del edificio es valido
bool edificio_valido(Lista_edificios * lista_edificios, string nombre_edificio);

//pre: -
//post: devuelve la posicion donde se encuentra el edificio o -1 si no lo encuentra
int obtener_posicion(Lista_edificios * lista_edificios, string nombre_edificio);

//pre: -
//post: Solicita al usuario el nombre del edificio
string pedir_nombre_edificio();

//pre: -
//post: convierte un String a minuscula
string convertir_a_minuscula(string palabra);

//pre: la posicion debe existir dentro de la lista de edificios
//post: contruye un edificio del tipo indicado en nombre
void construir_edificio(Lista_edificios * lista_edificios, Lista_materiales* lista_materiales, int pos);

//pre: el puntero lista_edificios debe ser valido (no nulo)
//post: Imprime por pantalla los edificios construidos que contiene la lista de edificios o un mensaje si no hay ningun edificio
void listar_edificios_contruidos (Lista_edificios * lista_edificios);

//pre: la posicion debe existir dentro de la lista de edificios
//post: destruye un edificio del tipo indicado en nombre
void demoler_edificio(Lista_edificios* lista_edificios, Lista_materiales* lista_materiales,int pos);

//pre: -
//post: Libera la memoria dinamica correspondiente a una lista de edificios
void destruir_lista_edificios(Lista_edificios* lista_edificios);

//pre: -
//post: guarda los cambios hechos en la lista de edificios y elimina la lista.
void cerrar_edificios(Lista_edificios* lista_edificios);

#endif