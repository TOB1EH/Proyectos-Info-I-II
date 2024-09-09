// Tobias Funes

/* ENUNCIADO: 
Crear un menú de opciones con las siguientes funciones:

Realice una función para cargar los datos. (código, hectáreas, costo de producción y cantidad de frascos de dulces)
Realice una función para calcular por cada código de fruta  el costo de producción por frasco. (costo de producción / cantidad de frascos de dulces)
Realice una función para calcular el precio unitario al público. Se espera una ganancia del 50% adicional al costo de producción por frasco.
Realice una función para calcular la recaudación por cada uno de los productos.
Realice una función para calcular la recaudación total de la chacra.
Realice una función para buscar la fruta que mejor rinde en cuanto su relación cantidad de hectáreas plantadas y cantidad de frascos obtenidos.
Realice una función para pasar las cantidades de frascos de dulces a un vector.
Realice una función para mostrar la matriz.*/

#include <stdio.h>

#define FIL 3
#define COL 7

void cargar_datos (float [][COL]);
float costo_produccion_x_frasco (float *, int *);
float precio_unitario_x_frasco (float *);
float recaudacion_x_producto (int *, float *);
void recaudacion_total (float [][COL]);
void fruta_con_mejor_rendimiento (float [][COL]);
void convertir_en_vector (float [][COL]);
void mostrar_matriz (float [][COL]);


int main(int argc, char const *argv[])
{
    float array_de_datos[FIL][COL]={0};
    printf("Codigos de cada fruta:\n"
            "1.Naranja\n"
            "2.Manzana\n"
            "3.Tomate\n");
    cargar_datos(array_de_datos);
    mostrar_matriz(array_de_datos);
    recaudacion_total(array_de_datos);
    fruta_con_mejor_rendimiento(array_de_datos);
    convertir_en_vector(array_de_datos);
    return 0;
}

/*-------------------------------------------------------------------------------------------------------------------*/

void cargar_datos (float vector[][COL])
{
    int ii = 0, jj = 0, cod = 0, cant_frascos = 0;
    float hectareas = 0, costo_produccion = 0, costo_frasco = 0, 
		precio_unitario = 0, recaudacion = 0;
    for (ii = 0; ii < FIL; ii++)
    {
        for (jj = 0; jj < COL; jj++)
        {
            if (jj == 0)
            {
                printf("Ingrese Codigo de Fruta: ");
                scanf("%d", &cod);
                vector[ii][jj] = cod;
            }
            if (jj == 1)
            {
                printf("Ingrese Hectareas plantadas (m2): ");
                scanf("%f", &hectareas);
                vector[ii][jj] = hectareas;
            }
            if (jj == 2)
            {
                printf("Ingrese Costo Produccion ($): ");
                scanf("%f", &costo_produccion);
                vector[ii][jj] = costo_produccion;
            }
            if (jj == 3)
            {
                printf("Ingrese Cant. Frascos Dulces: ");
                scanf("%d", &cant_frascos);
                vector[ii][jj] = cant_frascos;
            }
            if (jj == 4) // Costo Producción por frasco ($)
            {
                costo_frasco = costo_produccion_x_frasco(&costo_produccion, &cant_frascos);
                vector[ii][jj] = costo_frasco;
            }
            if (jj == 5) // Precio unitario al público
            {
                precio_unitario = precio_unitario_x_frasco(&costo_frasco);
                vector[ii][jj] = precio_unitario;
            }
            if (jj == 6) // Recaudaion teniendo en cuenta que se venden todos los frascos producidos por producto
            {
                recaudacion = recaudacion_x_producto(&cant_frascos, &precio_unitario) ;
                vector[ii][jj] = recaudacion;
            }
        }
        // mejor_rendimiento = fruta_con_mejor_rendimiento(&hectareas, &cant_frascos, &mejor_rendimiento);
    }
}
float costo_produccion_x_frasco (float *costo_produccion, int *frascos)
{
    float costo_frasco = 0;
    costo_frasco = *costo_produccion / *frascos;
    return costo_frasco;
}
float precio_unitario_x_frasco (float *precio_produccion_x_frasco)
{
    float precio_unitario = 0;
    precio_unitario = *precio_produccion_x_frasco + (*precio_produccion_x_frasco*0.5);
    return precio_unitario;
}
float recaudacion_x_producto (int *cant_de_frascos, float *precio_unitario)
{
    float recaudacion = 0;
    recaudacion = *cant_de_frascos * *precio_unitario; 
    return recaudacion;
}
void recaudacion_total (float vector[][COL])
{
    float total = 0;
    total = vector[0][6]+vector[1][6]+vector[2][6];
    printf("\nRecaudacion Total de la chacra: %.2f\n", total);
}
void fruta_con_mejor_rendimiento (float vector[][COL])
{
    int ii = 0, jj = 0;
    float rendimiento_hectarea = 0, codigo = 0, hectareas = 0, frascos = 0,
		mejor_rendimiento = 0, cod = 0;
    for (ii = 0; ii < FIL; ii++)
    {
        for (jj = 0; jj < COL; jj++)
        {
            if (jj == 0) codigo = vector[ii][jj];
            if (jj == 1) hectareas = vector[ii][jj];
            if (jj == 3) frascos = vector[ii][jj];
        }
        rendimiento_hectarea = hectareas / frascos;
        if (rendimiento_hectarea > mejor_rendimiento)
        {
            mejor_rendimiento = rendimiento_hectarea;
            cod = codigo;
        }
    }
    if (cod == 1)
    {
        printf("\nLa naranja es la fruta con mejor rendimiento de produccion por hectarea, es decir, produce mas");
        printf(" frascos de dulces por hectarea: %.0f frascos por hectaria(m2)\n", mejor_rendimiento);
    }
    if (cod == 2)
    {
        printf("\nLa manzana es la fruta con mejor rendimiento de produccion por hectarea, es decir, produce mas");
        printf(" frascos de dulces por hectarea: %.0f frascos por hectaria(m2)\n", mejor_rendimiento);
    }
    if (cod == 3)
    {
        printf("\nEl tomate es la fruta con mejor rendimiento de produccion por hectarea, es decir, produce mas");
        printf(" frascos de dulces por hectarea: %.0f frascos por hectaria(m2)\n", mejor_rendimiento);
    }
}
void convertir_en_vector (float array_2d[][COL])
{
    int ii = 0, jj = 0;
    float vector[3]={0};
    for (ii = 0; ii < FIL; ii++)
    {
        for (jj = 0; jj < COL; jj++)
        {
            if (jj == 3) vector[ii] = array_2d [ii][jj];
        }
    }
    printf("Cantidad de frascos de cada producto:\n");
    for (ii = 0; ii < 3; ii++)
    {
        printf("%.0f\t", vector[ii]);
    }
}
void mostrar_matriz (float vector[][COL])
{
    int ii = 0, jj = 0;
    printf("\nCostrol de costos de produccion:\n");
	printf("\n|Codigo||Hectareas||C.Prod||Cant.F||C.Prod.Fras||Precio.U||Recaudacion|\n");
    for (ii = 0; ii < FIL; ii++)
    {
        for (jj = 0; jj < COL; jj++)
        {
            printf("| %.2f |", vector[ii][jj]);
        }
        printf("\n");
    }
}
