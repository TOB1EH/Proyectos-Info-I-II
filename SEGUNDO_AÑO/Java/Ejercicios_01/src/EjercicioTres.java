/**
 * @author Tobias Funes
 */

/* Ejercicio3: Construir un programa que, dado un numero total de horas, devuelve el numero de semanas, dias y horas equivalentes. Por ejemplo, dado un total de 1000 horas debe mostrar 5 semanas, 6 dias y 16 horas. */

// Librerias
import java.util.Scanner;

public class EjercicioTres {
    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);
        int horas = 0, dias = 0, semanas = 0, horasTotales = 0;

        System.out.print("Ingrese el total de horas: ");
        horasTotales = entrada.nextInt();

        semanas = horasTotales / (24*7);
        dias = horasTotales%(24*7) / 24;
        horas = horasTotales%24;

        System.out.println("El equivalente es:");
        System.out.println("Semnas: "+semanas);
        System.out.println("dias: "+dias);
        System.out.println("horas: "+horas);

        entrada.close();
    }
}