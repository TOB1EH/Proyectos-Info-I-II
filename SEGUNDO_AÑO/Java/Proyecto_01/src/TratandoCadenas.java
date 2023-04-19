


public class TratandoCadenas {
    public static void main(String[] args) {
        // Tratando cadenas de caracteres

        /* Tamaño de un strings */
        var cadenaX = "Hola Mundito";
        System.out.println("Largo de la cadena: "+cadenaX.length());

        /* Mayusculas y minusculas */
        String s = "Esto es una cadena de CaraCTERES";
        /* Metodos para strings */
        String sMayus = s.toUpperCase(); // convierte caracteres a mayusculas
        String sMinus = s.toLowerCase(); // convierte caracteres a minusculas

        System.out.println("Original: "+s);
        System.out.println("Mayusculas: "+sMayus);
        System.out.println("Minusculas: "+sMinus);

        /* Subcadenas, uso para obtener porciones de la cadena original */
        String s1 = s.substring(0, 7); // tomamos desde el caracter 0 al 7
        String s2 = s.substring(8,11); // tomamos desde el caracter 8 al 11
        String s3 = s.substring(13); // tomamos desde el caracter 13 hasta el final

        System.out.println(s1);
        System.out.println(s2);
        System.out.println(s3);

        /* Ocurrencia de caracteres (Ubicar la posicion de un cacracter) */
        int pos1 = s.indexOf('C'); // retorna la posición de la primera ocurrencia de un carácter dentro del string. Si no existe retorna un valor negativo.
        int pos2 = s.lastIndexOf('C'); // retorna la posicion de la ultima ocurrenia de un caracter dentro del string. Si no existe retorna un valor negativo.  

        System.out.println("Primera ocurrencia letra C: "+pos1+". Ultima ocurrencia letra C: "+pos2);

        /* Conversion entre numeros y cadenas */
        System.out.println("Conversiones 1:");
        // operaciones con el tipo entero
        int k = 43;
        String sInt = Integer.toString(k); // convertirme de int a string
        int k2 = Integer.parseInt(sInt); // convertir de string a int

        // operaciones con el tipo double
        double d = 45.3;
        String sDouble = Double.toString(d); // convertimos de double a string
        double d2 = Double.parseDouble(sDouble); // convertir de string a double

        System.out.println(k2+", "+d2);

        // entero a cadena de caracteres
        System.out.println("Conversiones 2:");
        String cad = "10";
        int numerito = Integer.parseInt(cad);
        System.out.println("El numero es: "+numerito);

        System.out.println("El numero string es: "+String.valueOf(numerito));
        System.out.println("El numero string es: "+String.format("%d", numerito)); // alternativa

        /* Comparacion de Cadenas */
        String ss1 = "Hola", ss2 = "Chau";
        // uso del metodo equals para strings
        if (ss1.equals(ss2)) {
            System.out.println("Son iguales");
        } else {
            System.out.println("No son iguales");
        } // deberia retornar que no son iguales
    }
}
