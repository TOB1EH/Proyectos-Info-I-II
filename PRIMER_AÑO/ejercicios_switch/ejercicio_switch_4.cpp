//Informatica - Ejercicio Switch N°6 - FUNES TOBIAS

#include <stdio.h>

int main(int argc, char *argv[]) {
	char letra= '';
	printf("ingrese una letra para saber si es una vocal o una consonate: ");
	scanf("%c", &letra);
	switch(letra){
	case 'a':
		printf("'%c' es una vocal", letra);
		break;
	case 'e':
		printf("'%c' es una vocal", letra);
		break;
	case 'i':
		printf("'%c' es una vocal", letra);
		break;
	case 'o':
		printf("'%c' es una vocal", letra);
		break;
	case 'u':
		printf("'%c' es una vocal", letra);
		break;
	default:
		printf("'%c' es una consonante", letra);
		break;
	}
	return 0;
}

