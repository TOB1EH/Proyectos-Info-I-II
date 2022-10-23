/* Ejercicio 1: Crear un programa en la cual se solicite al usuario
el ingreso de 5 valores numericos y luego muestre la lista.  */

/* Librerias */
#include <stdio.h>
#include <stdlib.h>
/* Directivas */
#define TAM_LIST 5
/* Estructuras/listas */
struct Lista
{
    int iden;
    float data;
    struct Lista* next;
};
/* Funcion principal main */
int main(int argc, char const *argv[])
{
    /* Declaracion e inicializacion de variables */
    int ii = 0;
    float dato = 0;
    struct Lista *head = NULL; // primer nodo de la lista
    struct Lista *newNode = NULL; // nuevo nodo
    struct Lista *tempo = NULL; // variable temporal para no perder la direccion de memoria del head
    /* Bucle for para recorrer y cargar la lista */
    for (ii = 0; ii < TAM_LIST; ii++)
    {
        /* creacion de nuevo nodo */
        newNode = (struct Lista* ) malloc(sizeof(struct Lista));
        if (newNode == NULL)
        {
            printf("\nNo hay memoria suficiente\n");
            exit(0);
        }
        /* Carga de datos en Nodos */
        printf("Ingrese el %d° numero de la lista: ", ii+1);
        scanf("%f", &dato);
        newNode->data = dato;
        /* Nodo ingresado sera el ultimo en la lista*/
        newNode->next = NULL;
        /* Si la lista esta vacia, el nuevo nodo es el primero de la lista */
        if (head == NULL) head = newNode;
        else
        {
            /* Si no, buscamos cual es el ultimo */
            tempo = head;
            while (tempo->next != NULL)
            {
                tempo = tempo->next; // tempo ahora guarda la direccion de memoria del siguiente nodo de la lista
            }
            /* el que es el ultimo, ahora apunta al nuevo nodo */
            tempo->next = newNode;
        }        
    }
    /* Imprimir la lista */
    tempo = head;
    printf("\nLista de numeros ingresados:\n");
    while (tempo != NULL)
    {
        printf("%.2f\n", tempo->data);
        tempo = tempo->next; // tempo ahora guarda la direccion de memoria del siguiente nodo de la lista
    }
    printf("\n");
    /* Liberar Memoria */
    while (head != NULL)
    {
        tempo = head;
        head = head->next;
        free(tempo);
    }
    return 0;
}
