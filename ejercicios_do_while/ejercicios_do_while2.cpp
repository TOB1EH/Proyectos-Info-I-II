//Ejercicios Do-While Nº2 _ Funes Tobias

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int num=0, positive=0, negative=0;
	do{
		cout<<"\nIngrese 0 para terminar el proceso"<<endl;
		cout<<"Ingrese un numero entero 'positivo o negativo': ";
		cin>>num;
		if(num>0){
			positive++;
		}
		else{
			if(num<0){
				negative++;
			}
		}
	} while(num!=0);
	cout<<"\nNumeros positivos ingresados en total: "<<positive<<endl;
	cout<<"Numeros negativos ingresados en total: "<<negative<<endl;
	return 0;
}

