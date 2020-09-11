#include <iostream>
#include <string>
#include <cstring>
/**
 * Patrick Rodriguez Marquez
*/

using namespace std;



class Receptor {
    public:
    int clave;
    string mensaje;
    char * alfabeto;

    Receptor();
    void setMensaje(string m_mensaje);
    void setClave(int m_clave);
    string Decifrar();
};

    Receptor::Receptor(){
        alfabeto= "abcdefghijklmnopqrstuvwxyz";
    }

    void Receptor::setMensaje(string m_mensaje){        //Mensaje escriptado
            mensaje= m_mensaje;
            
    }

    void Receptor::setClave(int m_clave){
        clave= m_clave;
    }

    string Receptor::Decifrar(){
        string text;
        for (size_t i = 0; i < mensaje.size(); i++)
        {
            char crip;
            if(mensaje[i]-clave < 'a'){     
                crip= (mensaje[i]- clave) + strlen(alfabeto);
            }else {
                 crip= mensaje[i]-clave;
            }
           text +=crip;
        }
        return text;       
    }




class Emisor {
public:
    int clave;
    char * mensaje;
    char * alfabeto;

    Emisor();
    void setMensaje(char * m_mensaje);
    void setClave(int m_clave);
    string Cifrar();
    string Cifrar_dos();
};


    Emisor::Emisor(){
        alfabeto= "abcdefghijklmnopqrstuvwxyz";
    }

    void Emisor::setMensaje(char * m_mensaje){       
            mensaje= m_mensaje;
            
    }

    void Emisor::setClave(int m_clave){
        clave= m_clave;
    }

/**
 * Cifrafo de Cesar pero con char sumando valores a su numeraciópn ascii
*/
    string Emisor::Cifrar_dos(){
        string text;
        for (size_t i = 0; i < strlen(mensaje); i++)
        {
            cout<<mensaje[i]+clave <<"\n";  
            char crip;
            if(mensaje[i]+clave > 'z'){   
                cout<<mensaje[i]<<"\n";  
                crip= (mensaje[i]+ clave) - strlen(alfabeto);
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
    char * mensaje; cout<<"Encriptación \n** Mensaje: "; cin>> mensaje;
    int  clave; cout<<"** clave(#): "; cin>> clave;
    a.setMensaje(mensaje);
    a.setClave(clave);
    //std::cout<<"** Encriptado: " << a.Cifrar() << std::endl;
    string mensaje_escriptado = a.Cifrar_dos();
    cout << endl;
    std::cout<<"** Encriptado: " << mensaje_escriptado<< std::endl;   
    Receptor b;
    b.setMensaje(mensaje_escriptado);
    b.setClave(clave);
    string mensaje_desencriptado = b.Decifrar();
    std::cout<<"** Desencriptado: " << mensaje_desencriptado<< std::endl;




}

//receptor recibe:
//mensaje cifrado