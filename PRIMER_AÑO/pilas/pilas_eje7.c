/* 7. Desarrollo un programa que cree una pila de vehiculos que pasan por un peaje, en
la cual se deben registrar patente, marca, color, cantidad de ejes, precio, direccion.
El precio es segun la cantidad de ejes. (1 eje = $100, 2 ejes = $150, 3 ejes = $200 y
4 ejes o mas $300). La direccion es a la que se dirige el vehiculo, en este caso puede
ser de Norte a Sur o Sur a Norte. Luego, arme un menu de opciones que muestre lo siguiente:
    Agregar un vehiculo a la pila
    Borrar el último nodo de la pila.
    Mostrar todos los vehiculos.
    Mostrar los vehiculos por dirección
    Mostrar los vehiculos por ejes.  */

/* Librerias */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* Directivas */
#define TAM_STRINGS 25

/* Estructuras */
struct node
{
    char patente[TAM_STRINGS];
    char marca[TAM_STRINGS];
    int ejes;
    float precio;
    int direccion;
    struct node *next;
};
/* Declaracion  de tipo definido por el usuario */
typedef struct node stack_t;

/* Prototipo de Funciones */
void addNode(stack_t **stack, stack_t **node);
void popNode(stack_t **stack);
void printStack(stack_t *stack);

/* Funcion principal main */
int main(int argc, char const *argv[])
{
    /* Declaracion e inicializacion de variables */
    stack_t *stack = NULL;
    stack_t *node = NULL;
    stack_t *temp = NULL;
    char opcion = 0;

    /* Ciclo para menu de opciones */
    do
    {
        printf("Menu de opciones:\n"
                "a. Agregar un vehiculo a la pila.\n"
                "b. Borrar el último nodo de la pila.\n"
                "c. Mostrar todos los vehiculos.\n"
                "d. Mostrar los vehiculos por dirección.\n"
                "e. Mostrar los vehiculos por ejes.\n"
                "f. Cerrar menu.\n"
                "Ingrese una opcion: ");
        scanf(" %c", &opcion);
        opcion = tolower(opcion);
        switch (opcion)
        {
        case 'a':
            /* code */
            break;
        default:
            break;
        }
    } while (opcion != 'f');
    /* Liberar memoria */
    while (stack != NULL)
    {
        temp = stack;
        stack = stack->next;
        free(temp);
    }
    return 0;
} // main

/* Funciones */
void addNode(stack_t **stack, stack_t **node)
{
    *node = (stack_t *)malloc(sizeof(stack_t));
    if (*node == NULL)
    {
        printf("\nMemoria insuficiente.\n");
        exit(1);
    }
}