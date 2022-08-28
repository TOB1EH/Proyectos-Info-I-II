//Informatica - Ejersicio Switch N°1 -FUNES TOBIAS

#include <stdio.h>

int main(int argc, char *argv[]) {
	int num=0;
	printf("Ingrese un numero del 1 al 7 y se le indicara a que dia ");
	printf("de la semana corresponde: ");
	scanf("%d", &num);
	switch(num){
	case 1:
		printf("El numero 1 corresponde al dia Domingo");
		break;
	case 2:
		printf("El numero 2 corresponde al dia Lunes");
		break;
	case 3:
		printf("El numero 3 corresponde al dia Martes");
		break;
	case 4:
		printf("El numero 4 corresponde al dia Miercoles");
		break;
	case 5:
		printf("El numero 5 corresponde al dia Jueves");
		break;
	case 6:
		printf("El numero 6 corresponde al dia Viernes");
		break;
	case 7:
		printf("El numero 7 corresponde al dia Sabado");
		break;
	default:
		printf("Ingreso un numero invalido");
		break;
	}
	return 0;
}

