// Informatica -  Funciones E3 - Funes Tobias

#include <stdio.h>


/* Prototipos Funciones: */
float cuadrado (void);
float triangulo (void);
float circulo (void);

int main(int argc, char const *argv[])
{
    int opcion=0, stop_while=0;
    char si_no=' ';
    do // Ciclo do-While menu de opciones
    {
        printf("Calculo de Area y Perimetro de figuras geométricas:\n");
        printf("Ingrese una opcion:"
                "\n1. Cuadrado/Rectangulo"
                "\n2. Triangulo"
                "\n3. Circulo"
                "\n4. Finalizar Programa"
                "\nOpcion: ");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            cuadrado(); // invicacion a la funcion para calculos de un cuadrado/rectangulo
            break;
        case 2:
            triangulo(); // invicacion a la funcion para calculos de un triangulo
            break;
        case 3:
            circulo(); // invicacion a la funcion para calculos de un circulo
            break;
        case 4:
            printf("\nCerrando...\n");
            stop_while = 1; // detener ciclo do-while
            break;
        default: // caso por descarte para caracteres invalidos
            printf("\nOpcion invalida. Intente nuevamnete\n");
            break;
        }
        printf("Realizar Otra operacion (S/N)? ");
        scanf(" %c", &si_no);
        if (si_no == 'S' || si_no == 's') stop_while = 0; // reiniciar menu de opciones
        else if (si_no == 'N' || si_no == 'n')
        {
            printf("Cerrando...\n");
            stop_while = 1; // detener ciclo do-while
        }
        else
        {
            printf("\nCaracter invalido...se reiniciara el menu\n");
        }
    } while (stop_while==0);
    return 0;
}

/* FUNCIONES: */

float cuadrado (void) // Funcion para calculo de Perimetro y area de un Cuadrado/Rectangulo
{
    /* Cuerpo de la funcion */
    float base=0, altura=0;
    printf("\nPerimetro y Area de un Cuadrado/Rentangulo:\n");
    printf("Ingrese los sig. datos:\n");
    printf("Medida Base: ");
    scanf("%f", &base);
    printf("Medida Altura: ");
    scanf("%f", &altura);
        // Operaciones:
    if (base == altura)
    {
        printf("\nPerimetro del Cuadrado: %.2f\n", (base*2)+(altura*2));
        printf("Area del Cuadrado: %.2f\n\n", (base*altura)/2);
    }
    else
    {
        printf("\nPerimetro del Rectangulo: %.2f\n", (base*2)+(altura*2));
        printf("Area del Rectangulo: %.2f\n\n", (base*altura)/2);
    }   
}

float triangulo (void) // Funcion para calculo de Perimetro y area de un Triangulo
{
    /* Cuerpo de la funcion */
    float base=0, altura=0, lado_1=0, lado_2=0, lado_3=0;
    printf("\nPerimetro y Area de un Triangulo:\n");
    printf("Ingrese los sig. datos:\n");
    printf("Medida Base: ");
    scanf("%f", &base);
    printf("Medida Altura: ");
    scanf("%f", &altura);
    printf("Medida lado 1: ");
    scanf("%f", &lado_1);
    printf("Medida lado 2: ");
    scanf("%f", &lado_2);
    printf("Medida lado 3: ");
    scanf("%f", &lado_3);
        // Operaciones:     
    printf("\nPerimetro del Triangulo: %.2f\n", lado_1+lado_2+lado_3);
    printf("Area del Triangulo: %.2f\n\n", (base*altura)/2);
}

float circulo (void) // Funcion para calculo de Perimetro y area de un Circulo
{
    /* Cuerpo de la funcion */
    float radio=0, pi=3.14159265359;
    printf("\nPerimetro y Area de un Circulo:\n");
    printf("Ingrese los sig. datos:\n");
    printf("Medida Radio del circulo: ");
    scanf("%f", &radio);
        // Operaciones    
    printf("\nPerimetro del Circulo: %.2f\n", 2*pi*radio);
    printf("Area del Circulo: %.2f\n\n", pi*(radio*radio));
}