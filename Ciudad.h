#ifndef CIUDAD_H
#define CIUDAD_H

#include "Edificio.h"
#include "Inventario.h"

#include "Aserradero.h"
#include "Escuela.h"
#include "Fabrica.h"
#include "Obelisco.h"
#include "Planta.h"
#include "Yacimiento.h"
#include "Mina.h"

const int MAX_EDIFICIOS = 100;

class Ciudad
{
    private:
        Edificio* edificios[MAX_EDIFICIOS];
        int cantidad_edificios;
        
    public:
        Ciudad();

        void leer_archivo_edificios();

        void cargar_edificios(string nombre_edificio, int cantidad_piedra, int cantidad_madera, int cantidad_metal, int maximo_permitidos);

        int obtener_posicion(string ingresar_edificio_construir);

        string pedir_edificio();

        void mostrar_totalidad_edificios(Ciudad* datos_ciudad);

        void mostrar_edificios_construidos(Ciudad* datos_ciudad);

        void construir_edificio(int posicion,Inventario* datos_material, Ciudad* datos_ciudad);

        void guardar_edificios();


};


#endif //CIUDAD_H