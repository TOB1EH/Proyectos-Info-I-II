#include "opcion.h"
#include "ctype.h"

/* Funcion para recibir la opcion del menu y convertirla a minuscula:
Recibe el caracter para interactuar con un menu de opciones, y a su vez
transforma cualquier caracter que se ingrese a minusculas para tener
una mayor interaccion con el menu en caso de que el usuario ingrese una
mayuscula. */
void opcionMenu (char *opcion)
{
    printf("Ingrese una opcion: ");
    scanf(" %c", opcion);
    *opcion = tolower(*opcion); // coonvierte los caracteres a minusculas
}