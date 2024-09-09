/*--- LIBRERIAS ---*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

/*--- DIRECTIVAS ---*/
#define FIL 2 // cantidad de filas del arreglo
#define COL 3 // cantidad de columnas del arreglo

/*--- FUNCION PRINCIPAL MAIN ---*/
int main(int argc, char const *argv[])
{
    /* Declaracion e inicializacion de variables */
    char opcion = 0;
    int ii = 0, jj = 0, stop_while = 0, suma = 0;
    
    srand(time(NULL)); // funcion de numeros aleatorios
    
    /* Reservando memoria: Filas */
    int **array = (int **) malloc(FIL * sizeof(int *)); // arreglo de punteros para almacenar las colums.
    if (array == NULL)
    {
        printf("\nMemoria insuficiente...\n");
        exit(0); // si no hay memoria suficiente, finaliza el programa
    }
    /* Reservando memoria: Columnas */
    for (ii = 0; ii < FIL; ii++)
    {
        *(array+ii) = (int *) malloc(COL * sizeof(int));
        if (*(array+ii) == NULL)
        {
            printf("\nMemoria insuficiente...\n");
            exit(0);   
        }
    }
    /* Carga de datos */
    for (ii = 0; ii < FIL; ii++)
    {
        for (jj = 0; jj < COL; jj++)
        {
            *(*(array+ii)+jj) = rand()%100; // genera numeros aleatorios del 1 al 100
        }
    }
    /* Menu de opciones */
    do
    {
        printf("Menu de opciones:\n"
                "a. Sumatoria.\n"
                "b. Mostrar todos los valores.\n"
                "c. Cerrar Menu de opciones.\n"
                "Ingrese una opcion: ");
        scanf(" %c", &opcion);
        opcion = tolower(opcion); // convierte los valores ingresados a minusculas
        switch (opcion)
        {
        case 'a':
            /* Recorrer valores para sumarlos */
            for (ii = 0; ii < FIL; ii++)
            {
                for (jj = 0; jj < COL; jj++)
                {
                    suma += *(*(array+ii)+jj); // navega por los valores del arreglo y los suma
                }
            }
            printf("Suma total de valores: %d\n\n", suma);
            break;
        case 'b':
            /* Impresion de datos */
            printf("Valores aleatorios:\n");
            for (ii = 0; ii < FIL; ii++)
            {
                for (jj = 0; jj < COL; jj++)
                {
                    printf("%d\t", *(*(array+ii)+jj));
                }
                printf("\n");
            }
            printf("\n");
            break;
        case 'c':
            printf("\nCerrando...\n");
            stop_while = 1; // finaliza el bucle do-while
            break;
        default:
            printf("\nOpcion incorrecta. Intente nuevamente...\n");
            break;
        }
    } while (stop_while == 0);    
    /* Liberacion de memoria */
    for (ii = 0; ii < FIL; ii++)
    {
        free(*(array+ii));
    }
    free(array);
    return 0;
}