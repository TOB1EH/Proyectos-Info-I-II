/* Librerias */
#include <stdio.h>
#include <stdlib.h>

int producto (int n1, int n2);


int main(int argc, char const *argv[])
{
    int num1 = 0, num2 = 0;
    printf("Ingrese dos num. para multiplicarlos entre si:\n"
        "Num1: ");
    scanf("%d", &num1);
    printf("Num2: ");
    scanf("%d", &num2);
    printf("%d X %d = %d", num1, num2, producto(num1, num2));
    return 0;
} // main

int producto (int n1, int n2)
{
    int temp = 0;
    if (n2>0)
    {
        temp = n1+producto(n1, n2-1);
        return temp;
    } // if
}