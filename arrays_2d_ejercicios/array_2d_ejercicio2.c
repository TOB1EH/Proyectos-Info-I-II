// Informatica - Arrays 2D E2 - Funes Tobias

#define FIL 5 
#define COL 5

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    int array[FIL][COL], ii=0, jj=0;
    srand(time(NULL)); // Función para generar números aleatorios
    // for de cargar los valores en el array
    for (ii = 0; ii < FIL; ii++) // Filas
    {
        for (jj = 0; jj < COL; jj++) // Columnas
        {
            array[ii][jj] = (rand()%50)*2; // Numeros aleatorios PARES entre 1 y 100
        }
    }
    printf("Arreglo de %d x %d solo de numeros pares:\n", FIL, COL);
    // for para mostrar los valores cargados en el array
    for (ii = 0; ii < FIL; ii++) // Filas
    {
        for (jj = 0; jj < COL; jj++) // Columnas
        {
            printf("|%d", array[ii][jj]); // Muestra los numeros aleatorios pares         
        }
        printf("|\n"); // Salto de linea para filas
    }
    return 0;
}