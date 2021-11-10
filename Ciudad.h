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

        //PRE: ~
        //POST: Lee el archivo edificios.txt
        void leer_archivo_edificios();

        //PRE: ~
        //POST: Lee el archivo ubicaciones.txt
        void leer_ubicaciones();

        //PRE: Recibe los datos que conforman el archivo
        //POST: Crea el array
        void cargar_ubicaciones(std::string nombre_edificio_construido, std::string ancho, std::string alto);

        //PRE: Recibe los datos que conforman el archivo
        //POST: Crea el array
        void cargar_edificios(std::string nombre_edificio, int cantidad_piedra, int cantidad_madera, int cantidad_metal, int maximo_permitidos);

        //PRE: ~
        //POST: Muestra todos los edificios
        void mostrar_totalidad_edificios();

        //PRE: ~
        //POST: Muestra los edificios construidos
        void mostrar_edificios_construidos();

        //PRE: Recibe el nombre de un edificio
        //POST: Devuelve la posicion en el array de dicho edificio
        int obtener_posicion(string ingresar_edificio_construir);

        //PRE: ~
        //POST: Pide ingresar un edificio
        string pedir_edificio();

        //PRE: Recibe la posicion del edificio y la lista de materiales
        //POST: Segun el nombre del edificio y si se encuentra construido, suma los recursos a materiales
        void recolectar_recursos(int posicion, Inventario* datos_material);

        //PRE: Recibe la posicion del edificio y la lista de materiales
        //POST: Construye el edificio y resta los materiales correspondientes
        void construir_edificio(int posicion, Inventario* datos_material);

        //PRE: ~
        //POST: Guarda los cambios del array en el archivo txt
        void guardar_edificios();


};


#endif //CIUDAD_H