/* Ejercicio 7: Crear una estructura llamada producto con los siguientes atributos código,
nombre, stock, cantidad vendida. Crear un vector de estructuras del tipo producto (max 10).
Luego crear un menu de opciones:
    a. mostrar todos los productos
    b. cargar una venta (debe buscar y restar el stock y sumar la cant vendida)
    c. reponer mercadería (debe buscar y sumar el stock)
    d. ordenar por productos mas vendidos
    e. ordenar por productor con menor stock
Utilice funciones. */

/* Librerias */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

/* Directivas */
#define TAM_STRING 25 // tamanio/cantidad de caracteres para strings
#define TAM_MAX 10 // max de productos que puede ingresar

/* Estructuras */
struct Producto
{
    long cod;
    char nombre[TAM_STRING];
    int stock;
    int cant_vendida;
};
/* Declaracion  de tipo definido por el usuario */
typedef struct Producto producto_t; // alias para la Producto = producto_t

/* Prototipo de Funciones */
void checkMemory (struct Producto **ptr); // verifica si hay memoria suficiente para la redimension de memoria
void printProducts (struct Producto *ptr, int *nProducts); // imprime todos los productos del arreglo de estructuras Producto
void cargarVenta (struct Producto **ptr, int *nProducts); // agrega ventas de un producto 
void reponerMercaderia (struct Producto **ptr, int *nProducts); // aumena el stock de un prodcuto
void ordenMasVendidos (struct Producto *ptr, int *nProducts); // ordena los prodcutos deacuerdo a la mayor cant de ventas
void ordenMenorStock (struct Producto *ptr, int *nProducts); // ordena los productos  de acuerdo a la menor cantidad de stock

/* Funcion principal main */
int main(int argc, char const *argv[])
{
    /* Declaracion e inicializacion de variables */
    //struct Producto *producto = NULL;
    producto_t *producto = NULL;
    int nProducts = 0, stopWhile = 0, ii = 0;
    char opcion = '0';

    do // ciclo repetitivo do-while
    {
        printf("Ingrese la cantidad de productos (max. 10): ");
        scanf("%d", &nProducts);
        if (nProducts > TAM_MAX)
            printf("Supero el max de productos permitidos, ingrese una cantidad menor.\n");
        else
        {
            stopWhile = 1; // detiene el ciclo
        }
    } while (stopWhile == 0);
    /* Dimensionando memoria para arreglo de productos */
    producto = (producto_t *)malloc(nProducts*sizeof(producto_t));
    checkMemory(&producto); // verifica si hay memoria suficiente
    /* Carga de datos */
    printf("Carga de productos:\n");
    for (ii = 0; ii < nProducts; ii++)
    {
        printf("Producto Nro%d:\n"
        "Ingrese el codigo: ", (ii+1));
        scanf("%ld", &(producto+ii)->cod);

        printf("Ingrese el nombre del producto: ");
        setbuf(stdin, NULL);
        fgets((producto+ii)->nombre, TAM_STRING, stdin);

        printf("Ingresa la cantidad de stock: ");
        scanf("%d", &(producto+ii)->stock);

        (producto+ii)->cant_vendida = 0;
    }
    do // ciclo de menu de opciones
    {
        printf("\nMenu de opciones:\n"
                "a. mostrar todos los productos.\n"
                "b. cargar una venta.\n"
                "c. reponer mercadería.\n"
                "d. ordenar por productos mas vendidos.\n"
                "e. ordenar por productos con menor stock.\n"
                "f. cerrar menu.\n"
                "Ingrese una opcion: ");
        scanf(" %c", &opcion);
        opcion = tolower(opcion);
        switch (opcion)
        {
        case 'a':
            printProducts(producto, &nProducts); // invocacion a funcionm
            break;
        case 'b':
            cargarVenta(&producto, &nProducts); // invocacion a la funcion
            break;
        case 'c':
            reponerMercaderia(&producto, &nProducts); // invocacion de la funcion
            break;
        case 'd':
            ordenMasVendidos(producto, &nProducts);
            break;
        case 'e':
            ordenMenorStock(producto, &nProducts);
            break;
        case 'f':
            printf("\nCerrando Menu...\n");
            stopWhile = 0;
            break;
        default:
            printf("\nOpcion Invalida. Intente nuevamente\n");
            break;
        }
    } while (stopWhile == 1);

    /* Liberar memoria */
    free(producto);
    return 0;
} // main

/* Funciones */
void checkMemory (struct Producto **ptr)
{
    if (*ptr == NULL)
    {
        printf("\nMemoria Insuficiente\n");
        exit(0); // si no hay memoria disponible finalizar el programa
    }
} // funtion 'checkMemory'
void printProducts (struct Producto *ptr, int *nProducts)
{
    int ii = 0;
    /* Impresion de datos */
    printf("\nDatos de cada producto:\n");
    for (ii = 0; ii < *nProducts; ii++)
    {
        printf("producto: %s"
                "codigo: %ld\n"
                "stock: %d\n"
                "cant.ventas: %d\n\n",
                (ptr+ii)->nombre,
                (ptr+ii)->cod,
                (ptr+ii)->stock,
                (ptr+ii)->cant_vendida);
    }
} // function 'printProducts'
void cargarVenta (struct Producto **ptr, int *nProducts)
{
    int ii = 0, cantVendida = 0;
    long codigo = 0;
    printf("Introduzca el codigo del articulo: ");
    scanf(" %ld", &codigo);
    for (ii = 0; ii < *nProducts; ii++)
    {
        if ((*ptr+ii)->cod == codigo)
        {
            printf("Ingresa la cant. vendida: ");
            scanf("%d", &cantVendida);
            if (cantVendida > (*ptr+ii)->stock)
                printf("\nError! No hay stock suficiente para esa cantidad\n");
            else
            {
                (*ptr+ii)->cant_vendida += cantVendida;
                (*ptr+ii)->stock -= cantVendida;
            }
        }
    }       
} // function "cargarVenta"
void reponerMercaderia (struct Producto **ptr, int *nProducts)
{
    int ii = 0;
    long codigo = 0;
    int cantArticulos = 0;
    printf("Ingrese el codigo del articulo: ");
    scanf(" %ld", &codigo);
    for (ii = 0; ii < *nProducts; ii++)
    {
        if ((*ptr+ii)->cod == codigo)
        {
            printf("Ingrese la cantidad de articulos a reponer: ");
            scanf("%d", &cantArticulos);
            (*ptr+ii)->stock += cantArticulos;
        }   
    }
} // function "reponerMercaderia"
void ordenMasVendidos (struct Producto *ptr, int *nProducts)
{
    int ii = 0, jj = 0;
    producto_t temp; // variable temporaria
    for (ii = 1; ii < *nProducts; ii++) 
    {
        for (jj = 0; jj < *nProducts-1; jj++)
        {
            if (ptr[jj].cant_vendida < ptr[jj+1].cant_vendida)
            {
                temp = *(ptr+jj);
                *(ptr+jj) = *(ptr+jj+1);
                *(ptr+jj+1) = temp;
            }
        }
    }
    printf("\nProductos ordenados por mayor cant. de ventas\n\n");
} // function 'ordenarMasVendidos'
void ordenMenorStock (struct Producto *ptr, int *nProducts)
{
    int ii = 0, jj = 0;
    producto_t temp;
    for (ii = 1; ii < *nProducts; ii++)
    {
        for (jj = 0; jj < *nProducts-1; jj++)
        {
            if (ptr[jj].stock > ptr[jj+1].stock)
            {
                temp = ptr[jj];
                ptr[jj] = ptr[jj+1];
                ptr[jj] = temp;
            }
        }
    }
    printf("\nProductos ordenados por menor cant. de stock\n\n");
} // funcion 'ordenMenorStock'