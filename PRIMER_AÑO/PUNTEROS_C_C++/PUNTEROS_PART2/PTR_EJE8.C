/*--- LIBRERIAS ---*/
#include <stdio.h>
#include <ctype.h>
/*--- DIRECTIVAS ---*/
#define abc 26 // letras del abecedario
#define CYAN_T "\x1b[36m" // color cyan para texto
#define AZUL_T "\x1b[34m" // color azul para texto
#define RESET_COLOR "\x1b[0m" // resetear propiedades de colores
/*--- FUNCION PRINCIPAL MAIN ---*/
int main(int argc, char *argv[])
{
	int ii = 0; // acumulador/contador ii
	char ABC[abc], A = 65;
	char *ptr = ABC; // puntero tipo char apuntando a la direccion de memoria del primer elemento de ABC
	for (ii=0; ii < abc; ii++)
	{
		ptr[ii] = A++;
	} // for para cargar datos
	printf( AZUL_T "ABECEDARIO:\n");
	for (ii=0; ii < abc; ii++)
	{
		printf(CYAN_T"%c", ptr[ii]); // imprimir valores sin cambios (mayusculas)
		printf("%c\t", ptr[ii] = tolower(ptr[ii])); // imprimir valores en minusculas
	} // for para imprimir datos
	printf("\n" RESET_COLOR );
	return 0;
}