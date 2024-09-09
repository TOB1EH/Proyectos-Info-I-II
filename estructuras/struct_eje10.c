/* Ejercicio 10. Una  fábrica  de  tornillos  nos  ha  solicitado  desarrollar  un  programa
en  C  que permita  obtener  e  imprimir  las  estadísticas  de  una  determinada  muestra
de tornillos.  Para  ello  nos  indican  que  cada  tornillo  viene  caracterizado  por  su
longitud  y  su  diámetro  y  que  ambas  medidas deben  almacenarse  en  un  registro con
dos campos. Desarrollar un programa en C que:
    a. Solicite  al  usuario  los  datos  de  una   muestra  de   tornillos  (longitud  y
diámetro) y los almacene en un vector.
    b. A  partir  de  los  datos  introducidos  calcule  y  muestre  por  pantalla  la  media
de las longitudes y la media de los diámetros.
Nota:  El  tamaño  de  la  muestra  se  definirá  como  una  constante  denominada TAMANIO_MUESTRA */

/* Librerias */
#include <stdio.h>
#include <stdlib.h>

/* Directivas */
#define TAMANIO_MUESTRA 5

/* Estructuras */
struct muestraTornillos
{
    float longitud;
    float diametro;
};
/* Declaracion  de tipo definido por el usuario */
typedef struct muestraTornillos tornillos_t;

/* Prototipo de Funciones */

/* Funcion principal main */
int main(int argc, char const *argv[])
{
    tornillos_t *muestras = NULL;
    int cantMuestras = 0, stopWhile = 0;

    /* Gestion de cant de muestrasTornillos */
    do
    {
        printf("Introduzca la cantidad de muestrasTornillos(MAX 10): ");
        scanf("%d", &cantMuestras);
        if (cantMuestras > TAMANIO_MUESTRA) // verifica si se supera el tope max
            printf("\nSupero el max. Intente nuevamente.\n");
        else
        {
            stopWhile = 1; // finaliza el bucle do-while
        }
    } while (stopWhile == 0); // do-while 1
    
    /* Redimension de memoria, Arreglo de estructuras dinamico */
    muestras = (tornillos_t *)malloc(cantMuestras * sizeof(tornillos_t));
    if (muestras == NULL)
    {
        printf("\nMemoria insuficiente\n"); 
        exit(0); // Finaliza el programa
    }

    printf("Hola");
    
    /* Liberar memoria */
    free(muestras);
    return 0;
} // main