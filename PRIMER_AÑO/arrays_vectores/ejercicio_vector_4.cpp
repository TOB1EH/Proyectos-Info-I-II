//Informática - Vectores ejercicio N°4 - Funes Tobias

#define RAN 10 
#include <iostream>
#include <locale.h>
#include <ctime>
using namespace std;

int main(int argc, char const *argv[])
{
    int ii=0, num=0, vector[RAN]={0};
    srand(time(NULL)); // Función para generar números aleatorios
    cout<<"Valores aleatorios: "<<endl;
    for (ii = 0; ii < RAN; ii++)
    {        
        vector[ii] = 0 + rand() %100; // números aleatorios = desde + rand() %hasta
        cout<<vector[ii]<<" - ";
    }// cierre for1
    cout<<"\n\nValores pares:"<<endl;
    for (ii = 0; ii < RAN; ii++)
    {
        if (vector[ii]%2==0) cout<<vector[ii]<<" - "; // imprime por pantalla solos los numeros pares
    }// cierre for2
    cout<<endl;
    return 0;
}