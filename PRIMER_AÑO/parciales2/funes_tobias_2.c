/* Liberias */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    int *p=NULL, ii = 0, n = 0;

    p = (int *) malloc(10*sizeof(int));
    if (p == NULL)
    {
        printf("No hay memoria.\n");
        exit(0);
    }
    for (ii = 0; ii < 10; ii++)
    {
        *(p+ii) = rand()%100;
    }
    printf("Valores aleatorios:\t");
    for (ii = 0; ii < 10; ii++)
    {
        printf("%d\t", *(p+ii));
    }
    printf("\n");
    printf("Cuantos valores mas desea agregar?\n");
    scanf("%d", &n);
    p = (int *) realloc(p, n * sizeof(int));
    if (p == NULL)
    {
        printf("No hay memoria\n");
        exit(0);
    }
    printf("Ingrese los valores a agregar:\n");
    for (ii = 0; ii < n; ii++)
    {
        scanf("%d", (p+ii+10));
    }
    printf("Impresion total: ");
    for (ii = 0; ii < (10+n); ii++)
    {
        printf("%d\t", *(p+ii));
    }
    printf("\n");
    free(p);
	return 0;
}
