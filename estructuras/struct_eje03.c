#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define TAM 3
#define STRING_TAM 30

struct Empleado
{
    long legajo;
    char puesto_de_trabajo[STRING_TAM];
    float sueldo;
    int anios_antiguedad;
};

void agregarEmpleado (struct Empleado empleado[], int *count);
void listaDeEmpleados (struct Empleado empleado[], int *count);
void buscarXLegajo (struct Empleado empleado[], int *count);
void actualizarSueldo (struct Empleado empleado[], int *count);
void ordenarXSueldo (struct Empleado empleado[], int *count);
void ordenarxAnios (struct Empleado empleado[], int *count);

/* Funcion principal main */
int main(int argc, char const *argv[])
{
    /* Declaracion e inicializacion de variables */
    char opcion = 0;
    int stopWhile = 0, count = 0, cent = 0;
    struct Empleado empleado[TAM] = {0};
    /* Menu de opciones */
    do
    {
        printf("Menu de opciones:\n"
                "a. agregar un empleado.\n"
                "b. mostrar todos los empleados.\n"
                "c. buscar un empleado por legajo para ver si existe o no.\n"
                "d. actualizar sueldo.\n"
                "e. ordenar por sueldo.\n"
                "f. ordenar por anios de antiguedad.\n"
                "g. cerrar menu.\n"
                "Ingrese una opcion: ");
        scanf(" %c", &opcion);
        opcion = tolower(opcion);
        switch (opcion)
        {
        case 'a':
            cent = 1; 
            agregarEmpleado(empleado, &count);
            break;
        case 'b':
            if (cent == 0) printf("\nNo se cargaron empleados todavia.\n");
            listaDeEmpleados(empleado, &count);
            break;
        case 'c':
            buscarXLegajo(empleado, &count);
            break;
        case 'd':
            actualizarSueldo(empleado, &count);
            break;
        case 'e':
            ordenarXSueldo(empleado, &count);
            break;
        case 'f':
            ordenarxAnios(empleado, &count);
            break;
        case 'g':
            stopWhile = 1;
            break;
        default:
            printf("\nOpcion invalida. Intente nuevamente...\n");
            break;
        }
    } while (stopWhile == 0);
    return 0;
} // main

void agregarEmpleado (struct Empleado empleado[], int *count)
{
    if (*count < TAM)
    {
        printf("Ingrese el n° de legajo: ");
        scanf(" %li", &empleado[*count].legajo);
        printf("Ingrese el puesto de trabajo: ");
        setbuf(stdin, NULL);
        fgets(empleado[*count].puesto_de_trabajo, STRING_TAM, stdin);
        printf("Ingrese el sueldo correspondiente: $");
        scanf(" %f", &empleado[*count].sueldo);
        printf("Anios de antiguedad: ");
        scanf(" %d", &empleado[*count].anios_antiguedad);
        *count+=1;
        setbuf(stdin, NULL);
    }
    else
    {
        printf("\nLista de empleados llena.\n");
    }
} // function agregarEmpleado
void listaDeEmpleados (struct Empleado empleado[], int *count)
{
    int ii = 0;
    printf("\nLista de empleados:\n");
    for (ii = 0; ii < *count; ii++)
    {
        printf("* Empleado n°%d:\n"
                "\tN° de legajo: %li\n"
                "\tPuesto de trabajo: %s"
                "\tSueldo: $%.2f\n"
                "\tAnios de antiguedad: %d\n",
                ii+1,
                empleado[ii].legajo,
                empleado[ii].puesto_de_trabajo,
                empleado[ii].sueldo,
                empleado[ii].anios_antiguedad);
    }
} // function listaDeEmpleados
void buscarXLegajo (struct Empleado empleado[], int *count)
{
    int ii = 0;
    long n_legajo = 0;
    printf("Ingrese el numero de legajo a buscar: ");
    scanf("%li", &n_legajo);
    for (ii = 0; ii < *count; ii++)
    {
        if (empleado[ii].legajo == n_legajo)
        {
            printf("\nEmpleado encontrado!\n"
                    " Empleado n°%d:\n"
                    "N° de legajo: %li\n"
                    "Puesto de trabajo: %s"
                    "Sueldo: $%.2f\n"
                    "Anios de antiguedad: %d\n",
                    ii+1,
                    empleado[ii].legajo,
                    empleado[ii].puesto_de_trabajo,
                    empleado[ii].sueldo,
                    empleado[ii].anios_antiguedad);
        }
        else
        {
            printf("\nNo existe un empleado con ese numero de legajo :(\n");
        }
    }
} // function buscarXLegajo
void actualizarSueldo (struct Empleado empleado[], int *count)
{
    int ii = 0;
    long n_legajo = 0;
    printf("\nBUSCAR EMPLEADO POR N° DE LEGAJO:\n"
            "Ingrese el N° de legajo: ");
    scanf("%li", &n_legajo);
    for (ii = 0; ii < *count; ii++)
    {
        if (empleado[ii].legajo == n_legajo)
        {
            printf("Empleado encontrado!\n"
                    "Sueldo actual: $%.2f\n"
                    "Ingrese el nuevo sueldo: $",
                    empleado[ii].sueldo);
            scanf("%f", &empleado[ii].sueldo);
        }
        else
        {
            printf("\nEmpleado no encontrado. Intente nuevamente...\n");
        }
    }
} // function actualizarSueldo
void ordenarXSueldo (struct Empleado empleado[], int *count)
{
    int ii = 0, jj = 0;
    struct Empleado tempo;
    for (ii = 1; ii < *count; ii++)
    {
        for (jj = 0; jj < *count-1; jj++)
        {
            if (empleado[jj].sueldo > empleado[jj+1].sueldo)
            {
                tempo = empleado[jj];
                empleado[jj] = empleado[jj+1];
                empleado[jj+1] = tempo; 
            }
        }
    }
    printf("\nSueldos ordenados de menor a mayor con exito!\n\n");
} // funcion 'ordenarxSueldo'
void ordenarxAnios (struct Empleado empleado[], int *count)
{
    int ii = 0, jj = 0;
    struct Empleado tempo;
    for (ii = 1; ii < *count; ii++)
    {
        for (jj = 0; jj < *count-1; jj++)
        {
            if (empleado[jj].anios_antiguedad < empleado[jj+1].anios_antiguedad)
            {
                tempo = empleado[jj];
                empleado[jj] = empleado[jj+1];
                empleado[jj+1] = tempo; 
            }
        }
    }
    printf("\nAnios ordenados de mayor a menor con exito!\n\n");   
}