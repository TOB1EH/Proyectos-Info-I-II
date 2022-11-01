/* Ejercicio 1. Crear un programa con el siguiente menu de opciones:
    Agregar un nodo a la pila. (se deben agregar 5 valores)
    Borrar el último nodo de la pila.
    Imprimir pila.
    Suma de los valores de la pila. */

/* Librerias */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "pila_int.h"
#include "functions_stacks.h"

/* Directivas */
#define TAM 5

/* Declaracion de tipo definido por el usuario */
typedef struct node node_t;

/* Funcion principal main */
int main(int argc, char const *argv[])
{
    /* Declaracion e inicializacion de variables */
    node_t *stack = NULL;
    node_t *newNode = NULL;
    int stopWhile = 0, counter = 0;
    char opcion = 0;

    do // Menu de opciones
    {
        printf("Menu de opciones:\n"
                "a. Agregar un nodo a la pila.\n"
                "b. Borrar el ultimo nodo de la pila.\n"
                "c. Imprimir pila.\n"
                "d. Suma de los valores de la pila.\n"
                "e. Cerrar Menu.\n"
                "Ingrese una opcion: ");
        scanf(" %c", &opcion);
        opcion = tolower(opcion); // convierte cualquier caracter a minusculas
        switch (opcion)
        {
        case 'a':
            if (counter < TAM)
            {
                addNode(&stack, &newNode);
                printf("Ingrese el valor para el nuevo nodo: ");
                scanf("%d", &newNode->data);
                counter++;
            }
            else
            {
                printf("\nAlcanzo el tope maximo de nodos\n");
            }
            break;
        case 'b':
            printf("\nBorrando ultimo nodo de la Stack\n");
            popNode(&stack);
            break;
        case 'c':
            printf("\nStack completa:\n");
            printStackInt(stack);
            break;
        case 'd':
            printf("\nSuma de valores: %.0f\n", addValues(stack));
            break;
        case 'e':
            printf("\nCerrando...\n");
            stopWhile = 1;
            break;
        default:
            printf("\nIngreso una opcion invalida. Intente nuevamente.\n");
            break;
        }
    } while (stopWhile == 0);
    /* Liberar Memoria */
    freeMemory(&stack);
    return 0;
} // main