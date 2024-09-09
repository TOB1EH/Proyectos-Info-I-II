/* Librerias */
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
    char **materias;
    float *notas;
};

/* Prototipo de funciones */
void print (struct Alumno *alumno);

/* Funcion principal main */
int main(int argc, char const *argv[])
{
    /* Declaracion e inicializacion de variables */
    struct Alumno alumno;
    int cantMaterias = 0, ii = 0;
    float nota = 0;
    long telefono = 0;
    
    /* Carga de datos */
    printf("COMPLETE LOS DATOS DEL ALUMNO:\n"
            "Ingrese datos personales segun corresponda:\n"
            "Nombre: ");
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
    scanf("%li", &telefono);
    alumno.persona.telefono = telefono;
    printf("Ingrese la cantidad de materias que cursa: ");
    scanf("%d", &cantMaterias);
    alumno.materias = (char **)malloc(cantMaterias*sizeof(char *)); // redimension array materias, arreglo de strings para almacenar el nombre de cada materia
    alumno.notas = (float *)malloc(cantMaterias*sizeof(float)); // redimension de array notas, para almacenar la nota final de cada materia
    if (alumno.materias == NULL || alumno.notas == NULL)
    {
        printf("\nMemoria insuficiente\n");
        exit(0); // si no hay memoria suficiente finalizar el programa
    }
    for (ii = 0; ii < cantMaterias; ii++)
    {
        *(alumno.materias+ii) = (char *)malloc(TAM_STRINGS*sizeof(char)); // posicion de mem para almacenar cada string: materia
        if (*(alumno.materias+ii) == NULL)
        {
            printf("\nMemoria insuficiente\n");
            exit(0); //  si no hay memoria finalizar
        }
        setbuf(stdin, NULL);
        printf("Introduzca el nombre de la materia: ");
        fgets(*(alumno.materias+ii), TAM_STRINGS, stdin);
        printf("Introduzca la nota final: ");
        scanf("%f", &nota);
        *((alumno.notas)+ii) = nota;
    }

    /* Impresion de datos */
    print(&alumno);
    printf("Materias y Notas finales:\n");
    for (ii = 0; ii < cantMaterias; ii++)
    {
        printf("- %s\tNota final: %.1f", *(alumno.materias+ii), *((alumno.notas)+ii));
        printf("\n");
    }
    printf("\n");

    /* Liberar Memoria */
    free(alumno.notas);
    free(alumno.materias);
    return 0;
} // main
/* Funciones */
void print (struct Alumno *alumno)
{
    printf("\nDatos personales y academicos registrados:\n"
        "Nombre y Apellido: %s %s\n"
        "Fecha de nacimiento: %d/%d/%d\n"
        "Domicilio:\n\tLocalidad: %s"
        "\tCalle: %s"
        "\tBarrio: %s"
        "CEL: %ld\n",
        alumno->persona.nombre, alumno->persona.apellido,
        alumno->persona.fecha.dia, alumno->persona.fecha.mes, alumno->persona.fecha.anio,
        alumno->persona.direccion.localidad, alumno->persona.direccion.calle,
        alumno->persona.direccion.barrio,
        alumno->persona.telefono);
}
