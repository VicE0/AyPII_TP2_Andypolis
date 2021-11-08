#ifndef __MENU_H__
#define __MENU_H__

#include "utiles_materiales.h"
#include "utiles_edificios.h"


#ifdef __linux__
#define CLR_SCREEN "clear"
#endif

#ifdef __MINGW32__
#define CLR_SCREEN "CLS"
#endif

const int OPCION_MINIMA = 1;
const int OPCION_MAXIMA = 6;
const int LISTAR_MATERIALES = 1;
const int CONSTRUIR_EDIFICIO = 2;
const int LISTAR_ED_CONSTRUIDOS = 3;
const int LISTAR_EDIFICIOS = 4;
const int DEMOLER_EDIFICIO = 5;
const int SALIR = 6;



//pre: -
//post: Imprime por pantalla el menu
void mostrar_menu();

//pre: La opcion_elegida es valida
//post: Realiza la opcion pedida
void procesar_opcion(int opcion_elegida,Lista_materiales* lista_materiales, Lista_edificios* lista_edificios);

//pre: La opcion elegida es un numero
//post: Verifica que la opcion sea un numero entre 0 y el valor de OPCIONES_VALIDAS y si no lo es vuelve a solicitar los datos
void validar_opcion(int &opcion_elegida);

//pre: -
//post: Imprime un mensaje de bienvenida
void imprimir_bienvenida();

//pre: -
//post: Imprime un mensaje de despedida
void imprimir_despedida();

#endif

