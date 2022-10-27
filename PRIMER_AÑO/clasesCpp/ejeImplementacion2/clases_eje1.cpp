#include <iostream>
#include <string.h>
using namespace std;

#define TAM 2
#define TAM_STRINGS 15

class Vehiculo
{
    private:
        char tipo[TAM_STRINGS];
        int  capacidad;
        char patente[TAM_STRINGS];
        char color[TAM_STRINGS];
    public:
        void setTipo(char tip[TAM_STRINGS]);
        char getTipo();
        void setCapacidad(int capa);
        int getCapacidad();
        void setPatente(char pat[TAM_STRINGS]);
        char getPatente();
        void setColor(char col[TAM_STRINGS]);
        char getColor();
        char toString ();
        Vehiculo();
        ~Vehiculo();
};

/* desarrollo de las funciones de la clase. */
void Vehiculo::setTipo (char tip[TAM_STRINGS])
{
    tipo[TAM_STRINGS] = tip[TAM_STRINGS];
}
char Vehiculo::getTipo ()
{
    return tipo[TAM_STRINGS];
}

void Vehiculo::setCapacidad (int capa)
{
    capacidad = capa;
}
int Vehiculo::getCapacidad ()
{
    return capacidad;
}

void Vehiculo::setPatente (char pat[TAM_STRINGS])
{
    patente[TAM_STRINGS] = pat[TAM_STRINGS];
}
char Vehiculo::getPatente ()
{
    return patente[TAM_STRINGS];
}

void Vehiculo::setColor (char col[TAM_STRINGS])
{
    color[TAM_STRINGS] = col[TAM_STRINGS];
}
char Vehiculo::getColor ()
{
    return color[TAM_STRINGS];
}

/**/
char Vehiculo::toString ()
{
    char cadena[100] = "\nTipo: "+tipo+"\nCapacidad: "+std::to_string(capacidad)+"\nPatente: "+patente+"\nColor: "+color;
    return cadena[100];
}
/**/
Vehiculo::Vehiculo() // constructor
{}
Vehiculo::~Vehiculo() // destructor
{}
 int main(int argc, char const *argv[])
 {
    char opcion[TAM_STRINGS] = 0;
    int stopWhile = 0;
    Vehiculo v[TAM]; // v es un arreglo instancia de la clase Vehiculo
    /* Carga vehiculo 1 */
    v[0].setTipo("auto");
    v[0].setCapacidad(5);
    v[0].setPatente("123");
    v[0].setColor("rojo");
    /* Carga vehiculo 2 */
    v[1].setTipo("moto");
    v[1].setCapacidad(2);
    v[1].setPatente("465");
    v[1].setColor("verde");


    for (int ii = 0; ii < TAM; ii++)
    {
    }
    return 0;
 }