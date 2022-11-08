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
    /* Abrir archivo para escritura */
    fp = fopen("./archivos/pares.txt", "w");
    if (fp == NULL)
    {
        printf("\nImposible crear el archivo!\n");
        exit(0);
    }
    while (data<100)
    {
        data+=2;
        fprintf(fp, "%d\t", data);
    }
    fclose(fp);
    /* Abrir archivo para Lectura */
    fp = fopen("./archivos/pares.txt", "r");
    if (fp == NULL)
    {
        printf("\nImposible abrir el archivo!\n");
        exit(0);
    }
    while (!feof(fp))
    {
        fscanf(fp, "%d\t", &data);
        printf("%d\t", data);
    }
    fclose(fp);

/*  do
    {
        data = data+2;
        fputc(data, fp);
    } while (data<=100);
    fclose(fp);
    while (!feof(fp))
    {
        data = getc(fp);
        printf("%d\t", data);
    }
    fclose(fp); */
    return 0;
} // main