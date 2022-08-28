//Informatica - Ejercicio If else Nº3 - Funes Tobias

#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
	float min_n=0, min_i=0, precio=0;
	cout<<"Ingrese los minutos de llamadas locales: ";
	cin>>min_n;
	cout<<"Ingrese los minutos de llamadas internacionales: ";
	cin>>min_i;
	if(min_n > 1000 && min_i > 1000){
		precio = ((min_n*0.05)+(min_i*0.10))*0.90;
		cout<<"Usted si es beneficiario de la promocion, el total de";
		cout<<" su factura aplicando el descuento es de: $"<<precio;
	}
	else{
		precio = ((min_n*0.05)+(min_i*0.10));
		cout<<"Usted no es beneficiario de la promocion, el total de";
		cout<<" su factura a pagar es de: $"<<precio;
	}
	return 0;
}

