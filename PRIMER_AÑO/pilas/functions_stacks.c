#include "pila_int.h"
#include "functions_stacks.h"

void addNode (struct node **stack, struct node **node)
{
    *node = (struct node *)malloc(sizeof(struct node));
    if (*node == NULL)
    {
        printf("\nNo hay memoria disponible!\n");
        exit(0);
    }
    (*node)->next = *stack;
    *stack = *node;
    printf("exitoso");
} // addNode