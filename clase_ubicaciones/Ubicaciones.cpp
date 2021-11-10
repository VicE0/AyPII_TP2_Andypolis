#include "Ubicaciones.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string PATH_MATERIALES = "ubicaciones.txt";

void Ubicacion::leer_archivo_ubicaciones(){

    ifstream archivo_ubicaciones (PATH_MATERIALES);

    if (!archivo_ubicaciones){
        cout << "No se abrio correctamente el archivo de ubicaciones." << endl;
        exit(1);
    }

    

    archivo.close();
}
