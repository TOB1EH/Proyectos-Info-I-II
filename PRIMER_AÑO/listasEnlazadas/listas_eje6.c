/* Ejercicio 6. Crear un programa en la cual cargue una lista de 5 numeros aleatoriamente
(entre 1 y 10), luego muestre todos los valores. Finalmente borre un valor y
vuelva a mostrar la lista resultante. */

/* Librerias */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Directivas */
#define TAM_MAX 5

/* Estructuras */
struct lista
{
    int id;
    int data;
    struct lista *next;
};

typedef struct lista lista_t;

/* Prototipo de Funciones */
void addend (struct lista **head, struct lista **newNode);
void printList (struct lista *head);
void deleteNode (struct lista **head);
void freeMemory (struct lista **head);

/* Funcion principal main */
int main(int argc, char const *argv[])
{
    /* Declaracion e inicilizacion de variables */
    lista_t *head = NULL;
    lista_t *newNode = NULL;
    lista_t *temp = NULL;
    int ii = 0;
    
    srand(time(NULL)); // funcion de numeros de aleatorios
    
    for (ii = 0; ii < TAM_MAX; ii++)
    {
        addend(&head, &newNode); // creacion de nuevos nodos
        /* carga de datos */
        newNode->data = rand()%100; // asigna num. aleatorios del 1-100
    }
    
    printf("Valores:\n");
    printList(head);
    
    deleteNode(&head); // eliminar un nodo/dato

    printf("Lista Resultante:\n");
    printList(head);
    
    freeMemory(&head); // liberar memoria
    return 0;
} // main

/* Funciones */
void addend (struct lista **head, struct lista **newNode)
{
    struct lista *temp = NULL;
    /* Crear nuevo nodo en la lista */
    *newNode = (struct lista *)malloc(sizeof(struct lista));
    if (*newNode == NULL) // verifica si hay memoria suficiente
    {
        printf("\nMemora insuficiente.\n");
        exit(0); // finaliza el programa 
    }
    /* El nuevo nodo sera el ultimo en agregarse en la lista */
    (*newNode)->next = NULL;
    /* Si la lista esta vacia, el nuevo nodo sera el primero */
    if (*head  == NULL)
        *head = *newNode;
    /* Sino, buscar el ultimo elemento en la lista */
    else
    {
        temp = *head; // var temporal para no perder/modificar a head
        while (temp->next != NULL)
            temp = temp->next; // temp ahora almacena el siguinte nodo
        /* El que es el ultimo elemento de la lista ahora apunta a newNode (nuevo ultimo) */
        temp->next = *newNode; // el que era el ultimo nodo ahora apunta al nuevo ultimo.
    }
} // addend
void printList (struct lista *head)
{
    struct lista *temp = NULL;
    /* Impresion de datos */
    temp = head; // var temporal para no perder/modificar a head
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next; // temp almacena la memoria del siguiente nodo
    }
    printf("\n");
} // printList
void deleteNode (struct lista **head)
{
    struct lista *temp = NULL;
    struct lista *prev = NULL;
    struct lista *current = NULL;
    int dato = 0;
    
    if (*head == NULL)
        printf("\nLa lista esta vacia.\n");
    else
    {
        printf("Ingrese el dato a borrar: ");
        scanf("%d", &dato);
        /* si el dato a borrar es el primer nodo */
        if (dato == (*head)->data)
        {
            temp = *head;
            *head = (*head)->next;
            free(temp); // libera el dato almacenado en la posicion de memoria de head
        }
        else // si el dato no es el primer nodo
        {
            prev = *head;
            current = (*head)->next;
            while (current != NULL && current->data != dato)
            {
                prev = current;
                current = current->next;
            }
            if (current != NULL)
            {
                temp = current;
                prev->next = current->next;
                free(temp);
            }
        }
    }
} // deleteNode
void freeMemory (struct lista **head)
{
    /* Liberar Memoria */
    struct lista *temp = NULL;
    while (*head != NULL)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}// freeeMemory