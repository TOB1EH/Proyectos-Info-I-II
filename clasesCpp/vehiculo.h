#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>
using namespace std;

class Vehiculo
{
    private:
        string tipo;
        int capacidad;
        string patente;
        string color;
    public:
        void setTipo (string tipo_in);
        string getTipo ();
        void setCapacidad (int capacidad_in);
        int getCapacidad ();
        void setPatente (string patente_in);
        string getPatente ();
        void setColor (string color_in);
        string getColor ();
        string toString ();
        Vehiculo();
        ~Vehiculo();
};
#include "vehiculo.cpp"

#endif