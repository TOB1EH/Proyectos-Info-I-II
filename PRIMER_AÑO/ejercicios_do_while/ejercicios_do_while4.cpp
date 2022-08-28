//Ejercicios Do-While Nº4 _ Funes Tobias

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int edad=0, total=0;
	cout<<"Ingrese todas las edades del grupo familiar, cuando finalice"; 
	cout<<" ingrece 0:"<<endl;
	do{
		cin>>edad;
		if(edad>= 5 && edad<=15){
			total+=20;
		}
		else{
			if(edad>=0 && edad<5){
				total+=0;
			}
			else{
				if(edad>15){
				total+=40;
				}
				else{
					cout<<"ERROR! numero invalido: "<<edad<<endl;
					cout<<"Se omitira este valor\n";
					edad=0;
				}
			}
		}
	} while(edad!=0);
	cout<<"Total a pagar: $"<<total<<endl;
	cout<<"\n\nTabla de Precios:\n-Menores de 5 años gratis.\n-Entre 5";
	cout<<" 15 años inclusive $20.\n-Mayores de 15 años $40.";
	return 0;
}

