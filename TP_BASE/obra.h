#ifndef OBRA_H
#define OBRA_H
#include <stdbool.h>
#include <string>
using namespace std;
struct Edificio{
	string nombre;
	int cantPiedra;
	int cantMadera;
	int cantMetal;
	int cantConstruidos;
	int cantMaxPermitidos;
};

struct Material{
	string nombre;
	int cantMaterial;
};

struct Obra{
	Edificio** edificios;
	Material** materiales;
	int cantMateriales;
	int cantEdificios;
};

//PRE:
//POS: Reserva memoria para una Obra, devuelve NULL en caso de error sino la obra creada 
Obra* crearObra();

//PRE:Recibe una obra y un edificio
//POS: Agrega un edificio a la obra, si puso agregar devuelve 0 caso contrario -1
int agregarEdificio(Obra* obra, Edificio* edificio);

//PRE:Recibe una obra y un material 
//POS: Agrega un material a la obra, si puso agregar devuelve 0 caso contrario -1
int agregarMaterial(Obra* obra, Material* material);

//PRE: Recibe una obra
//POS: Devuelve los edificios caso contrario NULL
Edificio** obtenerEdificios(Obra* obra);

//PRE: Recibe una obra
//POS: Devuelve los edificios caso contrario NULL
Material** obtenerMateriales(Obra* obra);

//PRE: Recibe una obra
//POS: Devuelve la cantidad de edificios que hay, en caso de error devuelve -1
int obtenerCantEdificios(Obra* obra);

//PRE: Recibe una obra
//POS: Devuelve la cantidad de edificios que hay, en caso de error devuelve -1
int obtenerCantMateriales(Obra* obra);

//PRE: Recibe una obra y un nombre de un edificio
//POS: Busca el edificio, en caso de encontrarlo lo devuelve sino devuelve null
Edificio* obtenerEdificio(Obra* obra, string nombreEdificio);

//PRE: Recibe una obra y un nombre de un material 
//POS: Busca el material, en caso de encontrarlo lo devuelve sino devuelve null
Material* obtenerMaterial(Obra* obra, string nombreMaterial);

//PRE: Recibe una obra
//POS: Libera la memoria de toda la obra
void liberarObra(Obra* obra);

#endif //OBRA_H
