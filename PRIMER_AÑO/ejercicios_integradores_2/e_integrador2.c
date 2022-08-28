#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*----------------------- Directivas ---------------------------------*/
#define MAX 100
#define COL 2

/*--------------------------------- PROTOTIPO FUNCIONES ----------------------------------------*/

void mejor_nota (int [][COL], int *);  // Funcion para encontrar el alumno con la mejor nota
void peor_nota (int [][COL], int *); // Funcion para encontrar el alumno con la peor nota
void ordenamiento_descendente (int [][COL], int *); // Funcion para ordenar las notas de mayor a menor
void aprobados_desaprobados (int [][COL], int *); // Funcion para conocer la cantidad de candidatos aprobados y desaprobados
void imprimir_grupos (int *, int *, int [][COL], int [][COL]);

/*---------------------------------- FUNCION PRINCIPAL MAIN ---------------------------------------------*/

int main(int argc, char const *argv[])
{
    int array[MAX][COL]={0};
    int ii = 0, jj = 0, filas = 0, nota = 0;
    srand(time(NULL));
    printf("ingrese la cantidad de candidatos inscriptos: ");
    scanf("%d", &filas);
    printf("Cargando datos automaticamente...\n"); // Ciclo for para cargar notas y candidatos con numeros aleatorios
    for (ii = 0; ii < filas; ii++)
    {
        array[ii][0] = ii+1;
        for (jj = 0; jj < COL; jj++)
        {
            nota = rand()%10+1; // funcion para generar numeros aleatorios, del 1 al 10
            array[ii][1] = nota;
        }
    }
    printf("Tabla de Candidatos:\n");
    printf("Cand\tNota\n");
    for (ii = 0; ii < filas; ii++) // Ciclo for para imprimir la tabla de notas y candidatos 
    {
        for (jj = 0; jj < COL; jj++)
        {
            printf("%d\t", array[ii][jj]);
        }
        printf("\n");
    }
    /*--------  Invocacion de Funciones -------------*/
    mejor_nota(array, &filas);
    peor_nota(array, &filas);
    ordenamiento_descendente(array, &filas);
    aprobados_desaprobados(array, &filas);
    return 0;
}

/*----------------------------- FUNCIONES ------------------------------------------*/

void mejor_nota (int array[][COL], int *filas)
{
    int ii = 0, jj = 0;
    int mejor_nota = 0, peor_nota = 0, mejor_estudiante = 0, peor_estudiante = 0;
    //int nota[][COL]={0};
    for (ii = 0; ii < *filas; ii++)
    {
        for (jj = 0; jj < COL; jj++)
        {
            if (array[ii][1] > mejor_nota)
            {
                mejor_nota = array[ii][1];
                mejor_estudiante = array[ii][0];
            }
        }
    }
    printf("\nMejor calificacion: %d, perteneciente al estudiante: %d\n", mejor_nota, mejor_estudiante);
}

void peor_nota (int array[][COL], int *filas)
{
    int ii = 0, jj = 0;
    int peor_nota = 0, peor_estudiante = 0;
    
    for (ii = 0; ii < *filas; ii++)
    {
        for (jj = 0; jj < COL; jj++)
        {
            if (ii == 0 && jj == 1) 
            {
                peor_nota = array[ii][jj];
                peor_estudiante = array[ii][0];
            }
            
            if (array[ii][1] < peor_nota)
            {
                peor_nota = array[ii][1];
                peor_estudiante = array[ii][0];
            }
        }
    }
    printf("Peor calificacion: %d, perteneciente al estudiante: %d\n", peor_nota, peor_estudiante);
}

void ordenamiento_descendente (int array[][COL], int *filas)
{
    int ii = 0, jj = 0, aux1 = 0, aux2 = 0;
    // Ordenamineto por Intercambio o Burbujas:
    for (ii = 0; ii < *filas-1; ii++)
    {
        for (jj = 0; jj < *filas-1; jj++)
        {
            if (array[jj][1] < array[jj+1][1])
            {
                aux1 = array[jj][1];
                aux2 = array[jj][0];
                array[jj][1] = array[jj+1][1];
                array[jj][0] = array[jj+1][0];
                array[jj+1][1] = aux1;
                array[jj+1][0] = aux2;
            }
        }
    }
    // Imprime calificaciones ordenadas de mayor a menor:
    printf("\nCalificaciones por orden de merito, de mayor a menor:\n");
    printf("Cand\tNota\n");
    for (ii = 0; ii < *filas; ii++)
    {
        for (jj = 0; jj < COL; jj++)
        {
            printf("%d\t", array[ii][jj]);
        }
        printf("\n");
    }
}

void aprobados_desaprobados (int array[][COL], int *filas)
{
    int ii = 0, jj = 0, aprob = 0, desaprob = 0;
    int basico[MAX][COL]={0};
    int avanzado[MAX][COL]={0};
    for (ii = 0; ii < *filas; ii++)
    {
        for (jj = 1; jj < COL; jj++)
        {
            if (array[ii][jj] >= 7)
            {
                aprob++;
                avanzado[ii][0] = array[ii][0];
                avanzado[ii][1] = array[ii][1];
            }       
            if (array[ii][jj] < 7 && array[ii][jj] > 0)
            {
                desaprob++;
                basico[ii][0] = array[ii][0];
                basico[ii][1] = array[ii][1]; 
            }
        }       
    }
    printf("\nCant. de alumnos aprobados: %d\n", aprob);
    printf("Cant. de alumnos desaprobados: %d\n", desaprob);

    imprimir_grupos(&aprob, &desaprob, avanzado, basico);
}

void imprimir_grupos (int *aprob, int *desaprob, int avanzado[][COL], int basico[][COL])
{
    int ii = 0, jj = 0;
    if (*aprob < 2 && *aprob > 0)
    {
        *desaprob + *aprob;
        *aprob = 0;
    }
    if (*desaprob < 2 && *desaprob > 0)
    {
        *aprob + *desaprob;
        *desaprob = 0;
    }
    printf("Conforacion de Grupos:\nAVANZADO:\nCand\tNotas\n");
    for (ii = 0; ii < *aprob; ii++)
    {
        for (jj = 0; jj < COL; jj++)
        {
            printf("%d\t", avanzado[ii][jj]);
        }
        printf("\n");
    }
    printf("BASICO:\nCand\tNotas\n");
    for (ii = 0; ii < *desaprob; ii++)
    {
        for (jj = 0; jj < COL; jj++)
        {
            printf("%d\t", basico[ii][jj]);
        }
        printf("\n");
    }   
}