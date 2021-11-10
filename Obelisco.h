#ifndef Obelisco_H
#define Obelisco_H

#include "Edificio.h"
#include "Ubicacion.h"

class Obelisco : public Edificio, public Coordenadas
{
    public:
    //constructores
        Obelisco(std::string nombre_edificio, int cantidad_piedra, int cantidad_madera, int cantidad_metal,int maximo_permitidos);

        Obelisco(string nombre_edificio_construido, string ancho, string alto);
 
        //PRE: ~
        //POST: Devuelve los materiales producidos por los edificios  
        int obtener_recursos();

        //PRE: ~
        //POST: Devuelve la cantidad de edificios que se construyeron
        int obtener_construidos();

        //PRE: ~
        //POST: Muestra todos los datos del archivo edificios.txt
        void mostrar_edificios();

        //PRE: ~
        //POST: Muestra todos los datos del archivo ubicaciones.txt
        void mostrar_construidos();

        //PRE: ~
        //POST: Muestra el mensaje que le corresponde al edificio en los casilleros
        void mostrar_mensaje_casillero();
};


#endif //Obelisco_H