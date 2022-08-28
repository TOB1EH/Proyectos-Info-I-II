/*--- LIBRERIAS ---*/
#include <stdio.h>
#include <ctype.h>

/*--- DIRECTIVAS ---*/
#define abc 26 // letras del abecedario
#define CYAN_T "\x1b[36m" // color cyan para texto
#define AZUL_T "\x1b[34m" // color azul para texto
#define RESET_COLOR "\x1b[0m" // resetear propiedades de colores

/*--- PROTOTIPO DE FUNCIONES ---*/
void load (char *); // funcion para cargar datos en el vector
void minus (char *); // f. para convertir la letras en minusculas
void mayus (char *); // f. para convertir las letras en mayusculas

/*--- FUNCION PRINCIPAL MAIN ---*/
int main(int argc, char const *argv[])
{
    /* Declaracion e inicializacion de varibles */
    char ABC[26] = {0}; // vector que almacena datos de tipo caracter
    char *p = ABC; // *p = &ABC[0]
    /* puntero de tipo char inicializado apuntando a la direccion de
    memoria del primer elemento del vector ABC  */
    
    void (*ptrAFunc) (char *); // puntero a funcion, no retorna valor y recibe un puntero de tipo char
    ptrAFunc = load; // asigna la direccion de mem. de la funcion "load" al puntero "ptrAFunc"
    (*ptrAFunc)(p); // invocacion de la funcion apuntada
    ptrAFunc = mayus; // idem f. "load"
    (*ptrAFunc)(p); // invocacion de la funcion apuntada
    ptrAFunc = minus; // idem f. "load"
    (*ptrAFunc)(p); // invocacion de la funcion apuntada
    return 0;
} // function main

/*--- FUNCIONES ---*/
void load (char *ptr)
{
    int ii = 0; // acumulador/contador ii
    char A = 65; // letra A en codigo ASCII
    for (ii = 0; ii < abc; ii++)
    {
        *(ptr+ii) = A+ii;
    }
} // function load
void mayus (char *ptr)
{
    int ii = 0; // acumulador/contador ii
    printf( CYAN_T "Abecedario en Mayusculas:\n");
    for (ii = 0; ii < abc; ii++)
    {
        printf("%c\t", *(ptr+ii) = toupper (*(ptr+ii)));
    }
    printf("\n" RESET_COLOR );
} // function mayus
void minus (char *ptr)
{
    int ii = 0; // acumulador/contador ii
    printf( AZUL_T "Abecedario en Minusculas:\n");
    for (ii = 0; ii < abc; ii++)
    {
        printf("%c\t", *(ptr+ii) = tolower (*(ptr+ii)));
    }
    printf("\n" RESET_COLOR );
} // function minus