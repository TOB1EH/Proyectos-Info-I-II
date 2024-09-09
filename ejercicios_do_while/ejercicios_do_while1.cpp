//Ejercicios Do-While Nº1 _ Funes Tobias

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int edad=0, counter=0, prom=0, suma=0;
	char resp=NULL;
	do{
		cout<<"Ingrese edad: ";
		cin>>edad;
		suma +=edad;
		counter++;
		cout<<"Desea continuar S/N (si ingresa 'N' se calculara el promedio de edades ingresadas)";
		cin>>resp;
	} while(resp== 'S' || resp=='s');
	prom = suma/counter;
    cout<<"promedio de edades: "<<prom<<endl;
	return 0;
}
