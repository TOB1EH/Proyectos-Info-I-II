// Informatica -  Funciones E1 - Funes Tobias

#include <stdio.h>

void paridad(int); //  Protocolo de la funcion

int main(int argc, char const *argv[])
{
    int num=0;
    printf("Ingrese un numero entero para determinar su paridad: ");
    scanf("%d", &num);
    paridad(num); // llamada a la funcion
    return 0;
}

void paridad (int n) // Definicion de la funcion paridad
{
    if (n%2==0) printf("El numero %d es par\n", n); /* si el numero ingresado al dividirlo por 2 su resto 
    es igual a cero entonces el numero ingresado es par */
    else
    {
        printf("El numero %d no es par\n", n);
    }
}