//Informatica - Ejercicio If else Nº5 - Funes Tobias
/*Enunciado: Un Teatro tiene los siguientes precios en sus entradas: menores de 
10 años 15$, de 11 a 17 años 30$, adultos mayores de 18 años 50$ y ancianos a 
partir de 60 años 30$. Escribir un programa que al ingresar la edad muestre 
por pantalla el costo de la entrada*/

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int edad=0;
	cout<<"Ingrese la edad para valuar el costo de la entrada: ";
	cin>>edad;
	if(edad <11){
		cout<<"Costo de entrada: $15";
	}
	else{
		if(edad>10 && edad<18 || edad>=60){
			cout<<"Costo de entrada: $30";
		}
		else{
			cout<<"Costo de entrada: $50";
		}
	}
	return 0;
}

