/* 1. Escriba un programa que cree un archivo llamado "datos_personales.txt” que
pregunte los siguientes datos personales: nombre, apellido, dni, edad, nacionalidad.
Luego abrir el archivo y mostrarlo. */

/* Librerias */
#include <stdio.h>
#include <stdlib.h>
#include "librerias/open_file.h"

/* Directivas */
#define TAM_SG 20

/* Estructuras */
typedef struct datos
{
    char nombre[TAM_SG];
    char apellido[TAM_SG];
    int dni;
    int edad;
    char nacion[TAM_SG];
}datos_t;

/* Funcion principal main */
int main(int argc, char const *argv[])
{
    /* Declaracion e inicializacion de variables */
    datos_t datos;
    FILE *file = NULL;
    /* Escritura */
    file = fopen("archivos/datos_personales.txt", "w");
    openFile(&file);
    printf("Ingrese su nombre: ");
    scanf(" %s", datos.nombre);
    printf("\nIngrese su apellido: ");
    scanf(" %s", datos.apellido);
    printf("\nIngrese su edad: ");
    scanf("%d", &datos.edad);
    printf("\nIngrese su DNI: ");
    scanf("%d", &datos.dni);
    printf("\nIngrese su nacionalidad: ");
    scanf(" %s", datos.nacion);
    /* Carga */
    fprintf(file, "%s\n%s\n%d\n%d\n%s\n",
            datos.nombre,
            datos.apellido,
            datos.edad,
            datos.dni,
            datos.nacion);
    fclose(file);
    /* Lectura */
    file = fopen("archivos/datos_personales.txt", "r");
    openFile(&file); // invocacion de la funcion
    /* Impresion */
    printf("Datos registrados:\n");
    while (!feof(file))
    {
        fscanf(file, "%s\n%s\n%d\n%d\n%s\n",
                datos.nombre,
                datos.apellido,
                &datos.edad,
                &datos.dni,
                datos.nacion);
        printf("%s\n%s\n%d\n%d\n%s\n",
                datos.nombre,
                datos.apellido,
                datos.edad,
                datos.dni,
                datos.nacion);
    }
    fclose(file);
    return 0;
} // main