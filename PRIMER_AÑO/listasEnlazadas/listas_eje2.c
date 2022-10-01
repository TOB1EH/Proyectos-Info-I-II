/* Ejercicio 2: Crear un programa en la cual se solicite al usuario
el ingreso de 5 valores numericos. Luego muestre la lista y calcule
el promedio de ellos.  */

/* Librerias */
#include <stdio.h>
#include <stdlib.h>
/* Directivas */
#define TAM_LIST 5
/* Estructuras/Listas */
struct Lista
{
    int data;
    struct Lista* next;
};
/* Funcion principal main */
int main(int argc, char const *argv[])
{
    /* Declaracion e inicializacion de varibles */
    int ii = 0, dato = 0, total = 0;
    struct Lista* head = NULL; // primer elemento de la lista
    struct Lista* newNode = NULL; // var para crear nuevos Nodos
    struct Lista* tempo = NULL; // variable para no trabajar/modificar/perder la direccion de memoria de head
    /* Ciclo for para navegar por la lista */
    for (ii = 0; ii < TAM_LIST; ii++)
    {
        /* Crear nuevo nodo para la lista */
        newNode = (struct Lista* ) malloc(sizeof(struct Lista));
        if (newNode == NULL)
        {
            printf("\nNo hay memoria disponible.\n");
            exit(0); // si no hay memoria finaliza la ejecucion del programa
        }
        /* Carga de datos en el nuevo Nodo */
        printf("Ingrese el %d° numero(int): ", ii+1);
        scanf("%d", &dato);
        newNode->data = dato;
        /* El nuevo nodo es el ultimo en la lista */
        newNode->next = NULL;
        /* Si la lista esta vacia, el nuevo nodo es el primer elemento de la lista */
        if (head == NULL) head = newNode;
        /* Si no, buscamos cual es el ultimo elemento de la lista*/
        else
        {
            tempo = head; // variable temporal para no modificar o perder el head (primer elemento)
            while (tempo->next != NULL)
            {
                tempo = tempo->next;
            }
            /* el que sea el ultimo, ahora apunta al nuevo nodo (pasa a ser el ultimo elemento ingresado) */
            tempo->next = newNode;
        }
    }
    /* Imprimir Lista */
    tempo = head;
    printf("\nLista de numeros ingresados:\n");
    while (tempo != NULL)
    {
        printf("%d\n", tempo->data);
        total+= tempo->data; // sumatoria de datos ingresados
        tempo = tempo->next; // tempo ahora guarda la direccion de memoria del siguiente nodo de la lista
    }
    printf("\nPromedio: %.2f\n", ((float) total/TAM_LIST));
    /* Liberar Memoria */
    while (head != NULL)
    {
        tempo = head;
        head = head->next;
        free(tempo);
    }
    return 0;
}
