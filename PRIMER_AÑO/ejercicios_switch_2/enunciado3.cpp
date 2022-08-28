/*Enunciado N°3: codificar un programa para un negocio dedicado a la compra
de chatara de metales; el usuario debera ingresar el tipo de chatarra que 
quiere vender y su peso en gramos, siendo las siguientes:
hierro: $14kg.
bronce: $355kg.
cobre: $658kg.
chatarra: 7$kg.*/

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int opcion = 0;
	float peso = 0, precio =0;
	cout<<"Escriba el numero del tipo de chatarra que desea vender: "<<endl;
	cout<<"1.hierro: $14kg\n2.bronce: $355kg\n3.cobre: $658kg\n";
	cout<<"4.chatarra: 7$kg\n";
	cin>>opcion;
	cout<<"Ingrese el peso en gramos: "<<endl;
	cin>>peso;
	switch(opcion){
	case 1:
		precio = 0.014 * peso;
		cout<<"Se le pagara $"<<precio<<" por los "<<peso<<" gramos de hierro";
		break;
	case 2:
		precio = 0.355 * peso;
		cout<<"Se le pagara $"<<precio<<" por los "<<peso<<" gramos de bronce";
		break;
	case 3:
		precio = 0.658 * peso;
		cout<<"Se le pagara $"<<precio<<" por los "<<peso<<" gramos de cobre";
		break;
	case 4:
		precio = 0.007 * peso;
		cout<<"Se le pagara $"<<precio<<" por los ";
		cout<<peso<<" gramos de chatarra";
		break;
	default:
		cout<<"Parametros ingrasados invalidos";
		break;
	}
	return 0;
}

//Funes Tobias

