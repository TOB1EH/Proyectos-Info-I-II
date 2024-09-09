/* Ejercicio 4: Crear una estructura llamada persona con sus atributos nombre, apellido, fecha
de nacimiento, dirección y teléfono. Tanto la dirección como la fecha de nacimiento son otras
estructuras (estructura anidada). Cargue con datos y luego muéstrelos. */

/* Librerias */
#include <stdio.h>
#include <stdlib.h>

/* Directivas */
#define TAM_STRINGS 15

/* Estructuras */
struct fechaNacimiento
{
    int dia;
    char mes[TAM_STRINGS];
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
/* Prototipo de Funciones */
void print (struct Persona *datosPersonas); // funcion para imprimir los datos cargados
/* Funcion principal main */
int main(int argc, char const *argv[])
{
    /* Declaracion de variables */
    struct Persona datos_persona;
    /* Carga de datos */
    printf("Ingrese datos personales segun corresponda:\n"
            "Nombre: ");
    scanf(" %s", datos_persona.nombre);
    printf("Apellido: ");
    scanf(" %s", datos_persona.apellido);
    printf("Fecha de nacimiento:\nDia: ");
    scanf("%d", &datos_persona.fecha.dia);
    printf("Mes: ");
    scanf(" %s", datos_persona.fecha.mes);
    printf("Anio: ");
    scanf("%d", &datos_persona.fecha.anio);
    printf("Direccion/Domicilio:\ncalle: ");
    setbuf(stdin, NULL);
    fgets(datos_persona.direccion.calle, TAM_STRINGS, stdin);
    printf("Barrio: ");
    setbuf(stdin, NULL);
    fgets(datos_persona.direccion.barrio, TAM_STRINGS, stdin);
    printf("Localidad: ");
    setbuf(stdin, NULL);
    fgets(datos_persona.direccion.localidad, TAM_STRINGS, stdin);
    printf("Ingrese el numero de telefono: ");
    scanf(" %li", &datos_persona.telefono); 
    print(&datos_persona);
    return 0;
}
/* Funciones */
void print (struct Persona *datosPersonas)
{
    printf("\nDatos personales registrados:\n"
            "Nombre y Apellido: %s %s\n"
            "Fecha de nacimiento: %d de %s del %d\n"
            "Domicilio:\n\tLocalidad: %s"
            "\tCalle: %s"
            "\tBarrio: %s"
            "CEL.: %li\n\n",
            datosPersonas->nombre, datosPersonas->apellido,
            datosPersonas->fecha.dia, datosPersonas->fecha.mes, datosPersonas->fecha.anio,
            datosPersonas->direccion.localidad, datosPersonas->direccion.calle,
            datosPersonas->direccion.barrio,
            datosPersonas->telefono);
}