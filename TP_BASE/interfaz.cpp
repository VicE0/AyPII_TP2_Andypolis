#include "interfaz.h"
#include <iostream>
const int VACIO = 0;
const int MITAD = 2;
const string PIEDRA = "piedra";
const string MADERA = "madera";
const string METAL = "metal";



//----------------------------------------------------------FUNCIONES AUXILIARES----------------------------------------------------

string convertirMayuscula(string cadena){
	string cadenaNueva = "";
	for(int pos = 0; pos < (int)cadena.size(); pos++)
		cadenaNueva += (char)toupper(cadena[pos]);
	return cadenaNueva;	
}

//PRE: Recibe un material
//POS: Muestra el nombre del material y la cantidad que tiene
void mostrarMaterial(Material* material){
	//cout << material->nombre <<" " << material->cantMaterial << endl;
	cout << "\n\n"; 
	cout << "|---------------------------------------------|" << endl;
	cout << "		" << convertirMayuscula(material->nombre) << endl;
	cout << "	" << "CANDTIDAD MATERIAL : " << material->cantMaterial << endl;
	cout << "|---------------------------------------------|" << endl;
	cout << "\n"; 

}

//PRE: Recibe un edificio
//POS: Muestra los datos del edificio
void mostrarEdificio(Edificio* edificio){
	cout << "\n\n"; 
	cout << "|---------------------------------------------|" << endl;
	cout << "		"<< convertirMayuscula(edificio->nombre) << endl;
	cout << "	CANTIDAD DE PIEDRA : " << edificio->cantPiedra << endl;
	cout << "	CANTIDAD DE MADERA : " << edificio->cantMadera << endl;
	cout << "	CANTIDAD DE METAL : " << edificio->cantMetal << endl;
	cout << "	CANTIDAD CONSTRUIDOS : " << edificio->cantConstruidos << endl;
	cout << "	FALTAN CONSTRUIR : " << edificio->cantMaxPermitidos - edificio->cantConstruidos << endl;
	cout << "|---------------------------------------------|" << endl;
	cout << "\n";
}

//PRE: Recibe un edificio
//POS: Muestra el nombre del edificio y la cantidad de construidos
void mostrarEdificioConstruido(Edificio* edificio){
	cout << "\n\n"; 
	cout << "|---------------------------------------------|" << endl;
	cout << "		"<< convertirMayuscula(edificio->nombre) << endl;
	cout << "	CANTIDAD CONSTRUIDOS :" << edificio->cantConstruidos << endl;
	cout << "|---------------------------------------------|" << endl;
	cout << "\n"; 
}
//----------------------------------------------------------------------------------------------------------------------------------



//-------------------------------------------------------------FUNCIONES PRINCIPALES--------------------------------------------------

void listarMateriales(Material** materiales, int cantMateriales){
	cout << "\n\n\n\n";
	cout << "	LISTADO DE TODOS LOS MATERIALES";
	for(int pos = 0; pos < cantMateriales; pos++)
		mostrarMaterial(materiales[pos]);
}


void listarEdificios(Edificio** edificios, int cantEdificios){
	cout << "\n\n\n\n";
	cout << "	LISTADO DE TODOS LOS EDIFICIOS ";
	for(int pos = 0; pos < cantEdificios; pos++)
		mostrarEdificio(edificios[pos]);
}

void listarEdificiosConstruidos(Edificio** edificios, int cantEdificios){
	cout << "\n\n\n\n";
	cout << "   LISTADO DE TODOS LOS EDIFICIOS CONSTRUIDOS";
	for(int pos = 0; pos < cantEdificios; pos++){
		if(edificios[pos]->cantConstruidos != VACIO)
			mostrarEdificioConstruido(edificios[pos]);
	}
}

void demolerEdificio(Obra* obra, string nombreEdificio){
	Edificio* edificio = obtenerEdificio(obra, nombreEdificio);
	if(!edificio){
		cout << "ERROR! --> NO EXISTE EL NOMBRE DEL EDIFICIO " << endl;
	}else if(edificio->cantConstruidos == VACIO){
		cout << "ERROR! --> NO SE PUEDE DEMOLER EL EDIFICIO PORqUE AÙN NO SE AH CONSTRUIDO NINUNGO" << endl;
	}else{
		edificio->cantConstruidos--;

		Material* piedra = obtenerMaterial(obra, PIEDRA);
		Material* madera = obtenerMaterial(obra, MADERA);
		Material* metal = obtenerMaterial(obra, METAL);
	
		//No es necesario validar si existen pues el tp me asegura por lo menos esos 3 existiràn
	
		piedra->cantMaterial += edificio->cantPiedra/MITAD;
		madera->cantMaterial += edificio->cantMadera/MITAD;
		metal->cantMaterial += edificio->cantMetal/MITAD;
		cout << "SE DEMOLIÓ EXITOSAMENTE EL EDIFICIO" << endl;
	}
}

void construirEdificio(Obra* obra, string nombreEdificio){
	Edificio* edificio = obtenerEdificio(obra, nombreEdificio);
	if(!edificio)
		cout << "ERROR! --> NO EXISTE EL NOMBRE DEL EDIFICIO" << endl;
	else if(edificio->cantConstruidos == edificio->cantMaxPermitidos)
		cout << "ERROR! --> NO SE PUEDE CONSTRUIR MÁS EDIFICIOS! PORqUE LLEGÓ A SU MÁXIMA CANTIDAD DE CONSTRUCCION PERMITIDO" << endl;
	else{
		Material* piedra = obtenerMaterial(obra, PIEDRA);
		Material* madera = obtenerMaterial(obra, MADERA);
		Material* metal = obtenerMaterial(obra, METAL);
		if(edificio->cantPiedra <= piedra->cantMaterial && edificio->cantMadera <= madera->cantMaterial && edificio->cantMetal <= metal->cantMaterial){
			//construyo un edificio
			edificio->cantConstruidos++;

			//modifico los materiales que se usaron para construir
			piedra->cantMaterial -= edificio->cantPiedra;
			madera->cantMaterial -= edificio->cantMadera;
			metal->cantMaterial -= edificio->cantMetal;

			cout << "SE CONSTRUYÒ EXITOSAMENTE EL EDIFICIO " << nombreEdificio << endl;

		}else{
			cout << "ERROR! --> NO HAY MATERIALES SUFICIENTE PARA PODER CONSTRUIR EL EDIFICIO" << endl;
		}

	}


}

void guardarSalir(Edificio** edificios, Material** materiales, int cantEdificios, int cantMateriales, string nombreArchivoEdificios, string nombreArchivoMateriales){
	guardarEdificios(edificios, cantEdificios, nombreArchivoEdificios);
	guardarMateriales(materiales, cantMateriales, nombreArchivoMateriales);
}





