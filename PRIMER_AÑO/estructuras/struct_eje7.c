#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define TAM_STRING 15
#define TAM_MAX 10

struct Producto
{
    long cod;
    char nombre[TAM_STRING];
    int stock;
    int cant_vendida;
};

void cargarProductos (struct Producto **productos, int *nProducts);

int main(int argc, char const *argv[])
{
    
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
        exit(0);
    }
    
    /* Carga de datos */
    cargarProductos(&producto, &nProducts);

    free(producto);
    return 0;
}
void cargaProductos (struct Producto **productos, int *nProducts)
{
    int ii = 0;
    srand(time(NULL));
    // Datos aleatorios a modo de simplificar el ejercicio
    for (ii = 0; ii < *nProducts; ii++)
    {
       id = id + num;
       (*productos + ii)->cod = 100020+ii;
       (*productos + ii)->nombre[TAM_STRING] = id;
       (*productos + ii)->stock = rand()%100;
       (*productos + ii)->cant_vendida = 0;
    }
}