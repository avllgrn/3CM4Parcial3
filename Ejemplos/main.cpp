#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void rellenaVector(int n, int X[50]){
    for(int i=0; i<n; i++)
        X[i] = rand()%100;
}

void muestraVector(int n, int X[50]){
    for(int i=0; i<n; i++)
        cout<<X[i]<<" ";
    cout<<endl;
}

void intercambia(int X[50], int i, int f){
    int aux=X[i];
    X[i] = X[f];
    X[f] = aux;
}

int particiona(int X[50], int ini, int fin){
    int piv = X[fin];
    int i=ini;
    int f=fin-1;
    cout<<"ini="<<ini<<" fin="<<fin<<" piv="<<piv<<endl;
    while(i<=f){
        if(X[i]>piv){
            intercambia(X,i,f);
            f--;
        }
        else{
            i++;
        }
    }
    cout<<"i="<<i<<" f="<<f<<" piv="<<piv<<endl;
    intercambia(X,i,fin);
    return i-1;
}

void quickSort(int X[50], int ini, int fin){
    if(ini<fin){
        int p = particiona(X, ini, fin);
        cout<<"p="<<p<<endl;
        quickSort(X,ini,p);
        quickSort(X,p+1,fin);
    }
}

void quickSort(int n, int X[50]){
    quickSort(X,0,n-1);
}

int main(void){
    srand(time(NULL));
    int n, V[50];
    cout<<"Cuantos? ";cin>>n;

    rellenaVector(n, V);
    cout<<endl<<"V inicial"<<endl;
    muestraVector(n, V);
    cout<<endl<<endl;

    quickSort(n, V);
    cout<<endl<<"V final"<<endl;
    muestraVector(n, V);
    cout<<endl<<endl;

    return 0;
}
