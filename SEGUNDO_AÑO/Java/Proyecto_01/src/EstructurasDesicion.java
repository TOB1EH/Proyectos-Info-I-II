/* Librerias */
import java.util.Scanner;

/* Clase principal */
public class EstructurasDesicion {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Ingrese un valor para determinar si es par o no: ");
        int v = scanner.nextInt();
        int resto = v%2;

        // Sentencia if-inline
        String mssg = (resto == 0) ? "Nro es Par": "Nro es impar";
        System.out.println(mssg);

        scanner.close(); // cerramos el objeto
    }
}
