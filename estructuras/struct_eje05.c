/* Ejercicio5. Tomar el ejercicio anterior y modificarlo para que se cree un
vector de estructuras de tamaño 5. Cargar valores y mostrar.  */

#include <stdio.h>
#include <stdlib.h>

/* Directivas */
#define TAM_STRINGS 15
#define TAM_ARRAY 3 //5

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

/* Prototipo de funciones*/
void load(struct Persona **persona, int *ii);
void print(struct Persona *persona);

/* Funcion principal main */
int main(int argc, char const *argv[])
{
    int ii = 0;
    struct Persona *persona = NULL;
    persona = (struct Persona *)malloc(TAM_ARRAY * sizeof(struct Persona));
    if (persona == NULL)
    {
        printf("\nMemoria Insuficiente\n");
        exit(0);
    }
    for (ii = 0; ii < TAM_ARRAY; ii++)
    {
        load(&persona, &ii);
    }
    print(persona);
    free(persona);
    return 0;
}
/* Funciones */
void load(struct Persona **persona, int *ii)
{
    setbuf(stdin, NULL);
    printf("Ingrese datos personales segun corresponda:\n"
           "Nombre: ");
    scanf(" %s", (*persona+*ii)->nombre);
    setbuf(stdin, NULL);
    printf("Apellido: ");
    scanf(" %s", (*persona + *ii)->apellido);
    setbuf(stdin, NULL);
    printf("Fecha de nacimiento:\nDia: ");
    scanf("%d", &(*persona + *ii)->fecha.dia);
    setbuf(stdin, NULL);
    printf("Mes: ");
    scanf(" %s", (*persona + *ii)->fecha.mes);
    setbuf(stdin, NULL);
    printf("Anio: ");
    scanf("%d", &(*persona + *ii)->fecha.anio);
    setbuf(stdin, NULL);
    printf("Direccion/Domicilio:\ncalle: ");
    fgets((*persona + *ii)->direccion.calle, TAM_STRINGS, stdin);
    printf("Barrio: ");
    fgets((*persona + *ii)->direccion.barrio, TAM_STRINGS, stdin);
    printf("Localidad: ");
    fgets((*persona + *ii)->direccion.localidad, TAM_STRINGS, stdin);
    printf("Ingrese el numero de telefono: ");
    scanf(" %li", &(*persona + *ii)->telefono);
    setbuf(stdin, NULL);
}
void print(struct Persona *persona)
{
    int ii = 0;
    for (ii = 0; ii < TAM_ARRAY; ii++)
    {
        printf("\nDatos personales registrados N°%d:\n"
               "Nombre y Apellido: %s %s\n"
               "Fecha de nacimiento: %d de %s del %d\n"
               "Domicilio:\n\tLocalidad: %s"
               "\tCalle: %s"
               "\tBarrio: %s"
               "CEL.: %li\n\n",
               (ii+1),
               (persona+ii)->nombre, (persona+ii)->apellido,
               (persona+ii)->fecha.dia, (persona+ii)->fecha.mes, (persona+ii)->fecha.anio,
               (persona+ii)->direccion.localidad, (persona+ii)->direccion.calle,
               (persona+ii)->direccion.barrio,
               (persona+ii)->telefono);
    }
}