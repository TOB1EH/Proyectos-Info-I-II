// Informatica - Ejercicio While N°4 - FunesTobias

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    float producto=0, suma=0, total=0, pagar=0;
    char resp='s';
    while (resp!='N' || resp!='n')
    {
        cout<<"Importe del producto: $";
        cin>>producto;
        suma+=producto;
        if (producto==0)
        {        
            if (suma>=50 && suma<120) 
            {
                pagar = suma-(suma*0.15);
                cout<<"Total a pagar -15%: $"<<pagar<<endl;
            }
            else 
            {    
                if (suma>=120) 
                {
                    pagar = suma - (suma*0.20);
                    cout<<"Total a pagar -20%: $"<<pagar<<endl; 
                }
                else cout<<"Total a pagar: $"<<suma<<endl;
            }
            cout<<"¿Más clientes (S/N)? ";
            cin>>resp;
            
            if (resp=='S' || resp=='s') 
            {
                total += suma;
                suma = 0;
                producto=1;
            }
            else if (resp=='N' || resp=='n')
            {
                total += suma;
                suma = 0;
                break;
            }
        }
    }
    cout<<"\nTotal de importes cobrados por el negocio (sin aplicar desuentos): $"<<total<<endl;
    return 0;
}
