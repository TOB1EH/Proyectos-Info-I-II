//Informatica - Ejercicios for N°3 - Funes Tobias

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	float pointx=0, pointy=0;
	int ii=0, points=0, origen=0, c1=0, c2=0, c3=0, c4=0; //c=cuadrante
	cout<<"Ingrese la cantidad de puntos de coordenadas que va a ingresar: ";
	cin>>points;
	for(ii=1;ii<(points+1);ii++){
		cout<<"Ingrese las coordenadas (X, Y) del punto "<<ii<<endl;
		cout<<"Coordenadas en X: ";
		cin>>pointx;
		cout<<"Coordenadas en Y: ";
		cin>>pointy;
		if(pointx>0 && pointy>0){
			c1++;
		}
		else{
			if(pointx<0 && pointy>0){
				c2++;
			}
			else{
				if(pointx<0 && pointy<0){
					c3++;
				}
				else{
					if(pointx>0 && pointy<0){
						c4++;
					}
					else{
						origen++;
					}
				}
			}
		}	
	}
	cout<<"\nPuntos ingresados en el Primer Cuadrante: "<<c1;
	cout<<"\nPuntos ingresados en el Segundo Cuadrante: "<<c2;
	cout<<"\nPuntos ingresados en el Tercer Cuadrante: "<<c3;
	cout<<"\nPuntos ingresados en el Cuarto Cuadrante: "<<c4;
	cout<<"\nPuntos ingresados en el Origen de coordenadas: "<<origen<<endl;
	return 0;
}

