/* Desarrolle un programa que declare e inicialice un
arreglo de 2x3 con valores aleatorios. Luego mostrar los
valores. Utilice punteros para realizar el ejercicio. */

/*--- LIBRERIAS ---*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*--- DIRECTIVAS ---*/
#define FIL 2 //  cant. de filas del array
#define COL 3 // cant. de columnas del array

/*--- PROTOTIPO DE FUNCIONES ---*/
void print (int *);

/*--- FUNCION PRINCIPAL MAIN ---*/
int main(int argc, char const *argv[])
{
    int array[FIL][COL] = {0}, ii = 0, jj = 0;
    int *ptr_array = *array;

    void (*ptrAFunc) (int *);
    
    srand(time(NULL)); // funcion de numeros aleatorios
    
    for (ii = 0; ii < FIL; ii++)
    {
        for (jj = 0; jj < COL; jj++)
        {
            *((ptr_array+ii)+jj) = rand()%100;
        }
    }
    ptrAFunc = print;
    (*ptrAFunc)(ptr_array);
    return 0;
} // main

/*--- FUNCIONES ---*/
void print (int *ptr)
{
    int ii = 0, jj = 0;
    printf("Arreglo de %d x %d:\n", FIL, COL);
    for (ii = 0; ii < FIL; ii++)
    {
        for (jj = 0; jj < COL; jj++)
        {
            printf("%d\t", *((ptr+ii)+jj));
        }
        printf("\n");
    }
    printf("\n");
}