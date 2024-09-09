//INFORMATICA 15/03/22 FUNES TOBIAS

#include <stdio.h>

//Ejercicio 3: 

int main(int argc, char *argv[]) {
	int correctas = 0, incorrectas =0, blanco = 0;
	float nota = 0;
	printf("Ingrese el numero de respuestas correctas: \n");
	scanf("%d", &correctas);
	printf("Ahora ingrese el numero de respuestas incorrectas: \n");
	scanf("%d", &incorrectas);
	printf("Y por ultimo ingrese el numero de respuestas en blanco: \n");
	scanf("%d", &blanco);
	correctas *= 4;
	incorrectas *= (-1);
	blanco = 0;
	nota = correctas + incorrectas;
	printf("Su puntaje final es: %.2f", nota);
	return 0;
}

