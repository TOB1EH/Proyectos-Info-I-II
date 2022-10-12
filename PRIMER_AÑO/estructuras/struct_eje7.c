#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define TAM_STRING 15
#define TAM_MAX 10

struct Producto
{
    int cod;
    char nombre[TAM_STRING];
    int stock;
    int cant_vendida;
};


int main(int argc, char const *argv[])
{
    /* Declaracion e inicializacion de variables */
    struct Producto *producto = NULL;
    int nProducts = 0, stopWhile = 0, ii = 0;

    do
    {
        printf("Ingrese la cantidad de productos (max. 10): ");
        scanf("%d", &nProducts);
        if (nProducts > TAM_MAX)
            printf("Supero el max de productos permitidos, ingrese una cantidad menor.\n");
        else
        {
            stopWhile = 1;
        }
    } while (stopWhile == 0);
    /* Dimensionando memoria para arreglo de productos */
    producto = (struct Producto *)malloc(nProducts*sizeof(struct Producto));
    if (producto == NULL)
    {
        printf("\nMemoria Insuficiente\n");
        exit(0); // si no hay memoria disponible finalizar el programa
    }
    /* Carga de datos */
    for (ii = 0; ii < nProducts; ii++)
    {
        printf("Ingrese el codigo: ");
        scanf("%d", &(producto+ii)->cod);
    }
    /* Impresion de datos */
    printf("Datos:\n");
    for (ii = 0; ii < nProducts; ii++)
    {
        printf("codigo: %d", (producto+ii)->cod);
    }
    /* Liberar memoria */
    free(producto);
    return 0;
}