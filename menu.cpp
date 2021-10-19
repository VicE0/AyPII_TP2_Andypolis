#include <iostream>
#include <fstream>

#include "menu.h"

using namespace std;



void mostrar_menu()
{
    
    cout << "\n\n\t\t\tMenu de Opciones" << endl;
    cout << "\n\n\t\t\tQue desea hacer?" << endl;
    cout << "\t\t\t----------------" << endl;
    cout << "\n\t1. Listar materiales" << endl;
    cout << "\t2. Construir edificio" << endl;
    cout << "\t3. Listar edificios construidos" << endl;
    cout << "\t4. Listar todos los edificios " << endl;
    cout << "\t5. Demoler un edificio" << endl;
    cout << "\t6. Guardar y salir" << endl;

}


int pedir_opcion()
{
    int opcion_elegida = ERROR;
    cout << "\nOPCION => ";
    cin >> opcion_elegida;

    return opcion_elegida;
}


void validar_opcion_elegida(int &opcion_elegida)
{
    bool es_opcion_valida = opcion_elegida > 0 && opcion_elegida <= OPCIONES_VALIDAS;
    while(!es_opcion_valida)
    {
        cout << "\nOpcion no valida!\n Intente nuevamente: ";
        cin >> opcion_elegida;
        es_opcion_valida = opcion_elegida > 0 && opcion_elegida <= OPCIONES_VALIDAS;

    }
}
