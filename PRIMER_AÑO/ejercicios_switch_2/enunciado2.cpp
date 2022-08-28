/*Enunciado N°2: Codificar un programa para hacer un pasaje de unidad entre
grados Celsius, Kelvin y Fahrenheit*/

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	float c=0, k=0, f=0, valor=0, n1=0.5555555556;
	int opcion=0;
	cout<<"Ingrese un numero correspondiente a la unidad a convertir:\n";
	cout<<"1.Celsius\n2.Fahrenheit\n3.Kelvin\n";
	cin>>opcion;
	cout<<"A continuacion ingrese el valor numerico de la unidad: ";
	cin>>valor;
	switch(opcion){
	case 1:
		k = valor + 273.15;
		f = (1.8 * valor) + 32;
		cout<<"\n";
		cout<<valor<<"° Celsius equivalen a:"<<endl;
		cout<<k<<" Kelvin."<<endl;
		cout<<f<<"° Fahrenheit."<<endl;
		break;
	case 2:
		k = ((valor-32)* n1) + 273.15;
		c = (valor - 32)* n1;
		cout<<"\n";
		cout<<valor<<"° Fahrenheit equivalen a:"<<endl;
		cout<<k<<" Kelvin."<<endl;
		cout<<c<<"° Celsius."<<endl;
		break;
	case 3:
		f = (1.8*(valor - 273.15)) + 32;
		c = valor - 273.15;
		cout<<"\n";
		cout<<valor<<" Kelvin equivalen a:"<<endl;
		cout<<f<<"° Fahrenheit."<<endl;
		cout<<c<<"° Celsius."<<endl;
		break;
	default:
		cout<<"Parametro invalido";
		break;	
	}
	return 0;
}

//Funes Tobias

