//INFORMATICA 15/03/22 FUNES TOBIAS

#include <stdio.h>

//Ejercicio 1: Planilla de empleado

int main(int argc, char *argv[]) {
	float horas = 0, tarifa = 0, sueldo = 0;
	printf("Ingrese el numero de horas trabajadas: \n");
	scanf("%f", &horas);
	printf("Ingrese el precio de la tarifa por hora: \n");
	scanf("%f", &tarifa);
	sueldo = horas * tarifa;
	printf("Su sueldo es de: $ %.2f", sueldo);
	return 0;
}
