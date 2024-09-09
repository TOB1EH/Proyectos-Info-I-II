//If-else2 - Ejercicio N°5 -Funes Tobias

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	float nota=0;
	char letra=NULL;
	cout<<"Ingrese la inicial de su apellido en mayuscula: ";
	cin>>letra;
	cout<<"Ingrese su calificacion obtenida en el examen (1-10): ";
	cin>>nota;
	if(letra>= 'A' && letra<='M'){
		if(nota>=7){
			cout<<"Usted pertenece al grupo A"<<endl;
		}
		if(nota>=0 && nota<7){
			cout<<"Usted pertenece al grupo C"<<endl;
		}
	}
	else{
		if(letra>= 'N' && letra<= 'Z'){
			if(nota>=7){
				cout<<"Usted pertenece al grupo B"<<endl;
			}
			if(nota>=0 && nota<7){
				cout<<"Usted pertenece al grupo D"<<endl;
			}
		}
	}
	return 0;
}

