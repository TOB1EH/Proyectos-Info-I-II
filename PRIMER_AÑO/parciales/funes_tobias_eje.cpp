#define META 5000 //meta de venta de kilos en un mes 
#define MONTO 500 //precio del kilo de helado
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int ii=0, dia1=0, dia2=0; //dia1= mas ventas, dia2=menos ventas
	float kg=0, suma=0, mas=0, menos=0; //mas=kg vendidos en el dia con mas ventas, menos=kg vendidos en el dia con menos ventas
	char opcion=' ';
	for(ii = 1; ii < 31; ii++){ //mes de 30 dias pero inicializado en 1. por lo tanto el for finaliza cunado ii = 31 
		cout<<"Ingrese la cantidad de kilogramos de helados vendidos hoy";
		cout<<"(dia "<<ii<<"/30): ";
		cin>>kg;
		suma+=kg;
		if(ii==1){
			menos=kg;
			mas=kg;
		}
		if(kg>=mas){
			mas=kg;
			dia1=ii;
		}
		if(kg<menos){
			menos=kg;
			dia2=ii;
		}
	}
	while(ii==31){
		cout<<"\nIngrese una opcion para mostrar su informacion: ";
		cout<<"\na. Total de kilos de helado vendidos en un mes."<<endl; 
		cout<<"b. Monto recaudado en un mes."<<endl;
		cout<<"c. Día del mes que se vendió más kilos de helado y la cantidad."<<endl;
		cout<<"d. Día del mes que se vendió menos kilos de helado y la cantidad."<<endl;
		cout<<"e. Meta de vender más de 5000 kilos de helado."<<endl;
		cout<<"f. Cerrar el menu de opciones"<<endl;
		cout<<"Opcion (en minusculas): ";
		cin>>opcion;
		cout<<"\n-----------------------------------------------------------------------------";
		switch(opcion){
		case 'a':
			cout<<"\nKilos de helado vendido durante este mes: "<<suma<<" Kg."<<endl;
			break;
		case 'b':
			cout<<"\nMonto recaudado este mes: $"<<suma*MONTO<<endl;
			break;
		case 'c':
			cout<<"\nDia del mes con mas ventas: "<<dia1<<"/30"<<endl;
			cout<<"En total ese dia se vendieron: "<<mas<<"Kg. de helado"<<endl;
			break;
		case 'd':
			cout<<"\nDia del mes con menos ventas: "<<dia2<<"/30"<<endl;
			cout<<"En total ese dia se vendieron: "<<menos<<"Kg. de helado"<<endl;
			break;
		case 'e':
			if(suma>META){
				cout<<"\nSe cumplio la meta de vender más de 5000 kilos de helado.";
				cout<<"\nA los empleados les corresponde el bono adicional"<<endl;
			}
			else{
				cout<<"\nNo se cumplio la meta de vender más de 5000 kilos de helado.";
				cout<<"\nA los empleados no les corresponde el bono adicional"<<endl;
			}
			break;
		case 'f':
			ii=0;
			break;
		default:
			break;
		}
	}
	return 0;
}

