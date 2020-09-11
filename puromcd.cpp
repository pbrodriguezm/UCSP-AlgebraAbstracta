#include <iostream>
#include <string>
/**
 * Patrick Rodriguez Marquez -  Euclides 9
*/

using namespace std;


int mcd(int a, int b){
    
    int max = a;
    int min = b;
    int res;
    if(b>a){
        max=b;
    }

    while(b != 0 ){
        res=b;
        b=a%b;
        a=res;
    }

    return res;
}



int main()
{

    int a,b;
    cout<<"Ingrese 1º num:";cin>>a;
    cout<<"Ingrese 2º num:";cin>>b;
    cout<<"EL MCD: "<<mcd(a,b)<<endl;

   
}