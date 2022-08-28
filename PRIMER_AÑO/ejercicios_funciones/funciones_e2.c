// Informatica -  Funciones E2 - Funes Tobias

#include <stdio.h>

void suma (float, float); // Prototipo Funcion Suma
void resta (float, float); // Prototipo Funcion Resta
void producto (float, float); // Prototipo Funcion Producto
void division (float, float); // Prototipo Funcion Divivsion

int main(int argc, char const *argv[])
{
    int stop_while=0;
    char opcion=' ';
    float num1=0, num2=0;
    printf("Ingrese dos numeros a operar entre si: ");
    printf("\nNumero 1: ");
    scanf("%f", &num1);
    printf("Numero 2: ");
    scanf("%f", &num2);
    // ciclo do While para operaciones
    do
    {
        printf("\nIngrese la operacion a realizar: ");
        printf("\na. Sumar los numeros\nb. Restar\nc. Producto\nd. Division");
        printf("\ne. Cerrar Calculadora\nOperacion: ");
        scanf(" %c", &opcion);
        switch (opcion)
        {
        case 'a':
            suma(num1, num2); // Llamada a la funcion 'suma'
            break;
        case 'b':
            resta(num1, num2); // Llamada a la funcion 'resta'
            break;
        case 'c':
            producto(num1, num2); // Llamada a la funcion 'producto'
            break;
        case 'd':
            division(num1, num2); // Llamada a la funcion 'division'
            break;
        case 'e':
            printf("\nCerrando...\n");
            stop_while = 1; // termina el ciclo terminando asi tambien el programa
            break;
        default: // caso por descarte
            printf("\nIngreso un Caracter invalido...\nIntente nuevamnete\n");
            break;
        }
    } while (stop_while==0);
    return 0;
}
// Funcion Suma
void suma (float n1, float n2)
{
    printf("\nSuma:\n%.2f + %.2f = %.2f\n", n1, n2, n1+n2);
}
// Funcion Resta
void resta (float n1, float n2)
{
    printf("\nResta:\n%.2f - %.2f = %.2f\n", n1, n2, n1-n2);
    printf("%.2f - %.2f = %.2f\n", n2, n1, n2-n1);
}
// Funcion Producto/Multiplicacion
void producto (float n1, float n2)
{
    printf("\nProducto:\n%.2f * %.2f = %.2f\n", n1, n2, n1*n2);
}
// Funcion Division
void division (float n1, float n2)
{
    printf("\nDivision:\n%.2f / %.2f = %.2f\n", n1, n2, n1/n2);
    printf("%.2f / %.2f = %.2f\n", n2, n1, n2/n1);
}