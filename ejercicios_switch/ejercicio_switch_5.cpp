//Informatica - Ejercicio Switch Nº4 - FUNES TOBIAS

#include <stdio.h>

int main(int argc, char *argv[]) {
	float peso=0, precio=0;
	int opcion=0;
	printf("Envios internacionales\n");
	printf("Ingrese el peso del paquete en gramos: ");
	scanf("%f", &peso);
	printf("Ingrese el numero de su destino:\n");
	printf("1.America del Norte y central\n");
	printf("2.America del Sur\n");
	printf("3.Europa\n");
	printf("4.Asia y Occicdente\n");
	scanf("%d", &opcion);
	switch(opcion){
	case 1:
		precio = peso * 30;
		printf("El envio de su paquete a ese destino ");
		printf("tendra un costo de: $%.2f", precio);
		break;
	case 2:
		precio = peso * 20;
		printf("El envio de su paquete a ese destino ");
		printf("tendra un costo de: $%.2f", precio);
		break;
	case 3:
		precio = peso * 70;
		printf("El envio de su paquete a ese destino ");
		printf("tendra un costo de: $%.2f", precio);
		break;
	case 4:
		precio = peso * 100;
		printf("El envio de su paquete a ese destino ");
		printf("tendra un costo de: $%.2f", precio);
		break;
	default:
		printf("\nNumero de destino invalido!");
		break;
	}
	return 0;
}

