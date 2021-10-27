#include <iostream>
#include <fstream>

#include "menu.h"

using namespace std;


void mostrar_menu()
{
    
    cout << "\n\n\t\t\tMenu de Opciones" << endl;
    cout << "\n\n\t\t\tQue desea hacer?" << endl;
    cout << "\t\t\t----------------" << endl;
    cout << "\n\t1. Construir edificio por nombre" << endl;
    cout << "\t2. Listar los edificios construidos" << endl;
    cout << "\t3. Listar todos los edificios" << endl;
    cout << "\t4. Demoler un edificio por coordenada " << endl;
    cout << "\t5. Mostrar mapa" << endl;
    cout << "\t6. Consultar coordenada" << endl;
    cout << "\t7. Mostrar inventario" << endl;
    cout << "\t8. Recolectar recursos producidos" << endl;
    cout << "\t9. Lluvia de recursos" << endl;
    cout << "\t10. Guardar y salir" << endl;

}


int pedir_opcion_tp2()
{
    int opcion_elegida = ERROR;
    cout << "\nOPCION => ";
    cin >> opcion_elegida;

    return opcion_elegida;
}


void validar_opcion_elegida_tp2(int &opcion_elegida)
{
    bool es_opcion_valida = opcion_elegida > 0 && opcion_elegida <= OPCIONES_VALIDAS;
    while(!es_opcion_valida)
    {
        cout << "\nOpcion no valida!\n Intente nuevamente: ";
        cin >> opcion_elegida;
        es_opcion_valida = opcion_elegida > 0 && opcion_elegida <= OPCIONES_VALIDAS;

    }
}
