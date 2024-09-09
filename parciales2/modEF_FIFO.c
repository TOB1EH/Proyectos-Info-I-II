/* Librerias */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

/* Directivas */
#define TAM 20

/* Estructuras */
typedef struct Score
{
    char name[TAM];
    int nota1;
    int nota2;
    int nota3;
    int recup;
    float notaFinal;
    char resultado[TAM];
    struct Score *next;
}score_t;

/* Prototipo de Funciones */

/* Agregar nuevo Nodo */
void append (score_t **front, score_t **back,score_t **node);
/* Calcular promedio o nota final */
float promNotas (score_t **node);
/* Imprimir Lista */
void printList (score_t *head);
/* Buscar el mejor Promedio */
void mejorPromedio (score_t *head);
/* Liberar memoria */
void freeMemory (score_t **head);
/* Buscar alumnos desaprobados */
void desaprobrados (score_t *head);
/* Buscar alumnos aprobados */
void aprobrados (score_t *head);
/* Buscar alumnos con al menos un ausente */
void ausentes (score_t *head);
/* Contar cantidad de nodos */
int countNodes (score_t *head);
/* Crear archivo para guardar las calificaciones */
void archive (score_t **head);

/* Funcion principal main */
int main(int argc, char const *argv[])
{
    srand(time(NULL));
    /* Declaracion e inicializacion de variables */
    char opcion = 0;
    int alum = 0;
    score_t *front = NULL;
    score_t *back = NULL;
    score_t *node = NULL;

    /* Carga de Datos */
    printf("Calificaciones Ingles.\n"
            "Cuantos alumnos va a cargar: ");
    scanf("%d", &alum);
    for (int i = 0; i < alum; i++)
    {
        append(&front, &back, &node);
        printf("Ingrese el nombre del alumno: ");
        setbuf(stdin, NULL);
        fgets(node->name, TAM, stdin);
        node->name[strcspn(node->name, "\n")] = 0;
        node->nota1 = rand()%10;
        node->nota2 = rand()%10;
        node->nota3 = rand()%10;
        if (node->nota1 >=4 && node->nota2 >=4 && node->nota3 >=4)
        {
            node->recup = -1;
        } // if
        else
        {
            node->recup = rand()%10;
        } // else
        node->notaFinal = promNotas(&node); // calcula el promedio final
        if (node->notaFinal >= 4)
        {
            strcpy(node->resultado, "Aprobado");
        } // if
        else
        {
            strcpy(node->resultado, "Desaprobado");
        } // else
    } // for

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
            printList(front);
            break;
        case 'b':
            printf("Mejores promedios:\n");
            mejorPromedio(front);
            break;
        case 'c':
            printf("Alumnos Desaprobados:\n");
            desaprobrados(front);
            break;
        case 'd':
            printf("Alumnos Aprobados:\n");
            aprobrados(front);
            break;
        case 'e':
            printf("Alumnos con ausentes:\n");
            ausentes(front);
            break;
        case 'f':
            printf("Cantidad de alumnos: %d\n", countNodes(front));
            break;
        case 'g':
            archive(&front);
            break;
        case 'h':
            printf("\nCerrando...\n");
            break;
        default:
            break;
        } // switch
    } while (opcion != 'h'); // do-while
    /* Liberar memoria */
    freeMemory(&front);
    return 0;
} // main

/* Funciones */
void append (score_t **front, score_t **back, score_t **node)
{
    score_t *temp = NULL;
    *node = (score_t *)malloc(sizeof(score_t));
    if (*node == NULL)
    {
        printf("\nNo hay memoria!\n");
        exit(1);
    } // if
    (*node)->next = NULL;
    if (*back == NULL)
    {
        *back = *node;
        *front = *back;
    } // if
    else
    {
        (*back)->next = *node;
        *back = *node;
    } // else
} // append
float promNotas (score_t **node)
{
    int ii = 0;
    if ((*node)->recup == -1)
    {
        (*node)->notaFinal= (*node)->nota1+(*node)->nota2+(*node)->nota3;
    } // if
    else
    {
        if ((*node)->recup < 4 && ((*node)->nota1 < 4 || (*node)->nota2 < 4 || (*node)->nota3 < 4))
        {
            (*node)->notaFinal = 0;
        } // if
        else
        {
            if ((*node)->recup >=4)
            {
                if ((*node)->nota1 >=4)
                {
                    (*node)->notaFinal += (*node)->nota1;
                } // if
                if ((*node)->nota2 >=4)
                {
                    (*node)->notaFinal += (*node)->nota2;
                } // if
                if ((*node)->nota3 >=4)
                {
                    (*node)->notaFinal += (*node)->nota3;
                } // if
            } // if
            (*node)->notaFinal += (*node)->recup;
        } // else
    } // else
    return ((*node)->notaFinal/3);
} // promNotas
void printList (score_t *front)
{
    int count = 0;
    score_t *temp = NULL;
    temp = front;
    while (temp != NULL)
    {
        count++;
        printf("Alumno nro %d:\n"
                "\tNombre: %s\n"
                "\tNota 1: %d\n"
                "\tNota 2: %d\n"
                "\tNota 3: %d\n"
                "\trecup: %d\n"
                "\tNota final: %.2f\n"
                "\tResultado: %s\n",
                count,
                temp->name,
                temp->nota1,
                temp->nota2,
                temp->nota3,
                temp->recup,
                temp->notaFinal,
                temp->resultado);
        temp = temp->next;
    } // while
    printf("\n");
} // printList
void freeMemory (score_t **front)
{
    score_t *temp = NULL;
    while (*front != NULL)
    {
        temp = *front;
        *front = temp->next;
        free(temp);
        printf("OK\n");
    } // while
} // freeMemory
void mejorPromedio (score_t *front)
{
    int count = 0;
    float bestProm = 0;
    score_t *temp = front;
    while (temp != NULL)
    {
        if (temp->notaFinal > bestProm)
        {
            bestProm = temp->notaFinal;

        }
        temp = temp->next;
    } // while
    temp = front;
    while (temp != NULL)
    {
        count++;
        if (temp->notaFinal == bestProm)
        {
            printf("\tAlumno nro %d.\n"
                    "\tNombre: %s\n"
                    "\tPromedio: %.2f\n",
                    count,
                    temp->name,
                    temp->notaFinal);
        }
        temp = temp->next;
    } // while
    printf("\n");
} // mejorPromedio
void desaprobrados (score_t *front)
{
    int count = 0;
    score_t *temp = front;
    while (temp != NULL)
    {
        count++;
        if (temp->notaFinal < 4)
        {
            printf("\tAlumno nro %d.\n"
                    "\tNombre: %s\n"
                    "\tPromedio: %.2f\n",
                    count,
                    temp->name,
                    temp->notaFinal);
        }
        temp = temp->next;
    }
    printf("\n");
} // desaprobados
void aprobrados (score_t *front)
{
    int count = 0;
    score_t *temp = front;
    while (temp != NULL)
    {
        count++;
        if (temp->notaFinal >= 4)
        {
            printf("\tAlumno nro %d.\n"
                    "\tNombre: %s\n"
                    "\tPromedio: %.2f\n",
                    count,
                    temp->name,
                    temp->notaFinal);
        }
        temp = temp->next;
    }
    printf("\n");
} // aprobados
void ausentes (score_t *front)
{
    int count = 0;
    score_t *temp = front;
    while (temp != NULL)
    {
        count++;
        if (temp->nota1 == 0 ||
            temp->nota2 == 0 ||
            temp->nota3 == 0 ||
            temp->recup == 0)
        {
            printf("\tAlumno nro %d.\n"
                    "\tNombre: %s\n",
                    count,
                    temp->name);
        } // if
        temp = temp->next;
    } // while
    printf("\n");
} // ausentes
int countNodes (score_t *front)
{
    int count = 0;
    score_t *temp = front;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    } // while
    return count;
} // countNodes
void archive (score_t **front)
{
    score_t *temp = *front;
    FILE *fp = NULL;
    fp=fopen("calificaciones.txt", "w+"); //abre el archivo
    if (fp == NULL)
    {
        perror("calificaciones.txt");
        exit(1);
    } // if
    fputs("INFORME DE CALIFICACIONES DE INGLES\n", fp);
    fputs("Alumno N1 N2 N3 Recup. Promedio Resultado\n", fp);
    while (temp != NULL)
    {
        fprintf(fp, "%s %d %d %d %d %.2f %s\n",
            temp->name,
            temp->nota1,
            temp->nota2,
            temp->nota3,
            temp->recup,
            temp->notaFinal,
            temp->resultado);
        temp = temp->next;
    } // while
    fclose(fp); // cierra el archivo
} // archive