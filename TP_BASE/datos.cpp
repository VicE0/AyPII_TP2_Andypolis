#include <iostream>
#include "datos.h"
#include <fstream>

void cargarMateriales(Obra* obra, string nombreArchivoMateriales){
	fstream archivoMateriales(nombreArchivoMateriales, ios::in);
	if(!archivoMateriales.is_open()){
		cout << "NO SE ENCONTRÒ EL ARCHIVO " << nombreArchivoMateriales << endl;
		archivoMateriales.open(nombreArchivoMateriales, ios::out);
		archivoMateriales.close();
		archivoMateriales.open(nombreArchivoMateriales, ios::in);
	}

	string nombre, cantMaterial;
	Material* material;

	while(archivoMateriales >> nombre)
	{
		archivoMateriales >> cantMaterial;
		material = new Material;
		material->nombre = nombre;
		material->cantMaterial = (int)stol(cantMaterial);
		agregarMaterial(obra, material);
	}

	archivoMateriales.close();
}


void cargarEdificios(Obra* obra, string nombreArchivoEdificios){
	fstream archivoEdificios(nombreArchivoEdificios, ios::in);
	if(!archivoEdificios.is_open()){
		cout << "NO SE ENCONTRÒ EL ARCHIVO" << endl;
		archivoEdificios.open(nombreArchivoEdificios, ios::out);
		archivoEdificios.close();
		archivoEdificios.open(nombreArchivoEdificios, ios::in);
	}
	string nombre, cantPiedra, cantMadera, cantMetal, cantConstruidos, cantMaxPermitidos;
	Edificio* edificio;
	while(archivoEdificios >> nombre){
		archivoEdificios >> cantPiedra;
		archivoEdificios >> cantMadera;
		archivoEdificios >> cantMetal;
		archivoEdificios >> cantConstruidos;
		archivoEdificios >> cantMaxPermitidos;

		// asigno los datos a los edificios
		edificio = new Edificio;
		edificio->nombre = nombre;
		edificio->cantPiedra = (int)stol(cantPiedra);
		edificio->cantMadera = (int)stol(cantMadera);
		edificio->cantMetal = (int)stol(cantMetal);
		edificio->cantConstruidos = (int)stol(cantConstruidos);
		edificio->cantMaxPermitidos = (int)stol(cantMaxPermitidos);

		agregarEdificio(obra, edificio);
	}

	archivoEdificios.close();
}


void guardarEdificios(Edificio** edificios, int cantEdificios, string nombreArchivoEdificios){
	ofstream archivoEdificios(nombreArchivoEdificios);
	for(int pos = 0; pos < cantEdificios; pos++){
		archivoEdificios << edificios[pos]->nombre << ' '
										 << edificios[pos]->cantPiedra << ' '
										 << edificios[pos]->cantMadera << ' '
										 << edificios[pos]->cantMetal << ' '
										 << edificios[pos]->cantConstruidos << ' '
										 << edificios[pos]->cantMaxPermitidos << '\n';
	}
}

void guardarMateriales(Material** materiales, int cantMateriales, string nombreArchivoMateriales){
	ofstream archivoMateriales(nombreArchivoMateriales);
	for(int pos = 0; pos < cantMateriales; pos++){
		archivoMateriales << materiales[pos]->nombre << ' '
											<< materiales[pos]->cantMaterial << '\n';
	}
}
