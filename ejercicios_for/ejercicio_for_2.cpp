//Informatica - Ejercicios for N�2 - Funes Tobias

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int ii=0, num=0, suma=0, prom=0;
	cout<<"A continuacion se le pedira que ingrese 5 valores por separado:"<<endl;
	for(ii=0;ii<5;ii++){
		cout<<"Ingrese un valor entero: ";
		cin>>num;
		suma+=num;
	}
	prom=suma/ii;
	cout<<"Suma total de los valores ingresados = "<<suma<<endl;
	cout<<"Promedio de los valores ingresados = "<<prom<<endl;
	return 0;
}

