/* Ejercicio 3: Crear un programa en la cual cargue una lista de 5
numeros aleatoriamente (entre 1 y 10), luego los muestre y muestre
los valores multiples de 5. */

/* Librerias */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* Directivas */
#define TAM_LIST 5
/* Estructuras */
struct Lista
{
    int data;
    struct Lista* next;
};

void addend (struct Lista**);
/* Funcion principal main */
int main(int argc, char const *argv[])
{
    int ii = 0, data = 0;
    struct Lista* head = NULL;
    srand(time(NULL));
    for (ii = 0; ii < TAM_LIST; ii++)
    {
        data = rand()%10+1;
    }
    
    addend(&head);
    return 0;
}
void addend (struct Lista** head)
{

}