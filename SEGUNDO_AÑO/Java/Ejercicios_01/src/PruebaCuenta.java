public class PruebaCuenta {
    public static void main(String[] args) {
        // Declaracion e instancia de objetos
        Cuenta cuentaCredito = new Cuenta();
        Cuenta cuentaDebito = new Cuenta();

        // carga de datos
        cuentaCredito.setNombre("Pedro Sanchez");
        cuentaCredito.depositar(1500);
        cuentaCredito.setNumero(244513);
        cuentaCredito.setTipo("credito");

        cuentaDebito.setNombre("Pablo Garcia");
        cuentaDebito.depositar(7800);
        cuentaDebito.setNumero(273516);
        cuentaDebito.setTipo("debito");

        /* Impresion de datos */
        cuentaCredito.imprimir();
        cuentaDebito.imprimir();
    }
}
