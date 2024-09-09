/*Enunciado N°1: Codificar un programa capaz de calcular El perimetro
y el Area de las siguientes figuras geometricas: Circulos, Triangulos
Cuadrados y Rectangulos*/

#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, char *argv[]) {
	int opcion=0;
	float altura=0, base=0, radio=0, pi=3.141592653589793, perimetro=0, area=0;
	float lado1=0, lado2=0, lado3=0;
	cout<<"		Calculadora de Perimetro y  Area de figuras Geometricas:"<<endl;
	cout<<"Ingrese el numero correspondiente de la figura a calcular:"<<endl;
	cout<<"1.Circulo\n2.Triangulo\n3.Cuadrado\n4.Rectangulo\n";
	cin>>opcion;
	switch(opcion){
	case 1:
		cout<<"Ingrese la medida del radio del Circulo:"<<endl;
		cin>>radio;
		perimetro = (2*pi)* radio;
		area = pi * pow(radio,2);
		cout<<"\nPerimetro= "<<perimetro<<endl;
		cout<<"Area= "<<area<<endl;
		break;
	case 2:
		cout<<"Ingrese las medidas de los tres lados del Triangulo:"<<endl;
		cout<<"Lado1: ";
		cin>>lado1;
		cout<<"Lado2: ";
		cin>>lado2;
		cout<<"Lado3: ";
		cin>>lado3;
		cout<<"Ingrese las medidas de la base y la altura del Triangulo:"<<endl;
		cout<<"Base: ";
		cin>>base;
		cout<<"Altura: ";
		cin>>altura;
		area = (base * altura) /2;
		perimetro = lado1 + lado2 + lado3;
		cout<<"\nPerimetro= "<<perimetro<<endl;
		cout<<"Area= "<<area;
		break;
	case 3:
		cout<<"Ingrese las Medidas de uno de los lados del Cuadrado: ";
		cin>>lado1;
		perimetro = 4*lado1;
		area = 2*lado1;
		cout<<"\nPerimetro= "<<perimetro<<endl;
		cout<<"Area= "<<area;
		break;
	case 4:
		cout<<"Ingrese la medida de la base del Rectangulo: ";
		cin>>base;
		cout<<"Ingrese la altura del Rectangulo: ";
		cin>>altura;
		perimetro = (2*base)+(2*altura);
		area = base * altura;
		cout<<"\nPerimetro= "<<perimetro<<endl;
		cout<<"Area= "<<area;
		break;
	default:
		cout<<"Parametro incorrecto"<<endl;
	}
	return 0;
}

//FUNES TOBIAS

