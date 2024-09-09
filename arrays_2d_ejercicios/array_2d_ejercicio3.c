// Informatica - Arrays 2D E3 - Funes Tobias

/* 
Enunciado: Programe un sistema de facturación, donde emita las facturas de un negocio. 
Para ello primero deberá cargar los siguientes datos por cada articulo (código, precio unitario y cantidad) 
en un arreglo (máximo 5 filas). Una vez, cargado todos los artículos en la factura , el programa calculará 
cada uno de los subtotales y el total del monto a abonar por el cliente. Luego, el sistema solicita que se 
ingrese la forma de pago (efectivo, débito o tarjeta). Si es efectivo y este no es pago exacto, el programa 
deberá calcular el vuelto, y en el caso de la tarjeta de crédito calcular y sumar el recargo del 5%. Finalmente 
mostrar la factura.    
*/


#define FIL 5
#define COL 4

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int ii=0, jj=0, opcion=0, stop_while1=0, stop_while2=0, stop_while3=0, stop_while4=0, stop_for=FIL;
    float array[FIL][COL]={0}, valor=0, cod=0, precio=0, cant=0, sub_total=0, total=0, monto=0;
    char desicion=' ';
    printf("Sistema de Facturacion:\n");
    do
    {
        /* for de cargar los valores en el array */
        for (ii = 0; ii < stop_for; ii++) // Filas
        {
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
            
            // bucle de desicion para cargar mas articulos a la factura
            do 
            {
                printf("Desea ingresar otro articulo (S/N):");
                scanf(" %c", &desicion);
                if (desicion == 'N' || desicion == 'n') {
                    ii = FIL;
                    stop_while2 = 1;
                }
                else 
                {
                    if (desicion == 'S' || desicion == 's') stop_while2 = 1;
                    else if (desicion != 'N' || desicion != 'n' || desicion != 'S' || desicion != 's')
                    {
                        printf("\nCaracter invalido, intente nuevamente. "); // si se ingresa un caracter invalido vuelve a preguntar
                    }
                }
            } while (stop_while2 == 0); // do-while 2
        } // cierre for Filas
    
        /* FACTURA:  */    
        printf("\nCodigo|Precio U|Cantida|SubTotal|\n");
        // for para mostrar los valores cargados en el array
        for (ii = 0; ii < FIL; ii++) // Filas
        {
            for (jj = 0; jj < COL; jj++) // Columnas
            {
                printf("%.2f  | ", array[ii][jj]);         
            }
            printf("\n"); // Salto de linea para filas
        }
        
        do  // Menu de opciones para el metodo de pago
        {   
            printf("\nTotal a pagar: $%.2f", total);
            printf("\n\nIngrese metodo de pago:");
            printf("\n1. Efectivo\n2. Debito\n3. Credito");
            printf("\nOpcion: ");
            scanf("%d", &opcion);
            switch (opcion)
            {
            case 1:
                printf("\nOpcion Pago en efectivo: ");
                printf("\nTotal a pagar: $%.2f", total);
                printf("\nIngrese monto: $");
                scanf("%f", &monto);
                if (monto == total) printf("\nPago finalizado.");
                if (monto < total) printf("\nPago incompleto, ingrese un monto igual o mayor al total...");
                if (monto > total) printf("\nPago finalizado,  Vuelto = $%.2f\n", monto-total);
                stop_while3 = 1;
                break;
            case 2:
                printf("\nOpcion Pago con debito:");
                printf("\nIngrese el monto exacto a pagar: ");
                scanf("%f", &monto);
                if (monto == total) printf("\nPago aprobado");
                if (monto < total) printf("\nPago denegado.  Saldo insuficiente");  
                stop_while3 = 1;
                break;
            case 3:
                printf("\nOpcion Pago con Credito:");
                total = total + (total*0.05);
                printf("\nTotal a pagar = $%.2f. ", total);
                printf("Aplicando impuestos del 5 porciento");
                printf("\nIngrese el monto exacto a pagar con impuestos: ");
                scanf("%f", &monto);
                if (monto == total) printf("\nPago aprobado\n");
                if (monto < total) printf("\nPago denegado.  Saldo insuficiente\n"); 
                stop_while3 = 1;
                break;
            default:
                printf("\nIngreso una opcion invalida...");
                break;
            } 
        } while (stop_while3 == 0); // cierre do-while3

        do  // bucle de desicion para reiniciar o finalizar el programa de facturacion
        {
            printf("¿Desea comenzar una nueva Factura (S/N)? ");
            scanf(" %c", &desicion);
            if (desicion == 'N' || desicion == 'n') 
            {
                stop_while1 = 1; 
                stop_while4 = 1;
                /* Finaliza el programa de Facturacion */
            }
            else 
            {
                if (desicion == 'S' || desicion == 's') stop_while4 = 1; // Reinicia el programa para iniciar una nueva factura
                else if (desicion != 'N' || desicion != 'n' || desicion != 'S' || desicion != 's') 
                {
                    printf("\nCaracter invalido, intente nuevamente. "); // si se ingresa un caracter invalido vuelve a preguntar
                }
            }
        } while (stop_while4 == 0); // do-while 4
    } while (stop_while1 == 0); // do-while 1
    return 0;
}