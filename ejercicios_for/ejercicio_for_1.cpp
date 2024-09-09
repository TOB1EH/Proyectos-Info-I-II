//Informatica - Ejercicios for N�1 - Funes Tobias

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int ii=0, num=0;
	printf("Ingrese un numero entero: ");
	scanf("%d", &num);
	printf("Tabla del %d:", num);
	for(ii=1; ii<11; ii++){
		printf("\n%d * %d = %d", num, ii, num*ii);
	}
	printf("\n");
	return 0;
}

