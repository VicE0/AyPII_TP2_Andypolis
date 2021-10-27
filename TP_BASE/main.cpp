#include "interaccion.h"
#include <iostream>

const string ARCHIVO_EDIFICIOS = "edificios.txt";
const string ARCHIVO_MATERIALES = "materiales.txt";


int main(){
	Obra* obra = crearObra();
	cargarEdificios(obra,ARCHIVO_EDIFICIOS);
	cargarMateriales(obra, ARCHIVO_MATERIALES);
	
	iniciar(obra, ARCHIVO_EDIFICIOS, ARCHIVO_MATERIALES);
	liberarObra(obra);


	return 0;
}
