/* Librerias */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

/* Directivas */
#define TAM 20

/* Estructuras */
typedef struct Score
{
    char name[TAM];
    float notas[3];
    float recuperatorio;
    float notaFinal;
    char resultado;
    struct Score *next;
}score_t;

/* Prototipo de Funciones */
void append (score_t **head, score_t **node);
float promNotas (score_t **node);
void printList (score_t *head);
void freeMemory (score_t **head);


/* Funcion principal main */
int main(int argc, char const *argv[])
{
    srand(time(NULL));
    /* Declaracion e inicializacion de variables */
    char opcion = 0;
    int alum = 0;
    score_t *head = NULL;
    score_t *node = NULL;

    /* Carga de Datos */

    printf("Calificaciones Ingles.\n"
            "Cuantos alumnos va a cargar: ");
    scanf("%d", &alum);
    for (int i = 0; i < alum; i++)
    {
        append(&head, &node);
        printf("Ingrese el nombre del alumno: ");
        scanf(" %s", node->name);
        for(int jj = 0; jj < 3; jj++)
        {
            node->notas[jj] = rand()%10;
        } // for
        if (node->notas[0]>=4 && node->notas[1]>=4 && node->notas[3]>=4)
        {
            node->recuperatorio = -1;
        } // if
        else
        {
            node->recuperatorio = rand()%10;
        } // else
        node->notaFinal = promNotas(&node); // calcula el promedio final
    }




    do // ciclo menu de opciones
    {
        printf("Menu de opciones:\n"
            "a. Mostrar el listado de calificaciones del curso.\n"
            "b. Mostrar el/los mejor/es alumno/s.\n"
            "c. Mostrar todos los alumnos que reprobaron (promedio menor a 4).\n"
            "d. Mostrar todos los alumnos que aprobaron (promedio mayor o igual a 4).\n"
            "e. Mostrar todos los alumnos que tuvieron al menos un ausente.\n"
            "f. Contar cuantos alumnos en total hay en el curso.\n"
            "g. Grabar un archivo llamado calificaciones.txt en donde se listen los datos.\n"
            "h. Cerrar menu.\n"
            "Ingrese una opcion: ");
        scanf(" %c", &opcion);
        opcion = tolower(opcion);
        switch (opcion)
        {
        case 'a':
            printf("Listado de calificaciones:\n");
            printList(head);
            break;
        default:
            break;
        } // switch
    } while (opcion != 'h'); // do-while
    /* Liberar memoria */
    freeMemory(&head);
    return 0;
} // main

/* Funciones */
void append (score_t **head, score_t **node)
{
    score_t *temp = NULL;
    *node = (score_t *)malloc(sizeof(score_t *));
    if (*node == NULL)
    {
        printf("\nNo hay memoria!\n");
        exit(1);
    } // if
    (*node)->next = NULL;
    if (*head == NULL)
    {
        *head = *node;
    } // if
    else
    {
        temp = *head;
        while (temp != NULL)
        {
            temp = temp->next;
        }
        temp->next = *node;
    } // else
} // append
float promNotas (score_t **node)
{
    int ii = 0;
    if ((*node)->recuperatorio == -1)
    {
        for (ii = 0; ii < 3; ii++)
        {
            (*node)->notaFinal += (*node)->notas[ii];
        } // for
    } // if
    if ((*node)->recuperatorio < 4 && ((*node)->notas[0] < 4 || (*node)->notas[1] < 4 || (*node)->notas[3] < 4))
    {
        (*node)->notaFinal = 0;
    } // if
    else
    {
        for (ii = 0; ii < 3; ii++)
        {
            if ((*node)->notas[ii]>=4 && (*node)->recuperatorio>=4)
            {
                (*node)->notaFinal += (*node)->notas[ii];
            } // if
        } // for
        (*node)->notaFinal += (*node)->recuperatorio;
    } // else
    return ((*node)->notaFinal/3);
} // promNotas
void printList (score_t *head)
{
    int count = 0;
    score_t *temp = NULL;
    temp = head;
    while (temp != NULL)
    {
        count++;
        printf("Alumno nro %d:\n"
                "\tNombre: %s"
                "\tNota 1: %.2f\n"
                "\tNota 2: %.2f\n"
                "\tNota 3: %.2f\n"
                "\tRecuperatorio: %.2f\n"
                "\tNota final: %.2f\n"
                "\tResultado: \n",
                count,
                temp->name,
                temp->notas[0],
                temp->notas[1],
                temp->notas[2],
                temp->recuperatorio,
                temp->notaFinal,
                temp->resultado);
        temp = temp->next;
    } // while
} // printList
void freeMemory (score_t **head)
{
    score_t *temp = NULL;
    while (*head != NULL)
    {
        temp = *head;
        *head = temp->next;
        free(temp);
    } // while
} // freeMemory