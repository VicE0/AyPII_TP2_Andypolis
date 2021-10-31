#include <iostream>
#include <string>
#include "menu.h"

using namespace std;

int main()
{
    int opcion;
    //vectores new

    do
    {
        mostrar_menu();
        cin >> opcion;
        validar_opcion_elegida(opcion);
        procesar_opcion(opcion);

    }while(opcion != SALIR);
}