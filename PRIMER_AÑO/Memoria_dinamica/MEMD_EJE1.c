/*--- LIBRERIAS ---*/
#include <stdio.h>
#include <stdlib.h>

/*--- FUNCION PRINCIPAL MAIN ---*/
int main(int argc, char const *argv[])
{
    /* Declaracion e inicializacion de variables */
    int *p = NULL, n = 0, ii = 0, valor = 0;
    printf("Ingrese que cantidad de valores enteros va a ingresar: ");
    scanf("%d", &n);
    p = (int *) malloc(n*sizeof(int)); // obtener n x 4bytes (int) de memoria
    if (p == NULL)
    {
        printf("Memoria insuficiente\n");
        exit(0); // finaliza el programa
    } // if
    else
    {
        for (ii = 0; ii < n; ii++)
        {
            printf("Ingrese el valor N°%d: ", ii+1);
            scanf("%d", &valor);
            // asigna el valor a las direcciones de memorias obtenidas anteriormente
            *(p+ii) = valor; 
        } // for
        printf("Valores ingresados:\t");
        for (ii = 0; ii < n; ii++)
        {
            printf("%d\t", *(p+ii));
        } // for
        printf("\n");
    } // else
    free(p); // libera la memoria solicitada
    return 0;
}