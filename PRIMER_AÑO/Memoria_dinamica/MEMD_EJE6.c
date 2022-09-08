/*--- LIBRERIAS ---*/
#include <stdio.h>
#include <stdlib.h>

/*--- DIRECTIVAS ---*/
#define BLUE_T "\x1b[34m" // texto color azul
#define CYAN_T "\x1b[35m" // texto color cyan
#define RESE_COLOR "\x1b[0m" // resetear colores

/*--- PROTOTIPO DE FUNCIONES ---*/
void load (char *, int *); // funcion para cargar cantidad y datos
void mostrarOrden (char *, int *); // funcion imprimir datos en orden
void mostrarOrdenInverso (char *, int *); // funcion imprimir datos en orden inverso

/*--- FUNCION PRICIPAL MAIN ---*/
int main(int argc, char const *argv[])
{
    char *p = NULL;
    int n = 0;
    void (*ptrAFunc) (char *, int *); // puntero a funciones

    ptrAFunc = load; // direccion de memoria de la funcion "load"
    (*ptrAFunc)(p, &n); // invocacion  de la funcion 

    free(p); // liberar memoria asignada anteriormente
    return 0;
} // main

/*--- FUNCIONES ---*/
void load (char *p, int *n)
{
    int ii = 0;
    void (*ptrAFunc) (char *, int *); // puntero a funciones
    printf("Cuantos elementos desea ingresar: ");
    scanf("%d", n);
    p = (char *) malloc(*n * sizeof(char)); // invocacion funcion malloc
    if (p == NULL)
    {
        printf("\nMemoria insuficiente...\n");
        exit(0);
    }
    for (ii = 0; ii < *n; ii++)
    {
        printf("Ingrese el caracter n°%d: ", ii+1);
        scanf(" %c", (p+ii));
    } // for
    ptrAFunc = mostrarOrden; // direccion de memoria de la funcion "mostrarOrden"
    (*ptrAFunc)(p, n); // invocacion de la funcion

    ptrAFunc = mostrarOrdenInverso; // direccion de memoria de la funcion "mostrarOrdenInverso"
    (*ptrAFunc)(p, n); // invocacion de la funcion
}
void mostrarOrden (char *p, int *n)
{
    int ii = 0;
    printf( BLUE_T "\nCaracteres ingresados:\t");
    for (ii = 0; ii < *n; ii++)
    {
        printf("%c\t", *(p+ii));
    } // for
    printf("\n" RESE_COLOR );
} // funcion mostrarOrden
void mostrarOrdenInverso (char *p, int *n)
{
    int ii = 0;
    printf( CYAN_T "\nCaracteres en orden Inverso:\t");
    for (ii = 0; ii < *n; ii++)
    {
        printf("%c\t", *(p+(*n-1)-ii));
    } // for
    printf("\n" RESE_COLOR );
} // funcion mostrarOrdenInverso