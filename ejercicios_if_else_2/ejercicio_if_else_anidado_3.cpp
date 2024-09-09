//If-else2 - Ejercicio N°3 -Funes Tobias

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int num1=0, num2=0, num3=0;
	cout<<"Ingrese tres numeros para comparar: ";
	cin>>num1>>num2>>num3;
	if(num1!=num2 && num1!=num3 && num2!=num3){
		cout<<"Los tres numeros ingresados son diferentes";
	}
	else{
		if(num1 == num2 && num1 == num3){
		cout<<"Los tres numeros ingresados son iguales";
		}
		else{
			cout<<"Dos de los tres numeros ingresados son iguales";
		}
	}
	return 0;
}

