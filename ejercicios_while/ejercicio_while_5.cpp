//Informatica - Ejercicio While N°5 - FunesTobias

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int opcion=0, candi_1=0, candi_2=0, candi_3=0, blanco=0, inpugnado=0; // candi = candidatos
    char voto=' ';
    //Ciclo While
    while (opcion==0)
    {
        cout<<"\nPara finalizar las elecciones ingrese 'z'\nCandidatos a elecciones:\na.Candidato 'a'";
        cout<<"\nb.Candidato 'b'\nc.Candidato 'c'\nd.Voto en blanco\ne.Inpugnado\nIngrese su voto ('a', 'b' o 'c'): ";
        cin>>voto;
        if (voto=='a' || voto=='A') candi_1++;
        if (voto=='b' || voto=='B') candi_2++;
        if (voto=='c' || voto=='C') candi_3++;
        if (voto=='d' || voto=='D') blanco++;
        if (voto=='e' || voto=='E') inpugnado++;
        if (voto=='z' || voto=='Z') opcion=1; //si se ingresa 'Z' por teclado se termina el ciclo While
    }
    //if 1
    if (candi_1>candi_2 && candi_1>candi_3)
    {
        if (candi_2>candi_3)
        {        
            cout<<"\nResultado de elecciones: "<<endl;
            cout<<" 1°. Candidato 'a' con "<<candi_1<<" votos"<<endl;
            cout<<" 2°. Candidato 'b' con "<<candi_2<<" votos"<<endl;
            cout<<" 3°. Candidato 'c' con "<<candi_3<<" votos"<<endl;
            cout<<" En Blanco: "<<blanco<<" votos\n Inpugnados: "<<inpugnado<<" votos"<<endl;
        }
        if (candi_3>candi_2)
        {
            cout<<"\nResultado de elecciones: "<<endl;
            cout<<" 1°. Candidato 'a' con "<<candi_1<<" votos"<<endl;
            cout<<" 2°. Candidato 'c' con "<<candi_3<<" votos"<<endl;
            cout<<" 3°. Candidato 'b' con "<<candi_2<<" votos"<<endl;
            cout<<" En Blanco: "<<blanco<<" votos\n Inpugnados: "<<inpugnado<<" votos"<<endl;
        }
    }
    //if 2
    if (candi_2>candi_1 && candi_2>candi_3)
    {
        if (candi_1>candi_3)
        {        
            cout<<"\nResultado de elecciones: "<<endl;
            cout<<" 1°. Candidato 'b' con "<<candi_2<<" votos"<<endl;
            cout<<" 2°. Candidato 'a' con "<<candi_1<<" votos"<<endl;
            cout<<" 3°. Candidato 'c' con "<<candi_3<<" votos"<<endl;
            cout<<" En Blanco: "<<blanco<<" votos\n Inpugnados: "<<inpugnado<<" votos"<<endl;
        }
        if (candi_3>candi_1)
        {
            cout<<"\nResultado de elecciones: "<<endl;
            cout<<" 1°. Candidato 'b' con "<<candi_2<<" votos"<<endl;
            cout<<" 2°. Candidato 'c' con "<<candi_3<<" votos"<<endl;
            cout<<" 3°. Candidato 'a' con "<<candi_1<<" votos"<<endl;
            cout<<" En Blanco: "<<blanco<<" votos\n Inpugnados: "<<inpugnado<<" votos"<<endl;
        }
    }
    //if 3
    if (candi_3>candi_1 && candi_3>candi_2)
    {
        if (candi_1>candi_2)
        {        
            cout<<"\nResultado de elecciones: "<<endl;
            cout<<" 1°. Candidato 'c' con "<<candi_3<<" votos"<<endl;
            cout<<" 2°. Candidato 'a' con "<<candi_1<<" votos"<<endl;
            cout<<" 3°. Candidato 'b' con "<<candi_2<<" votos"<<endl;
            cout<<" En Blanco: "<<blanco<<" votos\n Inpugnados: "<<inpugnado<<" votos"<<endl;
        }
        if (candi_2>candi_1)
        {
            cout<<"\nResultado de elecciones: "<<endl;
            cout<<" 1°. Candidato 'c' con "<<candi_3<<" votos"<<endl;
            cout<<" 2°. Candidato 'b' con "<<candi_2<<" votos"<<endl;
            cout<<" 3°. Candidato 'a' con "<<candi_1<<" votos"<<endl;
            cout<<" En Blanco: "<<blanco<<" votos\n Inpugnados: "<<inpugnado<<" votos"<<endl;
        }
    }

    else if (candi_1==candi_2 && candi_1==candi_3)
    {
        cout<<"\nEmpate electoral"<<endl;
        cout<<" Candidato 'a': "<<candi_1<<" votos"<<endl;
        cout<<" Candidato 'b': "<<candi_2<<" votos"<<endl;
        cout<<" Candidato 'c': "<<candi_3<<" votos"<<endl;
        cout<<" En Blanco: "<<blanco<<" votos\n Inpugnados: "<<inpugnado<<" votos"<<endl;
    }
    return 0;
}