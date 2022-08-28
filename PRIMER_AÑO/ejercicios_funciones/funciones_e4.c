// Informatica -  Funciones E4 - Funes Tobias

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

/* Prototipos de Funciones: */
int suma (int *);
void promedio (int *);
void letras (int *);

int main(int argc, char const *argv[])
{
    int array[N]={0}, ii=0, num=0, stop_while=0, result_sum=0;
    char opcion=' ';
    srand(time(NULL)); // 
    printf("Arreglo con 10 numeros aleatorios:\n");
    for (ii = 0; ii < N; ii++)
    {
        array[ii] = rand() % 26 + 65; // Numeros aleatorios del 65 al 90
        printf("|%d", array[ii]);
        
    } // cierre for
    printf("|\n"); 
    
    do
    {
        printf("\nMenu de opciones:\n"
                "a. Sumar los valores del arreglo.\n"
                "b. Calcular el promedio.\n"
                "c. Trasformar los números en letras.\n"
                "d. Finalizar Programa.\n"
                "Ingrese una opcion: ");
        scanf(" %c", &opcion);
        switch (opcion)
        {
            case 'a':
                result_sum = suma(array); // Lamada a la funcion suma
                printf("\nSuma valores array = %d\n", result_sum);
                break;
            case 'b':
                printf("\nValor promedio del array: ");
                promedio(array); // Llamada a la funcion promedio
                printf("\n");
                break;
            case 'c':
                printf("\nNúmeros a letras (código ASCII):\n");
                letras(array); // Llamada a la funcion letras
                printf("\n");
                break;
            case 'd':
                printf("\nFinalizando programa...\n"); 
                stop_while = 1; // Termina el bucle
                break;
            default: // caso por descarte
                printf("\nIngreso una opcion invalida...\n"
                        "Intente nuevamente.\n");
                break;
        } // cierre switch
    } while (stop_while==0); 
    return 0;
}

int suma (int *vector) // Definicion funcion suma
{
    int ii=0, suma=0;
    for (ii = 0; ii < N; ii++)
    {
        suma += vector[ii];
    }
    return(suma);
}

void promedio (int *vector) // Definicion funcion PROMEDIO
{
    float prom=0, result_sum=0;
    result_sum = suma(vector); 
    prom = result_sum / N;
    printf("%.2f", prom);
}

void letras (int *vector) // Definicion funcion LETRAS
{
    int ii=0;
    char letras[N]={' '};
    for (ii = 0; ii < N; ii++)
    {
        letras[ii] = vector[ii];
        printf("|%c", letras[ii]);
    }
    printf("|");
}