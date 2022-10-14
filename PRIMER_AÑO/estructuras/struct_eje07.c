/* Ejercicio 7: Crear una estructura llamada producto con los siguientes atributos código,
nombre, stock, cantidad vendida. Crear un vector de estructuras del tipo producto (max 10).
Luego crear un menu de opciones:
    a. mostrar todos los productor
    b. cargar una venta (debe buscar y restar el stock y sumar la cant vendida)
    c. reponer mercadería (debe buscar y sumar el stock)
    d. ordenar por productos mas vendidos
    e. ordenar por productor con menor stock
Utilice funciones. */

/* Librerias */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

/* Directivas */
#define TAM_STRING 25 // tamanio/cantidad de caracteres para strings
#define TAM_MAX 10 // max de productos que puede ingresar

/* Estructuras */
struct Lista
{
    long cod;
    char nombre[TAM_STRING];
    int stock;
    int cant_vendida;
};
/* Declaracion  de tipo definido por el usuario */
typedef struct Lista Producto; // alias para la lista = Producto

/* Prototipo de Funciones */
void checkMemory (struct Lista **ptr); // verifica si hay memoria suficiente para la redimension de memoria

/* Funcion principal main */
int main(int argc, char const *argv[])
{
    /* Declaracion e inicializacion de variables */
    //struct Producto *producto = NULL;
    Producto *producto = NULL;
    int nProducts = 0, stopWhile = 0, ii = 0;

    do // ciclo repetitivo do-while
    {
        printf("Ingrese la cantidad de productos (max. 10): ");
        scanf("%d", &nProducts);
        if (nProducts > TAM_MAX)
            printf("Supero el max de productos permitidos, ingrese una cantidad menor.\n");
        else
        {
            stopWhile = 1; // detiene el ciclo
        }
    } while (stopWhile == 0);
    /* Dimensionando memoria para arreglo de productos */
    producto = (Producto *)malloc(nProducts*sizeof(Producto));
    checkMemory(&producto); // verifica si hay memoria suficiente
    /* Carga de datos */
    printf("Carga de productos:\n");
    for (ii = 0; ii < nProducts; ii++)
    {
        printf("Producto Nro%d:\n"
        "Ingrese el codigo: ", (ii+1));
        scanf("%ld", &(producto+ii)->cod);

        printf("Ingrese el nombre del producto: ");
        setbuf(stdin, NULL);
        fgets((producto+ii)->nombre, TAM_STRING, stdin);

        printf("Ingresa la cantidad de stock: ");
        scanf("%d", &(producto+ii)->stock);

        (producto+ii)->cant_vendida = 0;
    }
    /* Impresion de datos */
    printf("Datos:\n");
    for (ii = 0; ii < nProducts; ii++)
    {
        printf("codigo: %ld",
                (producto+ii)->cod);
    }
    /* Liberar memoria */
    free(producto);
    return 0;
} // main

/* Funciones */
void checkMemory (struct Lista **ptr)
{
    if (*ptr == NULL)
    {
        printf("\nMemoria Insuficiente\n");
        exit(0); // si no hay memoria disponible finalizar el programa
    }
} // funtion 'checkMemory'