//INFORMATICA 15/03/22 FUNES TOBIAS

#include <stdio.h>

//Ejercicio 2: Compra de entradas automaticas
	
int main(int argc, char *argv[]) {
	int num1 = 0, monto = 200, total = 0; //numeros de entrdas y costo de c/u
	printf("Ingrese la cantidad de entradas que desea comprar: \n");
	printf("(Se le recuerda que el valor de cada uno es de $200)\n");
	scanf("%d", &num1);
	total = num1 * monto;
	printf("El monto final de las %d entradas es de: $ %d", num1, total); 
	printf("\nGRACIAS POR SU COMPRA");
	return 0;
}
