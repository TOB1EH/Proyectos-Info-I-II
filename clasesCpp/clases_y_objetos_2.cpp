/* 2. Crear una clase Libro con sus atributos (a elección) y métodos (setter(), getter(),
toString()). Luego, crear una clase Principal en donde se declare un vector de objetos
Libro. Luego llenar este vector con datos y llamar a las  funciones mostrarListado y
calcularSumaPrecio. Hacer el diagrama de clase de Libro. */

/* Librerias */
#include <iostream>
#include <string.h>

using namespace std;

/* Directivas */
#define TAM_STRINGS 25
#define TAM 2

/* Estructuras */

class Libro // clase
{
private:
    char name[TAM_STRINGS];
    int cantHojas;
    float precio;
public:
    Libro();
    void setData(char titulo[TAM_STRINGS], int hojas, float precio);
    void toString();
    ~Libro();
};
/* Metodos de Clase Libro */
Libro::Libro() // constructor
{
    /* Inicializar atributos */
    name[TAM_STRINGS] = {0};
    //name = NULL;
    cantHojas = 0;
    precio = 0;
}
void Libro::setData(char titulo[TAM_STRINGS], int hojas, float precio_)
{
/*     name = (char *)malloc(TAM_STRINGS*sizeof(char));
    if (name == NULL)
    {
        printf("\nNo hay memoria.\n");
        exit(1);
    } */
    strcpy(name, titulo);
    //name = titulo;
    cantHojas = hojas;
    precio = precio_;
}
void Libro::toString()
{
    printf("Libro: %s\n"
            "Cant. hojas: %d\n"
            "Precio: $%.2f\n\n",
            name,
            cantHojas,
            precio);
}
Libro::~Libro(){} // destructor
class Principal // class
{
private:
    Libro libros[TAM];
public:
    Principal();
    void setData();
    void printData();
    ~Principal();
};

Principal::Principal(){} // constructor
void Principal::setData()
{
    int hojas = 0;
    float precio = 0;
    char cadena[TAM_STRINGS] = {0};
    for (int ii = 0; ii < TAM; ii++)
    {
        printf("\nIngrese el titulo del libro: ");
        scanf(" %[^\n]", cadena);
        printf("\nIngrese la cantidad de hojas: ");
        scanf("%d", &hojas);
        printf("\nIngrese el precio: $"),
        scanf("%f", &precio);
        libros[ii].setData(cadena, hojas, precio);
    }
}
void Principal::printData()
{
    for (int i = 0; i < TAM; i++)
    {
        libros[i].toString();
    }
}
Principal::~Principal(){} // constructor

/* Prototipo de Funciones */
void mostratListado(class Principal);

/* Funcion principal main */
int main(int argc, char const *argv[])
{
    /* Declaracion e inicializacion de variables */
    Principal l;
    char op = 0;

    l.setData(); // cargar datos

    do
    {
        printf("Opciones:\n"
                "a. Listado de libros.\n"
                "b. Suma de precios.\n"
                "c. Cerrar menu"
                "ingrese una opcion: ");
        scanf(" %c", &op);
        op = tolower (op);
        switch (op)
        {
        case 'a':
            mostratListado(l);
            break;
        default:
            break;
        }
    } while (op != 'c');
    return 0;
} // main

/* Funciones */
void mostratListado(class Principal l)
{
    printf("\n***** Lista de libros *****\n");
    l.printData();
}