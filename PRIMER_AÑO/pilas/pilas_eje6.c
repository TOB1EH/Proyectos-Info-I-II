/* 6. Elaborar un sistema de stock, en la cual posee una pila de productos con los
siguientes atributos: codigo, nombre, cantidad, precio lista. Desarrollar las siguientes
funciones:
    Agregar un nuevo producto.
    Borrar el último nodo de la pila.
    Mostrar el stock.
    Descontar stock.
    Reponer stock. */

/* Librerias */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* Directivas */
#define TAM_STRINGS 25

/* Estructuras */
struct node
{
    long int codigo;
    char nombre[TAM_STRINGS];
    int cantidad;
    float precioLista;
    struct node *next;
};

/* Declaracion  de tipo definido por el usuario */
typedef struct node stack_t;

/* Prototipo de Funciones */
void addNode(stack_t **stack, stack_t **node);
void popNode(stack_t **stack);
void printStack(stack_t *stack);
void descontarStock(stack_t **stack);
void reponerStock(stack_t **stack);

/* Funcion principal main */
int main(int argc, char const *argv[])
{
    /* Declaracion e inicializacion de variables */
    stack_t *stack = NULL;
    stack_t *node = NULL;
    stack_t *temp = NULL;
    char opcion = 0;

    do // ciclo menu de opciones
    {
        printf("Menu de opciones:\n"
                "a. Agregar un nuevo producto.\n"
                "b. Borrar el ultimo nodo de la pila.\n"
                "c. Mostrar el stock.\n"
                "d. Descontar stock.\n"
                "e. Reponer stock.\n"
                "f. Cerrar menu.\n"
                "Ingrese una opcion: ");
        scanf(" %c", &opcion);
        opcion = tolower(opcion);
        switch (opcion)
        {
        case 'a':
            addNode(&stack, &node);
            printf("\nIngrese el codigo de producto: ");
            scanf("%li", &node->codigo);
            printf("\nIngrese el nombre: ");
            setbuf(stdin, NULL);
            fgets(node->nombre, TAM_STRINGS, stdin);
            printf("\nIngrese la cantidad/stock: ");
            scanf("%d", &node->cantidad);
            printf("\nIngrese el precio de lista: ");
            scanf("%f", &node->precioLista);
            break;
        case 'b':
            popNode(&stack);
            printf("\nNodo Borrado.\n");
            break;
        case 'c':
            printf("\nStock de productos:\n");
            printStack(stack);
            break;
        case 'f':
            printf("\nCerrando...\n");
        default:
            printf("\nOpcion Invalida. Intente nuevamente.\n");
            break;
        }
    } while (opcion != 'f');
    /* Liberar Memoria */
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
    /* Crear memoria para el nuevo nodo */
    *node = (stack_t *)malloc(sizeof(stack_t));
    if (*node == NULL) // vericar si hay suficiente memoria
    {
        printf("\nNo hay memoria!\n");
        exit(1); // finalizar el programa
    }
    /* El nuevo nodo apunta al que es el ultimo en el stack */
    (*node)->next = *stack;
    /* Ahora eñ nuevo es el ultimo */
    *stack = *node;
} // addNode
void popNode(stack_t **stack)
{
    stack_t *temp = NULL;
    temp = *stack;
    *stack = temp->next;
    free(temp);
} // popNode
void printStack(stack_t *stack)
{
    stack_t *temp = NULL;
    temp = stack;
    while (temp != NULL)
    {
        printf("\tCodigo: %ld\n"
                "\tNombre: %s"
                "\tStock: %d\n"
                "\tPrecio: $%.2f\n\n",
                temp->codigo,
                temp->nombre,
                temp->cantidad,
                temp->precioLista);
        temp = temp->next;
    }
} // printStack