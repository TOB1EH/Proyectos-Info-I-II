//Informatica - Ejercicio Switch N°2 - FUNES TOBIAS

#include <stdio.h>

int main(int argc, char *argv[]) {
	int mes=0;
	printf("Al ingresar el numero correspondiente a un mes se imprimira"); 
	printf(" por pantalla la cantidad de días del mes ingresado. Siendo:\n");
	printf("1.Enero\n2.Febrero\n3.Marzo\n4.Abril\n5.Mayo\n6.Junio\n7.Julio\n");
	printf("8.Agosto\n9.Septiembre\n10.Octubre\n11.Noviembre\n12.Diciembre\n");
	scanf("%d", &mes);
	switch(mes){
	case 1:
		printf("Enero tiene 31 dias");
		break;
	case 2:
		printf("Febrero tiene 28 dias");
		break;
	case 3:
		printf("Marzo tiene 31 dias");
		break;
	case 4:
		printf("Abril tiene 30 dias");
		break;
	case 5:
		printf("Mayo tiene 31 dias");
		break;
	case 6:
		printf("Junio tiene 30 dias");
		break;
	case 7:
		printf("Julio tiene 31 dias");
		break;
	case 8:
		printf("Agosto tiene 31 dias");
		break;
	case 9:
		printf("Septiembre tiene 30 dias");
		break;
	case 10:
		printf("Octubre tiene 31 dias");
		break;
	case 11:
		printf("Noviembre tiene 30 dias");
		break;
	case 12:
		printf("Diciembre tiene 31 dias");
		break;
	default:
		printf("Valor ingresado invalido");
		break;
	}
	return 0;
}

