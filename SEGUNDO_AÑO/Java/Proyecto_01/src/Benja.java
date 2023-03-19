import javax.swing.JOptionPane;

public class Benja {
    public static void main(String[] args) {
        String nombre;

        nombre = JOptionPane.showInputDialog("Ingrese su nombre porfavor: ");

        JOptionPane.showMessageDialog(null, "Usted es muy sr. "+nombre);
    }
}
