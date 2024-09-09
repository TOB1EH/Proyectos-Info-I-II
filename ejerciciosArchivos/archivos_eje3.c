/* 3. Escriba un programa que cree un menu de opciones que permita a) abrir un archivo,
b) escribir un archivo, c) leer un archivo.  */

/* Librerias */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "librerias/open_file.h"

/* Directivas */
#define TAM_SG 30

/* Funcion principal main */
int main(int argc, char const *argv[])
{
    /* Declaracion e inicializacion de variables */
    char opcion = 0;
    char nameFile[TAM_SG] = {0};
    char string[1000] = {0};
    FILE *file = NULL;

    do
    {
        printf("Menu de opciones:\n"
                "a. Abrir un archivo.\n"
                "b. Excribir un archivo.\n"
                "c. Leer un archivo.\n"
                "d. Cerrar menu.\n"
                "Ingrese una opcion: ");
        scanf(" %c", &opcion);
        opcion = tolower(opcion);
        switch (opcion)
        {
        case 'a':
            printf("Ingrese el nombre y ruta del archivo: ");
            setbuf(stdin, NULL);
            fgets(nameFile, TAM_SG, stdin);
            nameFile[strcspn(nameFile, "\n")] = 0;
            file = fopen(nameFile, "a+");
            openFile(&file);
            printf("\nArchivo abierto con exito!\n");
            fclose(file);
            break;
        case 'b':
            printf("Ingrese el nombre y ruta del archivo: ");
            setbuf(stdin, NULL);
            fgets(nameFile, TAM_SG, stdin);
            nameFile[strcspn(nameFile, "\n")] = 0;
            file = fopen(nameFile, "w");
            openFile(&file);
            scanf(" %[^\n]", string);
            fprintf(file, "%s", string);
            fclose(file);
            break;
        case 'c':
            printf("Ingrese el nombre y ruta del archivo: ");
            setbuf(stdin, NULL);
            fgets(nameFile, TAM_SG, stdin);
            nameFile[strcspn(nameFile, "\n")] = 0;
            file = fopen(nameFile, "r");
            openFile(&file);
            while (!feof(file))
            {
                fscanf(file, "%s", string);
                printf("%s ", string);
            }
            printf("\n");
            fclose(file);
            break;
        case 'd':
            printf("\nCerrando...\n");
        default:
            printf("\nOpcion invalida. Intente nuevamente.\n");
            break;
        }
    } while (opcion != 'd');
    return 0;
} // main
