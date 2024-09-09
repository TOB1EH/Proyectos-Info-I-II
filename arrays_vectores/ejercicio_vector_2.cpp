// Informática - Vectores ejercicio N°2 - Funes Tobias

#include <iostream>
using namespace std;
#define RAN 5 // cantidad de elementos del vector

int main(int argc, char const *argv[])
{
    int vector[RAN], suma=0, ii=0, num=0;
    cout<<"Ingrese "<<RAN<<" numeros enteros: \n";
    for ( ii = 0; ii < RAN; ii++)
    {
        cout<<"Numero "<<ii+1<<": ";
        cin>>num;
        vector[ii] = num;
        suma += num; // suma de valores de 'vector'
    }// cierre for1
    cout<<"Numeros ingresados: ";       
    for ( ii = 0; ii < RAN; ii++)
    {
        cout<<vector[ii]<<" - ";
    }// cierre for2
    cout<<"\nEl Promedio de los "<<RAN<<" numeros ingresados es: "<<suma/RAN<<endl; 
    return 0;
}