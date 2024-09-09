//If-else2 - Ejercicio N°2 -Funes Tobias

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int num1=0, num2=0;
	cout<<"Ingrese dos numeros: ";
	cin>>num1>>num2;
	if(num1 == num2){
		cout<<"Ambos numeros son iguales: "<<num1<<" = "<<num2;
	}
	else{
		if(num1 < num2){
			cout<<num1<<" es menor que "<<num2;
		}
		else{
			cout<<num1<<" es mayor que "<<num2;
		}
	}
	return 0;
}

