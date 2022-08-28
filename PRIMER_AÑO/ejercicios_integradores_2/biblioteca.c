#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*------------------------- DIRECTIVAS ----------------------------------*/
#define FIL 10
#define COL 4

/*------------------------ PROTOTIPO FUNCIONES ----------------------------*/
void cargar_valores (int [][COL]);
void imprimir_datos_cargados (int [][COL]);
void prestar_libros (int [][COL]);

/*----------------------- FUNCION PRINCIPAL MAIN ----------------------------*/
int main(int argc, char const *argv[])
{
    int biblioteca[FIL][COL]={0};
    // Invocacion de Funciones:
    cargar_valores(biblioteca);
    imprimir_datos_cargados(biblioteca);
    prestar_libros(biblioteca);
    return 0;
}

/*--------------------- FUNCIONES -----------------------------------*/
void cargar_valores (int biblioteca[][COL])
{
    int ii = 0, jj = 0;
    int cod = 0;
    srand(time((NULL)));
    for (ii = 0; ii < FIL; ii++)
    {
        for (jj = 0; jj < COL; jj++)
        {
            if (jj == 0)
            {
                cod++;
                biblioteca[ii][jj] = cod;
            }
            if (jj == 1 || jj == 3)
            {
                biblioteca[ii][jj] = rand()%6+5;
            }
        }
    }
}

void imprimir_datos_cargados (int biblioteca[][COL])
{
    int ii = 0, jj = 0;
    for (ii = 0; ii < FIL; ii++)
    {
        for (jj = 0; jj < COL; jj++)
        {
            printf("%d\t", biblioteca[ii][jj]);
        }
        printf("\n");
    }
}

void prestar_libros (int biblioteca[][COL])
{
    int ii = 0, jj = 0;
    for (ii = 0; ii < FIL; ii++)
    {
        for (jj = 0; jj < COL; jj++)
        {
            if (biblioteca[ii][3] > 0)
            {
                
            }
        }
        
    }
    
}