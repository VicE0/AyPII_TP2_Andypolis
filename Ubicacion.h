#ifndef UBICACION_H
#define UBICACION_H

class Coordenadas
{
    protected:
        std::string nombre_edificio_construido;
        std::string alto;
        std::string ancho;

    public:
        //PRE: ~
        //POST: Muestra todos los datos del archivo ubicaciones.txt
        virtual void mostrar_construidos() = 0;           
};



#endif // UBICACION_H