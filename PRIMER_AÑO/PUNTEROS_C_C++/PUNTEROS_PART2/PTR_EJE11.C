/*--- LIBRERIAS ---*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*--- DIRECTIVAS ---*/
#define TAM 10 // tamaño arrays
#define ROJO_T "\x1b[31m" // texto de color rojo
/*--- FUNCION PRINCIPAL MAIN ---*/
int main(int argc, char const *argv[])
{
    /*-- Declaracion e inicializacion de variables --*/
    int *ptrVector[TAM], // arreglo de punteros (almacena direcciones de memoria de punteros)
    vector[TAM] = {0}, ii = 0, suma = 0;
    
    srand(time(NULL)); // func de numeros aleatorios
    
    for ( ii = 0; ii < TAM; ii++)
    {
        vector[ii] = rand()%100; // carga automatica
        // scanf("%d", (vector+ii)); // carga manual
        ptrVector[ii] = (vector+ii); /* el elemento ii del arreglo de punteros es igual a
        la posicion de memoria del elemento ii del vector */
    } // for para carga de datos
    for ( ii = 0; ii < TAM; ii++)
    {
        suma += *(ptrVector[ii]); // suma los valores almacenados en las direcciones de memoria que almacena el array de punteros
    } // for sumador
    printf("Valores cargados:\n");
    for ( ii = 0; ii < TAM; ii++)
    {
        printf("%d\t", *(ptrVector[ii]));
    } // for para imprimir los valores a los que apuntan los punteros del array de punteros
    printf( ROJO_T "\nPromedio: %.2f\n\n\n"
            "Posiciones de memoria de los valores almacenados: ", ((float) suma/TAM)); // se castean los valores a .flotante para el promedio
    for ( ii = 0; ii < TAM; ii++)
    {
        printf("%x\t", (ptrVector[ii]));
    } // for para imrpimir las direcciones de memorias alacenadas de cada elemento
}
