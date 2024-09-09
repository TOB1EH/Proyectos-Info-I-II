/*--- LIBRERIAS ---*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 20

/*--- ESTRUCTURAS ---*/
struct datosCancion
{
    char artista[TAM];
    char titulo[TAM];
    int duracion;
    float tam_kb;
};

/*--- FUNCION PRINCIPAL MAIN ---*/
int main(int argc, char const *argv[])
{
    struct datosCancion cancion; // declaracion de la estructura (comienza a ocupar memoria)
    /* Carga de datos */
    printf("Ingrese el titulo de cancion: ");
    fgets(cancion.titulo, TAM, stdin); // aca aparece el error "declaracion implicita de la funcion gets y agregra incluso si no quise decir fgets"
    printf("Ingrese el nombre del Artista: ");
    fgets(cancion.artista, TAM, stdin);
    printf("Ingrese la duracion de la cancion en segundos: ");
    scanf("%d", &cancion.duracion);
    printf("Ingrese el tamaño en KB de la cancion: ");
    scanf("%f", &cancion.tam_kb);
    /* Impreseion de la estructura ("datos de cancion") */
    printf("\nDatos de la cancion:\n"
            "Artista: %s"
            "Titulo: %s"
            "Duracion: %d seg\n"
            "Tamaño: %.2f KB\n",
            cancion.artista, cancion.titulo, cancion.duracion, cancion.tam_kb);
    return 0;
}
