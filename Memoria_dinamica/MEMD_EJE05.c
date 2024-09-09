/*--- LIBRERIAS ---*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*--- PROTOTIPO DE FUNCIONES ---*/
void print (char *, int *);

/*--- FUNCION PRINCIPAL MAIN ---*/
int main(int argc, char const *argv[])
{
    /* Declaracion e inicializacion de variables */
    char *p = NULL, val = 0, resp = 0;
    int n1 = 0, n2 = 0, ii = 0, stop_while = 0;
    
    printf("Cantidad de elementos que va a ingresar: ");
    scanf("%d", &n1);
    void (*ptrAFunc) (char *, int *); // puntero a funcion
    p = (char *) malloc(n1 * sizeof(char));
    if (p == NULL)
    {
        printf("\nMemoria insuficiente...\n");
        exit(0);
    }
    else
    {
        for (ii = 0; ii < n1; ii++)
        {
            printf("Ingrese un caracter: ");
            scanf(" %c", &val);
            *(p+ii) = val; // navega por las posiciones de memorias asignadas
        } // for
        ptrAFunc = print;
        printf("Caracteres ingresados:\t");
        (*ptrAFunc)(p, &n1);
    }
    do
    {    
        printf("¿Desea ingresar mas caracteres (S/n)? ");
        scanf(" %c", &resp);
        resp = tolower(resp); // convierte los caracteres ingresos en minusculas para mayor compatibilidad
        switch (resp)
        {
        case 's':

            printf("Cuantos caracteres mas desea ingresar: ");
            scanf("%d", &n2);
            // invocacion realloc
            p = (char *) realloc(p, (n1+n2) * sizeof(char)); /* La función realloc() cambia el tamaño 
            de la memoria asignado previamente por una llamada a malloc() en n1+n2 bytes (char) */
            if (p == NULL)
            {
                printf("\nMemoria insuficiente...\n");
                exit(0); // si no hay memoria suficiente finaliza el programa
            } // if
            else // de lo contrario continua
            {                            
                /* Cargar mas datos */
                for (ii = 0; ii < n2; ii++)
                {
                    printf("Ingrese un caracter: ");
                    scanf(" %c", &val);
                    *(p + ii + n1) = val;
                } // for
                n1 = n1+n2; // n1 = al total de elementos ingresados por ultima vez
                printf("Caracteres ingresados en Total:\t");
                ptrAFunc = print;
                (*ptrAFunc)(p, &n1);
            }
            break;
        case 'n':
            printf("\nFinalizando el programa...\n");
            stop_while = 1; // finaliza el bucle while
            break;
        default:
            printf("\nIngreso una opcion invalida. Intente nuevamente.\n");
            break;
        } // switch
    } while (stop_while == 0); // ciclo do_while
    free(p);
    return 0;
} // main

void print (char *p, int *n1)
{
    int ii = 0;
    for (ii = 0; ii < *n1; ii++)
    {
        printf("%c\t", *(p+ii));
    } // for
    printf("\n");
} // funcion print