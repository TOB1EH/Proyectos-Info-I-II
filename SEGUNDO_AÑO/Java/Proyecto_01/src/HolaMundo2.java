/**
 *
 * @author tobias
 */

 // Librerias
import javax.swing.JOptionPane;

public class HolaMundo2 {
    public static void main(String[] args) {

        /* Entrada y Salida de datos con JOptionPane */

        String cadena;
        int entero;
        char letra;
        double decimal;

        // Entrada de datos:
        cadena = JOptionPane.showInputDialog("Digite una cadena: ");
        entero = Integer.parseInt(JOptionPane.showInputDialog("Digite un entero: "));
        letra = JOptionPane.showInputDialog("Digite un caracter: ").charAt(0);
        decimal = Double.parseDouble(JOptionPane.showInputDialog("Digite un decimal: "));

        // Salida de datos:
        JOptionPane.showMessageDialog(null, "Cadena ingresada: "+cadena);
        JOptionPane.showMessageDialog(null, "Entero ingresado: "+entero);
        JOptionPane.showMessageDialog(null, "Letra ingresada: "+letra);
        JOptionPane.showMessageDialog(null, "Decimal ingresado: "+decimal);
    }
}