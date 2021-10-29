//***********************************************
//  Algoritmos y Programación II
//  TP-1 ANDYPOLIS
//  juego.cpp
//  108400 - Espeche, Victoria
//***********************************************


#include <iostream>
#include <fstream>
 
#include "juego.h"
#include "limpiar_pantalla.h"

using namespace std; 

void menu()
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


void procesar_archivo_materiales(Materiales materiales[MAX_MATERIALES], int &tope1)
{
    Materiales material;
    string cantidad;

    int contador = 0;

    ifstream archivo_materiales(PATH_MATERIALES);

    if (!archivo_materiales.is_open())
    {
        cout << "\nNo se encontro el archivo, revisa si esta en la misma carpeta que el programa" << endl;
        tope1 = ERROR;
    }
    else
    {
        while(archivo_materiales >> material.nombre)
        {
            archivo_materiales >> cantidad;

            material.cantidad = stoi(cantidad);

            materiales[contador] = material;
            contador++;
        }
        tope1 = contador;
    }

    archivo_materiales.close();
}


void procesar_archivo_edificios(Edificios edificios[MAX_EDIFICIOS], int &tope2)
{
    Edificios edificio;
    string piedra;
    string madera;
    string metal;
    string construidos;
    string max_construir;


    int contador = 0;

    ifstream archivo_edificios(PATH_EDIFICIOS);

    if (!archivo_edificios.is_open())
    {
        cout << "\nNo se encontro el archivo, revisa si esta en la misma carpeta que el programa" << endl;
        tope2 = ERROR;
    }
    else
    {
        while(archivo_edificios >> edificio.nombre)
        {
            archivo_edificios >> piedra;
            archivo_edificios >> madera;
            archivo_edificios >> metal;
            archivo_edificios >> construidos;
            archivo_edificios >> max_construir;
        

            edificio.piedra = stoi(piedra);
            edificio.madera = stoi(madera);
            edificio.metal = stoi(metal);
            edificio.construidos = stoi(construidos);
            edificio.max_construir = stoi(max_construir);


            edificios[contador] = edificio;
            contador++;
        }
        tope2 = contador;
    }

    archivo_edificios.close();
}

void mostrar_materiales(Materiales materiales[MAX_MATERIALES], int tope1)
{
    system(LIMPIAR_PANTALLA);
    cout << endl << "\n- INVENTARIO -" << endl;
    for (int i = 0; i < tope1; i++)
    {
        cout << "\nMaterial: " << materiales[i].nombre << " -> " << materiales[i].cantidad<< " unidades"<< endl;
    }
    cout << endl;
}


void mostrar_edificios(Edificios edificios[MAX_EDIFICIOS], int tope2)
{
    system(LIMPIAR_PANTALLA);
    cout << endl << "\n+ EDIFICIOS +" << endl;
    for (int i = 0; i < tope2; i++)
    {
        cout << '\t' << "\n--------------------------------\n" << endl;
        cout << '\t' << "\nEdificio: " << edificios[i].nombre << endl;
        cout << '\t' << "\nCantidad de piedra necesaria: " << edificios[i].piedra << endl;
        cout << '\t' << "\nCantidad de madera necesaria: " << edificios[i].madera << endl;
        cout << '\t' << "\nCantidad de metal necesario: " << edificios[i].metal << endl;
        cout << '\t' << "\nCantidad Construidos: " << edificios[i].construidos << endl;
        cout << '\t' << "\nSe puede(n) construir " << edificios[i].max_construir << " mas" << endl;
    }

}

void mostrar_edificios_construidos(Edificios edificios[MAX_EDIFICIOS], int tope2)
{
    system(LIMPIAR_PANTALLA);

    if(edificios[0].construidos == 0 && edificios[1].construidos == 0 && edificios[2].construidos == 0 && edificios[3].construidos == 0)
    {
        cout << "\nNo hay edificios construidos" << endl;

    }
    else
    {
        cout << endl << "\n+ EDIFICIOS +" << endl;
        for (int i = 0; i < tope2; i++)
        {
            if (edificios[i].construidos > 0)
            {
                cout << '\t' << "\n\nEdificio: " << edificios[i].nombre << endl; 
                cout << '\t' << "\n-> Cantidad Construidos: " << edificios[i].construidos << endl;   
            }
            
        }        

    }

}

void actualizar_materiales(Materiales materiales[MAX_MATERIALES], int &tope1)
{
    ofstream archivo_materiales(PATH_MATERIALES);

    for (int i = 0; i < tope1; i++)
    {
        archivo_materiales << materiales[i].nombre << ' ';
        archivo_materiales << materiales[i].cantidad << '\n';
    }
    cout << "Archivo "<< PATH_MATERIALES << " actualizado con exito" << endl;
    
}

void actualizar_edificios(Edificios edificios[MAX_EDIFICIOS], int &tope2)
{
    ofstream archivo_edificios(PATH_EDIFICIOS);

    for (int i = 0; i < tope2; i++)
    {
        archivo_edificios << edificios[i].nombre << ' ';
        archivo_edificios << edificios[i].piedra << ' ';
        archivo_edificios << edificios[i].madera << ' ';
        archivo_edificios << edificios[i].metal << ' ';
        archivo_edificios << edificios[i].construidos << ' ';
        archivo_edificios << edificios[i].max_construir << '\n';
    }
    cout << "Archivo "<< PATH_EDIFICIOS << " actualizado con exito" << endl;
    
}



void demoler_edificio(Edificios edificios[MAX_EDIFICIOS],Materiales materiales[MAX_MATERIALES], int tope2, int tope1)
{
    
    string edificio_demolido;
    int piedra_edificio = 0;
    int madera_edificio = 0;
    int metal_edificio = 0;

    system(LIMPIAR_PANTALLA);
    cout << "\nEdificio a demoler: ";
    cin >> edificio_demolido;
    if (edificio_demolido != edificios[0].nombre && edificio_demolido != edificios[1].nombre && edificio_demolido != edificios[2].nombre && edificio_demolido != edificios[3].nombre)
    {
        cout << "No existe este edificio"<<endl;
    }
    else
    {
        for (int i = 0; i < tope2; i++)
        {
            if (edificios[i].construidos > 0 && edificios[i].nombre == edificio_demolido)
            {
                cout << "\nVas a recibir:\n " << endl;
                cout << "*----------------*"<<endl;
                cout << '\n'<< (edificios[i].piedra)/2 << " de piedra" <<endl;
                cout << '\n'<<(edificios[i].madera)/2 << " de madera" <<endl;
                cout << '\n'<<(edificios[i].metal)/2 << " de metal" <<endl;
                cout << "*----------------*"<<endl;

                piedra_edificio = (edificios[i].piedra)/2;
                madera_edificio = (edificios[i].madera)/2;
                metal_edificio = (edificios[i].metal)/2;
            
                edificios[i].construidos -= 1;
            }


        }

        materiales[0].cantidad += piedra_edificio;
        materiales[1].cantidad += madera_edificio;
        materiales[2].cantidad += metal_edificio;
    }

}



void construir_edificio(Edificios edificios[MAX_EDIFICIOS],Materiales materiales[MAX_MATERIALES], int tope2, int tope1)
{
    string edificio_construir;
    int piedra_edificio = 0;
    int madera_edificio = 0;
    int metal_edificio = 0;

    system(LIMPIAR_PANTALLA);
    cout << "\nEdificio a construir: ";
    cin >> edificio_construir;

    if (edificio_construir != edificios[0].nombre && edificio_construir != edificios[1].nombre && edificio_construir != edificios[2].nombre && edificio_construir != edificios[3].nombre)
    {
        cout << "No existe este edificio"<<endl;
    }

    else
    {
        for (int i = 0; i < tope2; i++)
        {   
            if (edificios[i].construidos < edificios[i].max_construir && edificios[i].nombre == edificio_construir)
            {

                cout << "\nVas a necesitar:\n " << endl;
                cout << "*----------------*"<<endl;
                cout << '\n'<< edificios[i].piedra << " de piedra" <<endl;
                cout << '\n'<< edificios[i].madera << " de madera" <<endl;
                cout << '\n'<< edificios[i].metal  << " de metal" <<endl;
                cout << "\n*----------------*"<<endl;

                if (materiales[0].cantidad < edificios[i].piedra)
                {
                    cout << "\nNecesitas mas piedra"<<endl;
                }
                else if (materiales[1].cantidad < edificios[i].madera)
                {
                    cout << "\nNecesitas mas madera" << endl;
                }
                else if (materiales[2].cantidad < edificios[i].metal)
                {
                    cout << "\nNecesitas mas metal" << endl;
                }

                else
                {
                    edificios[i].construidos += 1;

                    cout << "\nEdificio construido con exito!"<< endl;
                    
                    if ((edificios[i].max_construir - edificios[i].construidos) > 0)
                    {
                        cout << "\nAun puedes construir mas de este edificio!" << endl;
                    }
                    else
                    {
                        cout << "\nYa no puedes construir mas de este edificio!" << endl;
                    }
                }


                piedra_edificio = edificios[i].piedra;
                madera_edificio = edificios[i].madera;
                metal_edificio = edificios[i].metal;
            }

        }

    }

    materiales[0].cantidad -= piedra_edificio;
    materiales[1].cantidad -= madera_edificio;
    materiales[2].cantidad -= metal_edificio;
    

}



void procesar_opcion(Materiales materiales[MAX_MATERIALES],Edificios edificios[MAX_EDIFICIOS], int &tope1, int &tope2,int opcion) 
{

    switch (opcion) 
    {
        case LISTAR_MATERIALES:
            mostrar_materiales(materiales, tope1);
            break;

        case CONSTRUIR_EDIFICIO:
            construir_edificio(edificios, materiales, tope2, tope1);
            break;

        case LISTAR_EDIFICIOS_CONSTRUIDOS:
            mostrar_edificios_construidos(edificios, tope2);
            break;

        case LISTAR_TODOS_EDIFICIOS:
            mostrar_edificios(edificios, tope2);
            break;

        case DEMOLER_EDIFICIO:
            demoler_edificio(edificios, materiales, tope2, tope1);
            break;


        default:
            cout << "Error: opcion invalida";
    }
}