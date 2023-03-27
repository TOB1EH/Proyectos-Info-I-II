/* Librerias */
import java.util.Scanner;

/* Clase principal */
public class EstructurasDesicion {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Ingrese un valor para determinar si es par o no: ");
        int v = scanner.nextInt();
        int resto = v%2;

        // Sentencia if-inline o if ternario
        boolean afirmacion = (resto==0) ? true : false;
        System.out.println("La afirmacion es: "+afirmacion);

        int entero = (resto == 0) ? 1 : 0;
        System.out.println("Rta: "+entero);

        String mssg = (resto == 0) ? "Nro es Par": "Nro es impar";
        System.out.println(mssg);


        System.out.println("Ingrese un num como opcion: ");
        int key = scanner.nextInt();

        // Sentencia switch
        switch (key) {
            case 1: case 2:
                System.out.println("Hola Mundo");
                break;
            default:
                System.out.println("Chau Mundo");
                break;
        }

        /* SENTENCIA SOLO DISPONIBLE HASTA JAVA 14
            switch (key) {
                case 1, 3, 5, 7, 8, 10, 12 -> System.out.println("this month has 31 days");
                case 4, 6, 9 -> System.out.println("this month has 30 days");
                case 2 -> System.out.println("February can have 28 or 29 days");
                default -> System.out.println("invalid month");
        } */


        scanner.close(); // cerramos el objeto
    }
}
