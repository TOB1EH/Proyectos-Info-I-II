//Informatica - Ejercicio If else Nº4 - Funes Tobias

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	float deg=0;
	cout<<"Ingrese la temperatura en grados: ";
	cin>>deg;
	if(deg > 100){
		cout<<"\narriba del punto de ebullicion del agua";
	}
	else{
		cout<<"\nabajo del punto de ebullicion del agua";
	}
	return 0;
}

