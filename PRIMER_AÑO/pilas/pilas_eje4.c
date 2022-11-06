/* 4. Crear un programa con el siguiente menu de opciones:
    Agregar un nodo a la stack.
    Borrar el último nodo de la stack.
    Imprimir stack.
    Cantidad de nodos en la stack.
    Cantidades de letras mayusculas y minusculas en la stack.
El usuario cargará la stack con letras mayusculas o minusculas.
Nota: Las letras en ASCII mayusculas estan entre el 65 a 90 y las
minusculas entre  97 a 122 inclusive. */

/* Librerias */
#include <stdio.h>
#include <stdlib.h>
#include "stack_char.h"
#include "functions_stacks.h"

/* Directivas */

/* Declaracion  de tipo definido por el usuario */
typedef struct nodeChar stack_t;

/* Prototipo de Funciones */

/* Funcion principal main */
int main(int argc, char const *argv[])
{
    /* Declaracion e inicializacion de variables */
    stack_t *stack = NULL;
    stack_t *node = NULL;
    char opcion = 0;
    do
    {
        printf("Menu para crear una Stack de letras:\n"
                "\ta. Agregar un nodo a la stack.\n"
                "\tb. Borrar el último nodo de la stack.\n"
                "\tc. Imprimir stack.\n"
                "\td. Tamaño de la stack.\n"
                "\te. Mostrar el último valor de la .\n"
                "\tf. Cerrar menu.\n"
                "Ingrese una opcion: ");
        scanf(" %c", &opcion);
        switch (opcion)
        {
        case 'a':
            addNode(&stack, &node);
            printf("Ingrese un valor para el nuevo nodo: ");
            scanf(" %c", &node->data);
            break;
        case 'b':
            popNode(&stack);
            printf("\nNodo Borrado.\n");
            break;
        case 'c':
            printf("Stack completa:\n");
            printStackChar(stack);
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
    return 0;
} // main

/* Funciones */
