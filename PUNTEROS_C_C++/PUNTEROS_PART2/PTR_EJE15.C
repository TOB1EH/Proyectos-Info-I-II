/* Desarrolle un programa que declare e inicialice un
arreglo de 4x3 con valores aleatorios de tipo flotantes.
Luego mostrar los valores. Utilice punteros para realizar 
el ejercicio. */

/*--- LIBRERIAS ---*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*--- DIRECTIVAS ---*/
#define FIL 4 //  cant. de filas del array
#define COL 3 // cant. de columnas del array

/*--- PROTO. FUNCIONES ---*/
void print (float *);

int main(int argc, char const *argv[])
{
    int  ii = 0, jj = 0;
    float array[FIL][COL] = {0}, *ptr_array = *array;

    void (*ptrAFunc) (float *);
    
    srand(time(NULL)); // funcion de numeros aleatorios
    
    for (ii = 0; ii < FIL; ii++)
    {
        for (jj = 0; jj < COL; jj++)
        {
            *((ptr_array+ii)+jj) = (float) (rand()%300)/2.735; // genera numeros aleatorios de tipo flotante
        }
    }
    ptrAFunc = print;
    (*ptrAFunc)(ptr_array);
    return 0;
} // main

/*--- FUNCIONES ---*/
void print (float *ptr)
{
    int ii = 0, jj = 0;
    printf("Arreglo de flotantes %d x %d:\n", FIL, COL);
    for (ii = 0; ii < FIL; ii++)
    {
        for (jj = 0; jj < COL; jj++)
        {
            printf("%.2f\t", *((ptr+ii)+jj));
        }
        printf("\n");
    }
    printf("\n");
}