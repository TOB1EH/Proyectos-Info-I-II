/* Ejercicio 5. Crear una lista con 10 letras y luego mostrar solo las consonantes.  */

/* Librerias */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Directivas */
#define TAM_MAX 10 // cantidad de letras

/* Estructuras */
struct lista
{
    int id; // identificador de nodo
    int data; // dato que almacena
    struct lista *next; // puntero al siguiente
};
typedef struct lista letras_t;

/* Prototipo de Funciones */
void addend (struct lista **head, struct lista **newNode);
void printList (struct lista *head);
void freeMemory (struct lista **head);

/* Funcion principal main */
int main(int argc, char const *argv[])
{
    /* Declaracion e inicializacion de variables */
    letras_t *head = NULL;
    letras_t *temp = NULL;
    letras_t *newNode = NULL;
    int ii = 0;

    srand(time(NULL)); // funcion de numeros aleatorios
    for (ii = 0; ii < TAM_MAX; ii++)
    {
        addend(&head, &newNode); // invocacion de la funcion para crear nodos al final
        /* Cargar valores de la variable interna del nuevo nodo */
        newNode->data = rand()%26+65; // carga de letras aleatorias
    }
    
    /* Imprimir valores */
    printf("Lista completa:\n");
    printList(head);
    
    /* Imprimir solo las consonantes */
    temp = head;
    printf("Consonantes encontradas:\n");
    while (temp != NULL)
    {
        if (temp->data != 65 && temp->data != 69 && temp->data != 73 && temp->data != 79 && temp->data != 85)
            printf("%c\t", temp->data);
        temp = temp->next;
    }
    printf("\n");

    /* Liberar Memoria */
    freeMemory(&head);
    return 0;
} // main

/* Funciones */
void addend (struct lista **head, struct lista **newNode)
{
    struct lista *temp = NULL;

    /* Crear nuevo Nodo en la lista */
    *newNode = (struct lista *)malloc(sizeof(struct lista));   
    if (*newNode == NULL) // verifica si hay memoria suficiente
    {
        printf("\nMemoria insuficiente\n");
        exit(0); // finaliza el programa
    }
    /* El nuevo nodo es el ultimo de la lista */
    (*newNode)->next = NULL;
    /* Si la lista esta vacia el nuevo nodo es el primero de la lista */
    if (*head == NULL)
        *head = *newNode;
    /* sino, buscar cual es el ultimo elemento de la lista */
    else
    {
        temp = *head; // var temporal para no perder/modificar a head
        while (temp->next != NULL)
            temp = temp->next;
        /* El que es el ultimo elemento de la lista ahora apunta a newNode (nuevo ultimo) */
        temp->next = *newNode;
    }
} // addend
void printList (struct lista *head)
{
    struct lista *temp = NULL;  
    temp = head; // var temporal para no perder/modificar a head
    while (temp != NULL)
    {
        printf("%c\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
} // printList
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