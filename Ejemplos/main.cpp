#include <iostream>
#include <stdlib.h>
using namespace std;

string f(int n){
    cout<<"f("<<n<<")"<<endl;
    if(n==0)
        return "";
    else if(n%2==0)
        return f(n/2) + "0";
    else
        return f(n/2) + "1";
}

int main(){
    int n;

    cout<<"Ingresa n ";
    cin>>n;
    cout<<endl<<endl;

    string binario = f(n);
    cout<<endl<<endl<< n <<"(10) = "<< binario <<"(2)"<<endl<<endl;

    return 0;
}
