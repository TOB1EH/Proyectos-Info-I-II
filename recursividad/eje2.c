/* Librerias */
#include <stdio.h>
#include <stdlib.h>

int sumaDescendente(int n);

/* Funcion principal main */
int main(int argc, char const *argv[])
{
    /* Declaracion e inicializacion de variables */
    int num = 0;
    printf("Ingrese un numero entero: ");
    scanf("%d", &num);
    printf("Suma descendente: %d", sumaDescendente(num));
    return 0;
} // main

/* Funciones */
int sumaDescendente(int n)
{
    int temp = 0;
    if (n==0)
    {
        return n;
    }
    else
    {
        temp = n+sumaDescendente(n-1);
        return temp;
    }
}