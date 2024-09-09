/* Librerias */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/* Directivas */
#define TAM 3 // tamano de arreglos
#define STRING_TAM 30 // tamaño de strings

/* Estructuras */
struct datosCanciones
{
    char titulo[STRING_TAM];
    char artista[STRING_TAM];
    int duracion;
    float tam_kb;
};

/* Prototipo de Funciones */
void consumirNuevaLinea (void);
void agregarCancion (struct datosCanciones cArray[], int *count);
void imprimirLista (struct datosCanciones cArray[], int *count);
void buscarCancion (struct datosCanciones cArray[], int *count);

/* Funcion principal main */
int main(int argc, char const *argv[])
{
    /* Declaracion e inicializacion de variables */
    char opcion = 0; // opcion para interactura con el menu
    int count = 0; // contador, para tener el numero de canciones ingresadas 
    int stopWhile = 0; // varible para detener el ciclo do-while 
    struct datosCanciones cArray[TAM]; // arreglo de estructura datosCancion
    
    /* Menu  */
    do // ciclo repetitivo do-while
    {
        printf("\n\nMenu de opciones:\n"
                "a. agregar una nueva canción.\n"
                "b. mostrar todas las canciones.\n"
                "c. buscar una canción por titulo.\n"
                "d. cerrar menu.\n"
                "Ingrese una opcion: ");
        scanf(" %c", &opcion);
        opcion = tolower(opcion); // convierte la opcion ingresada a minusculas para mayor compatibilidad
        switch (opcion)
        {
        case 'a':
            /* carga de datos */
            agregarCancion(cArray, &count);
            break;
        case 'b':
            /* impresion de datos */
            imprimirLista(cArray, &count);
            break;
        case 'c':
            /* comparador/buscar cancion por titulo */
            buscarCancion(cArray, &count);
            break;
        case 'd':
            /* terminar ciclo do-while */
            printf("\nCerrando...\n");
            stopWhile = 1;
            break;
        default:
            /* caso por descarte */
            printf("\nIngreso una opcion invalida. Intente nuevamente...\n");
            break;
        }
    } while (stopWhile == 0);
    return 0;
} // main

/* Funciones */
void agregarCancion (struct datosCanciones cArray[], int *count)
{
    if (*count < TAM)
    {
        printf("\nIngrese el titulo de cancion: ");
        setbuf(stdin, NULL);
        fgets(cArray[*count].titulo, STRING_TAM, stdin);
        printf("\nIngrese el nombre del Artista: ");
        fgets(cArray[*count].artista, STRING_TAM, stdin);
        printf("\nIngrese la duracion de la cancion en segundos: ");
        scanf("%d", &cArray[*count].duracion);
        printf("\nIngrese el tamaño en KB de la cancion: ");
        scanf("%f", &cArray[*count].tam_kb);
        *count+=1; // contador +1
    }
    else
    {
        printf("\nLista de canciones llena.\n");
    }
} // function agregarCancion
void imprimirLista (struct datosCanciones cArray[], int *count)
{
    int ii = 0;
    for (ii = 0; ii < (*count); ii++)
    {
        printf("\nDatos de la cancion n°%d:\n"
                "Artista: %s"
                "Titulo: %s"
                "Duracion: %d seg\n"
                "Tamaño: %.2f KB\n", 
                ii+1,
                cArray[ii].artista,
                cArray[ii].titulo, 
                cArray[ii].duracion,
                cArray[ii].tam_kb);
    }
}
void buscarCancion (struct datosCanciones cArray[], int *count)
{
    char name[STRING_TAM]={0};
    int ii = 0, cent = 0;
    printf("\nIngrese el Titulo: ");
    setbuf(stdin, NULL);
    fgets(name, STRING_TAM, stdin);
    for (ii = 0; ii < *count; ii++)
    {
        if ((strcmp(cArray[ii].titulo, name)) == 0)
        {
            printf("\nCancion encontrada!\n"
                    "Artista: %s"
                    "Titulo: %s"
                    "Duracion: %d seg\n"
                    "Tamaño: %.2f KB\n",
                    cArray[ii].artista,
                    cArray[ii].titulo,
                    cArray[ii].duracion,
                    cArray[ii].tam_kb);
            cent = 1;
        }
    }
    if (cent == 0) printf("\nTitulo no encontrado.\n");
}