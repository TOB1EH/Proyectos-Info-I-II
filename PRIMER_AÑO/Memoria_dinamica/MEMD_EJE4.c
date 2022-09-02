#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    int ii = 0, n1 = 0, stop_while = 0, n2 = 0;
    char *p = NULL, val = 0 , resp = 0;
    printf("Ingrese la cantidad de elementos a ingresar: ");
    scanf("%d", &n1);
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
            *(p+ii) = val;
        }
        printf("Caracteres ingresados:\t");
        for (ii = 0; ii < n1; ii++)
        {
            printf("%c\t", *(p+ii));
        }
        printf("\n");
    }
    printf("¿Desea ingresar mas caracteres (S/n)? ");
    scanf(" %c", &resp);
    resp = tolower(resp); 
    switch (resp)
    {
    case 's':
        printf("Cuantos caracteres mas desea ingresar: ");
        scanf("%d", &n2);
        p = (char *) realloc(p, (n1+n2) * sizeof(char));
        if (p == NULL)
        {
            printf("\nMemoria insuficiente...\n");
            exit(0);
        }
        else
        {                            
        for (ii = 0; ii < n2; ii++)
        {
            printf("Ingrese un caracter: ");
            scanf(" %c", &val);
            *(p + ii + n1) = val;
        }
        printf("Total de Caracteres ingresados:\t");
        for (ii = 0; ii < (n1+n2); ii++)
        {
            printf("%c\t", *(p+ii));
        }
        printf("\n");
        }
        break;
    case 'n':
        printf("\nFinalizando el programa...\n");
        exit(0);
        break;
    default:
        printf("\nIngreso una opcion invalida. Intente nuevamente.\n");
        break;
    }   
    return 0;
}
