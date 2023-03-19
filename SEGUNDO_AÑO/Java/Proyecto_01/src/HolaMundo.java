/**
 * @author funes tobias
 */

// Librerias
import java.util.Scanner;

// import javax.print.attribute.SupportedValuesAttribute;

public class HolaMundo {
    public static void main(String[] args) {
        /* --- SALIDA DE DATOS: --- */
        System.out.println("Hola Mundo"); // imprimir por pantalla con salto de linea

        /* VARIABLES o TIPOS DE DATOS: Tipos de espacios en memoria donde se almacena un valor */


        /* DATOS PRIMITIVOS: */

        /* Enteros:
         * byte    8 bits
         * short   16 bits
         * int   32 bits
         * long   64 bits
         * Rango es igual a 2 a n potencia de numeros de bits
        */
        int miVar = 2200;
        System.out.println(miVar); // impresion por consola
        miVar = 5;
        System.out.println(miVar);

        /* Punto flotante o Reales:
         * float    32 bits
         * double    64 bits
         */
        float miVarFlotante = 88.99f; // 'f' para indicar a la pc que se trata de un flotante
        System.out.println(miVarFlotante);
        // exponenciales
        float exp = 1.45E-45f;
        System.out.println("Num Exponencial: "+exp);

        // Caracteres
        char caracter = 'a';
        System.out.println(caracter);

        // Boleanos (Verdadero o falso)
        boolean decision = true;
        System.out.println("LA DECISION ES: "+decision);
        decision = false;

        /* Rangos */
        System.out.println("\nRangos de Enteros:");
        System.out.println("Max: "+Integer.MAX_VALUE);
        System.out.println("Min: "+Integer.MIN_VALUE+"\n");

        System.out.println("\nRango de Flotantes:");
        System.out.println("Max: "+Float.MAX_VALUE);
        System.out.println("Min: "+Float.MIN_VALUE+"\n");

        System.out.println("\nRango de Longs:");
        System.out.println("Max: "+Long.MAX_VALUE);
        System.out.println("Min: "+Long.MIN_VALUE+"\n");

        System.out.println("\nRango de Bytes:");
        System.out.println("Max: "+Byte.MAX_VALUE);
        System.out.println("Min: "+Byte.MIN_VALUE+"\n");


        /* DATOS NO PRIMITIVOS */

        Integer numero = null;
        numero = 10;
        System.out.println("Dato capaz de almacenar un valor nulo: "+numero);

        // Cadenas de texto o caracteres
        String miVarCadena = "Saludos gentusa";
        System.out.println(miVarCadena);

        // Variables sin tipo definido
        var miVarEntera = 15;
        System.out.println(miVarEntera);

        var miVarCadena2 = "Saludos mi rey";
        System.out.println(miVarCadena2 + " y " + miVarCadena);

        // Constantes: variables de valor no modificable
        final int num = 10;
        System.out.println("Numero constante: "+num);

        /* --- ENTRADA DE DATOS: --- */
        Scanner entrada = new Scanner(System.in); // Creamos un objeto con la clase 'Scanner' y lo instanciamos:

        int varI = 0;
        System.out.print("Ingrese un valor: ");
        varI = entrada.nextInt(); // comando para guardar varibles enteras
        System.out.println("El numero ingresado es: "+varI);

        entrada.nextLine(); // consume el salto de linea

        float var1 = 0f;
        System.out.print("Ingrese un valor flotante: ");
        var1 = entrada.nextFloat();
        System.out.println("El numero ingresado es: "+var1);

        entrada.nextLine(); // consume el salto de linea

        String cadena = "cadena";
        System.out.print("Digite una cadena: ");
        cadena = entrada.nextLine(); // para ingresar una cadena de un asola palabra
        System.out.println("Cadena ingresada: "+cadena);

        char letra;
        System.out.print("Ingrese un caracter: ");
        letra = entrada.next().charAt(0); // permite la entrada solo del primer caracter
        System.out.println("Caracter ingresado: "+letra);

        entrada.nextLine();

        // Caracteres especiales
        String nombre = "Tobias";
        System.out.print("Mi nombre es: \n"+nombre+"\n"); // salto de linea
        System.out.print("Mi nombre es: \t"+nombre+"\n"); // tabulado
        System.out.print("Mi nombre es: \b\b\b\b"+nombre+"\n"); // retroceso

        /* Clase Math (Matematicas) */

        // buscar metodos de la clase Math en Java


        /* UNICODE: caracteres especiales */

        /* Arrays/Arreglos: */
        int array[] = new int [10]; // arreglo de enteross
        // carga de datos
        for (int ii = 0; ii < 10; ii++) {
            System.out.print("Ingrese el valor n°"+(++ii)+": ");
            array[ii] = entrada.nextInt();
        }
        // impresion de datos
        for (int ii = 0; ii < 10; ii++) {
            System.out.println("Valor n°"+(++ii)+": "+array[ii]);
        }

        entrada.close();
    }
}

/* ALGUNOS ATAJOS EN JAVA:
 *  sout -> System.out.println
 */