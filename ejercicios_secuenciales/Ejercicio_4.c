//INFORMATICA 15/03/22 FUNES TOBIAS

#include <stdio.h>

//Ejercico 4:  

int main(int argc, char *argv[]) {
	int ganados = 0, perdidos = 0, empatados = 0, total = 0;
	printf("TORNEO DE APERTURA\n");
	printf("Ingrese el numero de partidos ganados por su equipo: \n");
	scanf("%d", &ganados);
	printf("Ahora ingrese el numero de partidos perdidos: \n");
	scanf("%d", &perdidos);
	printf("Y por ultimo ingrese el numero de partidos empatados: \n");
	scanf("%d", &empatados);
	perdidos = 0;
	ganados *= 3;
	empatados *= 1;
	total = ganados + empatados + perdidos;
	printf("El puntaje total de su equipo es: %d", total);
	return 0;
}

