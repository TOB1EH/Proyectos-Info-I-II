/**
 * @author Tobias Funes
 */

/* Ejercicio 4: Construir un programa que calcule y muestre por pantalla las raices de la ecuacion de segundo grado de coeficientes reales  */

// Librerias
import java.util.Scanner;

public class EjercicioCuatro {
    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);
        double a=0, b=0, c=0, x1=0, x2=0;

        System.out.println("Despejar/Calcular las raices de la ecuacion de segundo grado:\n' a(x^2)+bx+c=0 '");
        System.out.print("Ingrese el valor de 'a': ");
        a = entrada.nextDouble();
        System.out.print("ingrese el valor de 'b': ");
        b = entrada.nextDouble();
        System.out.print("Ingrese el valor de 'c': ");
        c = entrada.nextDouble();

        x1 = (-b + Math.sqrt((Math.pow(b, 2.0))-4*a*c))/2.0*a;
        x2 = (-b - Math.sqrt((Math.pow(b, 2.0))-4*a*c))/2.0*a;

        System.out.println("Raices:\nX1 = "+x1+"\nX2 = "+x2);

        entrada.close(); // cerramos la instancia entrada del objeto scanner
    }
}
