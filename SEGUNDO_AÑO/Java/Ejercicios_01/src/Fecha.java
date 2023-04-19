// Clase Fecha para sobrecarga de datos

public class Fecha {
    // Atributos
    private int dia;
    private int mes;
    private int anio;

    // constructor recibe dia, mes, anio
    public Fecha(int dia, int mes, int anio)
    {
        this.dia = dia;
        this.mes = mes;
        this.anio = anio;
    }
    // constructor sin argumentos
    public Fecha()
    {
    }

    // metodos setters y getters
    public void setDia(int dia)
    {
        this.dia = dia;
    }

    public int getDIa()
    {
        return dia;
    }

    public void setMes(int mes)
    {
        this.mes = mes;
    }

    public int getMes()
    {
        return mes;
    }

    public void setAnio(int anio)
    {
        this.anio = anio;
    }

    public int getAnio()
    {
        return anio;
    }

    public String toString()
    {
        return dia+"/"+mes+"/"+anio;
    }

    public Fecha(String s)
    {
        // buscamos la primera ocurrencia de '/'
        int pos1 = s.indexOf('/');

        // buscamos la ultima ocurrencia de '/'
        int pos2 = s.lastIndexOf('/');

        // procesamos el dia
        String sDia = s.substring(0, pos1);
        dia = Integer.parseInt(sDia);

        // procesamos el mes
        String sMes = s.substring(pos1+1, pos2);
        mes = Integer.parseInt(sMes);

        // procesamos el anio
        String sAnio = s.substring(pos2+1);
        anio = Integer.parseInt(sAnio);
    }
}
