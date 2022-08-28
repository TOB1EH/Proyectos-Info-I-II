//Informatica - Ejercicio Switch N°3 - Funes Tobias

#include <stdio.h>

//Ejercicio de la Calculadora

int main(int argc, char *argv[]) {
	int num1=0, num2=0, suma=0, resta=0, multi=0, opcion=0;
	float division=0;
	printf("CALCULADORA:\nIngrese dos numeros enteros:\n");
	scanf("%d%d", &num1, &num2);
	printf("Ingrese una operacion:\nsuma: 1 \nresta: 2 \nproducto: 3 \ndivision: 4\n");
	scanf("%i", &opcion);
	switch(opcion){
		case 1:
			suma = num1 + num2;
			printf("La suma de %d + %d es igual a: %d", num1, num2, suma);
			break;
		case 2:
			resta = num1 - num2;
			printf("La resta entre %d y %d es igual a: %d", num1, num2, resta);
			break;
		case 3:
			multi = num1 * num2;
			printf("El producto entre %d y %d es igual a: %d", num1, num2, multi);
			break;
		case 4:
			division = num1 / num2;
			printf("La division entre %d y %d es igual a: %.2f", num1, num2, division);
			break;
		default:
			printf("Ingreso una operacion invalida");
			break;
	}
	return 0;
}

