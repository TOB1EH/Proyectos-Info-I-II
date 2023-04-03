import java.util.Scanner;

/**
 * @author Tobias
 */

/* Ejercicio: Guillermo tiene N dolares. Luis tiene la mitad de lo que posee Gullermo. Juan tiene la mitad de lo que tiene de lo que possen Guillermo y Luis juntos. Hacer un progreama que calcule e imprima la cantidad de dinero que tienen entrre los tres */

// Librerias
import java.util.Scanner;

public class EjercicioUno {
    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);
        float guillermo = 0, luis = 0, juan = 0;

        System.out.print("Introduzca la cantidad de dolares que tiene Guillermo: $");
        guillermo = entrada.nextFloat();

        luis = guillermo/2;

        juan = (guillermo+luis)/2;

        entrada.close();

        System.out.println("Dinero que tienen entre los tres: $"+(guillermo+luis+juan));
    }
}
