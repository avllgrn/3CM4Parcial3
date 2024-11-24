#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void rellenaVector(int V[], int n) {
    for (int i = 0; i < n; i++)
        V[i] = rand()%100;
}
void muestraVector(int V[], int n) {
    for (int i = 0; i < n; i++)
        cout << V[i] << " ";
    cout << endl;
}

//Fusiona mitades
void fusiona(int V[], int izq, int mit, int der) {
    int n1 = mit - izq + 1;
    int n2 = der - mit;

    //Vectores para cada mitad
    int Izq[n1], Der[n2];

    //Se copian temporalmente los vectores
    for (int i = 0; i < n1; i++)
        Izq[i] = V[izq + i];

    for (int j = 0; j < n2; j++)
        Der[j] = V[mit + 1 + j];

    // Se fusionan ordenadamente los arreglos Izq y Der, en V
    int i = 0, j = 0, k = izq;
    while (i < n1 && j < n2) {
        if (Izq[i] <= Der[j]) {
            V[k] = Izq[i];
            i++;
        }
        else {
            V[k] = Der[j];
            j++;
        }
        k++;
    }

    //Se copian los restantes de Izq
    while (i < n1) {
        V[k] = Izq[i];
        i++;
        k++;
    }

    //Se copian los restantes de Der
    while (j < n2) {
        V[k] = Der[j];
        j++;
        k++;
    }
}

void mergeSort(int V[], int izq, int der) {
    if (izq < der) {
        int mit = izq + (der - izq) / 2;

        //Se divide recursivamente en mitades
        mergeSort(V, izq, mit);
        mergeSort(V, mit + 1, der);

        //Se fusiona ordenadamente las mitades
        fusiona(V, izq, mit, der);
    }
}

int main() {
    srand(time(NULL));
    int V[50];
    int n;

    cout<<"Cuantos? ";cin>>n;

    rellenaVector(V,n);
    cout << "V al inicio -> ";
    muestraVector(V, n);

    mergeSort(V, 0, n - 1);

    cout << "V al final  -> ";
    muestraVector(V, n);
    return 0;
}
