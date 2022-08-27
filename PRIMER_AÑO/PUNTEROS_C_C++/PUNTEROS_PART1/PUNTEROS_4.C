#include <stdio.h>

// INTERCAMBIAR VALORES ENTRE A Y B
int main(int argc, char *argv[]) {
	int a = 0, b = 0 , auxiliar = 0;
	int *pointer_1 = NULL;
	pointer_1 = &b;
	printf("Ingrese el valor de a: ");
	scanf("%d", &a);
	printf("Ingrese el valor de b: ");
	scanf("%d", &b);
	printf("Intercambio de valores...\n");
	auxiliar = a;
	a = *pointer_1;
	b = auxiliar;
	printf("Ahora a =  %d y b = %d\n", a, b);
	return 0;
}

