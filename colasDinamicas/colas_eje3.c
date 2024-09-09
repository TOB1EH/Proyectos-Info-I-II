/* Ejercicio 3. Crear un programa con el siguiente menu de opciones:
    Agregar un nodo a la cola. (se deben agregar 5 valores)
    Borrar el primer nodo de la cola.
    Imprimir cola.
    Tamaño de la cola
    Valor del frente de la cola */

/* Librerias */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "opcion.h"

/* Directivas */
#define TAM_MAX 5 // maximo de nodos permitidos

/* Estructuras */
struct node // Cola
{
    int data;
    struct node *link;
};
/* Declaracion  de tipo definido por el usuario */
typedef struct node node_t;

/* Prototipo de Funciones */
void push (struct node **front, struct node **back);
void load (struct node **newNode);
void printCola (struct node *front);
void pop (struct node **front, struct node **back);
void freeMemory (struct node **front);

/* Funcion principal main */
int main(int argc, char const *argv[])
{
    node_t *front = NULL;
    node_t *back = NULL;
    node_t *temp = NULL;
    int stopWhile = 0,  cantNodes = 0, count = 0;
    char opcion = 0;
    do
    {
        printf("Menu de opciones:\n"
                "a. Agregar un nodo a la cola.\n"
                "b. Borrar el primer nodo de la cola.\n"
                "c. Imprimir cola.\n"
                "d. Tamanio de la cola.\n"
                "e. Valor del frente de la cola.\n"
                "f. Cerrar menu.\n");
        opcionMenu(&opcion);
        switch (opcion)
        {
        case 'a':
            if (cantNodes < TAM_MAX)
            {
                push(&front, &back);
                cantNodes++;
            }
            else
            {
                printf("\nAlcanzo el maximo de nodos permitidos!\n");
            }
            break;
        case 'b':
            pop(&front, &back);
            break;
        case 'c':
            printf("Cola completa:\n");
            printCola(front);
            break;
        case 'd':
            temp = front;
            while (temp != NULL)
            {
                count++;
                temp = temp->link;
            }
            printf("\nTamanio de la lista: %d nodos\n", count);
            count = 0;
            break;
        case 'e':
            printf("\nPrimer valor de la Cola: %d\n", front->data);
            break;
        case 'f':
            printf("\nCerrando...\n");
            stopWhile = 1;
            break;
        default:
            printf("\nOpcion invalida. Intente nuevamente\n");
            break;
        }
    } while (stopWhile == 0);
    /* Liberar memoria */
    freeMemory(&front);
    return 0;
} // main

/* Funciones */
void push (struct node **front, struct node **back)
{
    struct node *newNode = NULL;
    newNode = (struct node *)malloc(sizeof(struct node)); // crea memoria para el nuevo nodo
    if (newNode == NULL) // si no hay memoria para crear el nodo
    {
        printf("\nNo hay memoria disponible!\n");
        exit(0); // finaliza el programa;
    }
    newNode->link = NULL;
    load(&newNode);
    /* Si la cola esta vacia, el nuevo nodo sera el primero */
    if (*back == NULL)
    {
        *back = newNode;
        *front = newNode;
    }
    /* Carga el reesto de nodos */
    else
    {
        /* El enlace del ultimo nodo apunta al nuevo nodo */
        (*back)->link = newNode;
        /* Ahora el nuevo nodo es el ultimo */
        *back = newNode;
    }
} // push
void load (struct node **newNode)
{
    /* Carga de datos en nuevo nodo */
    printf("\nIngrese un valor: ");
    scanf("%d", &(*newNode)->data);
}
void printCola (struct node *front)
{
    struct node *temp = front;
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->link;
    }
    printf("\n");
} // printCola
void pop (struct node **front, struct node **back)
{
    struct node *temp = NULL;
    /* Verificar que la lista no este vacia */
    if ((*back == *front) && (*back == NULL))
        printf("\nLa cola esat vacia!\n");
    else
    {
        temp = *front;
        *front = (*front)->link;
        if (*back == temp) // si el nodo es el ultimo
            *back = (*back)->link;
        free(temp);
        printf("\nBorrado con exito\n");
    }
} // pop
void freeMemory (struct node **front)
{
    struct node *temp = NULL;
    while (*front != NULL)
    {
        temp = *front;
        *front = (*front)->link;
        free(temp);
    }
} // freeMemory