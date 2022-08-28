//If-else2 - Ejercicio N°1 -Funes Tobias

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int num1=0, num2=0;
	float cociente=0;
	cout<<"Ingrese dos numeros enteros, que no sea cero, para";
	cout<<" dividirlos entre si: ";
	cin>>num1>>num2;
	if(num1%num2 == 0){
		cociente= num1/num2;
		cout<<"La division exacta entre "<<num1<<" y "<<num2<<" es igual a ";
		cout<<cociente;
	}
	else{
		cociente= num1/num2;
		cout<<"La division entre "<<num1<<" y "<<num2<<" no es exacta, es ";
		cout<<"decir su cociente no es un entero, sino un decimal";
	}
	return 0;
}

