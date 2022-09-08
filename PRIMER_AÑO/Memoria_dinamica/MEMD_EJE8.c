/*--- LIBRERIAS ---*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*--- FUNCION PRINCIPAL MAIN ---*/
int main(int argc, char const *argv[])
{
    /* Declaracion e inicializacion de variables */
    char opcion = 0;
    int n1 = 0, *p = NULL, val = 0, ii = 0, n2 = 0, stop_while = 0;
    /* Ciclo repetitivo do-while */
    do
    {
        printf("Menu de opciones:\n"
                "a. Reserva de memoria e introducción de datos enteros\n"
                "b. Agregar reserva de memoria e introducción de nuevos datos enteros\n"
                "c. Mostrar los datos en el orden y orden invertido al que fueron introducidos\n"
                "d. Cerrar Menu de opciones.\n"
                "Ingreso una opcion: ");
        scanf(" %c", &opcion);
        opcion = tolower(opcion); // convierte la letra ingresa a minusculas, para mayor onteraccion con el usuario
        switch (opcion)
        {
        case 'a':
            printf("Ingrese el N° de elementos: ");
            scanf("%d", &n1);
            p = (int *) malloc(n1 * sizeof(int));
            if (p == NULL)
            {
                printf("\nMemoria insuficiente...\n");
                exit(0);
            }
            else
            {
                for (ii = 0; ii < n1; ii++)
                {
                    printf("Ingre el valor n°%d: ", ii+1);
                    scanf("%d", (p+ii));    
                }
            }
            printf("\n");
            break;     
        case 'b':
            printf("\nIngrese la cantidad de nuevos elementos a agregar: ");
            scanf("%d", &n2);
            n1 = n1+n2;
            p = (int *) realloc(p, n1 * sizeof(int ));
            if (p == NULL)
            {
                printf("\nMemoria insuficiente...\n");
                exit(0);
            }
            else
            {
                for (ii = 0; ii < n2; ii++)
                {
                    printf("Ingrese el nuevo elemento n°%d: ", ii+1);
                    scanf("%d", (p+ii+n1));
                }
            }
            printf("\n");
            break;
        case 'c':
            printf("\nElementos ingresadose en orden:\n");
            for (ii = 0; ii < n1; ii++)
            {
                printf("%d\t", *(p+ii));
            }
            printf("\n");
            break;
        case 'd':
            printf("\nCerrando...\n");
            stop_while = 1;
            break;
        default:
            printf("\nOpcion invalida. Intente nuevamente...\n");
            break;
        }
    } while (stop_while == 0);
    free(p);
    return 0;
}