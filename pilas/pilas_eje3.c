/* 3. Crear un programa con el siguiente menu de opciones:
    Agregar un nodo a la pila. (se deben agregar 5 valores)
    Borrar el último nodo de la pila.
    Imprimir pila.
    Tamaño de la pila
    Mostrar el último valor de la pila */

/* Librerias */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "pila_int.h"
#include "functions_stacks.h"

/* Directivas */
#define TAM_MAX 5

/* Declaracion  de tipo definido por el usuario */
typedef struct node stack_t;

/* Funcion principal main */
int main(int argc, char const *argv[])
{
    /* Declaracion e inicializacion de variables */
    stack_t *stack = NULL;
    stack_t *node = NULL;
    int count = 0;
    char opcion = 0;
    do
    {
        printf("Menu de opcioness:\n"
                "\ta. Agregar un nodo a la pila.\n"
                "\tb. Borrar el último nodo de la pila.\n"
                "\tc. Imprimir pila.\n"
                "\td. Tamaño de la pila.\n"
                "\te. Mostrar el último valor de la pila.\n"
                "\tf. Cerrar menu.\n"
                "Ingrese una opcion: ");
        scanf(" %c", &opcion);
        opcion = tolower(opcion); // convierte cualquier letra a minusculas
        switch (opcion)
        {
        case 'a':
            if (count <= TAM_MAX)
            {
                addNode(&stack, &node);
                printf("Ingrese un valor para el nuevo nodo: ");
                scanf("%d", &node->data);
                count++;
            }
            else
            {
                printf("\nSe alcanzo el maximo de nodos.\n");
            }
            break;
        case 'b':
            popNode(&stack);
            printf("\nNodo Borrado.\n");
            break;
        case 'c':
            printf("Stack completa:\n");
            printStackInt(stack);
            break;
        case 'd':
            printf("\nStack de %d nodos.\n", countNodes(stack));
            break;
        case 'e':
            if (stack != NULL)
                printf("\nUltimo valor: %d\n", stack->data);
            else
            {
                printf("\nStack Vacia!\n");
            }
            break;
        case 'f':
            printf("\nCerrando...\n");
            break;
        default:
            printf("\nOpcion invalida. Intente nueamente.\n");
            break;
        }
    } while (opcion != 'f');
    freeMemory(&stack); // liberar memoria
    return 0;
} // main