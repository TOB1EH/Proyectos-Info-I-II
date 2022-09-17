/*--- LIBRERIAS ---*/
#include <stdio.h>

#define TAM 15

/*--- ESTRUCTURAS ---*/
struct datos_cancion
{
    char artista[TAM];
    char titulo[TAM];
    int duracion;
    float tam_kb;   
};

/*--- FUNCION PRINCIPAL MAIN ---*/
int main(int argc, char const *argv[])
{
    int ii = 0, count = 0;
    struct datos_cancion cancion; // declaracion de la estructura (comienza a ocupar memoria)
    /* Carga de datos */
    count = TAM;
    printf("Ingrese el titulo de cancion: ");
    for (ii = 0; ii < count; ii++)
    {
        scanf(" %c", &cancion.titulo[ii]);
    }
    printf("Ingrese el nombre del Artista: ");
        for (ii = 0; ii < TAM; ii++)
    {
        scanf(" %c", &cancion.artista[ii]);
    }
    printf("Ingrese la duracion de la cancion en segundos: ");
    scanf("%d", &cancion.duracion);
    printf("Ingrese el tamaño en KB de la cancion: ");
    scanf("%f", &cancion.tam_kb);
    /* Impreseion de la estructura ("datos de cancion") */
    printf("\nDatos de la cancion:\n"
            "Nombre: %s\n"
            "Titulo: %s\n"
            "Duracion: %d seg\n"
            "Tamaño: %.2f KB\n",
            cancion.artista, cancion.titulo, cancion.duracion, cancion.tam_kb);
    return 0;
}