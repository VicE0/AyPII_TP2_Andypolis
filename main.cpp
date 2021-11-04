#include <iostream>
#include <string>
#include "menu.h"
#include "Ciudad.h"
#include "Inventario.h"

using namespace std;

int main()
{   
    int opcion = 0;
    Ciudad* datos_ciudad = new Ciudad;

    Inventario inventario;
    Ciudad ciudad;

    inventario.leer_archivo_materiales();
    ciudad.leer_archivo_edificios();
    
    cout << "\t\t\tBienvenido a Andypolis" << endl;
    mostrar_menu();
    opcion = pedir_opcion();
    validar_opcion_elegida(opcion);
    do
    {
        procesar_opcion(opcion, datos_ciudad);
        mostrar_menu();
        opcion = pedir_opcion();
        validar_opcion_elegida(opcion);
        
    }while(opcion != SALIR);

    cout << "Gracias por jugar!"<<endl;
    //actualizar archivos

    return 0;
}

//g++ *.cpp -o a -Wall -Werror -Wconversion
