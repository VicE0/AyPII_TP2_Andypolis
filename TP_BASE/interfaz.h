#ifndef INTERFAZ_H
#define INTERFAZ_H

#include "datos.h"

//PRE: Recibe un vector de materiales y la cantidad que tiene
//POS: Muestra todos los materiales existentes y sus cantidades respectivamente.
void listarMateriales(Material** materiales, int cantMateriales);


//PRE: Recibe un vector de edificios y la cantidad que tiene
//POS: Muestra todos los edificios existentes y sus datos existentes.
void listarEdificios(Edificio** edificios, int cantEdificios);


//PRE: Recibe un vector de edificios y la cantidad que tiene
//POS: Muestra todos los edificios construidos y cuantos hay 
void listarEdificiosConstruidos(Edificio** edificios, int cantEdificios);


//PRE: Recibe una obra  y un nombre de un edificio
//POS: Si el edificio existe y al menos tiene una construcción se demolerá y sus materiales serán devuelvo a la mitad
void demolerEdificio(Obra* obra, string nombreEdificio);


//PRE: Recibe una obra y un nombre de edificio
//POS: Construirà el edificio en caso de existir y haber los materiales necesarios
void construirEdificio(Obra* obra, string NombreEdificio);

//PRE: Recibe un vector de edificios y materiales ambos con sus cantidades respectivamente. también recibe 2 nombres de archivo vàlidos tanto de edificios como materiales
//POS: Guarda los datos de los edificios y materiales en los archivos
void guardarSalir(Edificio** edificios, Material** materiales, int cantEdificios, int cantMateriales, string nombreArchivoEdificios, string nombreArchivoMateriales);


#endif //INTERFAZ_H
