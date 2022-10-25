#include "menu_opciones.h"

/* Implementacion de la funcion de menu de opciones */
void menuOpciones (char *opcion)
{
    printf("Menu de opciones:\n"
            "Opcion a.\n"
            "Opcion b.\n"
            "Opcion c.\n"
            "Ingrese una opcion");
    scanf(" %c", opcion);
    printf("\nOpcion ingresada: %c", *opcion);
} // end function
