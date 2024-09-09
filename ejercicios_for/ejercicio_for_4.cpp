//Informatica - Ejercicios for N�4 - Funes Tobias

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int ii=0;
	float sueldo_mes=0, gastos_mes=0, total_sueldo=0, total_gasto=0;
	for(ii=1;ii<13;ii++){
		cout<<"Ingrese el valor de su sueldo en el mes "<<ii<<": $";
		cin>>sueldo_mes;
		cout<<"Ingrese el valor de los gastos de este mismo mes: $";
		cin>>gastos_mes;
		total_sueldo+=sueldo_mes;
		total_gasto+=gastos_mes;
	}
	cout<<"Ahorros en un año: $"<<total_sueldo-total_gasto;
	return 0;
}

