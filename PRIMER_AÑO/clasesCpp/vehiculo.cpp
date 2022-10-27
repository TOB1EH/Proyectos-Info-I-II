#include "vehiculo.h"

/* desarrollo de las funciones de la clase. */
void Vehiculo::setTipo (string tipo_in)
{
    tipo = tipo_in;
}
string Vehiculo::getTipo ()
{
    return tipo;
}

void Vehiculo::setCapacidad (int capacidad_in)
{
    capacidad = capacidad_in;
}
int Vehiculo::getCapacidad ()
{
    return capacidad;
}

void Vehiculo::setPatente (string patente_in)
{
    patente = patente_in;
}
string Vehiculo::getPatente ()
{
    return patente;
}

void Vehiculo::setColor (string color_in)
{
    color = color_in;
}
string Vehiculo::getColor ()
{
    return color;
}

string Vehiculo::toString ()
{
    string cadena = "\nTipo: "+tipo+"\nCapacidad: "+std::to_string(capacidad)+"\nPatente: "+patente+"\nColor: "+color;
    return cadena;
}

Vehiculo::Vehiculo() //constructor
{}
Vehiculo::~Vehiculo() // destructor
{}
