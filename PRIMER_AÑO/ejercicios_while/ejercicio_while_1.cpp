// Informatica - Ejercicio While N°1 - FunesTobias

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int valor=0, count=0; 
	cout<<"Ingrese 1 para comenzar"<<endl;
	cin>>valor;
	while(valor!=0){
		cout<<"'Para finalizar el proceso ingrese 0'"<<endl;
		cout<<"Ingrese N valores:"<<endl;
		cin>>valor;
		if(valor==10){
			count++;
		}
	}
	cout<<"El ciclo a finalizado"<<endl;
	cout<<"El numero 10 fue ingresado "<<count<<" veces";
	return 0;
}

