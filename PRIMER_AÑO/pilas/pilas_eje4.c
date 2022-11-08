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
#include <ctype.h>
#include "pila_int.h"
#include "functions_stacks.h"

/* Declaracion  de tipo definido por el usuario */
typedef struct node stack_t;

/* Funcion principal main */
int main(int argc, char const *argv[])
{
    /* Declaracion e inicializacion de variables */
    stack_t *stack = NULL;
    stack_t *node = NULL;
    stack_t *temp = NULL;
    char opcion = 0, aux = 0;
    int countMayus = 0, countMinus = 0;
    do
    {
        printf("Menu para crear una Stack de letras:\n"
                "\ta. Agregar un nodo a la stack.\n"
                "\tb. Borrar el ultimo nodo de la stack.\n"
                "\tc. Imprimir stack.\n"
                "\td. Tamanio de la stack/cant. de nodos.\n"
                "\te. Cantidades de letras mayusculas y minusculas en la stack.\n"
                "\tf. Cerrar menu.\n"
                "Ingrese una opcion: ");
        scanf(" %c", &opcion);
        opcion = tolower(opcion); // convierte cualquier letra a minusculas
        system("cls");
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
            system("pause");
            break;
        case 'c':
            printf("Stack completa:\n");
            printStackChar(stack);
            system("pause");
            break;
        case 'd':
            printf("\nStack de %d nodos.\n", countNodes(stack));
            system("pause");
            break;
        case 'e':
            temp = stack;
            while (temp != NULL)
            {
                aux = temp->data;
                if (aux >= 65 && aux <= 90)
                    countMayus++;
                else
                {
                    countMinus++;
                }
                temp = temp->next;
            }
            printf("\nLetras Mayusculas: %d\n"
                    "Letras Minusculas: %d\n", countMayus, countMinus);
            system("pause");
            break;
        case 'f':
            printf("\nCerrando...\n");
            break;
        default:
            printf("\nOpcion invalida. Intente nueamente.\n");
            system("pause");
            break;
        }
    } while (opcion != 'f');
    freeMemory(&stack); // liberar memoria
    return 0;
} // main
