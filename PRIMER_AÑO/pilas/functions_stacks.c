#include <stdlib.h>
#include "pila_int.h"
#include "functions_stacks.h"

/* Funciones para Stacks */
void addNode(struct node **stack, struct node **node)
{
    /* Creando memoria */
    *node = (struct node *)malloc(sizeof(struct node));
    /* Verificacion de memoria disponible */
    if (*node == NULL)
    {
        printf("\nNo hay memoria disponible!\n");
        exit(1); // finaliza la ejecucion
    }
    /* El siguiente al nuevo nodo apunta al stackptr actual */
    (*node)->next = *stack;
    /* El nuevo nodo es el nuevo stackptr */
    *stack = *node;
    // printf("\nCreacion de noodo exitosa!\n");
} // addNode
void popNode(struct node **stack)
{
    struct node *temp = NULL;
    /* Verificamos que la stack no este vacia */
    if (*stack != NULL)
    {
        /* Asignamos en temp el stackptr actual */
        temp = *stack;
        /* Al stackptr, se asigna el valor del siguiente nodo */
        *stack = (*stack)->next;
        /* Libera memoria ocupada por el primer nodo */
        free(temp);
    }
    else
    {
        printf("\nPila Vacia\n");
    }
} // popNode
void printStackInt(struct node *stack)
{
    struct node *temp = NULL;
    /* Se comienza a recorrer desde el stackptr */
    temp = stack;
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        /* asignamos el nodo sig. de temp a temp */
        temp = temp->next;
    }
    printf("\n");
} // printStackInt
void printStackChar(struct node *stack)
{
    struct node *temp = NULL;
    /* Se comienza a recorrer desde el stackptr */
    temp = stack;
    while (temp != NULL)
    {
        printf("%c\t", temp->data);
        /* asignamos el nodo sig. de temp a temp */
        temp = temp->next;
    }
    printf("\n");
} // printStackInt
void freeMemory(struct node **stack)
{
    struct node *temp = NULL;
    while (*stack != NULL)
    {
        temp = *stack;
        *stack = (*stack)->next;
        free(temp);
    }
} // freeMemory
float addValues(struct node *stack)
{
    float total = 0;
    struct node *temp = NULL;
    /* Se comienza a recorrer desde el stackptr */
    temp = stack;
    while (temp != NULL)
    {
        /* Sumamos cada valor a la var total */
        total += temp->data;
        /* Se comienza a recorrer desde el stackptr */
        temp = temp->next;
    }
    return total;
} // addValues
int countNodes(struct node *stack)
{
    int count = 0;
    struct node *temp = stack;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}