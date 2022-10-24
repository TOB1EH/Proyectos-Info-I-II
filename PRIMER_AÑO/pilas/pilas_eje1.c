/* Ejercicio 1. Crear un programa con el siguiente menu de opciones:
    Agregar un nodo a la pila. (se deben agregar 5 valores)
    Borrar el último nodo de la pila.
    Imprimir pila.
    Suma de los valores de la pila. */

/* Librerias */
#include <stdio.h>
#include <stdlib.h>
#include "pila_int.h"
#include "functions_stacks.h"

/* Declaracion  de tipo definido por el usuario */
typedef struct node node_t;

/* Prototipo de Funciones */

/* Funcion principal main */
int main(int argc, char const *argv[])
{
    /* Declaracion e inicializacion de variables */
    node_t *stack = NULL;
    node_t *newNode = NULL;
    int stopWhile = 0;
    char opcion = 0;

    do // Menu de opciones
    {
        printf("Menu de opciones:\n"
                "a. Agregar un nodo a la pila.\n"
                "b. Borrar el último nodo de la pila.\n"
                "c. Imprimir pila.\n"
                "d. Suma de los valores de la pila.\n"
                "e. Cerrar Menu.\n");
    } while (stopWhile == 0);
    return 0;
} // main

/* Funciones */
