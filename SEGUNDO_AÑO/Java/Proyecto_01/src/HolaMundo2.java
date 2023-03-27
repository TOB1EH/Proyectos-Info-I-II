/**
 *
 * @author tobias funes
 */

 // Librerias
import javax.swing.JOptionPane;

/* Ventanas emergentes/dialogos con JOptionPane */
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

        /* Ventana personalizada */
        String[] opciones = {"Contento", "Triste", "Melancolico" };
        int opcion = JOptionPane.showOptionDialog(
                               null               // componente
                             , "Como te siente hoy?"      // Mensaje
                             , "Opciones Personalizada"     // Titulo en la barra del cuadro
                             , JOptionPane.DEFAULT_OPTION         // Tipo de opciones
                             , JOptionPane.INFORMATION_MESSAGE    // Tipo de mensaje (icono)
                             , null                         // Icono (ninguno)
                             , opciones                           // Opciones personalizadas
                             , null                 // Opcion por defecto
                           );
        JOptionPane.showMessageDialog(null, "Ha escogido "+opciones[opcion]);
    }
}