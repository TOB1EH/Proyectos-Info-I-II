/* 2. Escriba un programa que cree un archivo binario llamado
"pares.txt” que contenga los valores pares del 1 al 100. Luego
abrir el archivo y mostrarlo. */

/* Librerias */
#include <stdio.h>
#include <stdlib.h>

/* Funcion principal main */
int main(int argc, char const *argv[])
{
    /* Declaracion e inicializacion de variables */
    FILE *fp = NULL;
    int data = 0;

    fp = fopen("./pares.txt", "w");
    if (fp == NULL)
    {
        printf("\nImposible crear el archivo!\n");
        exit(0);
    }
    do
    {
        data = data+2;
        fputc(data, fp);
    } while (data<101);
    fclose(fp);

    fp = fopen("./pares.txt", "r");
    if (fp == NULL)
    {
        printf("\nImposible crear el archivo!\n");
        exit(0);
    }
    while (!feof(fp))
    {
        data = getc(fp);
        printf("%d\t", data);
    }
    fclose(fp);
    return 0;
} // main

/* Funciones */
