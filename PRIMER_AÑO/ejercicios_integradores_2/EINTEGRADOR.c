// Funes Tobias

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FIL 3 // directiva FIL, representa la cantidad de Filas para el array 2d
#define COL 3 // directiva COL, representa la cantidad de Columnas para el array 2d

void mostrar_array (int [][COL]);
void promedio (int [][COL]);
void veces_que_se_repite (int [][COL]);
void valores_pares (int [][COL]);
void sumar_valores_impares (int [][COL]);
void frecuencia_de_un_numero (int [][COL]);

int main(int argc, char const *argv[])
{
    int array[FIL][COL]={0}, ii = 0, jj = 0;
    srand(time(NULL));
    for (ii = 0; ii < FIL; ii++)
    {
        for (jj = 0; jj < COL; jj++)
        {
            array[ii][jj] = rand()%101;
        }
    }
    mostrar_array(array);
    promedio(array);
    veces_que_se_repite(array);
    valores_pares(array);
    sumar_valores_impares(array);
    frecuencia_de_un_numero(array);
    return 0;
}

/*---------------------------------- FUNCIONES ---------------------------------------------------------*/

void mostrar_array (int array_2d[][COL])
{
    int ii = 0, jj = 0;
    printf("Array (%d x %d) de numeros ramdoms:\n", FIL, COL);
    for (ii = 0; ii < FIL; ii++)
    {
        for (jj = 0; jj < COL; jj++)
        {
            printf("%d\t", array_2d[ii][jj]);
        }
        printf("\n");
    }
}
void promedio (int array_2d[][COL])
{
    int ii = 0, jj = 0;
    float suma = 0, promedio = 0;
    for (ii = 0; ii < FIL; ii++)
    {
        for (jj = 0; jj < COL; jj++)
        {
            suma += array_2d[ii][jj];
        }
    }
    promedio = suma / (FIL * COL);
    printf("\nValor promedio: %.2f\n", promedio);   
}
void veces_que_se_repite (int array_2d[][COL])
{
    int ii = 0, jj = 0, val = 0, count = 0;
    printf("\nIngrese un valor para buscar cuantas veces se repite: ");
    scanf("%d", &val);
    for (ii = 0; ii < FIL; ii++)
    {
        for (jj = 0; jj < COL; jj++)
        {
            if (val == array_2d[ii][jj]) count++;
        }
    }
    printf("\nEL numero %d se repite %d veces\n", val, count);
}
void valores_pares (int array_2d[][COL])
{
    int ii = 0, jj = 0;
    printf("\nValores Pares:\n");
    for (ii = 0; ii < FIL; ii++)
    {
        for (jj = 0; jj < COL; jj++)
        {
            if (array_2d[ii][jj]%2 == 0) printf("%d\t", array_2d[ii][jj]);
        }
    }
    printf("\n");
}
void sumar_valores_impares (int array_2d[][COL])
{
    int ii = 0, jj = 0, suma = 0;
    for (ii = 0; ii < FIL; ii++)
    {
        for (jj = 0; jj < COL; jj++)
        {
            if (array_2d[ii][jj]%2 != 0)
            {
                suma += array_2d[ii][jj];
            }
        }
    }
    printf("\nSuma de valores Impares = %d\n", suma);
}
void frecuencia_de_un_numero (int array_2d[][COL])
{
    int f[25][2]={0};
    int ii = 0, jj = 0, kk = 0, cont = 0;
    bool bandera = false;
	
	for(ii=0; ii<5; ii++){
		for(jj=0; jj<5; jj++){
			bandera=false;
			for(kk=0;kk<25;kk++){
				if(array_2d[ii][jj]==f[kk][0]){
					f[kk][1]=f[kk][1]+1;
					bandera=true;
				}
			}
			if(bandera==false){
				f[cont][0]=array_2d[ii][jj];
				f[cont][1]=1;
				cont++;
			}
		}
	}
	//Mostrar frecuencia
	printf("\nFrecuencia de valores\n");
	for(ii=0; ii<25; ii++){
		for(jj=0; jj<2; jj++){
			if(f[ii][jj]!=0){ //muestra solo las filas que tienen valores.
				printf("%d\t",f[ii][jj]);
			}
		}
		printf("\n");
	}
    /* for (ii = 0; ii < 25; ii++)
    {
        f[ii][0] = array_2d[jj][kk];
        for (jj = 0; jj < FIL; jj++)
        {
            for (kk = 0; kk < COL; kk++)
            {   
                if (f[ii][0] == array_2d[jj][kk])
                {
                    count++;
                    f[ii][1] = count;
                } 
            }
        }
    }
    for (ii = 0; ii < 25; ii++)
    {
        for (jj = 0; jj < 2; jj++)
        {
            if (f[ii][0] != 0) printf("%d\t", f[ii][0]);
        }
        printf("\n");
    } */
}

