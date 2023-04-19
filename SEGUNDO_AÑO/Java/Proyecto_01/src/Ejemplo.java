public class Ejemplo {
    /* Atributos */
    public int x;
    public int a;
    /* private int x; */
    /* private int a; */

    /* Metodos */
    public Ejemplo() {
        // Es importante tener en cuenta que al declarar, explícitamente, un constructor perdemos el constructor por defecto
    } // constructor por defecto

    public void hacerAlgo() {
        x = 1 + a + 3;
    }

    public int suma() {
        return x + a;
    }

    public void imprimir() {
        System.out.println("x = "+x+" a = "+a+"\n");
    }
}
