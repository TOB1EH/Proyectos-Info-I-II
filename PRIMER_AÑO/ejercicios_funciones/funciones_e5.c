// Informatica -  Funciones E5 - Funes Tobias

#define FIL 5
#define COL 4

#include <stdio.h>
#include <stdlib.h>

int desicion_de_continuar (int *);
void factura (float [][COL], int *);
void menu_de_pago (float *);

int main(int argc, char const *argv[])
{
    int ii=0, jj=0, stop_while=0, accion=0, productos = 0;
    float array[FIL][COL]={0}, cod=0, precio=0, cant=0, sub_total=0, total=0;
    char opcion=' ';
    printf("Sistema de Facturacion: ");

    do
    {
        /* for de cargar los valores en el array */
        for (ii = 0; ii < FIL; ii++) // Filas
        {
            productos++;
            for (jj = 0; jj < COL; jj++) // Columnas
            {
                if (jj == 0) // si esta en la columna nro 1 carga el codigo del articulo
                {
                    printf("\nIngrese el codigo del articulo N°%d: ", ii+1);
                    scanf("%f", &cod);
                    array[ii][jj] = cod;
                }
                if (jj == 1) // si esta en la columna nro 2 carga el precio unitario del artuculo
                {
                    printf("Ingrese el Precio Unitario del articulo N°%d: $", ii+1);
                    scanf("%f", &precio);
                    array[ii][jj] = precio;
                }
                if (jj == 2) // si esta en la columna nro 4 carga la cantidad del articulo seleccionado
                {
                    printf("Articulo N°%d Cantidad: ", ii+1);
                    scanf("%f", &cant);
                    array[ii][jj] = cant;
                }
                if (jj == 3) // en la columna nro 3 carga/almacena el subtotal de un mismo articulo (cantidad x precio)
                {
                    sub_total = precio * cant;
                    array[ii][jj] = sub_total;
                }
            } // cierre for Columnas
            total += sub_total; // total es la suma de los todos los subtotales, es decir el total a pagar
            accion = desicion_de_continuar(&ii);
            if (accion == 1) ii = FIL;
        } // cierre for Filas
        factura(array, &productos);
        menu_de_pago(&total);
        accion = desicion_de_continuar(&ii);
        if (accion == 1) stop_while = 1;
    } while (stop_while == 0);
    return 0;
}


/*-------------------------------------------------------------------------------------------------------------------*/

int desicion_de_continuar (int *ii)
{
    int stop_while=0;
    char desicion=' ';
    do 
    {
        if (*ii == 6) printf("¿Desea comenzar una nueva Factura (S/N)? ");
        else {
            printf("Desea ingresar otro articulo (S/N):");
        }
        scanf(" %c", &desicion);
        if (desicion == 'N' || desicion == 'n') {
            return 1;
        }
        else 
        {
            if (desicion == 'S' || desicion == 's')
            {
                return 2;
            }
            else if (desicion != 'N' || desicion != 'n' || desicion != 'S' || desicion != 's')
            {
                printf("\nCaracter invalido, intente nuevamente. "); // si se ingresa un caracter invalido vuelve a preguntar
            }
        }

    } while (stop_while == 0); // do-while
}

/*-------------------------------------------------------------------------------------------------------------------*/

void factura (float vector[][COL], int *productos)
{
    int ii=0, jj=0;
    /* FACTURA:  */    
    printf("\nCodigo|Precio U|Cantida|SubTotal|\n");
    // for para mostrar los valores cargados en el array
    for (ii = 0; ii < *productos; ii++) // Filas
    {
        for (jj = 0; jj < COL; jj++) // Columnas
        {
            printf("%.2f  | ", vector[ii][jj]);         
        }
        printf("\n"); // Salto de linea para filas
    }
}

/*-------------------------------------------------------------------------------------------------------------------*/

void menu_de_pago (float *total)
{
    int stop_while=0;
    float monto=0;
    char opcion=' ';
    do
    {
        printf("\nTotal a pagar: $%.2f", *total);
        printf("\n\nIngrese metodo de pago:");
        printf("\na. Efectivo\nb. Debito\nc. Credito");
        printf("\nOpcion: ");
        scanf(" %c", &opcion);
        switch (opcion)
        {
            case 'a':
                printf("\nOpcion Pago en efectivo: ");
                printf("\nTotal a pagar: $%.2f", *total);
                printf("\nIngrese monto: $");
                scanf("%f", &monto);
                if (monto == *total) printf("\nPago finalizado.");
                if (monto < *total) printf("\nPago incompleto.\nNO SE FIA!!!\n");
                if (monto > *total) printf("Pago finalizado,  Vuelto = $%.2f\n", monto - *total);
                stop_while = 1;
                break;
            case 'b':
                printf("\nOpcion Pago con debito:");
                printf("\nIngrese el monto exacto a pagar: "); // Bajo la logica de un pago con debito, se retira de la tarjeta el monto exacto a pagar
                scanf("%f", &monto);
                if (monto == *total) printf("\nPago aprobado");
                if (monto < *total) printf("\nPago denegado.  Saldo insuficiente");  
                stop_while = 1;
                break;
            case 'c':
                printf("\nOpcion Pago con Credito:");
                *total = *total + (*total*0.05);
                printf("\nTotal a pagar = $%.2f. ", *total);
                printf("Aplicando impuestos del 5 porciento");
                printf("\nIngrese el monto exacto a pagar con impuestos: "); // Bajo la logica de un pago con credito, el monto no sera mayor a lo indicadp
                scanf("%f", &monto);
                if (monto == *total) printf("\nPago aprobado\n");
                if (monto < *total) printf("\nPago denegado.\n"); 
                stop_while = 1;
                break;
            default:
                printf("\nIngreso una opcion invalida...\n");
                break;
        }
    } while (stop_while == 0);
}