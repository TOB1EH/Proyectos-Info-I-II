//Ejercicios Do-While Nº3 _ Funes Tobias

#include <iostream>
#include <ctime>
using namespace std;


int main(int argc, char *argv[]) {
	char si_no=' ';
	int n1=0, n2=0, result=0;
	
	do{
		srand(time(NULL));
		n1 = rand()%10;
		n2 = rand()%10;
		cout<<"Ingrese el resultado de la siguiente operacion: "<<endl;
		cout<<n1<<" * "<<n2<<" = ";
		cin>>result;
		if(result == n1*n2){
			cout<<"Resultado correcto!";
		}
		else{
			cout<<"Resultado incorrecto, "<<n1<<"*"<<n2<<" = "<<n1*n2;
		}
		cout<<"\nPara seguir practicando ingrese 'S', para salir ingrese 'N' ";
		cin>>si_no;
	} while(si_no == 'S' || si_no == 's');
	return 0;
}

