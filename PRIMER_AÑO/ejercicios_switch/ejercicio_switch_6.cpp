//Informatica - Ejercicio  Switch Nº5 - FUNES TOBIAS

#include <stdio.h>

int main(int argc, char *argv[]) {
	int tarjeta=0;
	float monto=0, limite=0;
	printf("Ingrese el numero de su tipo de tarjeta ");
	printf("para conocer el aumento en su limite de credito: ");
	scanf("%d", &tarjeta);
	printf("Por ultimo ingrese el monto actual de su tarjeta: ");
	scanf("%f", &monto);
	switch(tarjeta){
	case 1:
		limite = monto *1.25;
		printf("Su nuevo limite es de: $%.2f", limite);
		break;
	case 2:
		limite = monto *1.35;
		printf("Su nuevo limite es de: $%.2f", limite);
		break;
	case 3:
		limite = monto *1.40;
		printf("Su nuevo limite es de: $%.2f", limite);
		break;
	default:
		limite = monto *1.50;
		printf("Su nuevo limite es de: $%.2f");
		break;
	}
	return 0;
}

