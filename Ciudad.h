#ifndef CIUDAD_H
#define CIUDAD_H

#include "Edificio.h"
#include "Inventario.h"

const int MAX_EDIFICIOS = 100;

class Ciudad
{
    private:
        Edificio* edificios[MAX_EDIFICIOS];
        Material* materiales[MAX_MATERIALES];
        int cantidad_edificios;
        int posicion;
        

    public:
        Ciudad();
        void leer_archivo_edificios();
        void cargar_edificios(string nombre_edificio, int cantidad_piedra, int cantidad_madera, int cantidad_metal, int maximo_permitidos);
        int obtener_posicion(string ingresar_edificio_construir);
        string pedir_edificio();
        void mostrar_totalidad_edificios();
        void mostrar_edificios_construidos();
        void construir_edificio(int posicion);
        void guardar_edificios();


};


#endif //CIUDAD_H