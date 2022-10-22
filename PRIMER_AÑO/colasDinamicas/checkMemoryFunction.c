#include "structCola.h"
#include "check_memory.h"
#include <stdio.h>
#include <stdlib.h>

void checkMemory (struct node **newNode)
{
    if (*newNode == NULL) // verifica si hay memoria suficiente
    {
        printf("\nMemoria insuficiente!\n");
        exit(0); // si no hay memmoria finaliza el programa
    }
}