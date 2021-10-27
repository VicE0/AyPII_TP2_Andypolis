#include "interaccion.h"
#include <iostream>
#include <string.h>


const int LISTAR_MATERIALES = 1;
const int CONSTRUIR_EDIFICIOS = 2;
const int LISTAR_EDIFICIOS_CONSTRUIDOS = 3;
const int LISTAR_TODOS_LOS_EDIFICIOS = 4;
const int DEMOLER_EDIFICIO = 5;
const int GUARDAR_SALIR = 6;

//-----------------------------FUNCIONES AUXILIARES----------------------------

//PRE: Recibe un número entero
//POS: Devuelve true si es un número comprendido entre 1 y 6, false en caso contrario
bool validarOpcion(int opcion){
	return (opcion >= 1 && opcion <= 6);
}

//PRE: 
//POS: Devuelve una opción valida pedida al usuario
int obtenerOpcion(){
	int opcion = 0;
	bool esValido = false;
	while(!esValido){
		cout << "\n\n";
		cout << "SELECCIONE UNA OPCIÒN DEL 1 AL 6 " << endl;
		cin >> opcion;
		if(validarOpcion(opcion))
			esValido = true;
		else
			cout << "OPCIÓN INCORRECTA!" << endl;
	}
	return opcion;
}

//------------------------------------------------------------------------------


//-----------------------------FUNCIONES PRINCIPALES---------------------------


void mostrarMenu(){
	cout << "\n\n\n";
	cout << "------------------MENU------------------" << endl;
	cout << "1. LISTAR MATERIALES DE CONSTRUCCIÓN   |" << endl;
	cout << "2. CONSTRUIR EDIFICIO POR NOMBRE       |" << endl;
	cout << "3. LISTAR EDIFICIOS CONSTRUIDOS        |" << endl;
	cout << "4. LISTAR TODOS LOS EDIFICIOS          |" << endl;
	cout << "5. DEMOLER UN EDIFICIO POR NOMBRE      |" << endl;
	cout << "6. GUARDAR Y SALIR                     |" << endl;
	cout << "----------------------------------------" << endl;
	cout << "\n\n";
}



//PRE: Recibe una obra válida
//POS: Inicia el ciclo del programa
void iniciar(Obra* obra, string archivoEdificios, string archivoMateriales){
	int opcion ;
	string nombre = "";
	bool salir = false;
	do{
		mostrarMenu();
		opcion = obtenerOpcion();
		switch (opcion){
			case LISTAR_MATERIALES:
				listarMateriales(obtenerMateriales(obra), obtenerCantMateriales(obra));
				break;
			case CONSTRUIR_EDIFICIOS:
				cout << "\n\n\n";
				cout << "		CONSTRUCCIÓN DEL EDIFICIO" << endl;
				cout << "\nINGRESE EL NOMBRE DEL EDIFICIO PARA CONSTRUIRLO" << endl;
				cin >> nombre;
				cout << "\n" ;
				construirEdificio(obra,nombre);
				cout << "\n\n";
				break;
			case LISTAR_EDIFICIOS_CONSTRUIDOS:
				listarEdificiosConstruidos(obtenerEdificios(obra), obtenerCantEdificios(obra));
				break;
			case LISTAR_TODOS_LOS_EDIFICIOS:
				cout << "ENTRO A LISTAR TODOS LOS EDIFICIOS" << endl;
				listarEdificios(obtenerEdificios(obra), obtenerCantEdificios(obra));
				break;
			case DEMOLER_EDIFICIO:
				cout << "\n\n\n";
				cout << "		DEMOLER UN EDIFICIO" << endl;
				cout << "\nINGRESE EL NOMBRE DEL EDIFICIO A DEMOLER" << endl;
				cin >> nombre;
				cout << "\n";
				demolerEdificio(obra, nombre);
				cout << "\n\n";
				break;
			case GUARDAR_SALIR:
				//no hardcodear los nombres del arhivo, pasarle el que se inició
				cout << "\n\n\n";
				guardarSalir(obtenerEdificios(obra), obtenerMateriales(obra), obtenerCantEdificios(obra), obtenerCantMateriales(obra), archivoEdificios, archivoMateriales);
				salir = true;
				cout << "		SE GUARDARON LOS DATOS, HASTA LUEGO :D" << endl;
				break;
			default :
				cout << "INGRESÒ UNA OPCIÓN INCORRECTA!!!" << endl;
				break;
		}
	}while(!salir);
}

//------------------------------------------------------------------------------

