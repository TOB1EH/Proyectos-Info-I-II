/* Librerias */
#include <iostream>
#include <string>
using namespace std;

/* Clases */
class Calificaciones
{
private:
    string nombre;
    int nota1;
    int nota2;
    int nota3;
    int recuperatorio;
    float promedio;
    string resultado;
public:
    Calificaciones(string name, int n1, int n2, int n3, int recup, float prom, string result);
    Calificaciones();
    void setName(string name);
    string getName();
    void setNota1(int n1);
    int getNota1();
    void setNota2(int n2);
    int getNota2();
    void setNota3(int n3);
    int getNota3();
    void setRecup(int recup);
    int getRecup();
    void setProm(float prom);
    float getProm();
    void setResultado(string result);
    string getResultado();
    string toString();
    ~Calificaciones();
}; // Class Calificaciones

/* Constructor Cargado */
Calificaciones::Calificaciones(string name, int n1, int n2, int n3, int recup, float prom, string result)
{
    nombre = name;
    nota1 = n1;
    nota2 = n2;
    nota3 = n3;
    recuperatorio = recup;
    promedio = prom;
    resultado = result;
} // Constructor Calificaciones
Calificaciones::Calificaciones(){} // Constructor por defecto

void Calificaciones::setName(string name)
{
    nombre = name;
} // setName
string Calificaciones::getName()
{
    return nombre;
} // getName
void Calificaciones::setNota1(int n1)
{
    nota1 = n1;
} // setNota1
int Calificaciones::getNota1()
{
    return nota1;
} // getNota1
void Calificaciones::setNota2(int n2)
{
    nota2 = n2;
} // setNota2
int Calificaciones::getNota2()
{
    return nota2;
} // getNota2
void Calificaciones::setNota3(int n3)
{
    nota3 = n3;
} // setNota3
int Calificaciones::getNota3()
{
    return nota3;
} // getNota3
void Calificaciones::setRecup(int recup)
{
    recuperatorio = recup;
} // setRecup
int Calificaciones::getRecup()
{
    return recuperatorio;
} // getRecup
void Calificaciones::setProm(float prom)
{
    promedio = prom;
} // setProm
float Calificaciones::getProm()
{
    return promedio;
} // getProm
void Calificaciones::setResultado(string result)
{
    resultado = result;
} // setResultado
string Calificaciones::getResultado()
{
    return resultado;
} // getResultado
string Calificaciones::toString()
{
    string cadena = "Alumno: "+nombre+"\n"+"Nota1: "+std::to_string(nota1)+"\n"+"Nota2: "+std::to_string(nota2)+"\n"+"Nota3: "+std::to_string(nota3)+"\n"+"Recup: "+std::to_string(recuperatorio)+"\n"+"Prom: "+std::to_string(promedio)+"\n"+"Resultado: "+resultado+"\n"; 
    return cadena;
} // toString

Calificaciones::~Calificaciones(){} // Destructor

/* Funcion principal main */
int main(int argc, char const *argv[])
{
    /* Declaracion e inicializacion de variables */
    Calificaciones Cal1("Funes Tobias", 4, 3, 10, 4, (float((4+10+4)/3)), "Aprobado");
    Calificaciones Cal2;
    
    /* Carga de datos instancia nro 2 */
    Cal2.setName("Tobias Funes");
    Cal2.setNota1(10);
    Cal2.setNota2(3);
    Cal2.setNota3(5);
    Cal2.setRecup(0);
    Cal2.setProm(0);
    Cal2.setResultado("Desaprobado");
    
    /* Impresion de cada instancia */
    cout<<"Intancia1:\n"<<Cal1.toString();
    cout<<"\n";
    cout<<"Intancia2:\n"<<Cal2.toString();
    cout<<"\n";
    return 0;
} // main