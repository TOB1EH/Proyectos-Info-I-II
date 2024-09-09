/*--- LIBRERIAS ---*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*--- FUNCION PRINCIPAL MAIN ---*/
int main(int argc, char const *argv[])
{
    /* Declaracion e inicializacion de variables */
    int ii = 0, n1 = 0, n2 = 0, stop_while = 0;
    char *p = NULL, val = 0 , resp = 0;

    printf("Ingrese la cantidad de elementos que va a ingresar: ");
    scanf("%d", &n1);
    p = (char *) malloc(n1 * sizeof(char)); // invocacion malloc
    if (p == NULL)
    {
        printf("\nMemoria insuficiente...\n");
        exit(0); // si no hay memoria finaliza el programa
    } // if
    else // si en cambio, la mmoria es suficiente, continua...
    {
        for (ii = 0; ii < n1; ii++)
        {
            printf("Ingrese un caracter: ");
            scanf(" %c", &val);
            *(p+ii) = val; // navega por las posiciones de memorias asignadas
        } // for
        printf("Caracteres ingresados:\t");
        for (ii = 0; ii < n1; ii++)
        {
            printf("%c\t", *(p+ii));
        } // for
        printf("\n");
    } // else
    do
    {    
        printf("¿Desea ingresar mas caracteres (S/n)? ");
        scanf(" %c", &resp);
        resp = tolower(resp); // convierte los caracteres ingresos en minusculas para mayor compatibilidad
        switch (resp)
        {
        case 's':
            n1 = n1+n2; // n1 = al total de elementos ingresados por ultima vez
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
                for (ii = 0; ii < n2; ii++)
                {
                    printf("Ingrese un caracter: ");
                    scanf(" %c", &val);
                    *(p + ii + n1) = val;
                } // for
                printf("Caracteres ingresados en Total:\t");
                for (ii = 0; ii < (n1+n2); ii++)
                {
                    printf("%c\t", *(p+ii));
                } // for
                printf("\n");
            } // else
            break;
        case 'n':
            printf("\nFinalizando el programa...\n");
            stop_while = 1;
            break;
        default:
            printf("\nIngreso una opcion invalida. Intente nuevamente.\n");
            break;
        } // switch
    } while (stop_while == 0); // ciclo do_while
    free(p); // invocacion free para liberar la memoria asignada anteriormente
    return 0;
} // main
