/*--- LIBRERIAS ---*/
#include <stdio.h>
/*--- DIRECTIVAS ---*/
#define TAM 5 // tamaño para el array
/*--- FUNCION PRINCIPAL MAIN ---*/
int main(int argc, char *argv[])
{
	int ii = 0; // acumulador/contador ii
	float v[TAM] = {4.5, 8, 2.3, 1.1, 3}, sumatoria = 0, promedio = 0;
	float *p = v; // *p = &v[0]
	for (ii=0; ii < TAM; ii++)
	{
		sumatoria+= p[ii]; // sumatoria = sumatoria + valor del elemento v[ii]
	} // for
	promedio = (float) sumatoria/TAM; // casteo el valor a flotante
	printf("Sumatoria: %.1f, Promedio: %.1f", sumatoria, promedio);
	return 0;
}