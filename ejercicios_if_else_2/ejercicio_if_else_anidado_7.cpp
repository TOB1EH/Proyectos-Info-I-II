//Informatica - ejercicios if else Nº7 - Funes Tobias

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int edad=0;
	cout<<"Ingrese su edad: ";
	cin>>edad;
	if(edad<4 && edad>0){
		cout<<"Costo de entrada: GRATIS";
	}
	else{
		if(edad >=4 && edad <=18){
			cout<<"Costo de entrada: $100";
		}
		else{
			if(edad>18){
				cout<<"Costo de entrada: $200";
			}
			else{
				cout<<"valores invalidos";
			}
		}
	}
	return 0;
}

