#include <stdio.h>

int main(int argc, char *argv[]) {
	int numero=0;
	printf("Ingrese un numero entero: ");
	scanf("%i", &numero);
	if(numero <0){
		printf("El numero ingresado es negativo");
	}
	else{
		if(numero == 0){
			printf("El numero ingresado es cero");
		}
		else{
			printf("El numero ingresado es positivo");
		}
	}
	return 0;
}

