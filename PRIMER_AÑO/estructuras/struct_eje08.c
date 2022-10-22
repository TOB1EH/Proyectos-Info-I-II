/* Ejercicio 8. Crear un programa que pida al usuario los nombres, edades y
alturas de 10 jugadores. Posteriormente le presentará un menú que le permita:
    a. Listar los nombres de los jugadores
    b. Listar las alturas de los jugadores
    c. Listar las edades de los jugadores
Utilice funciones.  */

/* Librerias */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* Directivas */
#define TAM_MAX 10 // max de jugadores
#define TAM_STRINGS 25 // max tam para cadena de caracteres

/* Estructuras */
struct Jugadores
{
    int age;
    char name[TAM_STRINGS];
    float tall;
};
/* Declaracion  de tipo definido por el usuario */
typedef struct Jugadores jugadores_t; // sinonimo de struct Jugadores = jugadores_t 

/* Prototipo de Funciones */
void checkMemory (jugadores_t **ptr); // verificar si hay memoria suficinete para el malloc
void load (jugadores_t **ptr, int *nJugadores); // carga de datos/jugadores
void names (jugadores_t *ptr, int *nJugadores); // listar nombres de los jugadores
void alturas (jugadores_t *ptr, int *nJugadores); // listar alturas de los jugadores
void ages (jugadores_t *ptr, int *nJugadores); // listar edades de los jugadores

/* Funcion principal main */
int main(int argc, char const *argv[])
{
    /* Declaracion e inicilizacion de variables */
    jugadores_t *jugadores = NULL;
    int cantJugadores = 0, stopWhile = 0;
    char opcion = 0;

    do // ciclo do-while 1
    {
        printf("Ingrese la cantidad de jugadores (MAX 10): ");
        scanf("%d", &cantJugadores);
        if (cantJugadores > TAM_MAX) // verificar que la cantidad de jugadores este dentro del maximo permitido
            printf("\nSupero el maximo, intente nuevamente\n");
        else
        {
            stopWhile = 1; // termina el bucle do-while
        }
    } while (stopWhile == 0);
    /* Redimensionar tamanio que ocupa en memoria para almacenar cada jugador */
    jugadores = (jugadores_t *)malloc(cantJugadores*sizeof(jugadores_t));
    checkMemory(&jugadores); // invocacion funcion para verificar la disponibilidad de memoria
    load(&jugadores, &cantJugadores); // invocacion funcion para 'carga de jugadores'

    /* Menu de Opciones */
    do // ciclo do-while 2
    {
        printf("\nMenu de opciones:\n"
                "a. Listar los nombres de los jugadores.\n"
                "b. Listar las alturas de los jugadores.\n"
                "c. Listar las edades de los jugadores.\n"
                "d. Cerrar menu.\n"
                "Ingrese una opcion: ");
        scanf(" %c", &opcion);
        opcion = tolower(opcion); // transforma cualquiee letra a minuscula
        switch (opcion)
        {
        case 'a':
            names(jugadores, &cantJugadores); // invocacion funcion 'names'
            break;
        case 'b':
            alturas(jugadores, &cantJugadores); // invocacion funcion 'alturas' 
            break;
        case 'c':
            ages(jugadores, &cantJugadores); // invocacion funcion 'ages'
            break;
        case 'd':
            printf("\nCerrando Menu...\n");
            stopWhile = 0;
            break;
        default:
            printf("\nOpcion invalida. Intente nuevamente.\n");
            break;
        }
    } while (stopWhile == 1);
    
    /* Liberar memoria */
    free(jugadores);
    return 0;
} // main

/* Funciones */
void checkMemory (jugadores_t **ptr)
{
    /* Verificar si hay memoria suficiente */ 
    if (*ptr == NULL)
    {
        printf("\nMemoria insuficiente\n");
        exit(0); // si no hay memoria finaliza el progrma
    }
} // checkMemory
void load (jugadores_t **ptr, int *nJugadores)
{
    int ii = 0;
    for (ii = 0; ii < *nJugadores; ii++)
    {
        printf("\nIngrese el nombre del jugador n°%d: ", ii+1);
        setbuf(stdin, NULL); // libera el buffer
        fgets((*ptr+ii)->name, TAM_STRINGS+1, stdin);
        printf("Ingrese su edad: ");
        scanf("%d", &(*ptr+ii)->age);
        printf("Ingrese su altura: ");
        scanf("%f", &(*ptr+ii)->tall);
    }
} // load
void names (jugadores_t *ptr, int *nJugadores)
{
    int ii = 0;
    printf("\nLista de nombres de los jugadores:\n");
    for (ii = 0; ii < *nJugadores; ii++)
    {
        printf("%d. %s", ii+1, (ptr+ii)->name);
    }
    printf("\n");
} // names
void alturas (jugadores_t *ptr, int *nJugadores)
{
    int ii = 0;
    printf("\nAlturas de los Jugadores respectivamente:\n");
    for (ii = 0; ii < *nJugadores; ii++)
    {
        printf("%d. %.2f\n", ii+1, (ptr+ii)->tall);
    }
    printf("\n");
} // alturas
void ages (jugadores_t *ptr, int *nJugadores)
{
    int ii = 0;
    printf("\nEdades de los jugadores respectivamente:\n");
    for (ii = 0; ii < *nJugadores; ii++)
    {
        printf("%d. %d\n", ii+1, (ptr+ii)->age);
    }
    printf("\n");
} // ages