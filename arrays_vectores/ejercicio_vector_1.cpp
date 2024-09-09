// Informática - Vectores ejercicio N°1 - Funes Tobias

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int ii=0, num=0, enteros[5]; // posiciones del vector = 5 = {0, 1, 2, 3, 4}
    cout<<"Ingrese 5 numeros enteros que forman al vector:"<<endl;
    for (ii = 0; ii < 5; ii++)
    {
        cout<<"Numero "<<ii+1<<": ";
        cin>>num;
        enteros[ii] = num;
    }// cierre for1
    cout<<"Numeros en posiciones impares:"<<endl;
    for (ii = 1; ii < 5; ii=ii+2) // posiciones impares del vector: {1, 3}
    {
        cout<<enteros[ii]<<" - ";
    }// cierre for2
    cout<<endl;
    return 0;
}
