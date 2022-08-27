#include <stdio.h>

int main(int argc, char *argv[]) {
	int ii = 0, nota = 0, prom = 0;
	for (ii = 1; ii < 4; ii++)
	{
		printf("Ingrese nota n°%d: ", ii);
		scanf("%d", &nota);
		prom += nota;
	}
	printf("Promedio = %.2f", (prom/3.0));
	return 0;
}

