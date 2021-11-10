#ifndef INVENTARIO_H
#define INVENTARIO_H


#include "Material.h"

const int MAX_MATERIALES = 10;

class Inventario
{
    private:
        Material* materiales[MAX_MATERIALES]; //leo el archivo de forma estatica
        int cantidad_materiales;

    public:
    //Constructor
        Inventario();

        //PRE: ~
        //POST: Lee el archivo de materiales.txt
        void leer_archivo_materiales();

        //PRE: Recibe un punto de la lista de materiales
        //POST:  Devuelve el material     
        Material* obtener_material(string material, Inventario* datos_material);

        //PRE: ~
        //POST: Muestra el Inventario
        void mostrar_materiales(Inventario* datos_material);


        //PRE: ~
        //POST: Guarda los cambios del array en el materiales.txt
        void guardar_materiales();

};


#endif //INVENTARIO_H