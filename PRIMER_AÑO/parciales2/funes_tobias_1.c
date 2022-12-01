/* Librerias */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

/* Directivas */
#define TAM 20

/* Prototipo de funciones */
void carga (int *p); // funcion para la carga de datos
void imprimir (int *p); // funcion para imprimir los datos cargados
void pares (int *p); // funcion para imprimir solo los numeros pares
void suma_impares (int *p); // funcion para sumar solo los numeros impares
void val_entre_xy (int *p); // funcion para conocer la cantidad de numeros entre 10 y 15

/* Funcion principal main */
int main(int argc, char const *argv[])
{
    /* Declaracion e inicializacion de variables */
    char opcion = 0;
    int ii = 0, *p = NULL, stop_while = 0;
    
    srand(time(NULL)); // funcion de numeros aleatorios
    /* Asignacion de memoria */
    p = (int *) malloc(TAM * sizeof(int)); // asignacion de memoria
    if (p == NULL)
    {
       printf("\nMemoria insuficiente.\n");
       exit(0); // si no hay memoria finaliza el progrma
    }
    /* Carga de datos */
    carga(p);
    do
    {
        /* Menu de opicones */
        printf("Menu de opciones:\n"
                "a. Mostrar todos los valores con su respectiva dirección.\n"
                "b. Mostrar los valores pares.\n"
                "c. Sumar los valores impares.\n"
                "d. Contar las cantidad de valores que estan entre 10 y 15.\n"
                "e. Cerrar Menu.\n"
                "Ingrese una opcion: ");
        scanf(" %c", &opcion);
        opcion = tolower(opcion); // transforma la opcion en minusculas para tolerar el ingreso de mayusculas
        switch (opcion)
        {
        case 'a':
            imprimir(p);
            break;
        case 'b':
            pares(p);
            break;
		case 'c':
            suma_impares(p);
			break;
		case 'd':
            val_entre_xy(p);
			break;
        case 'e':
            printf("\nCerrando...\n");
            stop_while = 1;
        default:
            printf("\nIngreso una opcion invalida. Intente nuevamente...\n");
            break;
        }
    } while (stop_while==0);
    /* Liberar memoria */
    free(p);
    return 0;
}
/* Funciones */
void carga(int *p)
{
    int ii = 0;
    for (ii = 0; ii < TAM; ii++)
    {
        *(p+ii) = rand()%50+1; // carga de valores aleatorios al puntero
    }
} // funcion carga
void imprimir (int *p)
{
    int ii = 0;
    printf("Valores aleatorios generados:\n");
    for (ii = 0;ii < TAM; ii++)
    {
        printf("%d\t", *(p+ii));
    }
    printf("\nPosiciones de memoria de los mismos:\n");
    for (ii = 0; ii < TAM; ii++)
    {
        printf("%x\t", *(p+ii));
    }
    printf("\n");
} // funcion imprimir
void pares(int *p)
{
    int ii = 0;
    printf("Valores pares:\n");
    for ( ii = 0; ii < TAM; ii++)
    {
        if (*(p+ii)%2==0)
        {
            printf("%d\t", *(p+ii));
        }
    }
    printf("\n");
} // funcion pares
void suma_impares (int *p)
{
	int ii = 0, suma = 0;
    for ( ii = 0; ii < TAM; ii++)
	{
		if (*(p+ii)%2!=0)
		{
			suma += *(p+ii);
		}
	}
	printf("\nsuma de valores impares: %d\n\n", suma);
} // funcion suma_impares
void val_entre_xy (int *p)
{
	int ii = 0, suma = 0;
    for(ii=0; ii < TAM; ii++)
	{
		if (*(p+ii) > 10 && *(p+ii) < 15) suma++;
	}
	printf("\nCantidad de valores entre 10 y 15: %d\n", suma);
} // funcion val_entre_xy