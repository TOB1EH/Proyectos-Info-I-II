public class PruebaEjemplo {
    public static void main(String[] args) {
        Ejemplo e = new Ejemplo(); // Declaracion e instancia del objeto de la clase Ejemplo
        Ejemplo f = new Ejemplo(); // Declaracion e instancia del objeto

        e.a = 7;
        e.hacerAlgo();
        f.x = e.suma();
        f.a = f.x + e.a;
        e.a = f.suma();
        e.imprimir();;
        f.imprimir();;
    }
}
