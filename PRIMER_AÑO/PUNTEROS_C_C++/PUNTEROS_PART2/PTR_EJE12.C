/*--- LIBRERIAS ---*/
#include <stdio.h>
#include <ctype.h>

/*--- DIRECTIVAS ---*/
#define TAM 10

/*--- PROTOTIPO DE FUNCIONES ---*/
void load (float *);
void menu (float *);
void cantSaldos (float *);
void promedio (float *);

void print (float *);

int main(int argc, char const *argv[])
{
    /* Declaracion e inicializacion de varibles */
    float vector[TAM] = {0}, *ptr = vector;

    void (*ptrAFunc) (float *);
    ptrAFunc = load;
    (*ptrAFunc)(ptr);
    ptrAFunc = menu;
    (*ptrAFunc)(ptr);
    ptrAFunc = print;
    (*ptrAFunc)(ptr);
    return 0;
}

/*--- FUNCIONES ---*/
void load (float *ptr)
{
    int ii = 0;
    float value = 0;
    printf("Ingrese los saldos de los proveedores:\n");
    for (ii = 0; ii < TAM; ii++)
    {
        printf("Saldo %d: ", 1+ii);
        scanf("%f", &value);
        if (value <= 0) ii = TAM;
        *(ptr+ii) = value;
    }
}
void print (float *ptr)
{
    int ii = 0;
    for (ii = 0; ii < TAM; ii++)
    {
        if (*(ptr+ii) != 0) printf("%.2f\t", *(ptr+ii));
    }
    printf("\n");
}
void menu (float *ptr)
{
    char opcion = 0;
    int stop_while = 0;

    void (*ptrAFunc) (float *);
    do
    {
        printf("\nMenu de opciones:\n"
                "a. Cantidad de saldos cargados.\n"
                "b. Promedio de saldos.\n"
                "c. Cantidad de saldos menores al promedio.\n"
                "d. Cantidad de saldos mayores al promedio.\n"
                "e. Calcular cuanto fue lo recaudado en el mes.\n"
                "f. Mostrar saldos."
                "g. Cerrar menu.\n"
                "Ingrese una opcion: ");
        scanf(" %c", &opcion);
        opcion = tolower (opcion); // convierte el valor ingresado en minus. para tolerar ingresos de mayus
        switch (opcion)
        {
        case 'a':
            ptrAFunc = cantSaldos;
            (*ptrAFunc)(ptr);
            break;
        case 'b':
            ptrAFunc = promedio;
            (*ptrAFunc)(ptr);
            break;
        case 'g':
            printf("\nCerrando...\n");
            stop_while = 1;
            break;
        default:
            printf("\nOpcion ivalida. Intente nuevamente...\n");
            break;
        }
    } while (stop_while == 0);
}
void cantSaldos (float *ptr)
{
    int ii = 0, saldos  = 0;
    for (ii = 0; ii < TAM; ii++)
    {
        if (*(ptr+ii) > 0) saldos++;
    }
    printf("\nCantidad de saldos cargados: %d\n", saldos);
}
void promedio (float *ptr)
{
    int ii = 0, saldos  = 0;
    float suma = 0;
    for (ii = 0; ii < TAM; ii++)
    {
        if (*(ptr+ii) > 0)
        {
            saldos++;
            suma += *(ptr+ii);
        }
    }
    printf("\nPromedio de saldos: %.2f\n", ((float) suma/saldos));
}