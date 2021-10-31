#ifndef CIUDAD_H
#define CIUDAD_H

#include "Edificio.h"
#include "Material.h"
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
        bool edificio_valido();
        int obtener_posicion();
        string pedir_edificio();
        void mostrar_totalidad_edificios();
        void mostrar_edificios_construidos();
        void construir_edificio(int posicion);
        void demoler_edificio();
        void guardar_edificios();


};


#endif //CIUDAD_H