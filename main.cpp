#include <iostream>
#include <string>
#include "menu.h"

using namespace std;

int main()
{   
    int opcion = 0;
    //vectores new

    cout << "\t\t\tBienvenido a Andypolis" << endl;
    mostrar_menu();
    opcion = pedir_opcion();
    validar_opcion_elegida(opcion);
    do
    {
        procesar_opcion(opcion);
        mostrar_menu();
        validar_opcion_elegida(opcion);
        
    }while(opcion != SALIR);

    cout << "Gracias por jugar!"<<endl;
    //actualizar archivos

    return 0;
}

//g++ *.cpp -o a -Wall -Werror -Wconversion
