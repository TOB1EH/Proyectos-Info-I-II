//Informatica - Ejercicio While N°3 - FunesTobias

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	float nota=0, aprobo=0, desaprobo=0, mayor=0, menor=0, suma=0;
	int count=0;
	cout<<"Ingrese un numero distinto de cero para comenzar";  
	cout<<". Para finalizar ingrese 0 (no ingrese numeros negativos)"<<endl;
	cin>>nota;
	while(nota!=0)
	{	
		if (count==1){
			mayor=nota;
			menor=nota;
		}
		count++;
		cout<<"Ingrese nota N°"<<count<<": ";
		cin>>nota;
		suma+=nota;

//------------------------------------------------------------------------------
		if (nota>mayor) mayor=nota;
		if (nota<menor && nota!=0) menor=nota;
//----------------------------------------------------------------------------------
		if (nota>=4)
		{
			aprobo++;
		}
		else if(nota>0 && nota<4)
		{
			desaprobo++;
		}			
	}
	cout<<"Evaluaciones aprobadas: "<<aprobo<<endl;
	cout<<"Evaluaciones desaprobadas: "<<desaprobo<<endl;
	cout<<"Promedio General: "<<suma/(count-1)<<endl;
	cout<<"Nota mas alta: "<<mayor<<endl;
	cout<<"Nota mas baja: "<<menor<<endl;
	return 0;
}