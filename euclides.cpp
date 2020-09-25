#include <iostream>
#include <string>
#include <vector>


using namespace std;

void imprimir(vector<int> a)
{
	for(int i=0;i<a.size();i++)
		cout<<a[i]<<" ";
	cout<<endl;
}



vector<int> eulidesExtendido(int a, int b)
{
	int d=0,q=0,r=0;
	int x=0,x1,x2;
	int y=0,y1,y2;
	vector<int> rpta;

	if(b==0)
	{
		d=a;
		x=1;
		y=0;
		rpta.push_back(d);
		rpta.push_back(x);
		rpta.push_back(y);
		return rpta;
	}
	x2=1; x1=0; y2=0 ; y1=1;
    int i=0;
    cout<<a<<" & "<<b<<" & "<<d<<" & "<<q<<" & "<<r<<" & "<<x<<" & "<<x1<<" & "<<x2<<" & "<<y<<" & "<<y1<<" & "<<y2<<endl;
	while(b>0)
	{
		q=a/b; r=a-(q*b); x=x2-(q*x1); y=y2-(q*y1);		
		a=b; b=r; x2=x1; x1=x; y2=y1; y1=y;
        i++;
        cout<<a<<" & "<<b<<" & "<<d<<" & "<<q<<" & "<<r<<" & "<<x<<" & "<<x1<<" & "<<x2<<" & "<<y<<" & "<<y1<<" & "<<y2<<endl;
        cout<<"----------------------------------------------------------"<<endl;
	}
	d=a; x=x2; y=y2;
	rpta.push_back(d);
	rpta.push_back(x);
	rpta.push_back(y);
    cout<<a<<" & "<<b<<" & "<<d<<" & "<<q<<" & "<<r<<" & "<<x<<" & "<<x1<<" & "<<x2<<" & "<<y<<" & "<<y1<<" & "<<y2<<endl;
    cout<<"i: "<<i<<endl;
	return rpta;
}

int main () {
    imprimir(eulidesExtendido(255,111));
    return 0;
}