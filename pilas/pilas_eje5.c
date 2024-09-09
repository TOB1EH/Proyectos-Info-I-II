/* 5. Desarrolle un programa que cargue una pila de numeros enteros aleatorios.
Luego realice un menu de opciones:
    Agregar un nodo a la pila. (cuando agrega un valor, el mismo no tiene que estar
    repetido en la pila)
    Borrar el último nodo de la pila.
    Imprimir pila. */

/* Librerias */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "pila_int.h"
#include "functions_stacks.h"

/* Directivas */
#define MAX 10 // cantidad max de nodos, y de numeros aleatorios

/* Declaracion  de tipo definido por el usuario */
typedef struct node stack_t;

/* Funcion principal main */
int main(int argc, char const *argv[])
{
    /* Declaracion e inicializacion de variables */
    stack_t *stack = NULL;
    stack_t *node = NULL;
    stack_t *temp = NULL;
    char opcion = 0;
    int aux = 0, count = 0;

    srand(time(NULL)); // funcion de numeros aleatorios

    do // Ciclo Menu de opciones
    {
        printf("Menu para crear una Stack de letras:\n"
                "\ta. Agregar un nodo a la stack.\n"
                "\tb. Borrar el ultimo nodo de la stack.\n"
                "\tc. Imprimir stack.\n"
                "\td. Cerrar menu.\n"
                "Ingrese una opcion: ");
        scanf(" %c", &opcion);
        opcion = tolower(opcion);
        switch (opcion)
        {
        case 'a':
            if (count < MAX)
            {
                addNode(&stack, &node);
                aux = rand()%(MAX)+1;
                temp = stack;
                while (temp != NULL)
                {
                    if (temp->data == aux)
                    {
                        aux = rand()%(MAX)+1;
                        temp = stack;
                    }
                    else
                    {
                        temp = temp->next;
                    }
                }
                node->data = aux;
                count++;
            }
            else
            {
                printf("\nSe alcanzo el maximo de nodos.\n");
            }
            break;
        case 'b':
            popNode(&stack);
            printf("\nNodo borrado.\n");
            break;
        case 'c':
            printf("\nPila completa:\n");
            printStackInt(stack);
            break;
        case 'd':
            printf("\nCerrando...\n");
            break;
        default:
            printf("\nOpcion Invalida. Intente nuevamente.\n");
            break;
        }
    } while (opcion != 'd');
    freeMemory(&stack); // liberar memoria
    return 0;
} // main