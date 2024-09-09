//Informatica - Ejercicio If else Nº7 - Funes Tobias

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int dia=0;
	float cuota=0;
	cout<<"Ingrese el monto de la cuota y el día de pago: "<<endl;
	cout<<"Monto cuota: ";
	cin>>cuota;
	cout<<"Dia de Pago: ";
	cin>>dia;
	if(dia <= 10){
		cout<<"Valor final de la cuota: $"<<cuota<<", no se aplicaron recargos";
	}
	else{
		if(cuota > 5000){
			cuota = cuota *1.1;
			cout<<"Valor final de la cuota: $"<<cuota<<", se aplico un recargo";
			cout<<" del 10%";
		}
		else{
			cuota = cuota *1.05;
			cout<<"Valor final de la cuota: $"<<cuota<<", se aplico un recargo";
			cout<<" del 5%";
		}
	}
	return 0;
}

