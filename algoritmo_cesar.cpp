#include <iostream>
#include <string>
/**
 * Patrick Rodriguez Marquez
*/

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
    string Cifrar_dos();
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

/**
 * Cifrafo de Cesar recorriendo alfabeto con doble for
*/
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


/**
 * Cifrafo de Cesar pero con char sumando valores a su numeraciópn ascii
*/
    string Emisor::Cifrar_dos(){
        string text;
        for (size_t i = 0; i < mensaje.size(); i++)
        {
            char crip;
            if(mensaje[i]+clave > 'z'){     
                crip= (mensaje[i]+ clave) - alfabeto.size();
            }else {
                 crip= mensaje[i]+clave;
            }
           text +=crip;
        }
        return text;       
    }



int main()
{
    Emisor a;
    string mensaje; cout<<"Encriptación \n** Mensaje: "; cin>> mensaje;
    int  clave; cout<<"** clave(#): "; cin>> clave;
    a.setMensaje(mensaje);
    a.setClave(clave);
    std::cout<<"** Encriptado: " << a.Cifrar() << std::endl;
    std::cout<<"** Encriptado 2: " << a.Cifrar_dos() << std::endl;
    cout << endl;
}