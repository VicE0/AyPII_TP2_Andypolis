#include <iostream>
#include <string>
#include "menu.h"

using namespace std;

int main(){

    int opcion_elegida;
    Lista_materiales* lista_materiales = new Lista_materiales;
    Lista_edificios* lista_edificios = new Lista_edificios;

    if(!cargar_materiales(lista_materiales)){
        delete lista_materiales;
        delete lista_edificios;
        lista_materiales = nullptr;
        lista_edificios = nullptr;
        cerr << "No se pudo abrir el archivo " << PATH_MATERIALES << " intentelo luego. " << endl;
    }

    else if(!cargar_edificios(lista_edificios)){
        destruir_lista_materiales(lista_materiales);
        delete lista_edificios;
        lista_edificios = nullptr;
        cerr << "No se pudo abrir el archivo " << PATH_EDIFICIOS << " intentelo luego. " << endl;
    }

    else{

        imprimir_bienvenida();

        do{
            mostrar_menu();
            cin >> opcion_elegida;
            validar_opcion(opcion_elegida);;
            procesar_opcion(opcion_elegida,lista_materiales,lista_edificios);
        }while(opcion_elegida != SALIR);

        imprimir_despedida();
    }

    return 0;

}




