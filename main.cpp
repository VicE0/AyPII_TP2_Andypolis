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
    Ciudad* datos_ubicaciones = new Ciudad;
    Inventario* datos_material = new Inventario;

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
        procesar_opcion(opcion, datos_ciudad, datos_material, datos_ubicaciones);
        mostrar_menu();
        opcion = pedir_opcion();
        validar_opcion_elegida(opcion);
        
    }while(opcion != SALIR);

    cout << "Gracias por jugar!"<<endl;
    //actualizar archivos

    return 0;
}

//g++ *.cpp -o a -Wall -Werror -Wconversion
