#include <iostream>
#include <fstream>
#include "utiles_materiales.h"

using namespace std;

bool cargar_materiales(Lista_materiales* lista_materiales) {

    lista_materiales -> cantidad_de_materiales = 0;

    fstream archivo_materiales(PATH_MATERIALES, ios::in);

    if(!archivo_materiales.is_open()) {
        return false;
    }

    string nombre,cantidad;

    Material* material;

    while(archivo_materiales >> nombre){
        archivo_materiales >> cantidad;
        material = new Material;
        material -> nombre = nombre;
        material -> cantidad = stoi(cantidad);
        agregar_material(lista_materiales, material);
    }

    archivo_materiales.close();
    return true;

}

void agregar_material(Lista_materiales* lista_materiales, Material* material){

    int tope_viejo = lista_materiales -> cantidad_de_materiales;
    Material** nuevo_vector_materiales = new Material*[tope_viejo + 1];

    for(int i = 0; i < lista_materiales -> cantidad_de_materiales; i++){
        nuevo_vector_materiales[i] = lista_materiales -> materiales[i];
    }
    nuevo_vector_materiales[tope_viejo] = material;

    if(lista_materiales -> cantidad_de_materiales != 0){
        delete[] lista_materiales -> materiales;
    }

    lista_materiales -> materiales = nuevo_vector_materiales;
    lista_materiales -> cantidad_de_materiales++;

}

void mostrar_material(Lista_materiales* lista_materiales, int posicion){

    cout << "--------------------------------------------------------" << endl
         << '\t' << "Material: " << lista_materiales -> materiales[posicion] -> nombre << endl
         << '\t' << "Cantidad: " << lista_materiales -> materiales[posicion] -> cantidad << endl
         << "--------------------------------------------------------" << endl;

}

void listar_materiales(Lista_materiales* lista_materiales){

    cout << "MATERIALES: " <<endl;

    //No se deberia entrar a este if ya que el archivo contiene como minimo 3 materiales pero se deja por seguridad
    if(lista_materiales -> cantidad_de_materiales == 0){
        cout << "\"--------------------------------------------------------\"" << endl
             << '\t' << "No hay materiales disponibles" << endl
             << "\"--------------------------------------------------------\"" << endl;
    }

    for (int i=0; i < lista_materiales -> cantidad_de_materiales;i++){
        mostrar_material(lista_materiales,i);
    }

}

void destruir_lista_materiales(Lista_materiales* lista_materiales){

    int cantidad_materiales = lista_materiales -> cantidad_de_materiales;

    for(int i = 0; i < cantidad_materiales; i++){
        delete lista_materiales -> materiales[i];
        lista_materiales -> cantidad_de_materiales--;
    }
    delete[] lista_materiales -> materiales;
    lista_materiales -> materiales = nullptr;

    delete lista_materiales;
    lista_materiales = nullptr;
}



void cerrar_materiales(Lista_materiales* lista_materiales){

    ofstream archivo_materiales(PATH_MATERIALES);

    for(int i = 0; i < lista_materiales -> cantidad_de_materiales; i++){
        archivo_materiales << lista_materiales -> materiales[i] -> nombre << ' '
                          << lista_materiales -> materiales[i] -> cantidad << '\n';
    }

    destruir_lista_materiales(lista_materiales);

    archivo_materiales.close();

}
