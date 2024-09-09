//Informatica - Ejercicio If else Nº6 - Funes Tobias

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	float lado1=0, lado2=0, lado3=0;
	cout<<"A continuacion ingrese la medida de los lados de su triangulo ";
	cout<<"segun corresponda:\nLado 1: ";
	cin>>lado1;
	cout<<"Lado 2: ";
	cin>>lado2;
	cout<<"Lado 3: ";
	cin>>lado3;
	if(lado1==lado2 && lado1==lado3){
		cout<<"Corresponde a un triangulo Equilatero";
	}//cierre if
	else{
		if(lado1!=lado2 && lado1!=lado3 && lado2!=lado3){
			cout<<"Corresponde a un triangulo Escaleno";
		}//cierre if anidado
		else{
			cout<<"Corresponde a un triangulo Isoseles";
		}//cierre else anidado
	}//cierre else 
	return 0;
}//cierre main

