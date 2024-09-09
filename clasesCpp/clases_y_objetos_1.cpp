/* 1. Crear en código c++ una clase Vehículo y luego un vector de dos objetos. */

/* Librerias */
#include <iostream>
#include <string>
// #include <string.h>
#include "vehiculo.h"
using namespace std;

/* Directivas */
#define TAM 2

/* Prototipo de funciones */
void mostrarListado(Vehiculo v[]);
void buscarPorPatente(Vehiculo v[]);

/* Funcion Principal main */
int main(int argc, char const *argv[])
{
    char opcion = 0;
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

    /* Impresion */
    mostrarListado(v);
    do // Menu para buscar un vehiculo con su nro de patente
    {
        cout<<"Desea buscar un vehiculo por su patente(S/N)? ";
        cin>>opcion;
        opcion = tolower(opcion);
        switch (opcion)
        {
        case 's':
            buscarPorPatente(v);
            break;
        case 'n':
            cout<<"\nCerrando...\n";
            stopWhile = 1;
            break;
        default:
            cout<<"\nOpcion invalida. Intente nuevamente.\n";
            break;
        }
    } while (stopWhile == 0);
    return 0;
} // main

/* Funciones */
void mostrarListado(Vehiculo v[])
{
    for (int ii = 0; ii < TAM; ii++)
    {
        cout<<v[ii].toString()<<"\n";
    }
} // mostrarListado
void buscarPorPatente(Vehiculo v[])
{
    string patente; // string para almacenar la patente a buscar
    int f = 0;
    cout<<"Ingrese la patente a buscar: ";
    cin>>patente;

    /* char patente[10]; // string para almacenar la patente a buscar
    setbuf(stdin, NULL); // limpia el buffer
    fgets(patente, 10, stdin); // funcion para cargar el valor ingresado en string patente
    patente[strcspn(patente, "\n")] = 0; //buscará en string patente el primer match con \n y devolverá la posición en patente en la cual fue encontrado el match.
     */

    for (int ii = 0; ii < TAM; ii++)
    {
        if (patente == v[ii].getPatente())
        {
            cout<<v[ii].toString()<<"\n";
            f++;
        }
    }
    if (f==0) cout<<"\nPatente no encontrada\n";
} // buscarPorPatente