/* Ejercicio 2. Crear un programa en la cual cargue una cola de 5
numeros aleatoriamente (entre 1 y 10), luego los muestre y muestre
los valores pares. */

/* Librerias */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Directivas */
#define TAM_MAX 5 // tamanio max de la cola

/* Estructuras */
struct node
{
    int data; // dato
    struct node *link; // ptr al siguiente node
};
/* Declaracion  de tipo definido por el usuario */
typedef struct node node_t;

/* Prototipo de Funciones */
void push (struct node **front,struct node **back, struct node **node);
void print_int_list  (struct node *front);
void freeMemory (struct node **front);

/* Funcion principal main */
int main(int argc, char const *argv[])
{
    /* Declaracion e inicializacion de variables */
    node_t *front = NULL;
    node_t *back = NULL;
    node_t *newNode = NULL;

    srand(time(NULL));  // funcion de numeros aleatorios

    /* Creacion de nuevos nodos y carga de datos */
    for (int ii = 0; ii < TAM_MAX; ii++)
    {
        push(&front, &back, &newNode); // invocacion a la funcion push
        newNode->data = rand()%10+1; // carga de datos de los nodos
    }

    /* Imprimir Cola */
    printf("Cola de val. enteros generada aleatoriamente:\n");
    print_int_list(front);

    printf("Valores pares:\n");
    node_t *temp = front;
    while (temp != NULL)
    {
        if ((temp->data)%2 == 0)
        {
            printf("%d\t", temp->data);
        }
        temp = temp->link;
    }
    printf("\n");

    /* LIberar memoria */
    freeMemory(&front);
    return 0;
} // main

/* Funciones */
void push (struct node **front,struct node **back, struct node **node)
{
    *node = (node_t *)malloc(sizeof(node_t));
    if (node == NULL) // verifica si hay memoria suficiente
    {
        printf("\nMemoria insuficiente!\n");
        exit(0); // si no hay memmoria finaliza el programa
    }
    (*node)->link = NULL;
    /* Si la lista esta vacia, el nodo sera el primero */
    if (*back == NULL)
    {
        *back = *node;
        *front = *back;
    }
    /* Agregar el resto de nodos */
    else
    {
        /* El enlace del ultimo nodo apunta al nuevo */
        (*back)->link = *node;
        /* El nuevo nodo ahora es el ultimo */
        *back = *node;
    }
} // push
void print_int_list  (struct node *front)
{
    struct node *temp = NULL; // var temporal
    temp = front;
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->link;
    }
    printf("\n");
} // print_int_list
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