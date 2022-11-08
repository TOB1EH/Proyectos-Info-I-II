/* 8.  Escribir un programa que tenga un menú de opciones, cada una de ellas una función:
a. Cargar lista de productos en el archivo. b. Leer la lista de productos del archivo.
Para ello deberá crear un vector de estructura llamada "Producto" y de tamaño 3. La estructura
"Producto" contendrá los siguientes atributos: nombre del producto, marca, precio unitario,
fecha de elaboración, tamaño. El archivo se llamará “Listado_Producto.txt”.  */

/* Librerias */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "librerias/open_file.h"

/* Directivas */
#define TAM_STRINGS 20
#define TAM 3

/* Estructuras */
typedef struct Producto
{
    char name[TAM_STRINGS];
    char marca[TAM_STRINGS];
    float precio;
    char fecha[TAM_STRINGS];
    float tam;
}producto_t;

/* Prototipo de Funciones */
void writeFile(FILE **file, producto_t p[]);
void readFile(FILE **file);

/* Funcion principal main */
int main(int argc, char const *argv[])
{
    /* Declaracion e inicializacion de variables */
    char opcion = 0;
    producto_t productos[TAM];
    FILE *file = NULL;
    system("cls");
    do // bucle para menu de opciones
    {
        printf("Menu de opciones:\n"
                "a. Cargar lista de productos en el archivo.\n"
                "b. Leer la lista de productos del archivo.\n"
                "c. Cerrar menu.\n"
                "Ingrese una opcion: ");
        scanf(" %c", &opcion);
        opcion = tolower(opcion);
        switch (opcion)
        {
        case 'a':
            writeFile(&file, productos);
            break;
        case 'b':
            readFile(&file);
            break;
        case 'c':
            printf("\nCerrando...\n");
            break;
        default:
            printf("\nOpcion invalida. Intente nuevamente.\n");
            break;
        }
    } while (opcion != 'c');
    return 0;
} // main

/* Funciones */
void writeFile(FILE **file, producto_t p[TAM])
{
    *file = fopen("archivos/eje8.txt", "w");
    openFile(file);
    for (int i = 0; i < TAM; i++)
    {
        printf("\nIngrese el nombre del producto nro%d: ", (i+1));
        scanf(" %[^\n]", p[i].name);
        printf("\nIngrese la marca: ");
        scanf(" %[^\n]", p[i].marca);
        printf("\nIngrese la fecha de elaboracion: ");
        scanf(" %[^\n]", p[i].fecha);
        printf("\nIngrese el precio unitario: ");
        scanf("%f", &p[i].precio);
        printf("\nIngrese el tamanio: ");
        scanf("%f", &p[i].tam);
        /* Escritura del archivo */
        fputs(p[i].name, *file);
        fputs("\n", *file);
        fputs(p[i].marca, *file);
        fputs("\n", *file);
        fputs(p[i].fecha, *file);
        fputs("\n", *file);
        fprintf(*file, "%f\n%f\n", p[i].precio, p[i].tam);
    }
    fclose(*file);
    printf("\nDATOS CARGADOS CON EXITO!\n");
} // writeFile
void readFile(FILE **file)
{
    producto_t p;
    *file = fopen("archivos/eje8.txt", "r");
    openFile(file);
    printf("\nLista de productos:\n");
    while (!feof(*file))
    {
        fgets(p.name, TAM_STRINGS, *file);
        fgets(p.marca, TAM_STRINGS, *file);
        fgets(p.fecha, TAM_STRINGS, *file);
        fscanf(*file, "%f\n%f\n", &p.precio, &p.tam);
        printf("\tNombre: %s"
                "\tMarca: %s"
                "\tElaboracion: %s"
                "\tPrecio unitario: $%.2f.\n"
                "\tTamanio: %.2f.\n"
                "\n",
                p.name,
                p.marca,
                p.fecha,
                p.precio,
                p.tam);
    }
    fclose(*file);
}