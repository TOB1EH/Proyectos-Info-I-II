/**
 * @author Tobias Funes
 */

/* Ejercicio2: La calificacion final de un estudiante de informatica se calcula con base a las calificaciones de aspectos de su rendimiento academico: participacion, primer examen parcial, segundo examen parcial y examen final. Sabiendo que las calificaciones anteriores entran a la calificacion final con ponderaciones del 10%, 25%, 25% y 40%. hacer un programa que calcule e imprima la calificacion final obtenida por un estudiante */

// Librerias
import java.util.Scanner;

public class EjercicioDos {
    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);
        float participacion=0, parcial1=0, parcial2=0, examenFinal=0, notaFinal=0;

        // Entrada de datos
        System.out.println("Bienvenido!");
        System.out.print("Ingrese su nota de participacion: ");
        participacion = entrada.nextFloat();
        System.out.print("Ingrese su nota del primer parcial: ");
        parcial1= entrada.nextFloat();
        System.out.print("Ingrese su nota del segundo parcial: ");
        parcial2 = entrada.nextFloat();
        System.out.print("Ingrese su nota de Examen final: ");
        examenFinal = entrada.nextFloat();

        // Calculo de los porcentajes
        participacion *= 0.10f;
        parcial1 *= 0.25f;
        parcial2 *= 0.25f;
        examenFinal *= 0.40f;

        // Calificacion final
        notaFinal = participacion + parcial1 + parcial2 + examenFinal;
        System.out.println("Calificacion final del estudiante: "+notaFinal);

        // cerramos el objeto
        entrada.close();
    }
}
