
//***********************************************
//  Algoritmos y Programación II
//  TP-1 ANDYPOLIS
//  juego.h
//  108400 - Espeche, Victoria
//***********************************************

#ifndef JUEGO_H
#define JUEGO_H

#include <fstream>
#include <iostream>

const int OPCIONES_VALIDAS = 7;
const int MIN_MATERIALES = 3;
const std::string PATH_MATERIALES = "materiales.txt";
const std::string  PATH_EDIFICIOS = "edificios.txt";


struct Materiales
{
    std::string nombre;
    int cantidad;
  
};


struct Edificios
{
    std::string nombre;
    int piedra;
    int madera;
    int metal;
    int construidos;
    int max_construir;

};

const int LISTAR_MATERIALES = 1;
const int CONSTRUIR_EDIFICIO = 2;
const int LISTAR_EDIFICIOS_CONSTRUIDOS = 3;
const int LISTAR_TODOS_EDIFICIOS = 4;
const int DEMOLER_EDIFICIO = 5;
const int SALIR = 6;
const int ERROR = -1;

const int MAX_EDIFICIOS = 50;
const int MAX_MATERIALES = 10;


//Precondiciones: -
//Postcondiciones: Imprime por pantalla el menu.
void menu();


//Precondiciones: -
//Postcondiciones: Le solicita al usuario que ingrese el numero de la opcion que desea seleccionar.
int pedir_opcion();


//Precondiciones: Recibe la opcion elegida.
//Postcondiciones: Verifica que la opcion sea un numero entre 0 y el valor de OPCIONES_VALIDAS.
void validar_opcion_elegida(int &opcion_elegida);


//Precondiciones: Recibe los datos del archivo materiales.txt.
//Postcondiciones: Imprime por pantalla los materiales en el inventario.
void mostrar_materiales(Materiales materiales[MAX_MATERIALES], int tope1);


//Precondiciones: Recibe los datos del archivo edificios.txt.
//Postcondiciones: Imprime por pantalla los edificios.
void mostrar_edificios(Edificios edificios[MAX_EDIFICIOS], int tope2);


//Precondiciones: Recibe y filtra los datos del archivo edificios.txt, buscando unicamente los que sean > 0 en la posicion de construidos.
//Postcondiciones: Imprime por pantalla los edificios construidos.
void mostrar_edificios_construidos(Edificios edificios[MAX_EDIFICIOS], int tope2);


//Precondiciones: Recibe el array de materiales.
//Postcondiciones: sobreescribe el archivo materiales.txt.
void actualizar_materiales(Materiales materiales[MAX_MATERIALES], int &tope1);


//Precondiciones: Recibe el array de edificios.
//Postcondiciones: sobreescribe el archivo edificios.txt.
void actualizar_edificios(Edificios edificios[MAX_EDIFICIOS], int &tope2);


//Precondiciones: Pregunta al usario que edificio desea demoler y verifica si existe en el archivo y si el edificio fue construido.
//Postcondiciones: Resta -1 en "construidos" en el array de edificios. Devuelve la mitad de materiales.
void demoler_edificio(Edificios edificios[MAX_EDIFICIOS],Materiales materiales[MAX_MATERIALES], int tope2, int tope1);


//Precondiciones: Pregunta al usario que edificio desea construit y verifica si existe en el archivo y si ya se superó la cantidad maxima para construir.
//Postcondiciones: Suma +1 en "construidos" en el array de edificios. Utiliza los materiales.
void construir_edificio(Edificios edificios[MAX_EDIFICIOS],Materiales materiales[MAX_MATERIALES], int tope2, int tope1);


//Precondiciones: La opcion es valida.
//Postcondiciones: Realiza la opcion indicada.
void procesar_opcion(Materiales materiales[MAX_MATERIALES],Edificios edificios[MAX_EDIFICIOS], int &tope1, int &tope2,int opcion);


#endif //JUEGO_H