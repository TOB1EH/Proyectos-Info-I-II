#include <stdio.h>
#include <stdlib.h>

/* Directivas */
#define TAM_STRINGS 20
#define TAM_ARRAY 5

/* Estructuras */
struct fechaNacimiento
{
    int dia;
    int mes;
    int anio;
};
struct Direccion
{
    char calle[TAM_STRINGS];
    char barrio[TAM_STRINGS];
    char localidad[TAM_STRINGS];
};
struct Persona
{
    char nombre[TAM_STRINGS];
    char apellido[TAM_STRINGS];
    struct fechaNacimiento fecha;
    struct Direccion direccion;
    long telefono;
};
struct Alumno
{
    struct Persona persona;
    char materias;
    float notas;
};

/* Prototipo de funciones */
void print (struct Alumno *alumno);
/* Funcion principal main */
int main(int argc, char const **argv[])
{
    /* Declaracion e inicializacion de variables */
    struct Alumno alumno;
    int nMaterias = 0, ii = 0, jj = 0;
    char *ptrMaterias = &alumno.materias;
    float *ptrNotas = &alumno.notas;

    /* Carga de datos */
    printf("COMPLETE LOS DATOS DEL ALUMNO:\n");
    printf("Ingrese datos personales segun corresponda:\nNombre: ");
    scanf(" %s", alumno.persona.nombre);
    printf("Apellido: ");
    scanf(" %s", alumno.persona.apellido);
    printf("Fecha de nacimiento:\nDia: ");
    scanf(" %d", &alumno.persona.fecha.dia);
    printf("Mes: ");
    scanf(" %d", &alumno.persona.fecha.mes);
    printf("Anio: ");
    scanf(" %d", &alumno.persona.fecha.anio);
    printf("Direccion/Domicilio:\ncalle: ");
    setbuf(stdin, NULL);
    fgets(alumno.persona.direccion.calle, TAM_STRINGS, stdin);
    printf("Barrio: ");
    setbuf(stdin, NULL);
    fgets(alumno.persona.direccion.barrio, TAM_STRINGS, stdin);
    printf("Localidad: ");
    setbuf(stdin, NULL);
    fgets(alumno.persona.direccion.localidad, TAM_STRINGS, stdin);
    printf("Ingrese el numero de telefono: ");
    scanf(" %li", &alumno.persona.telefono);
    setbuf(stdin, NULL);

    printf("Ingrese la cantidad de materias que cursa: ");
    scanf("%d", &nMaterias);
    setbuf(stdin, NULL);
    ptrNotas = (float *)malloc(nMaterias * sizeof(float)); 
    ptrMaterias = (char **)malloc(nMaterias * sizeof(char *));
    if (ptrNotas == NULL || ptrMaterias == NULL)
    {
        printf("\nMemoria insuficiente.\n");
        exit(0);
    }
    for (ii = 0; ii < nMaterias; ii++)
    {
        *(ptrMaterias+ii) = (char *)malloc(TAM_STRINGS*sizeof(char));
        if (*(ptrMaterias+ii) == NULL)
        {
            printf("\nMemoria insuficiente\n");
            exit(0);
        }
        printf("Introduzca el nombre de la materia: ");
        setbuf(stdin, NULL);
        fgets(*(ptrMaterias+ii), TAM_STRINGS, stdin);
        printf("Introduzca la nota final: ");
        scanf("%f", ptrNotas+ii);
        setbuf(stdin, NULL);
    }
    /* Impresion de datos */
    print(&alumno);
    printf("Materias y Notas finales:\n");
    for (ii = 0; ii < nMaterias; ii++)
    {
        printf("%s", alumno->(materias+ii));
        // printf("%s %.1f", *(ptrMaterias+ii), *(ptrNotas+ii));
        printf("\n");
    }
    printf("\n");

    /* Liberacion de memoria */
    free(ptrMaterias);
    free(ptrNotas);
    return 0;
}
/* Funciones */
void print (struct Alumno *alumno)
{
    printf("\nDatos personales y academicos registrados:\n"
        "Nombre y Apellido: %s %s\n"
        "Fecha de nacimiento: %d/%d/%d\n"
        "Domicilio:\n\tLocalidad: %s"
        "\tCalle: %s"
        "\tBarrio: %s"
        "CEL: %li\n",
        alumno->persona.nombre, alumno->persona.apellido,
        alumno->persona.fecha.dia, alumno->persona.fecha.mes, alumno->persona.fecha.anio,
        alumno->persona.direccion.localidad, alumno->persona.direccion.calle,
        alumno->persona.direccion.barrio,
        alumno->persona.telefono);
}