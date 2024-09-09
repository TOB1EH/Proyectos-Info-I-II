//Informatica - ejercicios if else Nº4 - Funes Tobias

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int edad=0;
	float ingresos=0;
	cout<<"Ingrese su edad: ";
	cin>>edad;
	cout<<"Ingrese el monto de sus ingresos mensuales: $";
	cin>>ingresos;
	if(edad>25 && ingresos>=200000){
		cout<<"Usted debe tributar impuestos.";
	}
	else{
		cout<<"Usted no debe tributar impuestos";
	}
	return 0;
}

