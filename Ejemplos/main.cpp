#include <iostream>
#include <stdlib.h>
using namespace std;

int factorial(int n){
    if(n>=1)
        cout<<n<<"! = "<<n<<" * "<<n-1<<"!"<<endl;
    else
        cout<<"0! = 1"<<endl;
    if(n==0)
        return 1;
    else
        return n * factorial(n-1);
}

int main(){
    int n, f;

    cout<<"Ingresa n ";cin>>n;
    cout<<endl<<endl;

    f = factorial(n);
    cout<<endl<<endl;

    cout<<n<<"! = "<<f;
    cout<<endl<<endl;

    return 0;
}

