#include <stdio.h>

#define FIL 2
#define COL 2

void matriz (int [][COL]);

int main(int argc, char const *argv[])
{
	int array[FIL][COL]={0};
	array[1][0] = 22;
	printf("\nArray: %d", array[1][0]);
	matriz(array);
	printf("\nNuevo Array: %d\n", array[1][0]);
	return 0;
}

/* funciones */
void matriz (int vector[][COL])
{
	vector[1][0] = 45;
}
