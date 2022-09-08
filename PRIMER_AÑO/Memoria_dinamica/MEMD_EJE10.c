/* EJERCICIO: Cree un programa que permita reservar memoria para n caracteres (char).
Luego cargar los n caracteres e imprimirlos por pantalla. El usuario desea agregar
o quitar caracteres, por lo que ingresa la n cantidad de caracteres a agregar/quitar.
Luego cargar los n caracteres, imprimirlos y finalmente liberar la memoria */

/*--- LIBRERIAS ---*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*--- FUNCION PRINCIPAL MAIN ---*/
int main(int argc, char const *argv[])
{
    /* Declaracion e inicializacion de variables */
    char *p = 0, opcion = 0;
    int n1 = 0, n2 = 0, ii = 0, stop_while = 0;

    printf("Ingrese el nro de elementos: ");
    scanf("%d", &n1);
    p = (char *) malloc(n1 * sizeof(char)); // funcion malloc
    if (p == NULL)
    {
        printf("\nMemoria insuficiente...\n");
        exit(0);
    }
    for (ii = 0; ii < n1; ii++)
    {
        printf("Ingrese el valor n°%d: ", ii+1);
        scanf(" %c", (p+ii));
    }
    /* Impresion de datos */
    printf("Valores ingresados:\t");
    for (ii = 0; ii < n1; ii++)
    {
        printf("%c\t", *(p+ii));
    }
    printf("\n");
    do
    {
        /* Opciones */
        printf("¿Desea agregar/quitar valores (caracteres)?(S/N) ");
        scanf(" %c", &opcion);
        opcion = tolower(opcion);
        switch (opcion)
        {
        case 's':
            /* Opciones 2 */
            printf("\nQue desea hacer:\n"
                    "a. Agregar valores.\n"
                    "b. Quitar valores.\n"
                    "c. Cancelar.\n"
                    "opcion: ");
            scanf(" %c", &opcion);
            switch (opcion)
            {
            case 'a':
                printf("Cuantos elementos/valores desea agregrar: ");
                scanf("%d", &n2); // elementos a sumar a los anteriores
                p = (char *) realloc(p, (n1+n2) * sizeof(char));
                if (p == NULL)
                {
                    printf("\nMemoria insuficiente...\n");
                    exit(0); // cerrar el programa si no hay memoria
                }
                /* Carga de nuevos datos */
                for (ii = 0; ii < n2; ii++)
                {
                    printf("Ingrese el valor n°%d: ", (n1+(ii+1)));
                    scanf(" %c", (p + ii + n1));
                }
                /* Impresion de datos */
                printf("\nNuevo total de valores:\t");
                for (ii = 0; ii < (n1+n2); ii++)
                {
                    printf("%c\t", *(p+ii));
                }
                printf("\n");
                n1 = n1 + n2;
                break;
            case 'b':
                printf("\nCuantos elementos/valores desea quitar: ");
                scanf("%d", &n2);
                n1 = n1 - n2;
                p = (char *) realloc(p, n1 * sizeof(char));
                if (p == NULL)
                {
                    printf("\nMemoria insuficiente...\n");
                    exit(0);
                }
                /* Carga e impresion de valores */
            
                printf("\nSe eliminaran los ultimos %d valores\n"
                        "Total de valores actuales:\t", n2);
                for (ii = 0; ii < n1; ii++)
                {
                    printf("%c\t", *(p+ii));
                }
                printf("\n");
                n1 = n1 - n2;
                break;
            case 'c':
                printf("\nCancelando...\n");
                break;
            default:
                printf("\nOpcion incorrecta. Intente nuevamente...\n");
                break;
            }
            break;
        case 'n':
            printf("\nCerrando...\n");
            stop_while = 1;
            break;
        default:
            printf("\nOpcion invalida intente nuevamente...\n");
            break;
        }
    } while (stop_while == 0);
    free(p); // libera la memoria reservada anteriormente
    return 0;
}
