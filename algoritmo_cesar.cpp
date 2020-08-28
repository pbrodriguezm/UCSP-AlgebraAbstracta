#include <iostream>
#include <string>

using namespace std;



class Receptor {

};

class Emisor {
public:
    int clave;
    string mensaje;
    string alfabeto;

    Emisor();
    void setMensaje(string m_mensaje);
    void setClave(int m_clave);
    string Cifrar();
};


    Emisor::Emisor(){
        alfabeto= "abcdefghijklmnopqrstuvwxyz";
    }

    void Emisor::setMensaje(string m_mensaje){       
            mensaje= m_mensaje;
            
    }

    void Emisor::setClave(int m_clave){
        clave= m_clave;
    }

    string Emisor::Cifrar(){
        string text;

        for (size_t i = 0; i < mensaje.size(); i++)
        {
            for (int j = 0; j < alfabeto.size(); j++)
            {
                int pos=0;
                if(mensaje[i] == alfabeto[j]){

                  if(j+ clave > alfabeto.size()-1) {
                     int sobrante= (j+ clave) - alfabeto.size();

                      pos=0;
                      text+=alfabeto[sobrante];
                  }else {
                      pos=j;
                      text+=alfabeto[pos+ clave];
                  }
                
                }
            }
        }
        
        return text;       
    }



int main()
{
    
   /* 
    char c1,c2;
    c1 = 'a';
    c2 = 97;
    if(c1==c2) 
    {
        std::cout << " iguales "<< std::endl;
    } else     {
        cout<<"distintos";
    }*/

    Emisor a;
    string mensaje; cout<<"Encriptación \n Mensaje: "; cin>> mensaje;
    int  clave; cout<<"clave(#): "; cin>> clave;
    a.setMensaje(mensaje);
    a.setClave(clave);
    std::cout<<"Encriptado: " << a.Cifrar() << std::endl;

    cout << endl;
}