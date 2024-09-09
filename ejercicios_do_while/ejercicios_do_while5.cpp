//Ejercicios Do-While Nº5 _ Funes Tobias

#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

int main(int argc, char *argv[]) {
	# define MY_PI 3.14159265358979323846
	float num=0, rad=0;
	int opcion=0;
	do{
		cout<<"\nQue operacion desea realizar:\n";
		cout<<"1.Elevar a la potencia de 2 un numero\n2.Raíz cuadrada de un ";
		cout<<"numero\n3.Raíz cubica de un numero\n4.Calcular el seno, coseno";
		cout<<" y tangente de un angulo\n0.Finalizar menu"<<endl;
		cin>>opcion;
		switch(opcion){
		case 1:
			cout<<"Ingrese el numero en cuestion: ";
			cin>>num;
			num = pow(num,2);
			cout<<"Resultado = "<<num;
			break;
		case 2:
			cout<<"Ingrese el numero en cuestion: ";
			cin>>num;
			num = sqrt(num);
			cout<<"Resultado = "<<num;
			break;
		case 3:
			cout<<"Ingrese el numero en cuestion: ";
			cin>>num;
			num = pow(num,(double)1/3);
			cout<<"Resultado = "<<num;
			break;
		case 4:
			cout<<"Ingrese el angulo en cuestion (0º-360º):";
			cin>>num;
			if(num==90 || num==-90 || num==270 || num==-270){
				cout<<"sen("<<num<<") = 1";
				cout<<"\ncos("<<num<<") = 0";
				cout<<"\ntan("<<num<<") = INDEFINIDO"<<endl;
			}//cierre if1
			else{
				if(num==180 || num==-180 || num==360 || num==-360){
				cout<<"sen("<<num<<") = 0";
				cout<<"\ncos("<<num<<") = -1";
				cout<<"\ntan("<<num<<") = 0"<<endl;
				}//cierre if2
				else{
					rad = ((num * MY_PI)/180);
					cout<<"sen("<<num<<") = "<<sin(rad);
					cout<<"\ncos("<<num<<") = "<<cos(rad);
					cout<<"\ntan("<<num<<") = "<<tan(rad)<<endl;		
				}//cierre else2
			}//cierre else1
			break;
		}//cierre switch
		cout<<"\n";
	} while(opcion!=0);
	return 0;
}

