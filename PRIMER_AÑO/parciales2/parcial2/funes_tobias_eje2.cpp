#include <iostream>
#include <string>
using namespace std;

#define PESO_LADRILLO 0.350

class Remito
{
private:
    string apellido;
    int numero;
    int cantLadrillos;
    float pesoTot;
public:
    Remito(string ap, int num, int clad, float peso);
    Remito();
    void setterApellido(string ap);
    string getterApellido();
    void setterNUm(int num);
    int getterNum();
    void setterCantL(int clad);
    int getterCantL();
    void setterPesoT(float peso);
    float getterPesoT();
    string toString();
    ~Remito();
};
Remito::Remito(string ap, int num, int clad, float peso)
{
    apellido = ap;
    numero = num;
    cantLadrillos = clad;
    pesoTot = peso;
}
Remito::Remito(){}
void Remito::setterApellido(string ap)
{
    apellido = ap;
}
string Remito::getterApellido()
{
    return apellido;
}
void Remito::setterNUm(int num)
{
    numero = num;
}
int Remito::getterNum()
{
    return numero;
}
void Remito::setterCantL(int clad)
{
    cantLadrillos = clad;
}
int Remito::getterCantL()
{
    return cantLadrillos;
}
void Remito::setterPesoT(float peso)
{
    pesoTot = peso;
}
float Remito::getterPesoT()
{
    return pesoTot;
}
string Remito::toString()
{
    string cadena = "\nApellido: "+apellido+"\nnID: "+std::to_string(numero)+"Cant. Ladrillos: "+std::to_string(cantLadrillos)+"\nPeso total: "+std::to_string(pesoTot)+"Kg ";
    return cadena;
}
Remito::~Remito(){}

/* FUncion Main */
int main(int argc, char const *argv[])
{
    Remito Remito1("Funes", 1, 10, ((float)10*PESO_LADRILLO));
    Remito Remito2;

    /* Carga instancia dos */
    Remito2.setterApellido("Tolocka");
    Remito2.setterNUm(2);
    Remito2.setterCantL(15);
    Remito2.setterPesoT((float)Remito2.getterCantL()*PESO_LADRILLO);

    /* Impresion de dos instancias */
    cout<<Remito1.toString();
    cout<<"\n";
    cout<<Remito2.toString();
    return 0;
}
