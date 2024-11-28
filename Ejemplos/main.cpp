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
    void intercambia(Nodo* aux1, Nodo* aux2){
        int aux=aux1->dato;
        aux1->dato=aux2->dato;
        aux2->dato=aux;
    };
    Nodo* particiona(Nodo* ini, Nodo* fin){
        Nodo* aux1 = ini;
        Nodo* aux2 = ini;
        int pivote = fin->dato;
//        cout<<endl<<"ini = "<<ini->dato<<" fin = "<<fin->dato<<" pivote = "<<pivote<<endl;
        while (aux2!=fin&& aux2->previo!=fin){
            if(aux2->dato<=pivote){
//                cout<<"Se intercambia "<<aux1->dato<<" con "<<aux2->dato<<endl;
                intercambia(aux1, aux2);
                aux1=aux1->siguiente;
            }
            aux2=aux2->siguiente;
        }
        intercambia(aux1, fin);
//        cout<<"Se intercambia "<<aux1->dato<<" con "<<fin->dato<<endl;
//        cout<<endl;
//        muestraDePrimeroAUltimo();
        return aux1->previo;
    };
    Nodo* mitadEntre(Nodo* ini, Nodo* fin){
        Nodo* mitad=ini;
        Nodo* aux=ini;
        if(ini!=fin){
            aux=aux->siguiente;
            while(aux!=fin&&aux!=fin->siguiente){
                if(aux!=NULL)
                    aux=aux->siguiente;
                mitad=mitad->siguiente;
                aux=aux->siguiente;
            }
            return mitad;
        }
        else
            return ini;
    };
    void copia(Nodo* ini, Nodo* fin){
        Nodo* auxi=ini;
        Nodo* auxf=fin;

        if(ini==fin)
            insertaAlInicio(auxi->dato);
        else{
            insertaAlInicio(auxi->dato);
            insertaAlFinal(auxf->dato);
            if(ini->siguiente!=fin){
                Nodo* aux1=primero;
                Nodo* aux2=ultimo;
                auxi=auxi->siguiente;
                auxf=auxf->previo;
                while(auxi!=auxf && auxi->siguiente!=auxf){
                    aux1->siguiente=new Nodo(aux1,auxi->dato,NULL);
                    aux2->previo=new Nodo(NULL,auxf->dato,aux2);
                    aux1=aux1->siguiente;
                    aux2=aux2->previo;
                    auxi=auxi->siguiente;
                    auxf=auxf->previo;
                }
                if(auxi==auxf){
                    aux1->siguiente=new Nodo(aux1, auxi->dato, aux2);
                    aux2->previo=aux1->siguiente;
                }
                else{
                    aux1->siguiente=new Nodo(aux1, auxi->dato, NULL);
                    aux2->previo=new Nodo(NULL, auxf->dato, aux2);
                    aux1=aux1->siguiente;
                    aux2=aux2->previo;
                    aux1->siguiente=aux2;
                    aux2->previo=aux1;
                }
            }
        }
    };
    void quickSort(Nodo* ini, Nodo* fin){
        Nodo* p;
        if(ini!=fin && ini!=NULL && fin!=NULL && ini->previo!=fin){
            p = particiona(ini, fin);
            quickSort(ini, p);
            if(p!=NULL)
                quickSort(p->siguiente, fin);
            else
                quickSort(ini, fin);
        }
    };
    void mergeSort(Nodo* ini, Nodo* fin){
        if(ini!=fin&&ini->previo!=fin){
            Nodo* m = mitadEntre(ini, fin);
            LDE L1;
            L1.copia(ini,m);
            L1.mergeSort(L1.primero,L1.ultimo);
            LDE L2;
            L2.copia(m->siguiente, fin);
            L2.mergeSort(L2.primero,L2.ultimo);
            liberaLDE();
            fusiona(L1,L2);
        }
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
    void liberaLDE(void){
        while(!estaVacia()){
            eliminaAlInicio();
            //cout<<eliminaAlInicio()<<endl;
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
    bool estaVacia(void){
        return primero==NULL && primero==ultimo;
    };
    bool buscaDato(int d){
        return busca(d)!=NULL;
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
    int valorEnMitad(void){
        Nodo* mitad=mitadEntre(primero, ultimo);
        if(mitad!=NULL)
            return mitad->dato;
        else
            return -1;
    };
    void fusiona(LDE& L1, LDE& L2){
        Nodo* aux1=L1.primero;
        Nodo* aux2=L2.primero;
        while(!L1.estaVacia() && !L2.estaVacia()){
            if(aux1->dato<=aux2->dato){
                aux1=aux1->siguiente;
                insertaAlFinal(L1.eliminaAlInicio());
            }
            else{
                aux2=aux2->siguiente;
                insertaAlFinal(L2.eliminaAlInicio());
            }
        }
        while(!L1.estaVacia()){
            insertaAlFinal(L1.eliminaAlInicio());
        }
        while(!L2.estaVacia()){
            insertaAlFinal(L2.eliminaAlInicio());
        }
    };
    void copia(LDE& L){
        liberaLDE();
        if(!L.estaVacia()){
            copia(L.primero, L.ultimo);
        }
    };
    void mergeSort(void){
        if(primero!=ultimo)
            mergeSort(primero, ultimo);
    };
    void quickSort(void){
        quickSort(primero, ultimo);
    };
};

int main(){
    srand(time(NULL));
    system("cls");
    LDE L1, L2, L3;
    int n;
    cout<<"Cuantos? ";cin>>n;

    for(int i=0;i<n;i++)
        L1.insertaAlFinal(rand()%1000);

    system("cls");
    L2.copia(L1);
    L3.copia(L1);

    cout<<endl<<"L1 -> ";
    L1.muestraDePrimeroAUltimo();
    cout<<endl<<"L2 -> ";
    L2.muestraDePrimeroAUltimo();
    cout<<endl<<"L3 -> ";
    L3.muestraDePrimeroAUltimo();
    cout<<endl<<endl;
    system("pause");
    L2.quickSort();
    L3.mergeSort();

    cout<<endl<<"L1 -> ";
    L1.muestraDePrimeroAUltimo();
    cout<<endl<<"L2 -> ";
    L2.muestraDePrimeroAUltimo();
    cout<<endl<<"L3 -> ";
    L3.muestraDePrimeroAUltimo();
    cout<<endl<<endl;
    system("pause");

    return 0;
}
