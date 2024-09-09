/* Ejercicio 9. Implementar en C un programa que maneje un array de estructuras para
almacenar las fechas de cumpleaños de 20 amigos. Los datos a almacenar sobre cada
amigo son nombre, día, mes y año. El programa debe indicarnos cuántos de nuestros
amigos cumplen los años un día y mes determinados introducidos por teclado. */

/* Librerias */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* Directivas */
#define TAM_MAX 20
#define TAM_STRINGS 25

/* Estructuras */
struct Cumpleanios
{
    char nombre[TAM_STRINGS];
    int dia;
    int mes;
    int anio;
};
/* Declaracion  de tipo definido por el usuario */
typedef struct Cumpleanios cumples_t;

/* Prototipo de Funciones */
void checkMemory (cumples_t **ptr); // verificar si hay memoria suficinete para el malloc

/* Funcion principal main */
int main(int argc, char const *argv[])
{
    /* Declaracion e inicializacion de variables */
    cumples_t *listFriends = NULL;
    int cantAmigos = 0, stopWhile = 0, ii = 0;
    int dia = 0, mes = 0;
    char opcion = 0;

    do // bucle do-while
    {
        printf("Ingrese un nros enteros.\n"
                "Datos de cuantos amigos desea almacenar (MAX 20): ");
        scanf("%d", &cantAmigos);
        if (cantAmigos > TAM_MAX) // verificar que la cant no supere al maximo
            printf("\nExcede el max. Intente nuevamente\n");
        else // si no supera al max
        {
            stopWhile = 1; // detiene el bucle do-while
        }
    } while (stopWhile == 0);
    
    /* Redimension de memoria. Arreglo dinamico de estructura */
    listFriends = (cumples_t *)malloc(cantAmigos*sizeof(cumples_t)); // malloc
    checkMemory(&listFriends); // verifica si hay memoria suficiente para la redimension

    /* Carga de datos */
    for (ii = 0; ii < cantAmigos; ii++)
    {
        printf("\nAmigo %d:\n"
                "Ingrese el nombre: ", ii+1);
        setbuf(stdin, NULL); // libera el bufer
        fgets((listFriends+ii)->nombre, TAM_STRINGS+1, stdin); // fgets para ingresar strings

        printf("Ingrese la fecha de nacimiento (nros enteros):\n"
                "dia: ");
        scanf("%d", &(listFriends+ii)->dia);
        printf("mes: ");
        scanf("%d", &(listFriends+ii)->mes);
        printf("anio: ");
        scanf("%d", &(listFriends+ii)->anio);
    }

    do
    {
        printf("Buscar un cumpleanios.\n"
                "ingrese el dia (nro): ");
        scanf("%d", &dia);
        printf("ingrese el mes (nro): ");
        scanf("%d", &mes);

        if (dia == (listFriends+ii)->dia && mes == (listFriends+ii)->mes)
            printf("\n%s es quien cumple anios ese dia.\n", (listFriends+ii)->nombre);
        else
            printf("\nNo hay datos alcenados con esa fecha. Intente de nuevo\n");
        do
        {
            printf("\nDesea solicitar otra fecha?(s/n)");
            scanf(" %c", &opcion);
            opcion = tolower(opcion);
            if (opcion == 'n') exit(0);
            else
            {
                if (opcion == 's') stopWhile == 2;
                else
                    printf("\nIngrese S/n.\n");
            }
        } while (stopWhile == 1);
    } while (stopWhile == 1 || stopWhile == 2);
    
    /* Liberar memoria */
    free(listFriends);
    return 0;
} // main

/* Funciones */
void checkMemory (cumples_t **ptr)
{
    /* Verificar si hay memoria suficiente */ 
    if (*ptr == NULL)
    {
        printf("\nMemoria insuficiente\n");
        exit(0); // si no hay memoria finaliza el progrma
    }
} // checkMemory