#include <iostream>
#include <string>
using namespace std;

class Perfume
{
private:
    string nombre;
    int tamanio;
    string marca;
public:
    Perfume(); // constructor por defecto
    Perfume(string name, int tam, string marc); // constrcutor con datos
    void setNombre(string name);
    string getNombre();
    void setTam(int tam);
    int getTam();
    void setMarca(string marc);
    string getMarca();
    string toString();
    ~Perfume();
};
/* Metodos de la clase */
Perfume::Perfume(){}
Perfume::Perfume(string name, int tam, string marc)
{
    nombre = name;
    tamanio = tam;
    marca = marc;
}
void Perfume::setNombre(string name)
{
    nombre = name;
}
string Perfume::getNombre()
{
    return nombre;
}
void Perfume::setTam(int tam)
{
    tamanio = tam;
}
int Perfume::getTam()
{
    return tamanio;
}
void Perfume::setMarca(string marc)
{
    marca = marc;
}
string Perfume::getMarca()
{
    return marca;
}
string Perfume::toString()
{
    string cadena = "\nNombre: "+nombre+"\nTamanio: "+std::to_string(tamanio)+"\nMarca: "+marca+"\n";
    return cadena;
}
Perfume::~Perfume(){} // destructor

int main(int argc, char const *argv[])
{
    /* Declaracion e inicializacion de variables */
    Perfume perfume1("Colonia", 300, "PACO");
    Perfume perfume2;
    int tam = 0;
    string name, marc;

    cout<<"Ingrese el nombre del perfume: ";
    cin>>name;
    perfume2.setNombre(name);
    cout<<"Ingrese el tamanio: ";
    cin>>tam;
    perfume2.setTam(tam);
    cout<<"Ingrese la marca: ";
    cin>>marc;
    perfume2.setMarca(marc);

    /* Impresion:  */
    cout<<"\nPerfume 1: "<<perfume1.toString();
    cout<<"\n";
    cout<<"Perfume 2: "<<perfume2.toString();
    return 0;
}
