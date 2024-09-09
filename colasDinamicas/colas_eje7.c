/* Ejercicio 7. Desarrollo un programa que cree una cola de vehiculos que pasan por un
peaje, en la cual se deben registrar patente, marca, color, cantidad de ejes, precio,
direccion. El precio es segun la cantidad de ejes. (1 eje = $100, 2 ejes = $150, 3
ejes = $200 y 4 ejes o mas $300). La direccion es a la que se dirige el vehiculo, en
este caso puede ser de Norte a Sur o Sur a Norte. Luego, arme un menu de opciones que
muestre lo siguiente:
    Agregar un vehiculo a la cola
    Borrar el primer nodo de la cola.
    Mostrar todos los vehiculos.
    Mostrar los vehiculos por dirección
    Mostrar los vehiculos por ejes.  */

/* Librerias */
#include <stdio.h>
#include <stdlib.h>
#include "opcion.h"

/* Directivas */
#define TAM_STRINGS 30

/* Estructuras */
struct node // Cola
{
    char marca[TAM_STRINGS];
    char color[TAM_STRINGS];
    char patente[TAM_STRINGS];
    int cantEjes;
    float precio;
    int direccion;
    struct node *link;
};
/* Declaracion  de tipo definido por el usuario */
typedef struct node node_t;

/* Prototipo de Funciones */
void push (node_t **front, node_t **back, node_t **node); // funcion para crear un nuevo nodo
void cargarVehiculo (node_t **node); // funcion para cargar los datos de un vehiculo
int direccion (void); // funcion para determinar la direccion en la que circula el vehiculo
void pop (node_t **front, node_t **back); // funcion para eliminar el primer nodo de la cola
void printCola(node_t *front); // funcion para imprimir la cola de vehiculos
void filtrarXDireccion (node_t *front); // filtra a los vehiculos por la direccion que recorren
void filtrarXEjes (node_t *front); // filtra a los vehiculos por su cant. de ejes.

/* Funcion principal main */
int main(int argc, char const *argv[])
{
    /* Declaracion e inicializacion de variables */
    node_t *front = NULL;
    node_t *back = NULL;
    node_t *newNode = NULL;
    int stopWhile = 0;
    char opcion = 0;

    do // menu de opciones
    {
        printf("Menu de opciones:\n"
                "a. Agregar un vehiculo a la cola.\n"
                "b. Borrar el primer nodo de la cola.\n"
                "c. Mostrar todos los vehiculos.\n"
                "d. Mostrar los vehiculos por direccion.\n"
                "e. Mostrar los vehiculos por ejes.\n"
                "f. Cerrar Menu.\n");
        opcionMenu(&opcion);
        switch (opcion)
        {
        case 'a':
            push(&front, &back, &newNode);
            cargarVehiculo(&newNode);
            break;
        case 'b':
            pop(&front, &back);
            break;
        case 'c':
            printf("\nLista de vehiculos:\n");
            printCola(front);
            break;
        case 'd':
            printf("\nVehiculos por Direccion:\n");
            filtrarXDireccion(front);
            break;
        case 'e':
            printf("\nVehiculos por su cant. de ejes:\n");
            filtrarXEjes(front);
            break;
        case 'f':
            printf("\nCerrando...\n");
            stopWhile = 1;
        default:
            break;
        }
    } while (stopWhile == 0);

    return 0;
} // main

/* Funciones */
void push (node_t **front, node_t **back, node_t **node)
{
    *node = (node_t *)malloc(sizeof(node_t)); // creacion de nuevo nodo
    if (*node == NULL) // si hay memoria suficiente para crear el nodo
    {
        printf("\nNo hay memoria suficiente!\n");
        exit(0); // finaliza el programa
    }
    (*node)->link = NULL;
    /* Si la cola esta vacia el nuevo nodo es el primero */
    if (*back == NULL)
    {
        *back = *node;
        *front = *back;
    }
    else /* Cargar el resto de nodos */
    {
        /* El ultimo nodo de la cola se enlaza al nuevo nodo */
        (*back)->link = *node;
        /* El nuevo nodo ahora es el ultimo de la cola */
        *back = *node;
    }
} // push
void cargarVehiculo (node_t **node)
{
    /* variables */
    char opcion = 0;
    int stopWhile = 0;

    printf("Marca del Vehiculo: ");
    setbuf(stdin, NULL); // libera el buffer
    fgets((*node)->marca, TAM_STRINGS, stdin);
    printf("Color del vehiculo: ");
    fgets((*node)->color, TAM_STRINGS, stdin);
    printf("Patente: ");
    fgets((*node)->patente, TAM_STRINGS, stdin);
    do
    {
        printf("Cant. de ejes:\n"
                "1. Un eje.\n"
                "2. Dos ejes.\n"
                "3. Tres ejes.\n"
                "4. Cuatro ejes\n"
                "Opcion: ");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            (*node)->cantEjes = opcion;
            (*node)->precio = 100;
            (*node)->direccion = direccion();
            stopWhile = 1;
            break;
        case 2:
            (*node)->cantEjes = opcion;
            (*node)->precio = 150;
            (*node)->direccion = direccion();
            stopWhile = 1;
            break;
        case 3:
            (*node)->cantEjes = opcion;
            (*node)->precio = 200;
            (*node)->direccion = direccion();
            stopWhile = 1;
            break;
        case 4:
            (*node)->cantEjes = opcion;
            (*node)->precio = 300;
            (*node)->direccion = direccion();
            stopWhile = 1;
            break;
        default:
            printf("\nCaracteristica invalida.\n");
            break;
        }
    } while (stopWhile == 0);
} // cargarVehiculo
int direccion (void)
{
    /* Variables */
    int opcion, stopWhile = 0;
    do // menu de direccion
    {
        printf("Direccion:\n"
                "1. De Norte a Sur.\n"
                "2. De Sur a Norte.\n");
        scanf("%d", &opcion);
        if(opcion==1 || opcion==2)
            stopWhile = 1;
    } while (stopWhile == 0);
    return(opcion);
} // direccion
void pop (node_t **front, node_t **back)
{
    node_t *temp = NULL;
    if ((*front == *back)&&(*back == NULL))
        printf("\nLa Cola esta vacia!\n");
    else
    {
        temp = *front;
        *front = (*front)->link;
        if (*back == temp)
            *back = (*back)->link;
        free(temp);
    }
} // pop
void printCola(node_t *front)
{
    node_t *temp = NULL;
    int count = 1;
    temp = front;
    while (temp != NULL)
    {
        printf("Vehiculo %d:\n"
                "\tMarca: %s"
                "\tColor: %s"
                "\tPatente: %s"
                "\tCant. ejes: %d\n",
                count++,
                temp->marca,
                temp->color,
                temp->patente,
                temp->cantEjes);
        if (temp->direccion == 1)
            printf("\tDireccion: De Norte a Sur.\n");
        if (temp->direccion == 2)
            printf("\tDireccion: De Sur a norte.\n");
        printf("\tPrecio a pagar: $%.2f\n\n", temp->precio);
        temp = temp->link;
    }
    printf("\n");
} // printCola
void filtrarXDireccion (node_t *front)
{
    node_t *temp = NULL;

    printf("->De Norte a Sur:\n");
    temp = front;
    while (temp != NULL)
    {
        if (temp->direccion == 1)
        {
            printf("Vehiculo:\n"
                    "\tMarca: %s"
                    "\tColor: %s"
                    "\tPatente: %s"
                    "\tCant. ejes: %d\n"
                    "\tPrecio a pagar: $%.2f\n\n",
                    temp->marca,
                    temp->color,
                    temp->patente,
                    temp->cantEjes,
                    temp->precio);
        }
        temp = temp->link;
    }
    printf("->De Sur a Norte:\n");
    temp = front;
    while (temp != NULL)
    {
        if (temp->direccion == 2)
        {
            printf("Vehiculo:\n"
                    "\tMarca: %s"
                    "\tColor: %s"
                    "\tPatente: %s"
                    "\tCant. ejes: %d\n"
                    "\tPrecio a pagar: $%.2f\n\n",
                    temp->marca,
                    temp->color,
                    temp->patente,
                    temp->cantEjes,
                    temp->precio);
        }
        temp = temp->link;
    }
    printf("\n");
} // filtrarXDireccion
void filtrarXEjes (node_t *front)
{
    node_t *temp = NULL;
    temp = front;
    while (temp != NULL)
    {
        printf("Vehiculo %d:\n"
                "\tMarca: %s"
                "\tColor: %s"
                "\tPatente: %s"
                "\tCant. ejes: %d\n",
                temp->marca,
                temp->color,
                temp->patente,
                temp->cantEjes);
        if (temp->direccion == 1)
            printf("\tDireccion: De Norte a Sur.\n");
        if (temp->direccion == 2)
            printf("\tDireccion: De Sur a norte.\n");
        printf("\tPrecio a pagar: $%.2f\n\n", temp->precio);
        temp = temp->link;
    }
}