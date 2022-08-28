//INFORMATICA 15/03/22 FUNES TOBIAS

#include <stdio.h>

//Ejercicio 5: Calcular perimetro y area

int main(int argc, char *argv[]) {
	float perimetro = 0, area = 0, lado = 0, base = 0;
	printf("Para calcular el perimetro de un cuadrado o de un rectangulo ");
	printf("complete los datos a continuacion: \nMedida de la base: ");
	scanf("%f", &base);
	printf("Medida de uno de los lados: ");
	scanf("%f", &lado);
	perimetro = 2*base + 2*lado;
	area = base * lado;
	printf("Perimetro del cuadrado/rectangulo: %.2f", perimetro);
	printf("\nArea del cuadrado/rectangulo: %.2f", area);
	return 0;
}

