/**
 * @author Tobias Funes
 */

/* Ejercicio 5: hacer un programa que lea un numero entero y muestre si el numero es multiplo de 10 */

// Librerias
import java.util.Scanner;

public class EjercicioCinco {
    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);
        int num=0;

        System.out.print("Ingrese un numero entero para conocer si es multiplo de 10: ");
        num = entrada.nextInt();

        if (num%10==0) {
            System.out.println("El numero "+num+" si es multiplo de 10");
        }
        else {
            System.out.println("El numero "+num+" no es multiplo de 10");
        }

        entrada.close();
    }
}
