//Informatica - Ejercicio If else Nº1 - Funes Tobias

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int alum=0,  viaje=0;
	float total=0, bus=4000.00, precio_x_alum=0;
	cout<<"Ingrese la cantidad de alumnos que participaran del viaje: ";
	cin>>alum;
	if(alum >= 100){
		viaje = alum * 65;
		total = viaje + bus;
		bus = bus/alum;
		precio_x_alum = 65 + bus;
		cout<<"Costo total del viaje: $"<<total<<endl;
		cout<<"Siendo "<<alum<<" alumnos. Incluyendo viaje y colectivo c/u ";
		cout<<"debera abonar $"<<precio_x_alum<<endl;
		cout<<"El director debera pagar a la empresa de viajes: $"<<viaje;
	}//cierre primer if
	else{
		if(alum > 49 && alum < 100){
			viaje = alum * 70;
			total = viaje + bus;
			bus = bus/alum;
			precio_x_alum = 70 + bus;
			cout<<"Costo total del viaje: $"<<total<<endl;
			cout<<"Siendo "<<alum<<" alumnos. Incluyendo viaje y colectivo c/u ";
			cout<<"debera abonar $"<<precio_x_alum<<endl;
			cout<<"El director debera pagar a la empresa de viajes: $"<<viaje;
		}//cierre segundo if
		else{
			if(alum >= 30 && alum < 50){
				viaje = alum * 95;
				total = viaje + bus;
				bus = bus/alum;
				precio_x_alum = 95 + bus;
				cout<<"Costo total del viaje: $"<<total<<endl;
				cout<<"Siendo "<<alum<<" alumnos. Incluyendo viaje y colectivo c/u ";
				cout<<"debera abonar $"<<precio_x_alum<<endl;
				cout<<"El director debera pagar a la empresa de viajes: $"<<viaje;	
			}//cierre tercer if
			else{
				viaje = alum * 100;
				total = viaje + bus;
				bus = bus/alum;
				precio_x_alum = 100 + bus;
				cout<<"Costo total del viaje: $"<<total<<endl;
				cout<<"Siendo "<<alum<<" alumnos. Incluyendo viaje y colectivo c/u ";
				cout<<"debera abonar $"<<precio_x_alum<<endl;
				cout<<"El director debera pagar a la empresa de viajes: $"<<viaje;
			}//cierre tercer else
		}//cierre segundo else
	}//cierre primer else
	return 0;
}//cierre main

