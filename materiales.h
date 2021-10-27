#ifndef MATERIALES_H
#define MATERIALES_H

#include <iostream>
#include <fstream>
using namespace std;


class Materiales
{
    protected: //atributos
        string material;
        int cantidad;

    public: //metodos
        Materiales(){};
        void mostrar_materiales();
        int restar_material();
        int sumar_material();
        int lluvia_materiales();
};



#endif // MATERIALES_H
