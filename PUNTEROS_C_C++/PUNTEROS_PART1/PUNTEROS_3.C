#include <stdio.h>

int main(int argc, char *argv[]) {
	int a = 7;
	int *pointer = NULL; // Variable entera de tipo puntero
	pointer = &a; // puntero = direccion de memoria de a
	printf("Direccion de memoria de a: %X\n"
		   "Valor almacenado en a: %d\n"
		   "Valor del puntero: %X\n"
		   "Valor apuntado por el puntero: %d\n", &a, a, pointer, *pointer);
	return 0;
}

