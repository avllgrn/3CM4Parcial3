#include <iostream>
#include <stdlib.h>
using namespace std;

int sumatoria(int n){
    if(n>=1)
        cout<<"Suma de [0, "<<n<<"] = "<<n<<" + Suma de [0, "<<n-1<<"]"<<endl;
    else
        cout<<"Suma de [0, 0] = 0"<<endl;
    if(n==0)
        return 0;
    else
        return n + sumatoria(n-1);
}

int main(){
    int n, s;

    cout<<"Ingresa n ";cin>>n;
    cout<<endl<<endl;

    s = sumatoria(n);
    cout<<endl<<endl;

    cout<<"Suma de [0, "<<n<<"] = "<<s;
    cout<<endl<<endl;

    return 0;
}

