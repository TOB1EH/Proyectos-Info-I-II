#include <stdio.h>

int * funcion (int *);

int main(int argc, char const *argv[])
{
    int *ptr = NULL, num = 190;
    int * (*ptrAFunc) (int *);

    ptr = &num;

    ptrAFunc = funcion;
    ptr = (*ptrAFunc)(ptr);

    printf("Nuevo valor puntero: %d\n", *ptr);
    return 0;
}

int * funcion (int *ptr)
{
    int num = 122;
    printf("Valor puntero: %d\n", *ptr);
    ptr = &num;
    return(ptr);
}