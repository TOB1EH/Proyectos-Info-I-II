//Informatica - Ejercicio While N°2 - FunesTobias

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {	
	int opcion=0;
	float num1=0, num2=0;
	char resp=' ';
	cout<<"Ingresar dos numeros enteros para operar entre si:"<<endl;
	cout<<"Numero 1: ";
	cin>>num1;
	cout<<"Numero 2: ";
	cin>>num2;
	cout<<"Desea comenzar S/N: ";
	cin>>resp;
	while(resp=='S' || resp=='s' || resp!='N' || resp!='n'){
		cout<<"\nQue operacion desea realizar:\n";
		cout<<"1.Sumar ambos numeros\n2.Restar al primero el segundo";
		cout<<"\n3.Multiplicar entre si ambos numeros";
		cout<<"\n4.Dividir al primero por el segundo"<<endl;
		cin>>opcion;
		switch(opcion){
		case 1:
			cout<<"Suma: "<<num1<<" + "<<num2<<" = "<<num1+num2;
			break;
		case 2:
			cout<<"Resta: "<<num1<<" - "<<num2<<" = "<<num1-num2;
			break;
		case 3:
			cout<<"Producto/Multiplicacion: "<<num1<<" * "<<num2<<" = "<<num1*num2;
			break;
		case 4:
			cout<<"Division: "<<num1<<"/"<<num2<<" = "<<num1/num2;
			break;
		default:
			cout<<"Ingreso un valor invalido";
			break; 		
		}//cierre switch
		cout<<"\n¿Otra operación con los mismos números (S/N)?";
		cin>>resp;
	}//cierre while
	return 0;
}