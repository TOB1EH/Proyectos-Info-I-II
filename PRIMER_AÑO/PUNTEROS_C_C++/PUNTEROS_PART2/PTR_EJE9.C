/*--- LIBRERIAS ---*/
#include <stdio.h>
#include <ctype.h>

/*--- DIRECTIVAS ---*/
#define CYAN_T "\x1b[36m" // color cyan para texto
#define AZUL_T "\x1b[34m" // color azul para texto
#define RESET_COLOR "\x1b[0m" // resetear propiedades de colores

/*--- PROTOTIPO DE FUNCIONES ---*/
void load (char[26]);
void abc (char[26]);
void ABC (char[26]);

/*--- FUNCION PRINCIPAL MAIN ---*/
int main(int argc, char *argv[]) {
	char vector_abc[26], *p = vector_abc;
	void (*ptrAFunc)(char[26]);
	ptrAFunc = load;
	(*ptrAFunc)(p);
	ptrAFunc = abc;
	(*ptrAFunc)(p);
	ptrAFunc = ABC;
	(*ptrAFunc)(p);
	return 0;
} // main
/*--- FUNCIONES ---*/
void load (char p[26])
{
	int ii = 0;
	char A = 65;
	for (ii=0; ii < 26; ii++)
	{
		p[ii] = A+ii;
	}
} // funcion
void abc (char p[26])
{
	int ii = 0;
	printf( CYAN_T "Abecedario en Minusculas:\n");
	for (ii=0; ii < 26; ii++)
	{
		printf( CYAN_T "%c|\t", p[ii] = tolower(p[ii]));
	}
	printf("\n" RESET_COLOR );
} // funcion
void ABC (char p[26])
{
	int ii = 0;
	printf( AZUL_T "Abecedario en Mayusculas:\n");
	for (ii=0; ii < 26; ii++)
	{
		printf( AZUL_T "%c|\t", p[ii] = toupper(p[ii]));
	}
	printf("\n" RESET_COLOR );
} // funcion