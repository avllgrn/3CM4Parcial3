#include <iostream>
#include <stdlib.h>
using namespace std;

int multiplica(int a, int b){
    cout<<a<<" * "<<b<<" = "<<a<<" + ("<<a<<" * "<<b-1<<")"<<endl;
    if(b==1)
        return a;
    else
        return a + multiplica(a, b-1);
}

int main(){
    int a, b, c;

    cout<<"Ingresa a ";cin>>a;
    cout<<"Ingresa b ";cin>>b;
    cout<<endl<<endl;

    c = multiplica(a, b);
    cout<<endl<<endl;

    cout<<a<<" * "<<b<<" = "<<c;
    cout<<endl<<endl;

    return 0;
}

