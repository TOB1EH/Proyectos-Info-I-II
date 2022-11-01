/* Ejercicio 2. Crear un programa en la cual cargue una pila de 5 numeros aleatoriamente
(entre 1 y 10), luego los muestre y muestre los valores pares. */

/* Librerias */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pila_int.h"
#include "functions_stacks.h"

/* Directivas */
#define TAM 5

/* Declaracion  de tipo definido por el usuario */
typedef struct node node_t;

/* Prototipo de Funciones */
void printPairs(struct node *stack);

/* Funcion principal main */
int main(int argc, char const *argv[])
{
    /* Declaracion e inicializacion de variables */
    node_t *stack = NULL;
    node_t *newNode = NULL;
    srand(time(NULL)); // funcion de numeros aleatorios
    for (int ii = 0; ii < TAM; ii++)
    {
        addNode(&stack, &newNode);
        newNode->data = rand()%10+1;
    }
    printf("Stack de nros aleatorios: ");
    printStackInt(stack);
    printf("Valores pares: ");
    printPairs(stack);
    /* Liberar Memoria */
    freeMemory(&stack);
    return 0;
} // main

/* Funciones */
void printPairs(struct node *stack)
{
    node_t *temp = NULL;
    temp = stack;
    while (temp != NULL)
    {
        if (temp->data%2 == 0)
            printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}