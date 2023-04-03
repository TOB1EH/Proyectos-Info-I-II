/**
 * @author Tobias Funes
 */

/* Ejercicio 8: Un obrero necesita calcular su salario semanal, el cual se obtiene de la siguiente manera:
 * Si trabaja 40 horas o menos se le paga $16 por hora
 * Si trabaja mas de 40 horas se le paga $16 por cada una de las primeras 40 horas y $20 por cada hora extra
 */

// Librerias
import java.util.Scanner;
import javax.sound.sampled.SourceDataLine;

public class EjercicioOcho {
    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);
        int horas=0;
        float salario=0f;

        System.out.print("Ingrese sus horas trabajadas: ");
        horas = entrada.nextInt();

        if (horas <= 40) {
            salario = horas*16;
            System.out.print("Salario semanal: "+salario);
        } else if (horas > 40){
            salario = (40*16)+((horas-40)*20);
            System.out.print("Salario semanal: "+salario);
        }

        entrada.close();
    }

}