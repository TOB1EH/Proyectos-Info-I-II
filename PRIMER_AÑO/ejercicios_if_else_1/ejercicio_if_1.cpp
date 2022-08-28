//Informatica - Ejercicio If else Nº1 - Funes Tobias


#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
	int number=0;
	cout<<"Ingrese un numero para saber si es par o impar:"<<endl;
	cin>>number;
	if(number%2==0){
		cout<<"El numero "<<number<<" es par"<<endl;
	}
	else{
		cout<<"El numero "<<number<<" es impar"<<endl;
	}
	return 0;
}

