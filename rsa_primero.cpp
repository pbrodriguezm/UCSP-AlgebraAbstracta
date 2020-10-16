#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include <sstream>

using namespace std;


class Rsa
{
    public:
        Rsa(long long);

        long long euclidesBina(long long, long long);
        vector<long long> euclidesBinaExtendido(long long, long long);

        
        void generarPyQ();         
        
        void generarE();
        
                
        
        long long aleatoria_afin(long long, long long);
        void generarD();
        
        void generar();
        
        int mcd(int, int);

        string convertirString(long long );
        long long convertirAint(string);
        void imprimirVector(vector<long long>);
        void imprimirVstring(vector<long long> );
        string esMenorAlTamanyo(string );
        
        
        vector<long long> transformarPalabra(string, long long,long long,long long);

        void llenarVectorBinario( long long);
        long long expo_mod( long long, long long, long long);        
        
        void encriptar(long long,long long,string,char*);
        string desencriptar(string ,char *);
        
    
    private:
        string data;

        string abc;
        vector<long long> primos;
        vector<long long> vectorBinari;
        long long tamanyoAbc;        
        long long p;
        long long q;
        long long n;
        long long fn;
        long long e;
        long long d;
};


Rsa::Rsa(long long tam)
{
   
    abc="abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789?¿!¡.,;()[]áéíóú";
    tamanyoAbc=abc.size(); 
}

void Rsa::imprimirVector(vector<long long> vec)
{
	for(int i=0;i<vec.size();i++)
		cout<<vec[i]<<" ";
}

void Rsa::imprimirVstring(vector<long long> vec)
{
   for(int i=0;i<vec.size();i++)
		cout<<abc[vec[i]]<<" ";
}




vector<long long> Rsa::euclidesBinaExtendido(long long x, long long y)
{
    long long g=1;
    while((x%2==0)&&(y%2)==0)
    {
        x=x>>1;
        y=y>>1;
        g=2*g;
    }
    long long u=x;
    long long v=y;
    long long A=1;
    long long B=0;
    long long C=0;
    long long D=1;
    long long a;
    long long b;

    while(u!=0)
    {
        while(u%2==0)
        {
            u=u>>1;
            if((A%2==0)&&(B%2==0))
            {
                A=A>>1; B=B>>1;
            }
            else
            {
                A=(A+y)>>1; B=(B-x)>>1;
            }
        }

        while(v%2==0)
        {
            v=v>>1;
            if((C%2==0)&&(D%2==0))
            {
                C=C>>1; D=D>>1;
            }
            else
            {
                C=(C+y)>>1; D=(D-x)>>1;
            }
        }

        if(u>=v)
        {
            u-=v; A-=C; B-=D;
        }
        else
        {
            v-=u; C-=A; D-=B;
        }

        if(u==0)
        {
            a=C; b=D;
        }
    }
    cout<<"a: "<<a<<" b: "<<b<<" c: "<<" v: "<<g*v<<endl;
    vector<long long>rpta;
    rpta.push_back(a);
    rpta.push_back(b);
    rpta.push_back(g*v);

    return rpta;
}

void Rsa::generarPyQ()
{
    p=17;
    q=43;

}


int Rsa::mcd(int a, int b){
    
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


void Rsa::generarE()
{
    long long tamVecPrimos=primos.size();
    srand ( time(NULL) );    
    int fin=0;
    do{
    long long ran=rand()%1000;
        if(mcd(ran,fn) == 1){ //coprimos o relativamente primos
            e=ran;   
            fin=1;
        }
    }while(fin==0);
          
}



long long Rsa::aleatoria_afin(long long a,long long b)
{
    vector<long long> aaa=euclidesBinaExtendido(a,b);
    if(aaa[0]<0)
        return aaa[0]+b;
    return aaa[0];
}

void Rsa::generarD()
{    
    d=aleatoria_afin(e,fn);
}


void Rsa::generar()
{    
    generarPyQ(); //primero generar p y q, para esta parte seran primos manualmente
    n=p*q;
    fn=(p-1)*(q-1); // luego generar n q es pxq y fiDeN


    generarE();    
    generarD();  

    cout<<"P: "<<p<<endl;
    cout<<"Q: "<<q<<endl;    
    cout<<"N: "<<n<<endl;
    cout<<"FiN : "<<fn<<endl;        
    cout<<"Ce=<n,e>  : "<<n<<","<<e<<endl;    
    cout<<"Cd=<n,d> : "<<n<<","<<d<<endl;

}


void Rsa::llenarVectorBinario( long long exp)
{
    vectorBinari.erase(vectorBinari.begin(),vectorBinari.end());
    while(exp>=1)
    {
        vectorBinari.push_back(exp%2);
        exp=exp>>1;
    }        
}



long long Rsa::expo_mod( long long base, long long exp, long long mod)
{
    //cout<<"Base:"<<base<<" ^"<<exp<<" mod"<<mod<<endl;
    int rpta;
    base%=mod;
    if(exp%2==1)
        rpta=base%mod;
    exp/=2;
    while(exp!=0){
        base=(base*base)%mod;
        if(exp%2==1)
            rpta=(base*rpta)%mod;
        exp/=2;
    }
    return rpta;
}

string Rsa::convertirString(long long a)
{
    std::stringstream out;
    out<<a;
    string rpta=out.str();
    return rpta;
}

long long Rsa::convertirAint(string a)
{
    long long rpta=atoi(a.c_str());
    return rpta;
}

string Rsa::esMenorAlTamanyo(string a)
{
    int tam=a.size();    
    string newN=convertirString(n);
    
    while(tam<newN.size())
    {
        a=("0"+a);
        tam++;
    }
    return a;
}



/***********************transforma la palabra lista para ser encriptada************************************/
vector<long long> Rsa::transformarPalabra(string a, long long pasarN,long long pri, long long seg)
{    
    long long numAbc=tamanyoAbc;
    vector<long long> vecNumsFinal;//vector con los numeros listos para encriptar

    long long digitosAbc;//digitos de abecedario
    long long lugar;
    vector<string> numDletras;
    
    if( (pri==0) && (seg==0))
    {    
        

        for( digitosAbc=1;numAbc/10>0;digitosAbc++)//sacar los digitos del abc
        {
            numAbc=numAbc/10;
        }

        /*convertir el valor de numeros de acada letra en un vector de string*/
        for(int i=0;i<a.size();i++)
        {
           
            lugar=abc.find(a[i]);
            vecNumsFinal.push_back(lugar);
                        
        }
      
    }
    return vecNumsFinal;
    
    
}
/***********************transforma la palabra lista para ser encriptada************************************/
/*******************************************encriptar*****************************/
void Rsa::encriptar(long long e_, long long n_,string texto,char* texto2)
{   


    data=texto;    
    vector<long long> vCasiEncriptado;
    vector<long long>vecNumsFinal;
    
    vecNumsFinal=transformarPalabra(data,n_,0,0);    
    
    
    for(int i=0;i<vecNumsFinal.size();i++)
    {
        //llenarVectorBinario(e);
        cout<<">>"<<vecNumsFinal[i]<<endl;
        vCasiEncriptado.push_back(expo_mod(vecNumsFinal[i],e_,n_));
        //cout<<

    }
    imprimirVector(vCasiEncriptado);cout<<endl;
    
    cout<<endl;               
    cout<<"-----------------------------------------------------------------"<<endl;
}
/*******************************************encriptar*****************************/

/************************************desencriptar*******************************************/

string Rsa::desencriptar(string texto,char *file2)
{   

    data=texto;    
    vector<long long> vCasiEncriptado;
    vector<int>vecNumsFinal;

    
    
    
    std::string delimiter = "-";

    size_t pos = 0;
    

    std::string token = texto.substr(0, texto.find(delimiter));
    
    int y=atoi(token.c_str());
    //vecNumsFinal.push_back(y);
    vecNumsFinal.push_back(y);

    for(int i=0;i<vecNumsFinal.size();i++)
    {
        //llenarVectorBinario(e);
        vCasiEncriptado.push_back(expo_mod(vecNumsFinal[i],d,n));
        //cout<<

    }
    imprimirVstring(vCasiEncriptado);cout<<endl;
    
    cout<<endl;               
    cout<<"-----------------------------------------------------------------"<<endl;
}



int main()
{
    Rsa a(26);    
    
    
    
    long long ee,nn,dd;
    char texto;
    a.generar();
    

               

    int var;
   

        cout<<endl<<"---------------------------------------------------"<<endl;
        
        cout<<endl<<"---------------------------------------------------"<<endl;
        cout<<"(1)Encriptar."<<endl;
        cout<<"(2)Desencriptar."<<endl;
        cout<<"(3)SALIR"<<endl;
    
        cout<<endl<<"Ingrese la opcion a ejecutar: ";
        cin>>var;
        
       
                cout<<endl<<endl<<"------------------------------------Encriptar--------------------------------------"<<endl;
                cout<<"Ingresa llave publica para encriptar n e: ";    
                cin>>nn>>ee;  
                string at;
                cout<<"Mensaje Para encriptar: "<<endl;
                cin>>at;
                a.encriptar(ee,nn,at,"");                
             
                cout<<endl<<endl<<"------------------------------------Desencriptar--------------------------------------"<<endl;                            
                string as;
                cout<<"Mensaje encritado: "<<endl;
                cin>>as;
                cout<<endl<<a.desencriptar(as,"");
                cout<<endl<<endl;

       
    return 0;
}

