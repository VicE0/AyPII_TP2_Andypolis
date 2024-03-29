#include <iostream>
#include <string>
#include "limpiar_pantalla.h"
#include "menu.h"
#include "Ciudad.h"
#include "Inventario.h"

using namespace std;

int main()
{   
    int opcion = 0;

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
        procesar_opcion(opcion, datos_material);
        mostrar_menu();
        opcion = pedir_opcion();
        validar_opcion_elegida(opcion);
        
    }while(opcion != SALIR);

    cout << "Gracias por jugar!"<<endl;
    
    ciudad.guardar_edificios();


    return 0;
}


