#ifndef FUNCTIONS_STACKS_H
#define FUNCTIONS_STACKS_H
#include "pila_int.h"

/* Lista de Funciones para Pilas */
void addNode(struct node **stack, struct node **node); // funcion para crear un nuevo nodo de Stack
void popNode(struct node **stack); // funcion para eliminar el ultimo nodo de la pila
void printStackInt(struct node *stack); // funcion para imprmir una Stack de enteros
void printStackChar(struct node *stack); // funcion para imprimir una Stack de caracteres
void freeMemory(struct node **stack); // libera la memoria creada por la lista
float addValues(struct node *stack); // sumar los valores de la Stack

#include "functions_stacks.c"
#endif