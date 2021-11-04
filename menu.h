#ifndef MENU_H
#define MENU_H

#include "Inventario.h"
#include "Ciudad.h"

#include "Aserradero.h"
#include "Escuela.h"
#include "Fabrica.h"
#include "Obelisco.h"
#include "Planta.h"
#include "Yacimiento.h"
#include "Mina.h"

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
int pedir_opcion();

//pre: La opcion_elegida es valida
//post: Realiza la opcion pedida
void procesar_opcion();

//Precondiciones: Recibe la opcion elegida.
//Postcondiciones: Verifica que la opcion sea un numero entre 0 y el valor de OPCIONES_VALIDAS.
void validar_opcion_elegida(int &opcion_elegida);

//Precondiciones: La opcion es valida.
//Postcondiciones: Realiza la opcion indicada.
void procesar_opcion(int opcion, Ciudad* datos_ciudad);

#endif //MENU_H