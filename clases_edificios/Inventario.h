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
        void cargar_materiales();
        void mostrar_materiales();
        void guardar_materiales(string nombre, int cantidad);

};


#endif //INVENTARIO_H