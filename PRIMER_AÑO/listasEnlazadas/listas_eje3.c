/* Ejercicio 3: Crear un programa en la cual cargue una lista de 5
numeros aleatoriamente (entre 1 y 10), luego los muestre y muestre
los valores multiples de 5. */

/* Librerias */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Estructuras */
struct Lista
{
    int data;
    struct Lista* next;
};

/* Prototipo de funciones */
void addend (struct Lista **head, int *tam_list);
void print (struct Lista *head, int *tam_list);
void freeMemory (struct Lista **head);
/* Funcion principal main */
int main(int argc, char const *argv[])
{ 
    int tam_list = 5; // DEFINIR TAMANIO DE LA LISTA
    struct Lista *head = NULL; // head o inicio de la lista
    struct Lista *temp = NULL;
    
    int *ptrValues = NULL, count = 0, ii = 0;
    ptrValues = (int *)malloc(sizeof(int));
    
    addend(&head, &tam_list);
    print(head, &tam_list);
    
    temp = head;
    while (temp != NULL)
    {
        if (temp->data %5 == 0)
        {
            count++;
            ptrValues = (int *)realloc(ptrValues, count*sizeof(int));
            if (ptrValues == NULL)
            {
                printf("\nMemoria insuficiente\n");
                exit(0);
            }
            *ptrValues = temp->data;
        }
        temp = temp->next;
    }
    printf("Valores Multiplos de 5: ");
    for (ii = 0; ii < count; ii++)
    {
        printf("%d\t", *ptrValues);
    }
    printf("\n");


    freeMemory(&head); // liberar memoria
    return 0;
}
void addend (struct Lista** head, int *tam_list)
{
    srand(time(NULL));
    int ii = 0;
    struct Lista *newNode = NULL;
    struct Lista *temp = NULL;
    for (ii = 0; ii < *tam_list; ii++)
    {
        /* Crear nuevo nodo para la lista */
        newNode = (struct Lista*)malloc(sizeof(struct Lista));
        if (newNode == NULL)
        {
            printf("\nMemoria insuficiente\n");
            exit(0); // si no hay memoria finaliza el programa
        }
        /* Carga de datos aleatorios */
        newNode->data = rand()%10+1;
        /* El nuevo nodo es el ultimo en la lista */
        newNode->next = NULL;
        /* Si la lista esta vacia el nuevo nodo es el primero en la lista */
        if (*head == NULL) *head = newNode;
        /* Si no, buscar cual es el ultimo elemento de la lista */
        else
        {
            temp = *head; // var temporal para no perder/modificar a head
            while (temp->next != NULL) temp = temp->next;
            /* El que es el ultimo elemento de la lista ahora apunta a newNode (nuevo ultimo) */
            temp->next = newNode;
        }
    }
}
void print (struct Lista *head, int *tam_list)
{
    struct Lista *temp = NULL;
    temp = head;
    printf("Lista de numeros aleatorios:\n");
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void freeMemory (struct Lista **head)
{
    struct Lista *temp = NULL;
    /* Liberar Memoria */
    while (*head != NULL)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}