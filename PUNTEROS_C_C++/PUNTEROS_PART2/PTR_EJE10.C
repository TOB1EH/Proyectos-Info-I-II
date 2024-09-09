/*--- LIBRERIAS ---*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*--- DIRECTIVAS ---*/
#define TAM 10

/*--- PROTOTIPO DE FUNCIONES ---*/
void load (int *); // func para cargar los datos del array
void print (int *); // func para imprimir los datos
void odd (int *); // func. para posiciones impares
void pairs (int *); // func para posiciones pares

/*--- FUNCION PRINCIPAL MAIN ---*/
int main(int argc, char const *argv[])
{
    /* Declaracion e inicializacion de varibles */
    int values[TAM] = {0};
    int *pointer = values;
    
    void (*ptrAFunc) (int *); // puntero a funcion, no retorna valor y recibe un puntero de tipo char
    ptrAFunc = load; // asigna la direccion de mem. de la func "load" al puntero "ptrAFunc"
    (*ptrAFunc)(pointer); // invocacion de la funcion apuntada
    ptrAFunc = print; // idem f. "load"
    (*ptrAFunc)(pointer); // invocacion de la funcion apuntada
    ptrAFunc = odd; // idem f. "load"
    (*ptrAFunc)(pointer);// invocacion de la funcion apuntada
    ptrAFunc = pairs; // idem f. "load"
    (*ptrAFunc)(pointer); // invocacion de la funcion apuntada
    return 0;
}

/*--- FUNCIONES ---*/
void load (int *ptr)
{
    int ii = 0;
    srand(time(NULL)); // funcion de numeros aleatorios
    for (ii = 0; ii < TAM; ii++)
    {
        *(ptr+ii) = rand()%100; // carga automatica de valores aleatorios
        // scanf("%d", (ptr+ii)); carga manual
    }
} // function load
void print (int *ptr)
{
    int ii = 0; // acumulador/contador ii
    printf("Array: ");
    for (ii = 0; ii < TAM; ii++)
    {
        printf("%d\t", *(ptr+ii));
    }
    printf("\n");
} // function print
void odd (int *ptr)
{
    int ii = 0;
    printf("\nValores ubicados en posiciones impares del array: ");
    for (ii = 0; ii < TAM; ii++)
    {
        if (ii%2 != 0) printf("%d\t", *(ptr+ii));
    } // for
    printf("\n");
} // fuction odd
void pairs (int *ptr)
{
    int ii = 0;
    printf("\nValores ubicados en posiciones pares del array: ");
    for ( ii = 0; ii < TAM; ii++)
    {
        if (ii%2 == 0) printf("%d\t", *(ptr+ii));
    }
    printf("\n\n");
} // function pairs