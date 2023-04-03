/**
 * @author Tobias Funes
 */

/* Ejercicio 6: Hacer un programa que lea un caracter por teclado y compruebe si es una letra mayusucla */

// Librerias
import javax.lang.model.util.ElementScanner14;
import javax.swing.JOptionPane;

public class EjercicioSeis {
    public static void main(String[] args) {
        char letra=0;

        letra = JOptionPane.showInputDialog(null, "Ingrese una letra").charAt(0);

        // usando tabla de codigo ASCII
        if (letra>=65 && letra<=90) {
            JOptionPane.showMessageDialog(null, "La letra '"+letra+"' si es una mayuscula");
        } else if (letra>=97 && letra<=122) {
            JOptionPane.showMessageDialog(null, "La letra '"+letra+"' es una minuscula");
        } else {
            JOptionPane.showMessageDialog(null, "El caracter ingresado no es una letra");
        }

        // Alternativa usando metodos de la clase Character
        letra = JOptionPane.showInputDialog(null, "Ingrese otra letra").charAt(0);

        if (Character.isUpperCase(letra)) {
            JOptionPane.showMessageDialog(null, "La letra '"+letra+"' si es una mayuscula");
        } else if (Character.isLowerCase(letra)) {
            JOptionPane.showMessageDialog(null, "La letra '"+letra+"' es una minuscula");
        } else {
            JOptionPane.showMessageDialog(null, "El caracter ingresado no es una letra");
        }
    }
}