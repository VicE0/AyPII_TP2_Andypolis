#ifndef MAPA_H
#define MAPA_H

#include "CasilleroConstruible.h"
#include "CasilleroInaccesible.h"

class Mapa 
{
    private:
        int filas;
        int columnas;
        Casillero*** mapa; //doble puntero porque el array es de 2 dimensiones
    

    public:

        //CONSTRUCTOR
        Mapa();

        // PRE: ~ 
        // POST: Lee el archivo mapa.txt  y crea los array
        void leer_archivo_mapa();
        

        // PRE: ~ 
        // POST: Lee da formato a la matriz
        void formato_matriz();

        
        // PRE: Recibe las coordenadas
        // POST: TRUE si esta ocupado, FALSE si esta desocupado
        bool casillero_ocupado(int x, int y);
        
        // PRE: Recibe las coordenadas e informacion de Edificio
        // POST: Ocupa el casillero
        void actualizar_casillero_ocupado(Edificio* edificio, int x, int y);

        // PRE: Recibe las coordenadas
        // POST: Borra la informacion del casillero
        void sacar_edificio_construido(int x, int y);

        //PRE: ~
        //POST: Le pide al usuario la coordenada x que quiere consultar
        int pedir_coordenada_x();

        //PRE: ~
        //POST: Le pide al usuario la coordenada y que quiere consultar
        int pedir_coordenada_y();

        // PRE: Recibe las coordenadas
        // POST: Muestra los saludos de edificios/casilleros
        void consultar_coordenada(int x, int y);


        // PRE: Recibe las coordenadas
        // POST: Devuelve informacion del edificio en el casillero
        Edificio* obtener_elemento(int x , int y);

        // PRE:
        // POST: Muestra el mapa 
        void mostrar_mapa();

        // PRE: Recibe las coordenadas
        // POST: Devuelve que tipo de casillero se encuentra en las coordenadas dadas
        char obtener_casillero(int x, int y);



};

#endif