/*--- LIBRERIAS ---*/
#include <stdio.h>
#include <stdlib.h>

/*--- FUNCION PRINCIPAL MAIN ---*/
int main(int argc, char const *argv[])
{
    /* Declaracion e inicializacion de variables */
    char *p = NULL, valor = 0; 
    int n = 0, ii = 0;
    printf("Ingrese que cantidad de caracteres va a ingresar: ");
    scanf("%d", &n);
    p = (char *) malloc(n*sizeof(char)); // obtener n x 1bytes (char) de memoria
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
            scanf(" %c", &valor);
            // asigna el valor a las direcciones de memorias obtenidas anteriormente
            *(p+ii) = valor; 
        } // for
        printf("Valores ingresados:\t");
        for (ii = 0; ii < n; ii++)
        {
            printf("%c\t", *(p+ii));
        } // for
        printf("\n");
    } // else
    free(p); // libera la memoria solicitada
    return 0;
}