/* Librerias */
#include <stdio.h>
#include <stdlib.h>

int potencia (int n1, int n2);

int main(int argc, char const *argv[])
{
    int num1 = 0, num2 = 0;
    printf("Ingrese un numero entero: ");
    scanf("%d", &num1);
    printf("Ingrese la potencia a la cual desea elevarlo: ");
    scanf("%d", &num2);
    printf("%d elevado a la %d = %d", num1, num2, potencia(num1, num2));
    return 0;
}

int potencia (int n1, int n2)
{
    int temp = 0;
    if (n1==0)
    {
        return 0;
    }
    if (n2==0)
    {
        return 1;
    }
    else
    {
        if (n2>0)
        {
            temp = n1*potencia(n1, n2-1);
            return temp;
        }
    }
}