// Informatica - Ejercicios for N°5 - Funes Tobias

#include <iostream>
#define hours 24 // defino la cantidad de horas
using namespace std;

int main(int argc, char *argv[]) {
	int ii=0;
	float temp=0, sumatoria=0, temp_max=0, temp_min=0;
	for(ii=0; ii<hours; ii++){
		cout<<"Ingrese temperatura actual: ";
		cin>>temp;
		sumatoria+=temp; // sumatoria almacena la suma de todas las temp. ingresadas durante el ciclo
		
		if (ii==0) /* Cuando 'ii' sea igual a '0', es decir cuando cominza el ciclo for, las variables
		de temp_max y temp_min toman el valor de temp que se ingrese en ese momento */
		{
			temp_max=temp;
			temp_min=temp;
		}
		else{ /* Si el if anterior es falso, es decir 'ii' sea mayor a '0' temp_max y temp_min tomaran el 
		valor que les corresponda: temperatura maxima y minima ingresada */  
			if(temp>temp_max){
				temp_max=temp;
			}
			if(temp<temp_min){
				temp_min=temp;
			}
		}
	}
	cout<<"\nTemperatura promedio diaria: "<<sumatoria/hours<<endl; // imprime la temperatura promedio en 24 hs.
	cout<<"Temperatura maxima alcanzada: "<<temp_max<<endl;
	cout<<"Temperatura minima alcanzada: "<<temp_min<<endl;
	return 0;
}