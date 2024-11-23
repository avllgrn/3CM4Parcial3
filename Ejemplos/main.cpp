#include <iostream>
#include <stdlib.h>
using namespace std;

bool esNumero(char c){
    return 48<=c && c <=57;
}
bool esMayuscula(char c){
    return 65<=c && c <=90;
}
bool esMinuscula(char c){
    return 97<=c && c <=122;
}
bool esLetra(char c){
    return esMayuscula(c) || esMinuscula(c);
}
bool esEspecial(char c){
    return !esLetra(c) && !esNumero(c);
}

string procesaCadena(string Cadena){
    string Procesada;
    char c;
    int i,tam;
    tam = Cadena.size();

    for(i=0; i<tam; i++)
        if(!esEspecial(Cadena.at(i)))
            Procesada.push_back(toupper(Cadena.at(i)));

    return Procesada;
}

bool esPalindromo(string& Cadena, int ini, int fin){
    int n = fin-ini+1;
    if(n <= 1)
        return true;
    else if(Cadena[ini]!=Cadena[fin])
        return false;
    else{
        cout<<Cadena.substr(ini+1, n-2)<<endl;
        return esPalindromo(Cadena, ini+1, fin-1);
    }
}

int main(void){
    string Cadena, Procesada;
    char c;
    int i,tam;
    cout<<"Ingresa una cadena de caracteres ";
    getline(cin, Cadena);

    Procesada = procesaCadena(Cadena);

    if(esPalindromo(Procesada,0,Procesada.size()-1))
        cout<<"ES palindromo."<<endl;
    else
        cout<<"NO es palindromo."<<endl;

    return 0;
}
