/**
 * @author Tobias Funes
 */

/* Ejercicio 8: en un local se hace un descuento del 20% a los clientes cuya compra supere los 300$ ¿Cual sera la cantidad que pagara una persona por compra? */

// Librerias
import java.util.Scanner;

public class EjercicioSiete {
    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);
        float compra = 0f;

        System.out.print("Ingrese el precio de su compra: ");
        compra = entrada.nextFloat();

        if (compra > 300) {
            System.out.println("Aplica para descuento. Precio final: $"+(compra-compra*0.20));
        } else {
            System.out.println("No aplica para descuento. Precio final: $"+compra);
        }

        entrada.close();
    }
}
