
//***********************************************
//  Algoritmos y Programación II
//  TP-1 ANDYPOLIS
//  main.cpp
//  108400 - Espeche, Victoria
//***********************************************



#include <fstream>
#include <iostream>
#include "juego.h"

using namespace std;

//Precondiciones: -
//Postcondiciones: Lee el archivo y carga el vector materiales.
void procesar_archivo_materiales(Materiales materiales[MAX_MATERIALES], int &tope);

//Precondiciones: -
//Postcondiciones: Lee el archivo y carga el vector edificios.
void procesar_archivo_edificios(Edificios edificios[MAX_EDIFICIOS], int &tope);


int main() 
{

    Materiales materiales[MAX_MATERIALES];
    Edificios edificios[MAX_EDIFICIOS];

    int opcion = 0;
    int tope1;
    int tope2;

    procesar_archivo_materiales(materiales, tope1);
    procesar_archivo_edificios(edificios, tope2);

    if (tope1!= ERROR && tope2!= ERROR)
    {
        cout << "Bienvenido a Andypolis"<<endl;
        menu();
        opcion = pedir_opcion();
        validar_opcion_elegida(opcion);

        while(opcion != SALIR)
        {
            
            procesar_opcion(materiales,edificios,tope1,tope2,opcion);
            menu();
            opcion = pedir_opcion();
            validar_opcion_elegida(opcion);
        }

        cout << "Wololo~ Espero que te haya gustado!"<<endl;
        
        actualizar_materiales(materiales, tope1);
        actualizar_edificios(edificios, tope2);

        return 0;
    }
}


