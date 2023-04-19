public class Cuenta {
    /* Atributos */
    private String nombre;
    private double saldo;
    private int numero;
    private String tipo;

    /* Metodos */
    public void setNombre(String name) {
        nombre = name;
    }

    public void setNumero(int num) {
        numero = num;
    }

    public void setTipo(String tipo) {
        // para diferenciar las varibles
        this.tipo = tipo;
    }

    public void depositar(double deposito) {
        saldo += deposito;
    }

    public void retirar(double retiro) {
        if (saldo >= retiro) {
            saldo -= retiro;
            System.out.println("Retiro exitoso\n");
        } else {
            System.out.println("Saldo insuficiente\n");
        }
    }

    public void imprimir() {
        System.out.println("***************************\n"+
                            "DATOS DE LA CUENTA:\n"+
                            "Nombre: "+nombre+"\n"+
                            "Saldo: $"+saldo+"\n"+
                            "Numero: "+numero+"\n"+
                            "Tipo: "+tipo+"\n");
    }
}
