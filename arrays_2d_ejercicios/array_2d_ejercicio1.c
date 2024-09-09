// Informatica - Arrays 2D E1 - Funes Tobias

#define FIL 10
#define COL 10

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    int array[10][10], ii=0, jj=0, num=0, count=0, stop_while=0;
	float prom=0, suma=0;
    char opcion=' ';
    srand(time(NULL)); // Función para generar números aleatorios

	/* for de cargar los valores en el array */
    for (ii = 0; ii < FIL; ii++) // Filas
    {
        for (jj = 0; jj < COL; jj++) // Columnas
        {
            array[ii][jj] = rand()%101+1; // Numeros aleatorios del 1 al 100
			suma += array[ii][jj];
		}
    }
	printf("Arreglo de valores aleatorios cargado correctamente.");
	do
	{
		// Menu de opciones: 
		printf("\nIngrese una opcion para continuar:");
		printf("\na. Calcular Promedio\nb. Ingresar un numero ");
		printf("y buscar las veces que se repite\nc. Mostrar valores pares");
		printf("\nd. Mostrar todos los valores\ne. Finalizar menu.\n");
		printf("Opcion: ");
		scanf(" %c", &opcion);
		switch(opcion)
		{
		case 'a':
			prom = suma/(FIL*COL); // promedio es igual a la suma de todos los valores = Cant. de Filas x Cant. de Columnas
			printf("\nPromedio = %.2f\n", prom);
			break;
		case 'b':
			printf("\nIngrese un numero para buscar cuantas veces se repite: ");
			scanf("%d", &num);
			for (ii = 0; ii < FIL; ii++)
			{
				for (jj = 0; jj <COL; jj++)
				{
					if (num == array[ii][jj]) count++; // si el numero ingresado se encuentra en una posicion del array aumenta el contador en uno
				}
			}
			printf("\nEl %d se repite %d vez/veces\n", num, count);
			break;
		case 'c':
			printf("\nValores Pares:\n");
			for (ii = 0; ii < FIL; ii++)
			{
				for (jj = 0; jj <COL; jj++)
				{
					if (array[ii][jj]%2 == 0) // imprime aquellos valores del array que al dividirlos por dos su resto es cero
						printf("%d - ", array[ii][jj]);
				}
			}
			printf("\n");
			break;
		case 'd':
			printf("\nValores aleatorios/Todos los valores:\n");
			for (ii = 0; ii < FIL; ii++) // Filas
			{
				for (jj = 0; jj <COL; jj++) // Columnas
				{
					printf("%d - ", array[ii][jj]);
				}
				printf("\n"); // salto de linea entre filas
			}
			break;
		case 'e':
			printf("\ncerrando...\n");
			stop_while=1; //  detiene el ciclo do-while, finalizando asi tambien el programa
			break;
		default:
			printf("\nCaracter invalido, intente nuevamente...\n");
			break;
		}
	} while(stop_while == 0);
    return 0;
}