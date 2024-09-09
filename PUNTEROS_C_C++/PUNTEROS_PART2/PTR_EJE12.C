/*--- LIBRERIAS ---*/
#include <stdio.h>
#include <ctype.h>

/*--- DIRECTIVAS ---*/
#define TAM 10 // directiva tamaño para el arreglo
#define CYAN_T "\x1b[36m" // color cyan para texto
#define RESET_COLOR "\x1b[0m" // resetear propiedades de colores

/*--- PROTOTIPO DE FUNCIONES ---*/
void load (float *); // carga los datos del arreglo
void menu (float *); // menu de opciones para operar
void cantSaldos (float *); // cantidad de saldos ingresados
void promedio (float *); // calcula el promedio de los saldos ingresados
void saldosMenorProm (float *); // muestra los saldos menores al promedio
void saldosMayorProm (float *); // " " mayores al promedio
void recaudadoMes (float *); // calcula la recaudacion del mes (suma de saldos)
void print (float *); // imprime los valores del arreglo

/*--- FUNCION PRINCIPAL MAIN ---*/
int main(int argc, char const *argv[])
{
    /* Declaracion e inicializacion de varibles */
    float vector[TAM] = {0}, *ptr = vector;

    void (*ptrAFunc) (float *); // puntero a funcion
    ptrAFunc = load; // asigna la direccion de mem. de una funcion al puntero "ptrAFunc" (idem para el resto)
    (*ptrAFunc)(ptr); // invocacion de la funcion apuntada (idem para el resto)
    ptrAFunc = menu;
    (*ptrAFunc)(ptr);
    return 0;
} // main

/*--- FUNCIONES ---*/
void load (float *ptr)
{
    /* Declaracion e inicializacion de varibles */
    int ii = 0;
    float value = 0;

    printf("Ingrese los saldos de los proveedores:\n"
            "La carga finaliza con un saldo menor o igual a cero.\n");
    for (ii = 0; ii < TAM; ii++)
    {
        printf("Saldo %d: ", 1+ii);
        scanf("%f", &value);
        if (value <= 0) ii = TAM; // true: se termina el ciclo for con los valores ingresados hasta el momento
        *(ptr+ii) = value;
    } // for
} // funcion load
void print (float *ptr)
{
    /* Declaracion e inicializacion de varibles */
    int ii = 0;

    printf("\nTodos los Saldos:\n");
    for (ii = 0; ii < TAM; ii++)
    {
        if (*(ptr+ii) != 0) printf("$%.2f\t", *(ptr+ii));
    }
    printf("\n");
} // funcion print
void menu (float *ptr)
{
    /* Declaracion e inicializacion de variables */
    char opcion = 0;
    int stop_while = 0;

    void (*ptrAFunc) (float *);
    do // ciclo repetitivo do-while
    {
        printf( CYAN_T "\nMenu de opciones:\n" RESET_COLOR
                "a. Cantidad de saldos cargados.\n"
                "b. Promedio de saldos.\n"
                "c. Cantidad de saldos menores al promedio.\n"
                "d. Cantidad de saldos mayores al promedio.\n"
                "e. Calcular cuanto fue lo recaudado en el mes.\n"
                "f. Mostrar saldos.\n"
                "g. Cerrar menu.\n"
                "Ingrese una opcion: ");
        scanf(" %c", &opcion);
        opcion = tolower (opcion); // convierte el valor ingresado en minus. para tolerar ingresos de mayus
        switch (opcion)
        {
        case 'a':
            ptrAFunc = cantSaldos; // asigna la direccion de mem. de una funcion al puntero "ptrAFunc" (idem para el resto)
            (*ptrAFunc)(ptr); // invocacion de la funcion apuntada (idem para el resto)
            break;
        case 'b':
            ptrAFunc = promedio;
            (*ptrAFunc)(ptr);
            break;
        case 'c':
            ptrAFunc = saldosMenorProm;
            (*ptrAFunc)(ptr);
            break;
        case 'd':
            ptrAFunc = saldosMayorProm;
            (*ptrAFunc)(ptr);
            break;
        case 'e':
            ptrAFunc = recaudadoMes;
            (*ptrAFunc)(ptr);
            break;
        case 'f':
            ptrAFunc = print;
            (*ptrAFunc)(ptr);
            break;
        case 'g':
            printf("\nCerrando...\n");
            stop_while = 1; // el ciclo se repitira si y solo si stop_while es igual a cero
            break;
        default:
            printf("\nOpcion ivalida. Intente nuevamente...\n");
            break;
        }
    } while (stop_while == 0);
} // funcion menu
void cantSaldos (float *ptr)
{
    /* Declaracion e inicializacion de varibles */
    int ii = 0, saldos  = 0;

    for (ii = 0; ii < TAM; ii++)
    {
        if (*(ptr+ii) > 0) saldos++;
    }
    printf("\nCantidad de saldos cargados: %d\n", saldos);
} // funcion cantSaldos
void promedio (float *ptr)
{
    /* Declaracion e inicializacion de varibles */
    int ii = 0, saldos  = 0;
    float suma = 0, prom = 0;

    for (ii = 0; ii < TAM; ii++)
    {
        if (*(ptr+ii) > 0)
        {
            saldos++; // saldos+1
            suma += *(ptr+ii); // suma = valor del vector apuntado por el ptr
        }
    }
    prom = ((float) suma/saldos);
    printf("\nPromedio de saldos: %.2f\n", prom);
} // funcion promedio
void saldosMenorProm (float *ptr)
{
    /* Declaracion e inicializacion de varibles */
    int ii = 0, saldos  = 0;
    float suma = 0, prom = 0;

    for (ii = 0; ii < TAM; ii++)
    {
        if (*(ptr+ii) > 0)
        {
            saldos++;
            suma += *(ptr+ii);
        }
    }
    prom = ((float) suma/saldos);
    printf("\nSaldos menores al promedio:\n");
    for (ii = 0; ii < TAM; ii++)
    {
        if (*(ptr+ii) < prom && *(ptr+ii) > 0) printf("%.2f\t", *(ptr+ii));
    }
    printf("\n");
} // funcion saldosMenorProm
void saldosMayorProm (float *ptr)
{
    /* Declaracion e inicializacion de varibles */
    int ii = 0, saldos  = 0;
    float suma = 0, prom = 0;
    
    for (ii = 0; ii < TAM; ii++)
    {
        if (*(ptr+ii) > 0)
        {
            saldos++;
            suma += *(ptr+ii);
        } // if
    } // for
    prom = ((float) suma/saldos); // casteo a punto flotante
    printf("\nSaldos mayores al promedio:\n");
    for (ii = 0; ii < TAM; ii++)
    {
        if (*(ptr+ii) > prom) printf("%.2f\t", *(ptr+ii));
    }  // for
    printf("\n");
} // funcion saldosMayorProm
void recaudadoMes (float *ptr)
{
    /* Declaracion e inicializacion de varibles */
    int ii = 0;
    float recaudacion = 0;

    for (ii = 0; ii < TAM; ii++)
    {
        recaudacion += *(ptr+ii);
    }
    printf("\nRecaudado en el mes: $%.2f\n", recaudacion);
} // funcion recaudadoMes