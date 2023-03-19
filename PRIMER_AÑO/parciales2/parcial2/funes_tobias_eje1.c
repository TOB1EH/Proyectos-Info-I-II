#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define TAM_STRINGS 25
#define PESO_LADRILLO 0.350

typedef struct remito
{
    char apellido[TAM_STRINGS];
    int numero;
    int cantLadrillos;
    float pesoTot;
    struct remito *link;
}remito_t;

void push(remito_t **front, remito_t **back, remito_t **node);
void printFIFO(remito_t *front);
void mayorCarga(remito_t **front);
void buscarRemito(remito_t *front);

int main(int argc, char const *argv[])
{
    /* Declaracion e inicializacion de variables */
    FILE *file = NULL;
    remito_t *front = NULL;
    remito_t *back = NULL;
    remito_t *node = NULL;
    remito_t *temp = NULL;
    int nRemitos = 0, cont = 0;
    char op = 0;

    file = fopen("remito.txt", "w");
    if (file == NULL)
    {
        printf("\nNo se pudo abrir el achivo :/\n");
        exit(1);
    }
    fputs("Remito\tCant. Ladrillos\tPeso Total\tID\n", file);
    fclose(file);

    printf("Carga de remitos:\n"
            "Ingrese cuantos remitos va a cargar: ");
    scanf("%d", &nRemitos);
    for (int i = 0; i < nRemitos; i++)
    {
        push(&front, &back, &node);
        printf("\nIngrese el apellido: ");
        scanf(" %s", node->apellido);
        printf("\nIngrese numero id: ");
        scanf("%d", &node->numero);
        printf("\nIngrese cant. de ladrillos: ");
        scanf("%d", &node->cantLadrillos);
        node->pesoTot = (float)node->cantLadrillos*PESO_LADRILLO;
    }


    do // bucle para menu de opciones
    {
        printf("Opciones:\n"
                "a. Mostrar listado de remitos.\n"
                "b. Mostrar el remito con  mayor carga.\n"
                "c. Buscar un remito y mostrar datos.\n"
                "d. Grabar un archivo de datos.\n"
                "e. Cerrar menu.\n"
                "Ingrese una opcion: ");
        scanf(" %c", &op);
        op = tolower(op);
        switch (op)
        {
        case 'a':
            printFIFO(front);
            break;
        case 'b':
            mayorCarga(&front);
            break;
        case 'c':
            buscarRemito(front);
            break;
        case 'd':
            file = fopen("remito.txt", "a");
            if (file == NULL)
            {
                printf("\nNo se pudo abrir el achivo :/\n");
                exit(1);
            }
            temp = front;
            while (temp != NULL)
            {
                cont++;
                fprintf(file, "%d\t%d\t%f\t%d\n",
                        cont,
                        temp->cantLadrillos,
                        temp->pesoTot,
                        temp->numero);
                temp = temp->link;
            }
            printf("\nCarga exitosa.\n");
            fclose(file);
            break;
        case 'e':
            printf("\nCerrando...\n");
            break;
        default:
            printf("\nOpcion invalida. Intente nuevamente.\n");
            break;
        }
    } while (op != 'e');
    /* Free Memory */
    while (front != NULL)
    {
        temp = front;
        front = front->link;
        free(temp);
        // printf("\nNodo borrado.\n");
    }
    return 0;
}

void push(remito_t **front, remito_t **back, remito_t **node)
{
    *node = (remito_t *)malloc(sizeof(remito_t));
    if (*node == NULL)
    {
        printf("\nNo hay memoria!\n");
        exit(1);
    }
    if ((*front == *back)&&(*back == NULL))
    {
        *back = *node;
        *front = *back;
    }
    else
    {
        (*back)->link = *node;
        *back = *node;
    }
} // push
void printFIFO(remito_t *front)
{
    int num = 0;
    remito_t *temp = NULL; 
    temp = front;
    while (temp != NULL)
    {
        num++;
        printf("Nodo %d:\n"
                "\tApellido: %s\n"
                "\tNro ID: %d\n"
                "\tCant. de ladrillos: %d\n"
                "\tPeso total de carga: %.2fKg\n\n",
                num,
                temp->apellido,
                temp->numero,
                temp->cantLadrillos,
                temp->pesoTot);
        temp = temp->link;
    }
}
void mayorCarga(remito_t **front)
{
    float ptot = 0;
    remito_t *temp = NULL;
    temp = *front;
    while (temp != NULL)
    {
        if (temp->pesoTot > ptot)
        {
            ptot = temp->pesoTot;
        }
        temp = temp->link;
    }
    temp = *front;
    while (temp != NULL)
    {
        if (temp->pesoTot == ptot)
        {
            printf("\nRemito con mayor carga:\n"
                    "\tApellido: %s\n"
                    "\tNro ID: %d\n"
                    "\tCant. de ladrillos: %d\n"
                    "\tPeso total de carga: %.2fKg\n\n",
                    temp->apellido,
                    temp->numero,
                    temp->cantLadrillos,
                    temp->pesoTot);
        }
        temp = temp->link;
    }
} // mayorCarga
void buscarRemito(remito_t *front)
{
    remito_t *temp = NULL;
    int id = 0, count = 0;
    printf("\nIngrese un identificador(ID) para buscar el remito: ");
    scanf(" %d", &id);
    temp = front;
    while (temp != NULL)
    {
        if (temp->numero == id)
        {
            count++;
            printf("\nRemito encontrado!:\n"
                    "\tApellido: %s\n"
                    "\tNro ID: %d\n"
                    "\tCant. de ladrillos: %d\n"
                    "\tPeso total de carga: %.2fKg\n\n",
                    temp->apellido,
                    temp->numero,
                    temp->cantLadrillos,
                    temp->pesoTot);
        }
        temp = temp->link;
    }
    if (count == 0)
    {
        printf("\nRemito no encontrado :(\n");
    }
}