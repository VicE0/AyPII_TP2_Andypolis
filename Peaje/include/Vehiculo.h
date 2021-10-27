#ifndef VEHICULO_H
#define VEHICULO_H

class Vehiculo
{
    protected:
        bool telepase;
        unsigned int cantidadDeRuedas;

    public:
        Vehiculo(){};
        virtual float descuento() = 0;
        virtual void verificarTelepase(bool telepase) = 0;
        float montoAPagar(unsigned int precioPorRueda);

};

#endif // VEHICULO_H
