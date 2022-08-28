//Informatica - ejercicios if else Nº4 - Funes Tobias

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	float renta=0;
	cout<<"Ingrese el monto de su renta anual: U$S";
	cin>>renta;
	if(renta<20000 && renta>0){
		cout<<"Le corresponde un Tipo impositivo de 5%";
	}
	else{
		if(renta>= 20000 && renta<30000){
			cout<<"Le corresponde un Tipo impositivo de 10%";
		}
		else{
			if(renta>=30000 && renta<40000){
				cout<<"Le corresponde un Tipo impositivo de 15%";
			}
			else{
				if(renta>=40000){
					cout<<"Le corresponde un Tipo impositivo de 20%";
				}
				else{
					cout<<"Datos invalidos";
				}
			}
		}
	}
	return 0;
}

