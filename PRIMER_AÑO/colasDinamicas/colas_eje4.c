/* Ejercicio 4. Crear un programa con el siguiente menu de opciones:
    Agregar un nodo a la cola.
    Borrar el primer nodo de la cola.
    Imprimir cola.
    Cantidad de nodos en la cola.
    Cantidades de letras mayusculas y minusculas en la cola.
El usuario cargará la cola con letras mayusculas o minusculas. */

/* Librerias */
#include <stdio.h>
#include <stdlib.h>
#include "opcion.h"

/* Directivas */
#define RESET_COLOR "\x1b[0m"
#define ROJO_T "\x1b[31m"

/* Estructuras */
struct node // Cola
{
    char data;
    struct node *link;
};
/* Declaracion  de tipo definido por el usuario */
typedef struct node node_t;

/* Prototipo de Funciones */
void push (node_t **front, node_t **back); // agrega un nuevo nodo a la cola
void pop (node_t **front, node_t **back); // elimina el primer nodo de la cola
void printCola (node_t *front); // imprime la cola completa
void cantNodes (node_t *front); // cuenmta la cantidad de nodos
void cantMayusYMinus (node_t *front); // cuenta la cantidad de mayusculas y minusculas en la cola

/* Funcion principal main */
int main(int argc, char const *argv[])
{
    /* Declaracion e inicializacion de variables */
    node_t *front = NULL;
    node_t *back = NULL;
    int stopWhile = 0;
    char opcion = 0;

    do // Menu de opciones
    {
        printf("Menu de opciones:\n"
                "a. Agregar un nodo a la cola.\n"
                "b. Borrar el primer nodo de la cola.\n"
                "c. Imprimir cola.\n"
                "d. Cantidad de nodos en la cola.\n"
                "e. Cantidades de letras mayusculas y minusculas en la cola.\n"
                "f. Cerrar menu.\n");
        opcionMenu(&opcion);
        switch (opcion)
        {
        case 'a':
            push(&front, &back);
            break;
        case 'b':
            pop(&front, &back);
            break;
        case 'c':
            printf(ROJO_T"Cola completa:\t"RESET_COLOR);
            printCola(front);
            break;
        case 'd':
            cantNodes(front);
            break;
        case 'e':
            cantMayusYMinus(front);
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

    return 0;
} // main

/* Funciones */
void push (node_t **front, node_t **back)
{
    node_t *newNode = NULL;
    newNode = (node_t *)malloc(sizeof(node_t));
    if (newNode == NULL) // si hay memoria suficiente para crear el nodo
    {
        printf("\nNo hay memoria suficiente!\n");
        exit(0); // finaliza el programa
    }
    newNode->link = NULL;
    /* Carga de datos */
    printf("\nIngrese una letra: ");
    scanf(" %c", &newNode->data);
    /* Si la cola esta vacia, el nuevo nodo es el primero */
    if (*back == NULL)
    {
        *back = newNode;
        *front = *back;
    }
    /* Carga del resto de nodos */
    else
    {
        /* El ultimo nodo se enlaza con el nuevo */
        (*back)->link = newNode;
        /* Ahora el nuevo es el ultimo nodo */
        *back = newNode;
    }
} // push
void pop (node_t **front, node_t **back)
{
    node_t *temp = NULL;
    if ((*front == *back) && (*back == NULL))
        printf("\nLa cola esta vacia!\n");
    else // sino, borrar el primer nodo
    {
        temp = *front;
        *front = (*front)->link;
        if (*back == temp)
            *back = (*back)->link;
        free(temp);
    }
} // pop
void printCola (node_t *front)
{
    node_t *temp = NULL;
    temp = front;
    while (temp != NULL) // recorrer la cola cola hasta el final
    {
        printf(ROJO_T"%c\t", temp->data);
        temp = temp->link;
    }
    printf(RESET_COLOR"\n");
} // printCola
void cantNodes (node_t *front)
{
    /* Variables */
    node_t *temp = NULL;
    int count = 0;

    /* Contador */
    temp = front;
    while (temp != NULL)
    {
        count++;
        temp = temp->link;
    }
    printf(ROJO_T"\nCantidad de nodos: %d\n"RESET_COLOR, count);
} // countNodes
void cantMayusYMinus (node_t *front)
{
    /* Variables */
    node_t *temp = NULL;
    int countMayus = 0, countMinus = 0;
    /* Contar cantidad de minusculas y mayusculas */
    temp = front;
    while (temp != NULL)
    {
        countMinus++;
        if ((temp->data > 64)&&(temp->data < 91)) // si es una mayuscula
            countMayus++; // contador de mayusculas +1
        temp = temp->link; // temp igual al siguiente nodo
    }
    countMinus = (countMinus-countMayus); // cant de miculas es igual al total menos la cant. de mayusculas
    printf(ROJO_T"Cant. Mayusculas: %d\n"
            "Cant. Minusculas: %d\n"RESET_COLOR,
            countMayus, countMinus);
} // countMayusYMinus