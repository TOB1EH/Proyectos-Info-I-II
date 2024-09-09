/* Ejercicio 1. Crear un programa con el siguiente menu de opciones:
    Agregar un nodo a la cola. (se deben agregar 5 valores)
    Borrar el primer nodo de la cola.
    Imprimir cola.
    Suma de los valores de la cola. */

/* Librerias */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* Directivas */
#define TAM_MAX 5 // tamanio para el array de datos

/* Estructuras */
struct node // cola dinamica
{
    int id;
    int data[TAM_MAX];
    struct node *link;
};
/* Declaracion  de tipo definido por el usuario */
typedef struct node node_t;

/* Prototipo de Funciones */
void push (struct node **front, struct node **back); // funcion para cargar un nodo a la cola
void load (struct node **newNode); // funcion para cargar dats en un nodo
void pop (struct node **front, struct node **back); // funcion para haer pop/elimiar el primer nodo de la cola
void printFIFO (struct node *front); // funcion para imprimir la cola completa
void freeMemory (struct node **front); // funcion para liberar la memoria.

/* Funcion principal main */
int main(int argc, char const *argv[])
{
    /* Declaracion e inicializacion de variables */
    node_t *front = NULL;
    node_t *back = NULL;
    int stopWhile = 0;
    char opcion = 0;

    do // bucle repetitivo para menu de opciones
    {
        printf("Menu de opciones:\n"
                "a. Insertar un nuevo nodo de 5 elementos\n"
                "b. Borrar  el primer nodo de la cola.\n"
                "c. Imprimir cola.\n"
                "d. Cerrar menu.\n"
                "Ingrese un aopcion: ");
        scanf(" %c", &opcion);
        opcion = tolower(opcion); // convierte la letra ingresa a minuscula
        switch (opcion)
        {
        case 'a':
            push(&front, &back);
            break;
        case 'b':
            pop(&front, &back);
            break;
        case 'c':
            printFIFO(front);
            break;
        case 'd':
            printf("\nCerrando...\n");
            stopWhile = 1;
            break;
        default:
            printf("\nOpcion invalida. Intente nuevamnete.\n");
            break;
        }
    } while (stopWhile == 0);
    /* Liberar memoria */
    freeMemory(&front); // invocacion a la funcion 'freeMemory'
    return 0;
} // main

/* Funciones */
void push (struct node **front, struct node **back)
{
    struct node *newNode = NULL; // nuevo nodo para la cola
    newNode = (node_t *)malloc(sizeof(node_t));
    if (newNode == NULL) // verifica si hay memmoria suficiente
    {
        printf("\nMemoria insuficiente\n");
        exit(0); // si no hay memmoria finaliza el programa
    }
    newNode->link = NULL; // el ptr de newNode apunta a NULL
    load(&newNode); // invocacion a la funcion 'load'
    if (*back == NULL) // insersion del primer nodo
    {
        *back = newNode;
        *front = *back;
    }
    else // inserccion del resto de nodos
    {
        (*back)->link = newNode;
        *back = newNode;
    }
} // push
void load (struct node **newNode)
{
    int val = 0;
    for (int ii = 0; ii < TAM_MAX; ii++)
    {
        printf("ingrese el valor nro %d: ", ii+1);
        scanf("%d", &val);
        (*newNode)->data[ii] = val;
    }
} // load
void pop (struct node **front, struct node **back)
{
    struct node *temp = NULL; // var temporal
    if ((*front == *back) && (*back == NULL)) // verifica si la cola esta vacia
        printf("\nLa Cola esta vacia!\n");
    else // si no esta vacia:
    {
        temp = *front;
        *front = (*front)->link;
        if (*back == temp) // si la cola tiene un solo elemento
            *back = (*back)->link;
        free(temp); // libera la memoria que ocupa temp = primer nodo
    }
    printf("\nBorrado con exito\n");
} // pop
void printFIFO (struct node *front)
{
    struct node *temp = NULL; // variable temporal
    int ii = 0;
    temp = front;
    while (temp != NULL)
    {
        for (ii = 0; ii < TAM_MAX; ii++)
        {
            printf("%d\t", temp->data[ii]);
        }
        printf("\n");
        temp = temp->link;
    }
    printf("\n");
} // printFIFO
void freeMemory (struct node **front)
{
    struct node *temp = NULL; // var temporal
    while (*front != NULL)
    {
        temp = *front;
        *front = (*front)->link;
        free(temp); // libera la memoria que ocupa temp = primer nodo
    }
} // freeMemory