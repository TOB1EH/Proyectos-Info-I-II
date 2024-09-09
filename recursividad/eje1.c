/* Librerias */
#include <stdio.h>
#include <stdlib.h>

/* Directivas */

/* --- Prototipo de Funciones --- */

/* Convertir de decimal a binario */
int decToBin(int n);

/* Funcion principal main */
int main(int argc, char const *argv[])
{
    /* Declaracion e inicializacion de variables */
    int num = 0;

    printf("CONVERTIR DECIMAL A BINARIO:\n"
            "Ingrese un numero entero: ");
    scanf("%d", &num);
    decToBin(num);
    return 0;
} // main

/* Funciones */
int decToBin(int n)
{
    if(n>1)
    {
        decToBin(n/2);
    } // if
    printf("%d", n%2);
} // decToBin