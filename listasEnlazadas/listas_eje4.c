/* Ejercicio 4. Crear una lista con 10 letras y luego mostrar solo las vocales */

/* Librerias */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Diretivas */
#define TAM_LIST 10 // tamanio de la lista

/* Listas/estructuras */
struct Lista
{
    int id;
    int data;
    struct Lista *next;
};

/* Prototipo de Funciones */
void addend (struct Lista **head, struct Lista **newNode);
void print (struct Lista *head);
void mostrarVocales (struct Lista *head);

/* Funcion principal main */
int main(int argc, char const *argv[])
{
    srand(time(NULL)); // funcion de numeros aleatorios
    
    /* Declaracion e inicializacion de variables */
    int ii = 0;
    struct Lista *head = NULL;    
    struct Lista *newNode = NULL;
    struct Lista *temp = NULL;
    
    /* Carga de datos */
    for (ii = 0; ii < TAM_LIST; ii++)
    {
        addend(&head, &newNode); // funcion para cargar un nodo al final
        newNode->data = rand()%26+65; // carga de letras aleatorias
    }
    
    /* Imprimir datos */
    printf("Valores totales generados:\t");
    print(head); // funcion para imprimir todos los valores generados
    
    /* Imprimir solo las vocales */
    temp = head;
    printf("Vocales encontradas:\t");
    while (temp != NULL)
    {
        if (temp->data=='A' || temp->data=='E' || temp->data=='I' || temp->data=='O' || temp->data=='U')
        {
            printf("%c\t", temp->data);
        }
        temp = temp->next;
    }
    printf("\n");

    return 0;
}

void addend (struct Lista **head, struct Lista **newNode)
{
    struct Lista *temp = NULL;    

    /* Crear nuevo Nodo en la lista */
    *newNode = (struct Lista *)malloc(sizeof(struct Lista));
    if (*newNode == NULL)
    {
        printf("\nNo hay memoria suficiente\n");
        exit(0); // si no hay memoria suficiente finaliza el programa
    }
    /* El nuevo nodo es el ultimo en la lista */
    (*newNode)->next = NULL;
    /* Si la lista esta vacia el nuevo nodo es el primero en la lista */
    if (*head == NULL) *head = *newNode;
    /* Si no, buscar cual es el ultimo elemento de la lista */
    else
    {
        temp = *head; // var temporal para no perder/modificar a head
        while (temp->next != NULL) temp = temp->next;
        /* El que es el ultimo elemento de la lista ahora apunta a newNode (nuevo ultimo) */
        temp->next = *newNode;
    }
}
void print (struct Lista *head)
{
    struct Lista *temp = NULL;
    temp = head;
    while (temp != NULL)
    {
        printf("%c\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}