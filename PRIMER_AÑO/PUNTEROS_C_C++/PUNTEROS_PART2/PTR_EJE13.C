/*--- LIBRERIAS ---*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*--- DIRECTIVAS ---*/
#define TAM 5 // tam del arreglo
#define ROJO_T "\x1b[31m"
#define AZUL_T "\x1b[34m"
#define RESET_C "\x1b[0m"

/*--- PROTOTIPOS DE FUNCIONES ---*/
void load (int *);
void valMax (int *);
void valMin (int *);
void sumatoria (int *);
void print (int *);

/*--- FUNCION PRINCIPAL MAIN ---*/
int main(int argc, char const *argv[])
{
    /* Declaracion e inicializacion de vriables y punteros */
    int vector[TAM] = {0}, *ptr = vector, ii = 0;
    void (*ptrAFunc)(int *); // funcion a puntero

    ptrAFunc = load; // asigna la direcc. memoria de la funcion "load" al puntero
    (*ptrAFunc)(ptr); // invocacion de la funcion
    
    ptrAFunc = valMax; // asigna direcc. mem de la funcion "valMax" al puntero
    (*ptrAFunc)(ptr); // invocacion de la funcion "valMax"
 
    ptrAFunc = valMin; // asigna direcc. mem de la funcion "valMin" al puntero
    (*ptrAFunc)(ptr); // invocacion de la funcion "valMin"

    ptrAFunc = sumatoria; // asigna direcc. mem de la funcion "sumatoria" al puntero
    (*ptrAFunc)(ptr); // invocacion de la funcion "sumatoria"

    ptrAFunc = print; // asigna direcc. mem de la funcion "print" al puntero
    (*ptrAFunc)(ptr); // invocacion de la funcion "print"
    return 0;
}
 /*--- FUNCIONES ---*/
void load (int *ptr)
{
    int ii = 0;
    srand(time(NULL)); // funcion de numeros aleatorios
    for (ii = 0; ii < TAM; ii++)
    {
        *(ptr+ii) = rand()%100;
    }
} // funcion load
void print (int *ptr)
{
    int ii = 0;
    printf("\nValores cargados automaticamente:\t");
    for (ii = 0; ii < TAM; ii++)
    {
        printf("%d\t", *(ptr+ii));
    }
    printf("\n");
} // funcion valMax
void valMax (int *ptr)
{
    int ii = 0, max = 0;
    max = *(ptr);
    for (ii = 0; ii < TAM; ii++)
    {
        // if (ii = 0) max = *(ptr+ii);
        if (*(ptr+ii) > max) max = *(ptr+ii);
    }
    printf( ROJO_T "\nValor maximo: %d\n" RESET_C , max);
} // funcion valMax
void valMin (int *ptr)
{
    int ii = 0, min = 0;
    min = *(ptr);
    for (ii = 0; ii < TAM; ii++)
    {
        if (*(ptr+ii) < min) min = *(ptr+ii);
    }
    printf( AZUL_T "\nValor minimo: %d\n" RESET_C , min);
} // funcion valMin
void sumatoria (int *ptr)
{
    int ii = 0, total = 0;
    for (ii = 0; ii < TAM; ii++)
    {
        total += *(ptr+ii);
    }
    printf("\nSumatoria de valores = %d\n", total);
} // funcion sumatoria
