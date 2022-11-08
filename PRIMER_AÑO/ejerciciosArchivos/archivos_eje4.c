/* 4. Escriba un programa que busque dentro del archivo el_quijote.txt la cantidad de veces
que aparecen las palabras “Quijote”, “Rocinante” y “Sancho”. Recuerden descargar el archivo
en el mismo lugar donde corren el programa. */

/* Librerias */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "librerias/open_file.h"

/* Funcion principal main */
int main(int argc, char const *argv[])
{
    /* Declaracion e inicializacion de variables */
    char texto[30] = {0};
    int countQuijote = 0, countRocinante = 0, countSancho = 0;

    FILE *file = NULL;
    file = fopen("archivos/el_quijote.txt", "r");
    openFile(&file);
    while (fscanf(file, "%s", texto) != EOF)
    {
        if (strcmp(texto, "Quijote") == 0)
            countQuijote++;
        if (strcmp(texto, "Rocinante") == 0)
            countRocinante++;
        if (strcmp(texto, "Sancho") == 0)
            countSancho++;
    }
    fclose(file);
    printf("Quijote: %d veces.\n"
            "Rocinante: %d veces.\n"
            "Sancho: %d veces.\n",
            countQuijote,
            countRocinante,
            countSancho);
    return 0;
} // main

/* Funciones */
