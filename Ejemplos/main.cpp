#include <iostream>
#include <stdlib.h>
using namespace std;

int fibonacci(int n){
    if(n>1)
        cout<<"fibonacci("<<n<<") = "<<"fibonacci("<<n-1<<") + "<<"fibonacci("<<n-2<<")"<<endl;
    else if(n==1)
        cout<<"fibonacci(1) = 1"<<endl;
    else
        cout<<"fibonacci(0) = 0"<<endl;

    if(n==0 || n==1)
        return n;
    else
        return fibonacci(n-1) + fibonacci(n-2);
}

int main(){
    int n, f;

    cout<<"Ingresa n ";cin>>n;
    cout<<endl<<endl;

    f = fibonacci(n);
    cout<<endl<<endl;

    cout<<"fibonacci("<<n<<") = "<<f;
    cout<<endl<<endl;

    return 0;
}

