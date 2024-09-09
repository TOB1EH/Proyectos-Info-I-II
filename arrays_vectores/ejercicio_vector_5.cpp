// Informática - Vectores ejercicio N°5 - Funes Tobias

#define RAN 50 // 50 = valor maximo de saldos que se pueden ingresar en el ciclo for
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int ii=0, stop_for=0, stop_while=0, cant_menor=0, cant_mayor=0;
    float v_saldos[RAN]={0}, saldo=0, suma=0, prom=0; 
    char opcion=' ';
    stop_for = RAN; /* en un principio stop_for toma el valor maximo de saldos que se pueden
    ingresar en caso de que se alcance el maximo antes de finalizar el proceso de carga */ 
    printf("Ingrese los saldos de cada provedor(MAXIMO 50):\n");
    printf("Para finalizar ingrese un numero <= 0\n");
    for (ii = 0; ii < stop_for; ii++)
    {
        printf("Provedor %d: $", ii+1);
        scanf("%f", &saldo);

        if (saldo <= 0) stop_for = ii; /* la variable stop_for sirve para detener el ciclo for 
        y tambien para almacenar la cantidad de saldos ingresados */
        
        else // sino, los elementos del vector toman 
        {
            v_saldos[ii] = saldo; /* el elemento del vector determinado por el valor de 'ii' 
            tomara el valor de saldo ingresado en ese momento */ 
            suma += saldo; // suma de valores ingresados
        }
    }
    prom = suma/(float)stop_for; // calculo del promedio de los saldos ingresados
    do // ciclo do-while
    {
        opcion = ' ';
        printf("\nDesea continuar con el menu de opciones(S/N): ");
        scanf(" %c", &opcion);
        if (opcion =='N' || opcion =='n') stop_while = 1; // terminar ciclo do-while
        else if (opcion =='S' || opcion =='s') // abre el menu de opciones
        {
            printf("\n\nMenu de opciones:");
            printf("\na. Cantidad de saldos cargados.");
            printf("\nb. Promedio de saldos.");
            printf("\nc. Cantidad de saldos menores al promedio.");
            printf("\nd. Cantidad de saldos mayores al promedio.");
            printf("\ne. Recaudado en el mes.");
            printf("\nINGRESE LA OPCION DESEADA: ");
            scanf(" %c", &opcion);
            switch (opcion)
            {
            case 'a':
                printf("\nOpcion a. ");
                printf("Cantidad de saldos cargados: %d", stop_for);
                break;
            case 'b':
                printf("\nOpcion b. ");
                printf("Promedio : %.2f", prom);
                break;
            case 'c':
                printf("\nOpcion c. ");
                for (ii = 0; ii < stop_for; ii++)
                {
                    if (v_saldos[ii] < prom)
                    {
                        cant_menor++;
                    }
                }
                printf("Cant. de Saldos menores al promedio: %d", cant_menor);
                break;
            case 'd':
                printf("\nOpcion d. ");
                for (ii = 0; ii < stop_for; ii++)
                {
                    if (v_saldos[ii] > prom)
                    {
                        cant_mayor++;
                    }
                }
                printf("Cant. de Saldos mayores al promedio: %d", cant_mayor);
                break;
            case 'e':
                printf("\nOpcion e. ");
                printf("Recaudado este mes: $%.2f", suma);
                break;
            default: // caso por descarte
                printf("\nCaracter ingresado no valido...");
                break;
            } //cierre switch
        }// cierre else       
    } while (stop_while == 0);
    return 0;
}