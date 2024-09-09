/* Librerias */
#include <stdio.h>
#include <stdlib.h>
#include "menu_opciones.h"


/* Funcion principal main */
int main(int argc, char const *argv[])
{
    int stopWhile = 0;
    char opcion = 0;
    do // Menu de opciones
    {
        menuOpciones(&opcion);
    } while (stopWhile == 0);
    
    return 0;
}
