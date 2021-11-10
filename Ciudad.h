#ifndef CIUDAD_H
#define CIUDAD_H

#include "Edificio.h"
#include "Ubicacion.h"
#include "Inventario.h"

#include "Mina.h"
#include "Aserradero.h"
#include "Escuela.h"
#include "Fabrica.h"
#include "Obelisco.h"
#include "Planta.h"


const int MAX_EDIFICIOS = 100;
const int MAX_UBICACIONES = 100;

class Ciudad 
{
    private:
        Edificio* edificios[MAX_EDIFICIOS];
        Coordenadas* ubicaciones[MAX_UBICACIONES];
        int cantidad_edificios;
        int cantidad_ubicaciones;
        
    public:
        Ciudad();

        void leer_archivo_edificios();

        void leer_ubicaciones();

        void cargar_ubicaciones(std::string nombre_edificio_construido, std::string ancho, std::string alto);

        void cargar_edificios(std::string nombre_edificio, int cantidad_piedra, int cantidad_madera, int cantidad_metal, int maximo_permitidos);

        void mostrar_totalidad_edificios();

        void mostrar_edificios_construidos();

        int obtener_posicion(string ingresar_edificio_construir);

        string pedir_edificio();

        void construir_edificio(int posicion, Inventario* datos_material);

        void guardar_edificios();


};


#endif //CIUDAD_H