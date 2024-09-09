//Informatica - Ejercicio If else Nº2 - Funes Tobias

#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
	int unidades=0, estudiadas=0, faltantes=0;
	cout<<"Ingrese el numero de unidades de la Materia: ";
	cin>>unidades;
	cout<<"Ingrese las unidades estudiadas: ";
	cin>>estudiadas;
	if(unidades == estudiadas){
		cout<<"El alumno estudio todas las unidades de la materia";
	}
	else{
		faltantes = unidades-estudiadas;
		cout<<"Al alumno le faltan estudiar "<<faltantes<<" unidades";
		cout<<" de la materia";
	}
	return 0;
}

