#ifndef __UTILES_MATERIALES_H__
#define __UTILES_MATERIALES_H__
#include <string>

using namespace std;

const string PATH_MATERIALES = "materiales.txt";
const int PIEDRA = 0;
const int MADERA =1;
const int METAL=2;
const int FACTOR_DEVOLUCION =2;

struct Material{
    string nombre;
    int cantidad;
};

struct Lista_materiales{
    Material** materiales;
    int cantidad_de_materiales;
};


//pre: El material debe estar bien cargado
//post: Carga el material a la lista de materiales
void agregar_material(Lista_materiales* lista_materiales, Material* material);

//pre:
//post: Carga la lista de materiales con los valores del archivo materiales.txt
bool cargar_materiales(Lista_materiales* lista_materiales);

//pre: La posicion debe existir dentro de la lista de materiales
//post: Muestra por pantalla los datos del material que se encuentra en la lista de materiales
void mostrar_material(Lista_materiales* lista_materiales, int posicion);

//pre: el puntero lista_materiales debe ser valido (no nulo)
//post: Imprime por pantalla los materiales que contiene la lista de materiales o un mensaje si esta vacia
void listar_materiales(Lista_materiales* lista_materiales);

//pre: -
//post: Libera la memoria dinamica correspondiente a una lista de materiales
void destruir_lista_materiales(Lista_materiales* lista_materiales);

//pre: -
//post: guarda los cambios hechos en la lista de materiales y elimina la lista.
void cerrar_materiales (Lista_materiales* lista_materiales);

#endif
