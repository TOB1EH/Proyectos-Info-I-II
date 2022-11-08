/* 6.  Escribir un programa que solicite los datos de un producto (nombre del producto, marca, precio
unitario, fecha de elaboración, tamaño) y lo guarde en un archivo con el nombre “Datos_Producto.txt”.6.
Escribir un programa que solicite los datos de un producto (nombre del producto, marca, precio unitario,
fecha de elaboración, tamaño) y lo guarde en un archivo con el nombre “Datos_Producto.txt”. */

/* Librerias */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "librerias/open_file.h"

/* Directivas */
#define TAM_STRINGS 20

/* Estructuras */
typedef struct producto
{
    char name[TAM_STRINGS];
    char marca[TAM_STRINGS];
    float precio;
    char fecha[TAM_STRINGS];
    float tam;
}producto_t;

/* Funcion principal main */
int main(int argc, char const *argv[])
{
    /* Declaracion e inicializacion de variables */
    char op = 0;
    producto_t product;
    FILE *file = NULL;

    /* Carga de datos */
    printf("\n********** CARGA DE PRODUCTO **********\n"
            "\nNombre del Producto: ");
    scanf(" %[^\n]", product.name);
    printf("\nMarca: ");
    scanf(" %[^\n]", product.marca);
    printf("\nPrecio unitario: ");
    scanf("%f", &product.precio);
    printf("\nFecha elaboracion (DD/MM/AA): ");
    scanf(" %[^\n]", product.fecha);
    printf("\nTamanio: ");
    scanf("%f", &product.tam);

    /* Escribir en el archivo */
    file = fopen("archivos/Datos_Producto.txt", "w");
    openFile(&file); // verifica si se puede abrir el archivo
    fputs(product.name, file);
    fputs("\n", file);
    fputs(product.marca, file);
    fputs("\n", file);
    fputs(product.fecha, file);
    fputs("\n", file);
    fprintf(file, "%f\n%f\n", product.precio, product.tam);
    fclose(file); // cerrar el archivo

    /* Lectura del archivo */
    do
    {
        printf("\nDesea Leer el archivo?(S/N) ");
        scanf(" %c", &op);
        op = tolower(op);
        switch (op)
        {
        case 's':
            file = fopen("archivos/Datos_Producto.txt", "r");
            openFile(&file);
            while (!feof(file))
            {
                fgets(product.name, TAM_STRINGS, file);
                fgets(product.marca, TAM_STRINGS, file);
                fgets(product.fecha, TAM_STRINGS, file);
                fscanf(file, "%f\n%f\n", &product.precio, &product.tam);
                printf("\tNombre: %s\tMarca: %s\tPrecio: $%.2f\n\tElaboracion: %s\tTamanio: %.2f",
                        product.name,
                        product.marca,
                        product.precio,
                        product.fecha,
                        product.tam);
            }
            fclose(file); // cerrar el archivo
            break;
        case 'n':
            printf("\bCerrando...\n");
            break;
        default:
            printf("\nOpcion invalida.\n");
            break;
        }
    } while (op != 'n');
    return 0;
} // main
