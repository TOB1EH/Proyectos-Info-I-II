//Informática - Vectores ejercicio N°3 - Funes Tobias

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int ii=0;
    char ABC[26], abc[26]; // 26 = letras en el abecedario sin incluir la Ñ
    for ( ii = 0; ii < 26; ii++)
    {
        ABC[ii] = ii+65; // De acuerdo al codigo ASCII A=65
        abc[ii] = ii+97; // De acuerdo al codigo ASCII a=97
    }// cierre for1
    cout<<"|";
    for ( ii = 0; ii < 26; ii++)
    {
        cout<<" "<<ABC[ii]<<abc[ii]<<" |";
    }// cierre for2
    cout<<endl;
    return 0;
}