/*--- LIBRERIAS ---*/
#include <stdio.h>
#include <math.h>
/*--- PROTOTIPO DE FUNCIONES ---*/
void calculadora (float *, float *, char *, int *); // Funcion para realizar todas las operaciones solicitadas

int main(int argc, char *argv[]) // funcion principal main
{
	int stop_while = 0; // variable para detener el bucle do_while
	float num_1 = 0, num_2 = 0; // variables flotantes para ingresar los numeros a operar
	char opcion = ' '; // variable para interactuar con el menu de opciones
	printf("Ingrese dos numeros para operarlos entre si:\nnum 1: ");
	scanf("%f", &num_1);
	printf("num 2: ");
	scanf("%f", &num_2);
	do
	{
		printf("\nMenu de opciones:\n" // OPCIONES PARA EL MENU DE OPERACIONES ALGEBRAICAS
			   "a. sumar\n"
			   "b. restar\n"
			   "c. multiplicar\n"
			   "d. dividir dos numeros\n"
			   "e. elevar a una potencia\n"
			   "f. calcular la raiz de numero\n"
			   "g. cambiar los valores ingresados\n"
			   "h. cerrar menu\n"
			   "Ingrese una opcion: ");
		scanf(" %c", &opcion); // SCANF PARA ENTRADA DE OPCIONES
		calculadora(&num_1, &num_2, &opcion, &stop_while); // invocacion sin retorno de funcion calculadora
	} while(stop_while == 0); // ciclo do while
	return 0;
} // main
/*---- FUNCIONES ----*/
void calculadora (float *a, float *b, char *opcion, int *stop)
{
	float num1 = 0, num2 = 0; // variables flotantes para ingresar los numeros valores a operar
	if (*opcion == 'a' || *opcion == 'A') // opcion para sumar ambos numeros
	{
		printf("\nSuma:\n"
			   "%.2f + %.2f = %.2f\n", *a, *b, (*a + *b));
	}
	if (*opcion == 'b' || *opcion == 'B') // opcion para restar los numeros entre si
	{
		printf("\nResta:\n"
			   "%.2f - %.2f = %.2f\n"
			   "%.2f - %.2f = %.2f\n",
			   *a, *b, (*a - *b), *b, *a, (*b - *a));
	}
	if (*opcion == 'c' || *opcion == 'C') // opcion para realizar el producto entre los dos numeros
	{
		printf("\nProducto:\n"
			   "%.2f x %.2f = %.2f\n", *a, *b, (*a * *b));
	}
	if (*opcion == 'd' || *opcion == 'D') // opcion para dividir ambos numeros entre si
	{
		printf("\nDivision:\n"
			   "%.2f / %.2f = %.2f\n"
			   "%.2f / %.2f = %.2f\n",
			   *a, *b, (*a / *b), *b, *a, (*b / *a));
	}
	if (*opcion == 'e' || *opcion == 'E')  // opcion para elevar un numero a la potencia del otro
	{
		printf("\nPotencia:\n"
			   "%.2f^%.2f = %.2f\n"
			   "%.2f^%.2f = %.2f\n",
			   *a, *b, (pow(*a,*b)), *b, *a, (pow(*b,*a))); // funcion potencia de la libreria math
	}
	if (*opcion == 'f' || *opcion == 'F') // opcion para calcular la raiz cuadrada de ambos numeros
	{
		printf("\nRaiz Cuadrada:\n"
			   "%.2f^1/2 = %.2f\n"
			   "%.2f^1/2 = %.2f\n",
			   *a, (sqrt(*a)), *b, (sqrt(*b))); // funcion raiz cuadrada de la libreria math
	}
	if (*opcion == 'g' || *opcion == 'G') // opcion para cambiar los valores ingresados
	{
		printf("\nIngrese los nuevos valores a continuacion:\nnum 1: ");
		scanf("%f", &num1);
		printf("num 2: ");
		scanf("%f", &num2);
		*a = num1;
		*b = num2;
	}
	if (*opcion == 'h' || *opcion == 'H') // opcion para  cerrar el menu de operaciones
	{
		printf("\nCerrando...\n");
		*stop = 1;
	}
	if (*opcion < 65 || (*opcion > 72 && *opcion < 97) || *opcion > 104) /* mensaje de advertencia de entradas
	por teclado incorrectas */
	{
		printf("\nIngreso una opcion incorrecta. Intente nuevamente.\n");
	}
}