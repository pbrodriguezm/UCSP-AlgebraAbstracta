#include <iostream>
#include <string>
/**
 * Patrick Rodriguez Marquez
 * Tarea Viernes 4 de Septiembre
 * División números enteros
*/

using namespace std;



int main()
{
int a;
cout<<"a: ";cin>>a;
int n;
cout<<"n: "; cin>>n;

int q = a/n;
int r = a%n;
cout<<a<<"=("<<q<<"x"<<n<<")+("<<r<<") \n";

if(r<0){
    cout<<"sale negativo \n";
    r=n+r;
    q=q+1;
}

cout<<a<<"=("<<q<<"x"<<n<<")+("<<r<<")\n";

    
return 1;

}