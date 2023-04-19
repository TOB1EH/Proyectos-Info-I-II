import java.util.Scanner;

public class TestFecha {
    public static void main(String[] args) {
        Scanner console = new Scanner(System.in);

        // creamos una instancia de la clase Fecha indicando los valores iniciales
        Fecha fecha1 = new Fecha(10, 12, 2021);

        System.out.println(fecha1.toString());

        // creamos una fecha sin indicar los valores indicar los valores iniciales
        Fecha fecha2 = new Fecha();

        fecha2.setDia(9);
        fecha2.setMes(9);
        fecha2.setAnio(2002);

        System.out.println(fecha2.toString());

        // Crear fechas a partir de una cadena
        System.out.println("Ingrese una Fecha siguiendo el formato dia/mes/anio: ");
        String ss = console.nextLine();

        Fecha fecha3 = new Fecha(ss);

        Fecha fecha4 = new Fecha(9, 9, 2002);

        System.out.println(fecha3.toString());

        //
        if (fecha1.equals(fecha4)) {
            System.out.println("Las fechas son iguales!");
        }
    }
}
