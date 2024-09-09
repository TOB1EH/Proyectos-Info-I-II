// Funes Tobias

/*--- LIBRERIAS ---*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*--- DIRECTIVAS ---*/
#define MAX 10 // cantidad maxima de caracteres

int main(int argc, char const *argv[])
{
    int edad = 0, ID = 0;
    char nombre[MAX] = {' '}, apellido[MAX] = {' '};
    char *pointer = NULL;
    srand(time(NULL)); // funcion de numeros aleatorios
    printf("Menu de Registro:\n");
    printf("Ingrese su Nombre: ");
    scanf("%s", nombre);
    printf("Ingrese su Apellido: ");
    scanf("%s", apellido);
    printf("Ingrese su Edad: ");
    scanf("%d", &edad);
    
    pointer = nombre; // --> pointer = &nombre[0];
    /* asignacion de puntero a la posicion de memoria del primer elemento del arreglo */

    ID = (rand()%6555+1456); // numeros aleatorios muy altos para crear un ID ramdom
    printf("\n\nSus datos se ingresaron correctamente!\n\n\n"
            "- Nombre de usuario: %c.%s\n"
            "- Edad: %d\n"
            "- ID: #%d\n", *pointer, apellido, edad, ID);
    //printf("¿Los datos creados son correctos S/N? ");
    return 0;
}
