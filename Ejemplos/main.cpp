#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

class LDE{
private:
    class Nodo{
    public:
        Nodo* previo;
        int dato;
        Nodo* siguiente;
        Nodo(void){
            previo = NULL;
            dato = 0;
            siguiente = NULL;
        };
        Nodo(Nodo* p, int d, Nodo* s){
            previo = p;
            dato = d;
            siguiente = s;
        };
        void muestraTuEstado(void){
            cout<<"| ";
            if(previo==NULL)
                cout << "NULL";
            else
                cout<< previo;
            cout<<" <- "<<dato<<" -> ";
            if(siguiente==NULL)
                cout << "NULL";
            else
                cout<< siguiente;
            cout<<" |"<<endl;
        };
    };
    Nodo* busca(int d){
        if(!estaVacia()){
            Nodo* aux1 = primero;
            Nodo* aux2 = ultimo;
            while(aux1!=aux2 && aux1->siguiente!=aux2
                  && aux1->dato!=d && aux2->dato!=d){
                aux1 = aux1->siguiente;
                aux2 = aux2->previo;
            }
            if(aux1->dato==d)
                return aux1;
            else if(aux2->dato==d)
                return aux2;
        }
        return NULL;
    };
    Nodo* primero;
    Nodo* ultimo;

    public:
    LDE(void){
        primero = NULL;
        ultimo = NULL;
    };
    ~LDE(void){
        liberaLDE();
    };
    bool estaVacia(void){
        return primero==NULL && primero==ultimo;
    };
    void liberaLDE(void){
        while(!estaVacia()){
            cout<<eliminaAlInicio()<<endl;
        }
    };
    int eliminaAlInicio(void){
        int d;
        Nodo* aux;
        if(!estaVacia() && primero!=ultimo){
            d = primero->dato;
            aux = primero;
            primero = primero->siguiente;
            delete aux;
            primero->previo = NULL;
        }
        else if(!estaVacia() && primero==ultimo){
            d = primero->dato;
            delete primero;
            primero = NULL;
            ultimo = NULL;
        }
        return d;
    };
    int eliminaAlFinal(void){
        int d;
        Nodo* aux;
        if(!estaVacia()){
            d = ultimo->dato;
            if(primero==ultimo){
                delete ultimo;
                ultimo = NULL;
                primero = NULL;
            }
            else{
                aux = ultimo;
                ultimo = ultimo->previo;
                delete aux;
                ultimo->siguiente = NULL;
            }
            return d;
        }
    };
    bool eliminaDato(int d){
        Nodo* aux1 = busca(d);
        if(aux1==NULL)
            return false;
        else if(aux1==primero)
            eliminaAlInicio();
        else if(aux1==ultimo)
            eliminaAlFinal();
        else{
            Nodo* aux2 = aux1->previo;
            aux2->siguiente = aux1->siguiente;
            aux2 = aux1->siguiente;
            aux2->previo = aux1->previo;
            delete aux1;
        }
        return true;
    };
    void insertaAlInicio(int d){
        if(estaVacia()){
            primero = new Nodo(NULL, d, NULL);
            ultimo = primero;
        }
        else{
            primero->previo = new Nodo(NULL, d, primero);
            primero = primero->previo;
        }
    };
    void insertaAlFinal(int d){
        if(estaVacia()){
            ultimo = new Nodo(NULL, d, NULL);
            primero = ultimo;
        }
        else{
            ultimo->siguiente = new Nodo(ultimo, d, NULL);
            ultimo = ultimo->siguiente;
        }
    };
    void inserta(int d){
        if(estaVacia()||d<=primero->dato)
            insertaAlInicio(d);
        else if(d>=ultimo->dato)
            insertaAlFinal(d);
        else{
            Nodo* aux1=primero;
            Nodo* aux2=ultimo;
            while(d>aux1->dato && d<aux2->dato){
                aux1=aux1->siguiente;
                aux2=aux2->previo;
            }
            if(d<=aux1->dato){
                aux2=aux1->previo;
                aux2->siguiente = new Nodo(aux2,d,aux1);
                aux1->previo = aux2->siguiente;
            }
            else if(d>=aux2->dato){
                aux1=aux2->siguiente;
                aux2->siguiente = new Nodo(aux2,d,aux1);
                aux1->previo = aux2->siguiente;
            }
            else{
                aux1->siguiente = new Nodo(aux1,d,aux2);
                aux2->previo = aux1->siguiente;
            }
        }
    };
    void muestraDePrimeroAUltimo(void){
        Nodo* aux;
        aux = primero;
        while(aux!=NULL){
            cout<<aux->dato<<" ";
            aux = aux->siguiente;
        }
    };
    void muestraDeUltimoAPrimero(void){
        Nodo* aux;
        aux = ultimo;
        while(aux!=NULL){
            cout<<aux->dato<<" ";
            aux = aux->previo;
        }
    };
    bool buscaDato(int d){
        return busca(d)!=NULL;
    };
};

int main(){
    srand(time(NULL));
    system("cls");
    LDE L;
    int n;
    cout<<"Cuantos? ";cin>>n;

    for(int i=0;i<n;i++)
        L.insertaAlFinal(rand()%1000);

    cout<<endl<<"L -> ";
    L.muestraDePrimeroAUltimo();
    cout<<endl;
    L.muestraDeUltimoAPrimero();
    cout<<"<- L";
    cout<<endl<<endl;
    system("pause");

    return 0;
}
