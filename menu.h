#ifndef __MENU_H__
#define __MENU_H__

#include "materiales.h"
#include "edificios.h"
#include "construcciones.h"
#include "mapa.h"


const int OPCIONES_VALIDAS = 11;
const int CONSTRUIR_EDIFICIO = 1;
const int LISTAR_EDIFICIOS_CONSTRUIDOS = 2;
const int LISTAR_TODOS_EDIFICIOS = 3;
const int DEMOLER_EDIFICIO = 4;
const int MOSTRAR_MAPA = 5;
const int CONSULTAR_COORDENADA = 6;
const int MOSTRAR_INVENTARIO = 7;
const int RECOLECTAR_RECURSOS = 8;
const int LLUVIA_RECURSOS = 9;
const int SALIR = 10;
const int ERROR = -1;


//pre: -
//post: Imprime por pantalla el menu
void mostrar_menu();

//Precondiciones: -
//Postcondiciones: Le solicita al usuario que ingrese el numero de la opcion que desea seleccionar.
int pedir_opcion_tp2();

//pre: La opcion_elegida es valida
//post: Realiza la opcion pedida
void procesar_opcion_tp2();

//Precondiciones: Recibe la opcion elegida.
//Postcondiciones: Verifica que la opcion sea un numero entre 0 y el valor de OPCIONES_VALIDAS.
void validar_opcion_elegida_tp2(int &opcion_elegida);

#endif //__MENU__