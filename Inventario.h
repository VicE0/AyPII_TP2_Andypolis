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
        Inventario();
        void leer_archivo_materiales();
        int obtener_material(string material);
        void mostrar_materiales();
        void guardar_materiales();

};


#endif //INVENTARIO_H