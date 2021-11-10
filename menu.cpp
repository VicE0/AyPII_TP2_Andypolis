#include <iostream>
#include <fstream>

#include "menu.h"

using namespace std;

void mostrar_menu()
{
    
    cout << "\n\n\t\t\tMenu de Opciones" << endl;
    cout << "\n\t\t\tQue desea hacer?" << endl;
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


int pedir_opcion()
{
    int opcion_elegida = ERROR;
    cout << "\nOPCION => ";
    cin >> opcion_elegida;
    return  opcion_elegida;
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

void procesar_opcion(int opcion, Inventario* datos_material) 
{
    Inventario inventario;
    Ciudad ciudad;
    // Mapa mapa;
    
    string ingresar_edificio_construir;
    int posicion;
    // int x;
    // int y;

    switch (opcion) 
    {
        case CONSTRUIR_EDIFICIO:
            ingresar_edificio_construir = ciudad.pedir_edificio();
            posicion = ciudad.obtener_posicion(ingresar_edificio_construir);
            ciudad.construir_edificio(posicion, datos_material);
            break;

        case LISTAR_EDIFICIOS_CONSTRUIDOS:
            ciudad.mostrar_edificios_construidos();
            break;

        case LISTAR_TODOS_EDIFICIOS:
            ciudad.mostrar_totalidad_edificios();
            break;

        case DEMOLER_EDIFICIO:
            break;

        case MOSTRAR_MAPA:
            // mapa.mostrar_mapa();
            break;

        case CONSULTAR_COORDENADA:
            // x = mapa.pedir_coordenada_x();
            // y = mapa.pedir_coordenada_x();
            // mapa.consultar_coordenada(x, y);
            break;

        case MOSTRAR_INVENTARIO:
            inventario.mostrar_materiales(datos_material);
            break;
        
        case RECOLECTAR_RECURSOS:
            cout << "¿De cual edificio desea recolectar?" << endl;
            ingresar_edificio_construir = ciudad.pedir_edificio();
            posicion = ciudad.obtener_posicion(ingresar_edificio_construir);
            ciudad.recolectar_recursos(posicion, datos_material);
            break;

        case LLUVIA_RECURSOS:
            break;

        case SALIR:
            break;

        default:
            cout << "Error - opcion invalida";
    }
}
