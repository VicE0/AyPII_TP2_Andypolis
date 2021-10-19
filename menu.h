#ifndef __MENU_H__
#define __MENU_H__

#include "materiales.h";
#include "edificios.h";
#include "construcciones.h";
#include "mapa.h";


const int OPCIONES_VALIDAS = 7;
const int LISTAR_MATERIALES = 1;
const int CONSTRUIR_EDIFICIO = 2;
const int LISTAR_EDIFICIOS_CONSTRUIDOS = 3;
const int LISTAR_TODOS_EDIFICIOS = 4;
const int DEMOLER_EDIFICIO = 5;
const int SALIR = 6;
const int ERROR = -1;
//VER ENUNCIADO



//pre: -
//post: Imprime por pantalla el menu
void mostrar_menu();

//Precondiciones: -
//Postcondiciones: Le solicita al usuario que ingrese el numero de la opcion que desea seleccionar.
int pedir_opcion();

//pre: La opcion_elegida es valida
//post: Realiza la opcion pedida
void procesar_opcion();

//Precondiciones: Recibe la opcion elegida.
//Postcondiciones: Verifica que la opcion sea un numero entre 0 y el valor de OPCIONES_VALIDAS.
void validar_opcion_elegida(int &opcion_elegida);

#endif //__MENU__