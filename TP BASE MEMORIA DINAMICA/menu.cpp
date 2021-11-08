#include <iostream>
#include <string>
#include "menu.h"

using namespace  std;

void mostrar_menu(){
    cout << endl << " -----" << endl
         << "|" << "MENU:" << "|" << endl
         << " -----" << endl << endl
         << " Elija la opcion que quiera realizar" << endl
         << endl
         << "1. Listar materiales de construccion." << endl
         << "2. Construir edificio por nombre." << endl
         << "3. Listar los edificios construidos." << endl
         << "4. Listar todos los edificios." << endl
         << "5. Demoler un edificio por nombre." << endl
         << "6. Guardar y salir." << endl
         << endl ;
}

void procesar_opcion(int opcion_elegida, Lista_materiales* lista_materiales, Lista_edificios* lista_edificios) {

    string nombre_edificio;
    int pos_edificio;

    system(CLR_SCREEN);

    switch (opcion_elegida) {

        case LISTAR_MATERIALES:
            listar_materiales(lista_materiales);
            break;

        case CONSTRUIR_EDIFICIO:
            nombre_edificio = pedir_nombre_edificio();
            if(!(edificio_valido(lista_edificios,nombre_edificio))){
                cout << "No existe la posibilidad de construir el edificio indicado." <<endl;
            }
            else {
                pos_edificio=obtener_posicion(lista_edificios,nombre_edificio);
                construir_edificio(lista_edificios,lista_materiales,pos_edificio);
            }
            break;

        case LISTAR_ED_CONSTRUIDOS:
            listar_edificios_contruidos(lista_edificios);
            break;

        case LISTAR_EDIFICIOS:
            listar_edificios(lista_edificios);
            break;

        case DEMOLER_EDIFICIO:
            nombre_edificio = pedir_nombre_edificio();
            if(!(edificio_valido(lista_edificios,nombre_edificio))){
                cout << "No existe la posibilidad de demoler el edificio indicado." <<endl;
            }
            else {
                pos_edificio=obtener_posicion(lista_edificios,nombre_edificio);
                demoler_edificio(lista_edificios,lista_materiales,pos_edificio);
            }
            break;

        case SALIR:
            cerrar_materiales(lista_materiales);
            cerrar_edificios(lista_edificios);
            break;

        default:
            cout << "Error: opcion invalida";
    }
}

void validar_opcion(int &opcion_elegida){

    bool es_opcion_valida = opcion_elegida >= OPCION_MINIMA && opcion_elegida <= OPCION_MAXIMA;

    while(!es_opcion_valida){
        system(CLR_SCREEN);
        cout << endl << "Ese numero de opcion no es valido, intentemos otra vez:" << endl << endl;
        mostrar_menu();
        cin >> opcion_elegida;
        es_opcion_valida = opcion_elegida >= OPCION_MINIMA && opcion_elegida <= OPCION_MAXIMA;
    }

}

void imprimir_bienvenida(){
    cout << "--------------------------------------------------------" << endl
         << "--------------------------------------------------------" << endl
         << '\t' << '\t' << "BIENVENIDO A ANDYPOLIS" << endl
         << "--------------------------------------------------------" << endl
         << "--------------------------------------------------------" << endl
         << endl;
}

void imprimir_despedida(){
    cout << "--------------------------------------------------------" << endl
         << '\t' << "Se han realizado los cambios con exito. " << endl
         << "--------------------------------------------------------" << endl
         << endl << endl ;
}

