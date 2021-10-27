#include "obra.h"
#include <iostream>

const int ERROR = -1;
const int EXITO = 0;
const int VACIO = 0;

const string PIEDRA = "PIEDRA";
const string MADERA = "MADERA";
const string METAL = "METAL";

const int MITAD = 2;

//-----------------------------------------------------------FUNCIONES AUXILIARES-----------------------------------------

//PRE: Recibe un vector de edificios y su cantidad
//POS: Libera cada edificio y al final libera el vector
void liberarEdificios(Edificio** edificios, int cantEdificios){
	if(edificios){
		//Libero primero cada edificio 
		for(int pos = 0; pos < cantEdificios; pos++){
			delete edificios[pos];
		}
		//Libero el array del edificio
		delete[] edificios;	
	}
}

//PRE: Recibe un vector de materiales y su cantidad
//POS: Libera cada material y al final libera el vector
void liberarMateriales(Material** materiales, int cantMateriales){
	if(materiales){
		for(int pos = 0; pos < cantMateriales; pos++)
			delete materiales[pos];
		delete[] materiales;
	}
}

//----------------------------------------------------------------------------------------------------------------------------




//---------------------------------------------------------FUNCIONES PRINCIPALES---------------------------------------------------
Obra* crearObra(){
	Obra* obra = new Obra;
	obra->edificios = NULL;
	obra->materiales = NULL;
	obra->cantMateriales = 0;
	obra->cantEdificios = 0;
	return obra;
}

int agregarEdificio(Obra* obra, Edificio* edificio){
	Edificio** nuevoVectorEdificios = new Edificio*[obra->cantEdificios + 1];
	//El peor caso sería que no se pueda reservar memoria, si pasara esto no podría copiar los datos ni seguir
	if(!nuevoVectorEdificios) return ERROR;
	
	//Copio los datos
	for(int pos = 0; pos < obra->cantEdificios; pos++){
		nuevoVectorEdificios[pos] = obra->edificios[pos];
	}

	//agrego el nuevo edificio
	nuevoVectorEdificios[obra->cantEdificios] = edificio;

	//libero el contenedor edificios , sus valores no! porque aún los conservo! en el nuevo 
	if(obra->cantEdificios != 0){
		delete[] obra->edificios;
	}

	//reasigno el nuevo vector y aumento la cantidad de edificios que tengo
	obra->edificios = nuevoVectorEdificios;
	obra->cantEdificios++;
	return EXITO;
}


int agregarMaterial(Obra* obra, Material* material){
	Material** nuevoVectorMateriales = new Material*[obra->cantMateriales + 1];
	if(!nuevoVectorMateriales) return ERROR;

	for(int pos = 0; pos < obra->cantMateriales; pos++)
		nuevoVectorMateriales[pos] = obra->materiales[pos];
	

	nuevoVectorMateriales[obra->cantMateriales] = material;

	if(obra->cantMateriales != 0)
		delete[] obra->materiales;

	obra->materiales = nuevoVectorMateriales;
	obra->cantMateriales++;
	return EXITO;
}



void liberarObra(Obra* obra){
	if(obra){
		liberarEdificios(obra->edificios, obra->cantEdificios);
		liberarMateriales(obra->materiales, obra->cantMateriales);
		delete obra;
	}
}

Edificio** obtenerEdificios(Obra* obra){
	return (obra)? obra->edificios : NULL;
}

Material** obtenerMateriales(Obra* obra){
	return (obra)? obra->materiales : NULL;
}

int obtenerCantEdificios(Obra* obra){
	return obra->cantEdificios;
} 
int obtenerCantMateriales(Obra* obra){
	return obra->cantMateriales;
} 

Edificio* obtenerEdificio(Obra* obra, string nombre){
	Edificio* edificio = NULL;
	int pos = 0;
	bool seEncontro = false;
	while(!seEncontro && pos < obra->cantEdificios){
		if(obra->edificios[pos]->nombre== nombre){
			edificio = obra->edificios[pos];
			seEncontro = true;
		}
		pos++;
	}
	return edificio;
}

Material* obtenerMaterial(Obra* obra, string nombre){
	Material* material = NULL;
	int pos = 0;
	bool seEncontro = false;
	while(!seEncontro && pos < obra->cantMateriales){
		if(obra->materiales[pos]->nombre == nombre){
			material = obra->materiales[pos];
			seEncontro = true;
		}
		pos++;
	}
	return material;
}

